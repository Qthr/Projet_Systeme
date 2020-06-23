#include "ChefEquipe.h"

#define NBTHREADS 50

void traitement_ChefEquipe(Message msg){

	Fichier* f = ouvrirFichier(msg.chemin, "r");
	if(f == NULL){
		//printf("Le fichier message %d : \"%s\" n'a pas pu être ouvert.\n",msg.numero, msg.chemin);
		exit(EXIT_FAILURE);
	}
	char buffMot[MAX_TAILLE_MOT];
	pthread_t* tids = malloc(NBTHREADS*sizeof(pthread_t));
	DonneesTraitement* donnees = malloc(NBTHREADS*sizeof(DonneesTraitement));
	pthread_mutex_t mut = PTHREAD_MUTEX_INITIALIZER;
	pthread_cond_t condc = PTHREAD_COND_INITIALIZER;
	pthread_cond_t condp = PTHREAD_COND_INITIALIZER;
	pthread_cond_t condo = PTHREAD_COND_INITIALIZER;
	Buffer* buf = initialize_Buffer(&mut, &condc, &condp, &condo);
	int i = 0;																					// Parcours des tableaux de pthread_t et de structure DonneesTraitement.
	int numMot = 1;

	while(getWord(f, buffMot, MAX_TAILLE_LIGNE) != -1){
		Mot* m = initialize_Mot(buffMot, numMot);
		donnees[i] = initialize_DonneesTraitement(m, msg.sens, msg.clef, buf);
		pthread_create(tids+i,NULL,traitement_Employe, donnees+i);
		i++;
		numMot++;
		if(i == NBTHREADS){																			// Si le maximum possible de threads a été créé (paquet maximal de threads).
			consommer(buf, NBTHREADS);																// On va récupérer les mots traités par les threads
			for(i=0; i<NBTHREADS;i++){																// Attendre leur terminaison
				pthread_join(tids[i], NULL);														// Puis recommencer à créer un nouveau paquet de threads pour les mots suivants.
			}
			i = 0;																					// Ne pas oublier finalize(mot);
		}
	}
	if(i>0 && i< NBTHREADS){																		// Lorsqu'on a atteint la fin du fichier, on traite le dernier paquet de threads (non maximal)
		consommer(buf, i);																				// On récupère les mots traités par les dernier threads.
		for(i=0; i<NBTHREADS;i++){																	// On attend leur terminaison
			pthread_join(tids[i], NULL);
		}
	}
	finalize_Buffer(buf);
	free(donnees);
	free(tids);
}
																				// ATTENTE PASSIVE
void consommer(Buffer* buf, int nbThreads){
	int i = 0;																	// Le thread principal consomme le contenu du buffer tant que les mots de tous les threads n'ont pas été récupérés.
	while(i<nbThreads){															// On va compter les mots du buffer lors de son vidage pour connaitre le nombre de threads qu'il reste à traiter.
		pthread_mutex_lock(buf->mutex);											// On entre en section critique, on la protège avec un mutex.
		if(estVide_Buffer(buf))													// Si le buffer est vide, le thread principal(consommateur) attend sur la condition peutConsommer
			pthread_cond_wait(buf->peutConsommer, buf->mutex);
		i += vide_Buffer(buf);													// Si le buffer n'est pas vide, le thread vide le buffer, et compte le nombre de mots/threads completement traités.
		pthread_cond_broadcast(buf->peutProduire);								// Lorsque le buffer est vide, le thread envoie à tous les threads producteurs, le signal "vous pouvez produire".
		pthread_mutex_unlock(buf->mutex);										// On sort de section critique, on libère le mutex.
	}
}


DonneesTraitement initialize_DonneesTraitement(Mot* mot, int sens, int clef, Buffer* buffer){
	DonneesTraitement d;
	d.mot = mot;
	d.clef = clef;
	d.sens = sens;
	d.buffer = buffer;
	return d;
}
