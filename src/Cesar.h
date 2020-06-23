#ifndef CESAR_H
#define CESAR_H
#endif

#ifndef STDLIB_H
#define STDLIB_H
  #include <stdlib.h>
#endif

#ifndef STRING_H
#define STRING_H
  #include <string.h>
#endif

#ifndef CTYPES_H
#define CTYPES_H
  #include <ctype.h>
#endif

#ifndef CONSTANTE_H
#define CONSTANTE_H
  #include "Constantes.h"
#endif

char* traitement_Cesar(char* mot, int clef, int sens);
/**
* \func : ChiffrerCar
* \brief : fonction qui chiffre un caractere selon la méthode Cesar.
*
* \param : c char qui contient une lettre, clef : entier qui indique la clef du decalage.
* \return : un char chiffré selon la clef indiquée
*/
char ChiffrerCar(char c, int clef);


/**
* \func : Chiffrer
* \brief : fonction qui controle le chiffrage avec la méthode cesar, en utilisant
* la fonction ChiffrerCar pour chiffrer les caractères 1 par 1
*
* \param : chaine chaine de caractere a chiffrer, clef : entier qui indique la clef du decalage.
* \return : renvoie la chaine de caractère chiffrée
*/
char* Chiffrer(char* chaine, int clef);

/**
* \func : dechiffrer
* \brief : fonction qui controle le dechiffrage avec la méthode cesar, en appelant
* la fonction Chiffrer avec 26 - le décalage (clef)
*
* \param : chaine chaine de caractere a chiffrer, clef : entier qui indique la clef du decalage.
* \return : renvoie la chaine de caractère déchiffrée
*/

char* Dechiffrer(char* chaine, int clef);
