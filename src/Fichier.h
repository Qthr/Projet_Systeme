#ifndef SYS_H
#define SYS_H
  #include <sys/types.h>
  #include <sys/wait.h>
  #include <sys/stat.h>
#endif

#ifndef FCNTL_H
#define FCNTL_H
  #include <fcntl.h>
#endif

#ifndef UNISTD_H
#define UNISTD_H
  #include <unistd.h>
#endif

#ifndef CESAR_H
#define CESAR_H
  #include "Cesar.h"
#endif

/**
\struct : Fichier
\brief  : Structure qui stocke le descripteur d'un fichier.
*/
typedef struct {
  int fd;     /*!< Descripteur de fichier. */
} Fichier;


/**
\fn     :   ouvrirFichier
\brief  :   Ouvre un fichier selon un mode entré.
\param  :   chemin : chemin du fichier, mode : mode d'ouverture.
      Les modes d'ouverture sont : r (lecture), r+ (lecture/ecriture), w (écriture + troncature), a (écriture + ajout en fin de fichier)
      Les modes w et a entrainent la création du fichier s'il n'existe pas.
\return :   Renvoie le flux du fichier si l'ouverture a fonctionné, NULL sinon.
*/
Fichier* ouvrirFichier(const char* chemin, const char* mode);


/**
\fn     :   fermerFichier
\brief  :   Ferme un fichier.
\param  :   f : Flux du fichier
\return :   Renvoie 0 si le fichier a été fermé, -1 sinon.
*/
int fermerFichier(Fichier* f);


/**
\fn     :   getChar
\brief  :   Lit un caractère dans un fichier.
\param  :   f : Flux du fichier.
\return :   Renvoie le caractère lu si succès, EOF si échec.
*/
char getChar(Fichier* f);


/**
\fn     :   getWord
\brief  :   Lit un mot dans un fichier.
\param  :   f : flux du fichier, buf : le buffer pour stocker le mot, size : la taille maximale du buffer.
\return :   Renvoie le nombre de caractères lus si succès, -1 si échec.
*/
int getWord(Fichier* f, char *buf, int size);


/**
\fn     :   getLine
\brief  :   Lit une ligne dans un fichier.
\param  :   f : flux du fichier, buf : le buffer pour stocker la ligne, size : la taille maximale du buffer.
\return :   Renvoie le nombre de caractères lus si succès, -1 si échec.
*/
int getLine(Fichier* f, char *buf, int size);


/**
\fn     :   putChar
\brief  :   Écrit un caractère dans un fichier.
\param  :   f : Flux du fichier, c : le caractère à écrire.
\return :   Renvoie 0 si le caractère a été écrit, -1 sinon.
*/
int putChar(Fichier* f, char c);


/**
\fn     :   putString
\brief  :   Ecrit une chaine de caracteres dans un fichier
\param  :   f : Flux du fichier, c : le caractère à écrire.
\return :   Renvoie 0 si le caractère a été écrit, -1 sinon.
*/
int putString(Fichier* f, char *c);
