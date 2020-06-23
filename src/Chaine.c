#include "Chaine.h"


SousChaines initialize_SousChaines(int nb, int tailleChaine){
	SousChaines sc;
	sc.nb = nb;
	sc.tab = malloc(nb * sizeof(char*));
	int i;
	for(i=0;i<nb;i++)
		sc.tab[i] = malloc(tailleChaine * sizeof(char));
	return sc;
}


void finalize_SousChaines(SousChaines sc){
	int i;
	for(i=0;i<sc.nb;i++)
		free(sc.tab[i]);
	free(sc.tab);
}


SousChaines extraire_SousChaines(const char* a, const char d){
	SousChaines r;
	int i = 0, j = 0, n = 0;
	int compte = 1;
	while(a[n] != '\0'){
		if(a[n] == d)
			compte++;
		n++;
	}
	r = initialize_SousChaines(compte, n);
	n = 0;
	while(a[n] != '\0'){
		if(a[n] != d)
			r.tab[i][j] = a[n];
		else{
			r.tab[i][j] = '\0';
			j = (-1);
			i++;
		}
		n++;
		j++;
	}
	r.tab[i][j] = '\0';
	return r;
}


void affiche_SousChaines(SousChaines sc){
		int i;
		for(i=0; i< sc.nb; i++)
			printf("Chaine %d: %s ", i, sc.tab[i]);
}
