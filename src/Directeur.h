#ifndef DIRECTEUR_H
#define DIRECTEUR_H
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

#ifndef SYS_H
#define SYS_H
	#include <sys/types.h>
	#include <sys/wait.h>
  #include <sys/stat.h>
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

#ifndef CHEFEQUIPE_H
#define CHEFEQUIPE_H
  #include "ChefEquipe.h"
#endif


/**
* \func : traitement_Directeur
* \brief : fonction qui ouvre le fichier indiqué lors de l'appel du programme.
* Elle créé ensuite les chef d'équipes qui traitent tous les fichiers et tous les messages.
*
* \param : chemin : chemin du fichier directeur.
*
*/
void traitement_Directeur(char* chemin);
