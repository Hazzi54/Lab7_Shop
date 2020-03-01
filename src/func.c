#include "func.h"

void init_shop() {
    int num, i;
    printf("Enter product number: ");
    scanf("%d", &num);
    for(i = 0; i < N; i++)
        shop[i] = num;
    
    pthread_mutex_init(&m0, NULL);
    pthread_mutex_init(&m1, NULL);
    pthread_mutex_init(&m2, NULL);
    pthread_mutex_init(&m3, NULL);
    pthread_mutex_init(&m4, NULL);
}

void *load_to_shop(void *prod) {
    int *ptr = (int *)prod, i = 0;
    while(1) {
        i = rand() % 5;
        switch(i) {
            case 0: {
                pthread_mutex_lock(&m0);
                shop[i] += *ptr;
                printf("Loaded at %d shop. Products - %d\n", i+1, shop[i]);
                pthread_mutex_unlock(&m0);
                sleep(2);
                break;
            }
            case 1: {
                pthread_mutex_lock(&m1);
                shop[i] += *ptr;
                printf("Loaded at %d shop. Products - %d\n", i+1, shop[i]);
                pthread_mutex_unlock(&m1);
                sleep(2);
                break;
            }
            case 2: {
                pthread_mutex_lock(&m2);
                shop[i] += *ptr;
                printf("Loaded at %d shop. Products - %d\n", i+1, shop[i]);
                pthread_mutex_unlock(&m2);
                sleep(2);
                break;
            }
            case 3: {
                pthread_mutex_lock(&m3);
                shop[i] += *ptr;
                printf("Loaded at %d shop. Products - %d\n", i+1, shop[i]);
                pthread_mutex_unlock(&m3);
                sleep(2);
                break;
            }
            case 4: {
                pthread_mutex_lock(&m4);
                shop[i] += *ptr;
                printf("Loaded at %d shop. Products - %d\n", i+1, shop[i]);
                i = -1;
                pthread_mutex_unlock(&m4);
                sleep(2);
                break;
            }
        }
    }   
}

void *buying(void *h) {
    int *hunger = (int *)h, i = 0;
    while(1) {
        i = rand() % 5;
        switch(i) {
            case 0: {
                pthread_mutex_lock(&m0);
                if(shop[i] < *hunger) {
                    *hunger -= shop[i];
                    shop[i] = 0;
                }
                else {
                    shop[i] -= *hunger;
                    *hunger = 0;
                }
                printf("Buying at %d shop. Products - %d, hunger - %d\n", i+1, shop[i], *hunger);
                pthread_mutex_unlock(&m0);
                sleep(1);
                break;
            }
            case 1: {
                pthread_mutex_lock(&m1);
                if(shop[i] < *hunger) {
                    *hunger -= shop[i];
                    shop[i] = 0;
                }
                else {
                    shop[i] -= *hunger;
                    *hunger = 0;
                }
                printf("Buying at %d shop. Products - %d, hunger - %d\n", i+1, shop[i], *hunger);
                pthread_mutex_unlock(&m1);
                sleep(1);
                break;
            }
            case 2: {
                pthread_mutex_lock(&m2);
                if(shop[i] < *hunger) {
                    *hunger -= shop[i];
                    shop[i] = 0;
                }
                else {
                    shop[i] -= *hunger;
                    *hunger = 0;
                }
                printf("Buying at %d shop. Products - %d, hunger - %d\n", i+1, shop[i], *hunger);
                pthread_mutex_unlock(&m2);
                sleep(1);
                break;
            }
            case 3: {
                pthread_mutex_lock(&m3);
                if(shop[i] < *hunger) {
                    *hunger -= shop[i];
                    shop[i] = 0;
                }
                else {
                    shop[i] -= *hunger;
                    *hunger = 0;
                }
                printf("Buying at %d shop. Products - %d, hunger - %d\n", i+1, shop[i], *hunger);
                pthread_mutex_unlock(&m3);
                sleep(1);
                break;
            }
            case 4: {
                pthread_mutex_lock(&m4);
                if(shop[i] < *hunger) {
                    *hunger -= shop[i];
                    shop[i] = 0;
                }
                else {
                    shop[i] -= *hunger;
                    *hunger = 0;
                }
                printf("Buying at %d shop. Products - %d, hunger - %d\n", i+1, shop[i], *hunger);
                pthread_mutex_unlock(&m4);
                sleep(1);
                break;
            }
        }
        if(*hunger <= 0)
            break;
    }
}

void destruct() {
    pthread_mutex_destroy(&m0);
    pthread_mutex_destroy(&m1);
    pthread_mutex_destroy(&m2);
    pthread_mutex_destroy(&m3);
    pthread_mutex_destroy(&m4);
}
