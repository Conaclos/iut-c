/*
    Copyright (c) 2020 Victorien Elvinger
    Licensed under the zlib license (https://opensource.org/licenses/zlib).

    Explciit pointer version.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "fighter-bet-pointers.h"
#include "random_name.h"

/**
 * Bet on a fighter and let's see if you win!
 */
int main() {
    Fighter f0;
    Fighter f1;
    char bet[MAX_NAME_LEN];
    Fighter *winner;

    srand(time(NULL));

    f0 = random_fighter();
    f1 = random_fighter();

    display(&f0);
    display(&f1);

    printf("Sur quel·le combattant·e pariez-vous ? ");
    scanf("%s", bet);
    if (strcmp(f0.name, bet) != 0 &&
            strcmp(f1.name, bet) != 0) {
        printf("Ce·tte combattant·e n'existe pas !\n");
        return 1;
    }

    printf("\n");
    winner = fight(&f0, &f1);
    printf("\n");

    if(strcmp((*winner).name, bet) == 0) {
        printf("Good bet!\n");
    }
    else {
        printf("Bad bet!\n");
    }

    return 0;
}

