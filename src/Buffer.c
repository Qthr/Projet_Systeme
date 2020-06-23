#include "Buffer.h"


Buffer* initialize_Buffer(pthread_mutex_t* mut, pthread_cond_t* condc, pthread_cond_t* condp, pthread_cond_t* condo){
	Buffer* buf = malloc(sizeof(Buffer));
	buf->tab = malloc(TAILLE_BUFFER*sizeof(char));
	buf->taille = 0;
	buf->ordre = 1;
	buf->mutex = mut;
	buf->peutConsommer = condc;
	buf->peutProduire = condp;
	buf->dansOrdre = condo;
	return buf;
}


void finalize_Buffer(Buffer* buf){
	if(buf != NULL){
		free(buf->tab);
		free(buf);
	}
}


int estPlein_Buffer(Buffer* buf){
	return buf->taille == TAILLE_BUFFER;
}


int estVide_Buffer(Buffer* buf){
	return buf->taille == 0;
}


int peutContenirMot_Buffer(Buffer* buf, Mot m){
	return TAILLE_BUFFER > (buf->taille + m.taille + 1);			// +1 : pour l'espace
}


void insert_Buffer(Buffer* buf, Mot m){
	int i,j;
	for(i=0,j=buf->taille;i<m.taille;i++,j++){
		buf->tab[j] = m.mot[i];
	}
	buf->tab[j] = ' ';
	buf->tab[j+1] = '\0';
	buf->taille += (m.taille+1);					// La prochaine insertion commencera sur '\0' de la precedente insertion
}

int vide_Buffer(Buffer* buf){
	int nbMots = 0;
	int i;
	for(i=0;buf->tab[i]!='\0';i++){
		if(buf->tab[i]==' '){
			nbMots++;
			if(buf->tab[i-1] == '\n')
				continue;						// On saute les espaces qui suivent un retour à la ligne.
		}
		write(1,buf->tab+i,1);
	}
	buf->taille = 0;
	return nbMots;
}
