#ifndef MESSAGE_H
#define MESSAGE_H
#endif

#ifndef STDIO_H
#define STDIO_H
	#include <stdio.h>
#endif

#ifndef CHAINE_H
#define CHAINE_H
	#include "Chaine.h"
#endif

#ifndef CONSTANTE_H
#define CONSTANTE_H
	#include "Constantes.h"
#endif

#ifndef FICHIER_H
#define FICHIER_H
	#include "Fichier.h"
#endif


/**
\struct	:	Message
\brief	:	Stocke les données représentant un message.
*/
typedef struct Message{
	int numero;				/*!< Numéro du message. */
	char* chemin;			/*!< Chemin du fichier contenant les caractères du message. */
	int sens;				/*!< Sens de traitement à effectuer sur le message : chiffrage ou déchiffrage. */
	int clef;				/*!< Clef de traitement. */

} Message;


/**
\fn		:	init_Message
\brief	:	Initialise une structure Message en mémoire à partir d'une structure SousChaines et d'un numéro.
\param 	:	sc : Structure SousChaines dont on va copier les données, num : numéro de la structure Message initialisée.
\return :	Renvoie la structure Message initialisée.
*/
Message initialize_Message(SousChaines sc, int num);


/**
\fn		:	finalize_Message
\brief	:	Supprime une structure Message en mémoire.
\param 	:	msg : structure Message à supprimer.
\return :	Ne renvoie rien.
*/
void finalize_Message(Message msg);


/**
\fn		:	affiche_Message
\brief	:	Affiche les données contenues dans la structure SousChaines.
\param 	:	msg : la structure Message dont on souhaite afficher le contenu.
\return :	Ne renvoie rien.
*/
void affiche_Message(Message msg);
