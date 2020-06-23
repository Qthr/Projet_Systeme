#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "Constantes.h"

#include "Cesar.h"

char* traitement_Cesar(char* mot, int clef, int sens){
	return (sens == CHIFFRAGE) ? Chiffrer(mot, clef) : Dechiffrer(mot, clef);
}


char ChiffrerCar(char c, int clef)
{
	if (!isalpha(c))
		return c;

	char decalage = isupper(c) ? 'A' : 'a';
	return (char)((((c + clef) - decalage) % 26) + decalage);
 }


char* Chiffrer(char* chaine, int clef)
{
	int tailleChaine = strlen(chaine);
	int i;
	for (i = 0; i < tailleChaine; ++i)
		chaine[i] = ChiffrerCar(chaine[i], clef);

	return chaine;
}


char* Dechiffrer(char* chaine, int clef)
{
	return Chiffrer(chaine, 26 - clef);
}
