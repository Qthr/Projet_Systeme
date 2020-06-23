//©C.Briand 2017
#include <fcntl.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>

int nbthread;
typedef struct{
  int msg;
  int vide;
  pthread_mutex_t mutex;
  pthread_cond_t cond;
}mailbox;

typedef struct {
  mailbox *a;
  mailbox *b;
  int v;
} lol;

void mbox_init(mailbox *mb){
mb->vide = TRUE;
  pthread_mutex_init = (&(mb->mutex), NULL);
  pthread_cond_init = (&(mb->cond), NULL);

}

void mbox_write(mailbox *mb, int i){
  pthread_mutex_lock(&(mb->mutex));
  while(!mb->vide){
    pthread_cond_wait(&(mb->cond), &(mb->mutex));
    pthread_cond_signal(&(mb->cond));
  }

  mb->msg = i;
  mb -> vide = FALSE;
  pthread_mutex_unlock(&(mb->mutex));
}

int mbox_read(mailbox * mb){
  pthread_mutex_lock(&(mb->mutex));
  int val;
  while(mb->vide){
    pthread_cond_wait(&(mb->cond), &(mb->mutex));
    //signal reveille le suivant de la liste
    pthread_cond_signal(&(mb->cond));
  }
  val = mb->msg;
  mb->vide = TRUE;
  pthread_mutex_unlock(&(mb->mutex));
  return val;
}
void * f(void * a){
  lol * z = (lol *) a;
  while(z->v){
    mbox_write(z->b, mbox_read(z->a) + 1);
    --z->v;
  }

}

void omega (lol * z){
  int i;
  for(i=0; i< z->v; i++){
    mbox_write(z->b, i);
  }

  while(z->v){
    printf("%d \n" mboxread(z->a));
    --z->v;
  }
}
int main(int argc, char** argv)
{
  int n = atoi(argv[1]), i;
  int m = atoi(argv[2]);
  lol *tab = malloc(n* sizeof(lol));
  pthread_t *tid = malloc((n - 1) * sizeof(pthread_t));
  int i;
  mailbox *a = malloc(sizof(mailbox) * (n+1));

  for(i=0; i < n+1; i++){
    mbox_init(a+i);
  }
  for (i=0; u<n+1; ++i){
    tab[i].a = i;
    tab[i].b = (i+1)%(n+1);
    tab[i].v = m;
  }

  for(i=0; i< n+1; ++i){
    pthread_create = (tid+i, NULL, &f, tab +i);
  }
  omega = (tab + n);
  for(i=0; u<n; i++){
    pthread_join(tid[i], NULL);
  }
  free(a);
  free(tid);
  free(tab);
  return 0;
}
