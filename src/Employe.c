#include "Employe.h"

void* traitement_Employe(void* p){

	DonneesTraitement* d = (DonneesTraitement*) p;
	traitement_Cesar(d->mot->mot, d->clef, d->sens);
	produire(d->mot, d->buffer);
	return NULL;
}
																	// ATTENTE PASSIVE
void produire(Mot* m, Buffer* buf){
	pthread_mutex_lock(buf->mutex);									// On entre en section critique, on la protège avec un mutex.
	while(m->numero != buf->ordre){									// Un thread producteur attend sur la condition "dansOrdre" tant qu'il n'est pas le prochain mot dans l'ordre imposé par le buffer (numero mot == ordre buffer).
		pthread_cond_wait(buf->dansOrdre, buf->mutex);
	}																// Lorsque le mot correspond à l'ordre :
	if(!peutContenirMot_Buffer(buf, *m))							// Si le buffer ne peut pas contenir le mot, le thread producteur attend sur la condition peutProduire.
		pthread_cond_wait(buf->peutProduire, buf->mutex);				
	insert_Buffer(buf, *m);											// Si le buffer peut contenir le mot, le thread producteur l'insère dans le buffer.
	finalize_Mot(m);												// Il supprime la structure Mot en mémoire.
	buf->ordre += 1;												// Il met à jour l'ordre du buffer.
	pthread_cond_broadcast(buf->dansOrdre);							// Il envoie à tous les autres threads producteurs qui attendent sur la condition dansOrdre, le signal "vérifiez si vous correspondez à l'ordre du buffer"
	pthread_cond_signal(buf->peutConsommer);						// Il envoie au thread consommateur le signal "tu peux consommer".
	pthread_mutex_unlock(buf->mutex);								// On sort de section critique, on libère le mutex.
}
