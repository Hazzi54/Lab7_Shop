#include "func.h"

pthread_mutex_t mut[N] = PTHREAD_MUTEX_INITIALIZER;

void init_shop() {
    int num, i;
    printf("Enter product number: ");
    scanf("%d", &num);
    for(i = 0; i < N; i++)
        shop[i] = num;
}

void *load_to_shop(void *prod) {
    int *ptr = (int *)prod, i = 0;
    while(1) {
        i = rand() % 5;
        pthread_mutex_lock(&mut[i]);
        shop[i] += *ptr;
        printf("Loaded at %d shop. Products - %d\n", i+1, shop[i]);
        pthread_mutex_unlock(&mut[i]);
        sleep(2);
    }   
}

void *buying(void *h) {
    int *hunger = (int *)h, i = 0;
    while(1) {
        i = rand() % 5;
        pthread_mutex_lock(&mut[i]);
        if(shop[i] < *hunger) {
            *hunger -= shop[i];
            shop[i] = 0;
        }
        else {
            shop[i] -= *hunger;
            *hunger = 0;
        }
        printf("Buying at %d shop. Products - %d, hunger - %d\n", i+1, shop[i], *hunger);
        pthread_mutex_unlock(&mut[i]);
        sleep(1);
        if(*hunger <= 0)
            break;
    }
}
