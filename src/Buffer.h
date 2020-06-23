#ifndef BUFFER_H
#define BUFFER_H
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

#ifndef CONSTANTE_H
#define CONSTANTE_H
	#include "Constantes.h"
#endif

#ifndef MOT_H
#define MOT_H
  #include "Mot.h"
#endif

/**
\struct	:	Buffer
\brief	:	Structure représentant le buffer partagé entre les différents threads.
*/
typedef struct {
	char* tab;							/*!< Chaine de caractères stockant le contenu du buffer. */
	int taille;							/*!< La taille du buffer : nombre de caractères qu'il comporte. */
	pthread_mutex_t* mutex;				/*!< Mutex pour assurer la dépendance du buffer à plusieurs threads. */
	pthread_cond_t* peutConsommer;		/*!< Condition pour gérer la synchronisation entre les threads producteurs et le thread consommateur. */
	pthread_cond_t* peutProduire;		/*!< Condition pour gérer la synchronisation entre le thread producteur et les threads consommateurs. */
	pthread_cond_t* dansOrdre;			/*!< Condition pour gérer la synchronisation entre les threads producteurs en suivant l'ordre défini par "ordre". */
	int ordre;							/*!< Numéro du prochain mot qui pourra être ajouté au buffer. */

} Buffer;

/**
\fn		:	initialize_Buffer
\brief	:	Initialise une structure Buffer en mémoire.
\param 	:	mut : pointeur sur un mutex , condc/condp/condo : conditions.
\return :	Renvoie un pointeur sur la structure Buffer initialisée.
*/
Buffer* initialize_Buffer(pthread_mutex_t* mut, pthread_cond_t* condc, pthread_cond_t* condp, pthread_cond_t* condo);


/**
\fn		:	finalize_Buffer
\brief	:	Supprime une structure Buffer en mémoire.
\param 	:	buf : pointeur vers la structure Buffer à supprimer.
\return :	Ne renvoie rien.
*/
void finalize_Buffer(Buffer* buf);


/**
\fn		:	estPlein_Buffer
\brief	:	Indique si le buffer est rempli.
\param 	:	buf : pointeur sur la structure Buffer.
\return :	Renvoie 1 si le buffer est plein, 0 sinon.
*/
int estPlein_Buffer(Buffer* buf);


/**
\fn		:	estVide_Buffer
\brief	:	Indique si le buffer est vide.
\param 	:	buf : pointeur sur la structure Buffer.
\return :	Renvoie 1 si le buffer est vide, 0 sinon.
*/
int estVide_Buffer(Buffer* buf);


/**
\fn		:	peutContenirMot_Buffer
\brief	:	Indique si le buffer peut contenir un mot (+ un espace);
\param 	:	buf : pointeur sur la structure Buffer, m : mot.
\return :	Renvoie 1 si le buffer peut contenir le mot, 0 sinon.
*/
int peutContenirMot_Buffer(Buffer* buf, Mot m);


/**
\fn		:	insert_Buffer
\brief	:	Ajoute un mot suivi d'un espace dans le buffer.
\param 	:	buf : pointeur sur la structure Buffer, m : mot à ajouter.
\return :	Ne renvoie rien.
*/
void insert_Buffer(Buffer* buf, Mot m);


/**
\fn		:	vide_Buffer
\brief	:	Vide le buffer.
\param 	:	buf : pointeur sur la structure Buffer
\return :	Renvoie le nombre de mots vidés.
*/
int vide_Buffer(Buffer* buf);
