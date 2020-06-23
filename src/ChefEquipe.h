#ifndef CHEFEQUIPE_H
#define CHEFEQUIPE_H
#endif

#ifndef BUFFER_H
#define BUFFER_H
  #include "Buffer.h"
#endif

#ifndef STDLIB_H
#define STDLIB_H
  #include <stdlib.h>
#endif

#ifndef STDIO_H
#define STDIO_H
  #include <stdio.h>
#endif

#ifndef UNISTD_H
#define UNISTD_H
  #include <unistd.h>
#endif

#ifndef PTHREAD_H
#define PTHREAD_H
  #include <pthread.h>
#endif

#ifndef MOT_H
#define MOT_H
  #include "Mot.h"
#endif

#ifndef CONSTANTE_H
#define CONSTANTE_H
	#include "Constantes.h"
#endif

#ifndef FICHIER_H
#define FICHIER_H
	#include "Fichier.h"
#endif

#ifndef CHAINE_H
#define CHAINE_H
	#include "Chaine.h"
#endif

#ifndef MESSAGE_H
#define MESSAGE_H
	#include "Message.h"
#endif

#ifndef EMPLOYE_H
#define EMPLOYE_H
	#include "Employe.h"
#endif

/**
\struct	:	DonneesTraitement
\brief	:	Stocke les données necéssaires au traitement d'un mot par les threads employés.
*/
typedef struct{
	Mot* mot;			/*!< Pointeur sur le mot à traiter. */
	int sens;			/*!< Sens de traitement du mot : chiffrage ou déchiffrage. */
	int clef;			/*!< Clef de traitement. */
	Buffer* buffer;		/*!< Pointeur sur la structure Buffer qui contiendra la chaine de caractères du mot traité. */
} DonneesTraitement;


/**
* \func : traitement_ChefEquipe
* \brief : fonction qui ouvre le fichier que le chef d'equipe doit traiter, puis qui
* lis les mots contenus dans ce même fichier et qui les traites par blocs,
* en fonction de la limite de threads définie dans constante, avec un mot =  thread.
*
* \param : msg un message qui contient les infos du fichier a déchiffrer.
*
*/
void traitement_ChefEquipe(Message msg);


/**
* \func : consommer
* \brief : fonction qui
*
* \param : msg un message qui contient les infos du fichier a déchiffrer.
*
*/
void consommer(Buffer* buf, int nbThreads);

/**
* \func : initialize_DonneesTraitement
* \brief : fonction qui créer, puis renvoie un struct DonneesTraitement en fonction des paramètres qu'on lui a passé.
*
* \param : mot, le mot qu'on cherche à traiter. sens : chiffrage ou déchiffrage, clef : le décalage. Buffer : conteneur du futur mot traité.
* \return : un DonneesTraitement qui initialise chaques champs avec les valeurs indiquées dans les paramètres lors de l'appel de la fonction
*/
DonneesTraitement initialize_DonneesTraitement(Mot* mot, int sens, int clef, Buffer* buffer);
