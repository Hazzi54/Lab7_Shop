#include "func.h"

int main() {
    init_shop();
    pthread_t loader, client1, client2, client3;
    int prod;
    printf("Loads at a time: ");
    scanf("%d", &prod);
    /*printf("Hunger of people:");
    scanf("%d", &hunger);*/

    pthread_create(&loader, NULL, load_to_shop, (void *)&prod);
    pthread_join(loader, NULL);

    pthread_mutex_destroy(&m0);
    pthread_mutex_destroy(&m1);
    pthread_mutex_destroy(&m2);
    pthread_mutex_destroy(&m3);
    pthread_mutex_destroy(&m4);
    return 0;
}
