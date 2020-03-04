#include "func.h"

int main() {
    srand(time(NULL));
    init_shop();
    pthread_t loader, client1, client2, client3;
    int prod, h1, h2, h3;
    printf("Loads at a time: ");
    scanf("%d", &prod);
    printf("Hunger of people: ");
    scanf("%d", &h1);
    h2 = h1;
    h3 = h1;

    pthread_create(&loader, NULL, load_to_shop, (void *)&prod);
    pthread_create(&client1, NULL, buying, (void *)&h1);
    pthread_create(&client2, NULL, buying, (void *)&h2);
    pthread_create(&client3, NULL, buying, (void *)&h3);

    pthread_join(client1, NULL);
    pthread_join(client2, NULL);
    pthread_join(client3, NULL);

    pthread_cancel(loader);

    //destruct();
    return 0;
}
