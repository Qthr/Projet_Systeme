#ifndef DIRECTEUR_H
#define DIRECTEUR_H
	#include "Directeur.h"
#endif

#ifndef ASSERT_H
#define ASSERT_H
	#include <assert.h>
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

int main(int argc, char** argv){

	assert(argc > 1);

	traitement_Directeur(argv[1]);

	return 0;
}
