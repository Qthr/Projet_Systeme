#include "Message.h"


Message initialize_Message(SousChaines sc, int num){
	Message msg;
	msg.numero = num;														// Donne le numéro entré en paramètre à la structure Message.
	msg.sens = (sc.tab[2][0] == 'c') ? CHIFFRAGE : DECHIFFRAGE;				// Ajoute le sens de traitement du message dans la structure Message.
	msg.clef = atoi(sc.tab[1]);												// Convertit une sous chaine en nombre pour donner une clef à la structure Message.
																			// => Allocations mémoires statiques dans la pile.
	msg.chemin = malloc((strlen(sc.tab[0])+1) * sizeof(char));				// Alloue un espace mémoire correspondant à celui de la chaine de caractère contenant le message + 1 pour \0 (réduit l'espace occupé par le message a son strict minimum))
	strcpy(msg.chemin, sc.tab[0]);											// On copie la chaine de caractère contenant le chemin dans l'attribut chemin de la structure Message.
																			// => Allocation d'une mémoire dynamique dans le tas : la fonction finalize_Message permettra de la désallouer.
	finalize_SousChaines(sc);												// On désalloue la mémoire de la structure SousChaines copiée.

	return msg;
}


void finalize_Message(Message msg){
	free(msg.chemin);
}


void affiche_Message(Message msg){
		printf("\n");
		printf("Message n°%d \n", msg.numero);
		printf("Chemin du fichier : %s \n", msg.chemin);
		printf("Clef : %d \n", msg.clef);
		(msg.sens == CHIFFRAGE) ? printf("Sens : Chiffrage\n") : printf("Sens : Déchiffrage\n");

}
