#ifndef _FUNC
#define _FUNC

#include <stdio.h>
#include <pthread.h>

#define N 5

int shop[N];

pthread_mutex_t m0, m1, m2, m3, m4;

void init_shop();
void *load_to_shop(void *prod);

#endif
