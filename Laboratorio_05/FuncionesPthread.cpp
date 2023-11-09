#include <pthread.h>

int pthread_create(pthread_t *hilo, const pthread_attr_t *atributo, void *(*inicio_rutina) (void *), void *argumento);


int pthread_join(pthread_t hilo, void **valor_retorno);


int pthread_detach(pthread_t hilo);


void pthread_exit(void *valor_retorno);

pthread_t pthread_self();

int pthread_kill(pthread_t hilo, int señal);
