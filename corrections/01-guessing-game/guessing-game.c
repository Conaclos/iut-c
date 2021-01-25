/*
    Copyright (c) 2020 Victorien Elvinger
    Licensed under the zlib license (https://opensource.org/licenses/zlib).
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_NB 100
#define DEBUG 0

int main() {
    int candidate;
    int nb;
    int iter = 0;

    srand(time(NULL));
    nb = rand() % (MAX_NB + 1);

    if (DEBUG) {
        printf("number to guess: %d\n", nb);
    }

    do {
        printf("Nb ? ");
        scanf("%d", &candidate);
        if (candidate > nb) {
            printf("Plus petit !\n");
        }
        else if (candidate < nb) {
            printf("Plus grand !\n");
        }
        iter++;
    } while (candidate != nb);

    if (iter > 2) {
        printf("Bravo ! Il t'a fallu tout de même %d tentatives !\n", iter);
    }
    else {
        printf("Bravo !");
    }

    return 0;
}

