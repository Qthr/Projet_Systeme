#include <stdlib.h>
#include <stdio.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#include "Fichier.h"


Fichier* ouvrirFichier(const char* chemin, const char* mode){

  Fichier* f = malloc(sizeof(Fichier));
  mode_t n;

  if(mode[0] == 'r'){
    n = O_RDONLY;
    if(strlen(mode) > 1)
      n = O_RDWR;
  }
  else if(mode[0] == 'w')
    n = O_WRONLY | O_CREAT;
  else if(mode[0] == 'a')
    n = O_WRONLY | O_CREAT | O_APPEND;

  f->fd = open(chemin, n, 00600);

  if(f->fd >= 0)
    return f;
  else{
    free(f);
    return NULL;
  }
}



int fermerFichier(Fichier* f){
  if(f!=NULL)
    if(close(f->fd) == 0){
      free(f);
      return 0;
    }
  return -1;
}


char getChar(Fichier* f){
  if(f != NULL){
    char c;
    if(read(f->fd, &c, 1) > 0)
      return c;
  }
  return EOF;
}


int getWord(Fichier* f, char *buf, int size){
  if(f == NULL) return -1;
  if (size == 0) return 0;

  int count;
  for (count = 0; count < size - 1; count++)
  {
    char c = getChar(f);
    if (c == ' ')  break;
    if(c == '\n'){
      buf[count] = c;
      count++;
      break;
    }
    if (c == EOF) {
        if (count == 0) return -1;
        break;
    }
    buf[count] = c;
  }
  buf[count] = '\0';
  return count;
}



int getLine(Fichier* f, char *buf, int size)
{
  if(f == NULL) return -1;
  if (size == 0) return 0;

  int count;
  for (count = 0; count < size - 1; count++)
  {
    char c = getChar(f);
    if (c == '\n')  break;
    if (c == EOF) {
        if (count == 0) return -1;
        break;
    }
    buf[count] = c;
  }
  buf[count] = '\0';
  return count;
}


int putChar(Fichier* f, char c){
  if(f != NULL){
    if(write(f->fd, &c, 1) > 0)
      return 0;
  }
  return -1;
}


int putString(Fichier* f, char *c){
  int err = 0, i=0;
  while(c[i] != '\0'){
    if(write(f->fd, &c, 1) > 0)
      err = -1;
      i++;
  }
  if(err == -1)
    printf("~!~ erreur dans l'ecriture");
  return err;
}
