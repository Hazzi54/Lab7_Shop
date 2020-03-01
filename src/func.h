#ifndef _FUNC
#define _FUNC

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <unistd.h>

#define N 5

int shop[N];

pthread_mutex_t m0, m1, m2, m3, m4;

void init_shop();
void *load_to_shop(void *);
void *buying(void *);
void destruct();

#endif
