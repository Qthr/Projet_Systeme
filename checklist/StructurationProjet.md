# Projet Cesar

## Fichiers sources

+ **Main/Directeur/Principal** : 
+ **ChefEquipe/Message** : 
+ **Employe/Mot** : 
+ **Cesar** : 
+ **Chargement** : 
+ **Sauvegarde/Ecriture** : 

+ **...** : 


## Structures de données

+ **Message** :
	+ numero
	+ chemin
	+ cle
	+ sens (cryptage/decryptage)
	+ tube (pour les messages passant de crypter à décrypter : processus fils les passe au processus père via le tube qui les affiche sur la sortie standard)

+ **Mot** :
	+ données pour gérer le remplissage du buffer (mutex, condition, buffer)
	+ mot à traiter (vide)
	+ sens (Cryptage/Decryptage)


## Instructions des fichiers sources

### Main/Directeur/Principal

*Le processus qui exécute les instructions suivantes est le processus Directeur*

#### main()

+ Charge les données du fichier principal : n lignes (n : nombre de chemins vers les fichiers messages contenus dans le fichier principal)
+ Initialise n structures message avec :
	+ Les informations contenues dans les lignes (numero, chemin, cle, sens).
	+ Création d'un tube (Les futurs processus utiliseront ce tube pour écrire les messages **déchiffrés**, et le processus directeur lira, au retour, ce tube pour les afficher sur la sortie standard)
+ Crée n processus. Ces processus sont les **chefs d'équipes**.
+ Chaque processus appelle une fonction traitement_chefEquipe() en envoyant une structure message (numero, chemin, cle, sens, tube).
+ Attendre la terminaison des n processus créés
+ Si le code de retour d'un processus vaut 1, il s'agira d'un processus **déchiffreur**, les processus déchiffreur auront écrit le message déchiffré dans le tube.
+ Si le code de retour d'un processus vaut 0, il s'agira d'un processus **chiffreur**, les processus chiffreur auront écrit le message chiffré dans un nouveau fichier créé.
+ On comptera le nombre de processus avec code retour à 1 et on affichera : "X messages déchiffrés : " + contenu du tube.
+ On comptera le nombre de processus avec code retour à 0 et on affichera : "X messages chiffrés".
+ Si la valeur de retour diffère de 0 ou 1 -> gérer l'erreur.

Problème : Ordre des messages déchiffrés dans le tube (aléatoire car un processus créé avant un autre peut se terminer après lui).

### ChefEquipe/Message

*Les processus qui exécutent les instructions suivantes sont les processus chefs d'équipe*

#### traitement_chefEquipe()

+ Charge le fichier message : lecture des mots du message.
+ Initialise structures mot avec :
	+ données pour gérer le remplissage du buffer (mutex, condition, buffer)
	+ mot à traiter
	+ sens (Cryptage/Decryptage)
+ Créer pour chaque mot lu, un thread en lui envoyant une structure mot avec la fonction traitementEmploye()
+ Vider buffer dans :
	+ fichier externe : nomFichier_cypher pour les messages venant d'être chiffré.
	+ tube : pour les messages venant d'être déchiffré

Problème : Comment remplir le buffer avec mot dans l'ordre (cond+mutex).

### Employe/Mot 

*Les threads qui exécutent les instructions suivantes sont les threads employés*

#### traitement_employe()

+ Convertir mot avec Cesar
+ Ajouter mot au buffer / Gestion mutex condition

Problème : Comment remplir le buffer avec mot dans l'ordre (cond+mutex).


### Cesar

+ Traitement
+ Crypte
+ Decrypte


### Chargement/Lecture 

+ Permet au processus directeur de charger les données du fichier principal
+ Permet aux processus chef d'équipe de charger les mots

### Sauvegarde/Ecriture 

+ ...





