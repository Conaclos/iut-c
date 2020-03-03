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

void try_hit(Fighter *f) {
    const int attack = rand() % 101;
    if (attack > (*f).esquive) {
        (*f).pv--;
        printf("%s hit\n", (*f).name);
    }
}

Fighter * fight(Fighter *f0, Fighter *f1) {
    int f_number = rand() % 2;
    while ((*f0).pv != 0 && (*f1).pv != 0) {
        if (f_number == 0) {
            try_hit(f1);
        }
        else {
            try_hit(f0);
        }
        f_number = (f_number + 1) % 2;
    }
    if ((*f0).pv !=0) {
        return f0;
    }
    else {
        return f1;
    }
}

/**
 * @param min
 * @param max
 * @return random int between min and max.
 */
int random_btw(int min, int max) {
    int res = rand() % (max + 1 - min);
    res = res + min;
    return res;
}

Fighter random_fighter() {
    Fighter res;
    res.pv = random_btw(MIN_PV, MAX_PV);
    res.esquive = random_btw(MIN_ESQUIVE, MAX_ESQUIVE);
    random_name(res.name, random_btw(MIN_NAME_LEN, MAX_NAME_LEN - 1));
    return res;
}

void display(Fighter *f) {
    printf("%s(pv: %d, esquive: %d%%\n", (*f).name, (*f).pv, (*f).esquive);
}

