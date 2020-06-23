#ifndef EMPLOYE_H
#define EMPLOYE_H
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

#ifndef CHEFEQUIPE_H
#define CHEFEQUIPE_H
  #include "ChefEquipe.h"
#endif

#ifndef CESAR_H
#define CESAR_H
  #include "Cesar.h"
#endif

#ifndef BUFFER_H
#define BUFFER_H
  #include "Buffer.h"
#endif


/**
* \func : traitement_Employe
* \brief : fonction qui gère le thread et qui s'occupe de chiffrer/ou de dechiffrer le mot
* le mot qu'un thread contient
*
* \param : p le void* qui sera casté en DonneesTraitement.
*
*/
void* traitement_Employe(void* p);


/**
* \func : produire
* \brief : fonction qui insère, une fois que c'est possible, le mot dans le buffer.
*
* \param : m, struct Mot qui contient les infos sur le mot a inscrire, *buf : l'addresse du
* buffer contenant le mot 
*
*/
void produire(Mot* m, Buffer* buf);
