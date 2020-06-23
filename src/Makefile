CC= gcc
CFLAGS = -Wall
LDFLAGS = -lm -pthread
EXEC = cesar

all : $(EXEC)

run : $(EXEC)
	./$(EXEC) ${ARGS}

cesar: main.o Buffer.o Cesar.o Chaine.o ChefEquipe.o Constantes.h Employe.o Directeur.o Fichier.o  Message.o Mot.o
	$(CC) -o $@ $^ $(LDFLAGS)

main.o: Buffer.h Cesar.h Chaine.h ChefEquipe.h Constantes.h Employe.h Directeur.h Fichier.h  Message.h Fichier.h Mot.h

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

gitclean :
	git rm *.o
	git rm cesar

clean:
	rm -rf *.o
	rm -rf cesar
