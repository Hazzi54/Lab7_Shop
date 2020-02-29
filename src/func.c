#include "func.h"

void init_shop() {
    int num, i;
    printf("Input product number: ");
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
    int *ptr = (int *)prod, i;
    for(i = 0; i < N; i++) {
        switch(i) {
            case 0: {
                pthread_mutex_lock(&m0);
                shop[i] += *ptr;
                printf("%d ", shop[i]);
                pthread_mutex_unlock(&m0);
                break;
            }
            case 1: {
                pthread_mutex_lock(&m1);
                shop[i] += *ptr;
                printf("%d ", shop[i]);
                pthread_mutex_unlock(&m1);
                break;
            }
            case 2: {
                pthread_mutex_lock(&m2);
                shop[i] += *ptr;
                printf("%d ", shop[i]);
                pthread_mutex_unlock(&m2);
                break;
            }
            case 3: {
                pthread_mutex_lock(&m3);
                shop[i] += *ptr;
                printf("%d ", shop[i]);
                pthread_mutex_unlock(&m3);
                break;
            }
            case 4: {
                pthread_mutex_lock(&m4);
                shop[i] += *ptr;
                printf("%d\n", shop[i]);
                i = -1;
                pthread_mutex_unlock(&m4);
                break;
            }
        }
        if(shop[i] >= 1000)
            break;
    }   
}
