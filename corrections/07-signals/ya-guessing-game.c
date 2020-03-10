/*
    Copyright (c) 2020 Victorien Elvinger
    Licensed under the zlib license (https://opensource.org/licenses/zlib).
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <signal.h>
#include <unistd.h>

#define MAX_NB 100
#define DEBUG 0
#define MAX_TIME 8

void quit_game() {
    printf("\n\x1b[1;31mLâche !\x1b[0m\n");
    exit(1);
}

void stop_game() {
    printf("\n\x1b[1;31mPerdu !\x1b[0m\n");
    exit(1);
}

int main() {
    int candidate;
    int nb;
    int iter = 0;

    signal(SIGINT, &quit_game);
    signal(SIGALRM, &stop_game);
    alarm(MAX_TIME);

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
        printf("Bravo ! Il t'as fallu tout de même %d tentatives !\n", iter);
    }
    else {
        printf("Bravo !");
    }

    return 0;
}

