#ifndef CHAINE_H
#define CHAINE_H
#endif

#ifndef STDLIB_H
#define STDLIB_H
  #include <stdlib.h>
#endif

#ifndef STDIO_H
#define STDIO_H
  #include <stdio.h>
#endif

#ifndef STRING_H
#define STRING_H
  #include <string.h>
#endif

/**
\struct	:	SousChaines
\brief	:	Stocke les chaines de caractères extraites d'une chaine principale.
*/

typedef struct{
	char** tab;		/*!< Tableau à deux dimensions pour stocker les chaines de caractères. */
	int nb;			/*!< Nombre de chaines de caractères contenues dans la structure. */
} SousChaines;

/**
\fn		:	initialize_SousChaines
\brief	:	Initialise une structure SousChaines en mémoire.
\param 	:	nb : nombre de chaines , tailleChaine : taille maximale d'une chaine.
\return :	Renvoie la structure SousChaines initialisée.
*/
SousChaines initialize_SousChaines(int nb, int tailleChaine);

/**
\fn		:	finalize_SousChaines
\brief	:	Supprime une structure SousChaines en mémoire.
\param 	:	sc : Structure SousChaines à supprimer.
\return :	Ne renvoie rien.
*/
void finalize_SousChaines(SousChaines sc);

/**
\fn		:	extraire_SousChaines
\brief	:	Extrait les sous chaines d'une chaine principale au niveau d'un délimitateur donné.
\param 	:	a : la chaine principale, d : le délimitateur
\return :	Renvoie une structure SousChaines contenant toutes les chaines extraites de la chaine principale au niveau du délimitateur.
*/
SousChaines extraire_SousChaines(const char* a, const char d);

/**
\fn		:	affiche_SousChaines
\brief	:	Affiche les sous chaines contenues dans la structure SousChaines.
\param 	:	sc : la structure SousChaines dont on souhaite afficher le contenu.
\return :	Ne renvoie rien.
*/
void affiche_SousChaines(SousChaines sc);
