#ifndef CONSTANTE_H
#define CONSTANTE_H
#endif

#define MAX_TAILLE_LIGNE 256	// Taille du buffer qui sert à stocker les lignes lues dans un fichier.
#define MAX_TAILLE_MOT 128		// Taille du buffer qui sert à stocker les mots lus dans un fichier.
#define CHIFFRAGE 100
#define DECHIFFRAGE 101
#define TAILLE_BUFFER 1024		// Taille du buffer qui stockera les mots traités par Cesar.
#define NBLETTRE 26

// ############################### Gestion des Threads ########################################


// Un système Linux a une limite au nombre total de processus pouvant être chargés en même temps.
// Pour le connaitre, effectuer la commande shell : cat /proc/sys/kernel/threads-max
// Le système Linux sur lequel sera testé le programme donne : 61253.
// On prend en compte (de manière arbitraire), les processus/threads nécessaires au fonctionnement du système, et la place pour d'autre processus/threads utilisateurs, chargés lors de l'exécution du programme.
// On définit donc :
#define NB_THREADS_SYSTEM_MAX 55000 		// Nombre maximal de processus(threads) chargeables en mémoire en même temps par le système.


// Un système Linux a une limite au nombre total de processus pouvant être chargés en même temps par un même utilisateur.
// Pour le connaitre, effectuer la commande shell : ulimit -u
// Le système Linux sur lequel sera testé le programme donne : 30626.
// On prend en compte (de manière arbitraire), les processus/threads nécessaires au fonctionnement du système, et la place pour d'autre processus/threads utilisateurs, chargés lors de l'exécution du programme.
// On définit donc :
#define NB_THREADS_USER_MAX 25000 		// Nombre maximal de processus(threads) chargeables en mémoire en même temps par le système pour un même utilisateur.


// Man ulimit
// ulimit [-HSTabcdefilmnpqrstuvx [limit]]
//              .....
//              -u     The maximum number of processes available to a single user
//              .....

/*

There is no limit that I know of, but there are two practical limits:

The virtual space for the stacks. For example in 32-bits the virtual space of the process is 4GB, but only about 2G are available for general use. By default each thread will reserve 1MB of stack space, so the top value are 2000 threads. Naturally you can change the size of the stack and make it lower so more threads will fit in (parameter dwStackSize in CreateThread or option /STACK in the linker command). If you use a 64-bits system this limit practically dissapears.
The scheduler overhead. Once you read the thousands of threads, just scheduling them will eat nearly 100% of your CPU time, so they are mostly useless anyway. This is not a hard limit, just your program will be slower and slower the more threads you create.
*/

// Il faut également prendre en compte deux autres contraintes :

//sizeof(pthread_t) => 8 octets = 0,008ko

// 1- L'espace occupé par les threads créés dans la mémoire virtuelle d'un processus.
// Un système Linux alloue 4 Go de mémoire virtuelle par processus :
//		* Pour une architecture 32 bits : 3 Go pour l'espace utilisateur et 1 Go pour l'espace système.
//		* Pour une architecture 64 bits : 4 Go pour l'espace utilisateur (utilise d'autres adresses pour l'espace système).
// Le système Linux sur lequel sera testé le programme repose sur une architecture 64 bits.
// On a vu en cours que les threads étaient chargés dans l'espace utilisateur, et nos recherches nous ont appris que chaque thread occupé approximativement 1 MB dans l'espace utilisateur.
// On va calculer le nombre maximal de thread stockable dans le tas de l'espace utilisateur.
// La taille du tas est approximativement égal à l'espace mémoire utilisateur total moins la taille de la pile.
// On utilise la commande shell : ulimit -s pour connaître la taille de la pile par défaut des processus, on obtient : 8192ko.
// La taille du tas vaut = 4 000 - 8,192 = 3991.808 Mo

// On a donc : nombre max de thread par processus = 3 000 000 / 8192 = 366
// Si l'on souhaitait augmenter le nombre maximal de threads pour améliorer les performances du programme, il faudrait diminuer la taille de la pile.
// Il faudra néanmoins veiller à garder un certain "équilibre", que l'exécution des threads supplémentaires apporte bien un gain de temps.
// Ce n'est pas toujours le cas, utiliser trop de threads peut parfois être contre-productif, par exemple si le système a du mal à gérer l'allocation de la ressource processeur à un trop grand nombre de threads.
//#define NB_THREADS_

// (Qui sature les 1 Go de l'espace utilisateur

// Un système Linux a également une limite au nombre de threads pouvant être lancés en même temps par un même processus.



/*
J'ai trouvé la cause de cette limite, j'ai pas eut le temps d'essayer de le résoudre.

Comme tout le monde le sait, linux alloue 4Go de mémoire virutelle par processus (1Go système / 3Go utilisateur).

Il se trouve que la mémoire virtuelle utilisateur arrive à 3Go au bout des 382 threads créés. )
*/
