#include "Directeur.h"


void traitement_Directeur(char* chemin){

	Fichier* f = ouvrirFichier(chemin, "r");
	if(f == NULL){
		printf("Le fichier principal \"%s\" entré n'a pas pu être ouvert.\n", chemin);
		exit(EXIT_FAILURE);
	}
	char buffLigne[MAX_TAILLE_LIGNE];
	int num = 1;
	pid_t pid;
	while(getLine(f, buffLigne, MAX_TAILLE_LIGNE)!=-1){
		SousChaines sc = extraire_SousChaines(buffLigne, ';');				// On rappelle qu'après l'utilisation d'un fork(), si les variables du processus père sont copiées dans le processus fils,
		Message msg = initialize_Message(sc, num);							// elles n'en demeurent pas moins totalement distinctes. Deux processus différents n'ont pas la même mémoire (contrairement aux threads).
		num += 1;															// On peut donc se permettre de n'utiliser qu'une seule variable msg pour initialiser toutes les structures Messages.
		pid = fork();														// Les processus fils créés par l'appel système fork() à chaque itération i, possèderont une copie de la structure Message initialisée à l'itération i.
		if(pid == 0){														// Au final, chaque processus fils possedera une structure Message complètement distincte. 
			traitement_ChefEquipe(msg);
			//affiche_Message(msg);											// Juste pour tester la structure message et la création des processus.
			int sens = (msg.sens == CHIFFRAGE) ? CHIFFRAGE : DECHIFFRAGE;
			finalize_Message(msg);											// On libère la mémoire de la structure Message (pour les processus fils).
			exit(sens);
		}
		finalize_Message(msg); 												// On libère la mémoire de la structure Message (pour le processus père).
	}

	int codeRetour;
	int nbChiffreur = 0;
	int nbDechiffreur = 0;
	int nbMessagesErreur = 0;

	while(wait(&codeRetour) != -1){								// Faire un switch
		if (WEXITSTATUS(codeRetour) == CHIFFRAGE)
			nbChiffreur += 1;
		else if(WEXITSTATUS(codeRetour) == DECHIFFRAGE)
			nbDechiffreur += 1;
		else if(WEXITSTATUS(codeRetour) == EXIT_FAILURE)
			nbMessagesErreur += 1;
	}

	printf("\n");
	printf("%d messages à traiter :\n", num-1);
	printf("%d messages chiffrés \n", nbChiffreur);
	printf("%d messages déchiffrés \n", nbDechiffreur);
	if(nbMessagesErreur > 0)
	printf("%d messages n'ont pas pu être traités \n", nbMessagesErreur);
	// Contenu du tube*/

	fermerFichier(f);

}

