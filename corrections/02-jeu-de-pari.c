/*
    Copyright (c) 2020 Victorien Elvinger
    Licensed under the zlib license (https://opensource.org/licenses/zlib).

    No pointer version (except arrays).
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


#define MIN_NAME_LEN 3
#define MAX_NAME_LEN 6

#define MIN_PV 4
#define MAX_PV 6

#define MIN_ESQUIVE 40
#define MAX_ESQUIVE 60


typedef struct {
    char name[MAX_NAME_LEN];
    int pv;
    int esquive; /* percentage between 0 and 100 */
} Fighter;


/**
 * f0 and f1 fight until one of them is KO (pv == 0).
 *
 * @param f0
 * @param f1
 * @retuen winning fighter.
 */
Fighter fight(Fighter f0, Fighter f1);

/**
 * Generate a random name which can be spelled.
 *
 * @param res where t ostore the generated name.
 * @param len name's length.
 */
void random_name(char res[], int len);

/**
 * @return randomly generated fighter.
 */
Fighter random_fighter();

/**
 * @param f fighter to print on stdout.
 */
void display_fighter(Fighter f);


/**
 * Bet on a fighter and let's see if you win!
 */
int main() {
    Fighter f0;
    Fighter f1;
    char chosen_competitor[MAX_NAME_LEN];
    Fighter winner;

    srand((unsigned int) time(NULL)); /* safe cast */

    f0 = random_fighter();
    f1 = random_fighter();

    display_fighter(f0);
    display_fighter(f1);

    printf("Sur quel·le combattant·e pariez-vous ? ");
    scanf("%s", chosen_competitor);
    if (strcmp(f0.name, chosen_competitor) != 0 &&
            strcmp(f1.name, chosen_competitor) != 0) {
        printf("Ce·tte combattant·e n'existe pas !\n");
        return 1;
    }

    winner = fight(f0, f1);
    if(strcmp(winner.name, chosen_competitor) == 0) {
        printf("Good bet!\n");
    }
    else {
        printf("Bad bet!\n");
    }

    return 0;
}

Fighter fight(Fighter f0, Fighter f1) {
    int f_number = rand() % 2;
    int attack;
    while (f0.pv != 0 && f1.pv != 0) {
        attack = rand() % 101;
        if (f_number == 0) {
            if (attack > f1.esquive) {
                f1.pv = f1.pv - 1;
                printf("%s hit\n", f1.name);
            }
        }
        else {
            if (attack > f0.esquive) {
                f0.pv = f0.pv - 1;
                printf("%s hit\n", f0.name);
            }
        }
        f_number = (f_number + 1) % 2;
    }
    if (f0.pv !=0) {
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

const char consonants[] = "bcdfghjklmnpqrstvwxz";
const char vowels[] = "aeiouy";

void random_name(char res[], int len) {
    int i;
    int r;

    for (i = 0; i < len; i++) {
        if (i % 2 == 0) {
            r = rand() % (sizeof(consonants) - 1);
            res[i] = consonants[r];
        }
        else {
            r = rand() % (sizeof(vowels) - 1);
            res[i] = vowels[r];
        }
    }
    res[len] = '\0';
}

Fighter random_fighter() {
    Fighter res;
    res.pv = random_btw(MIN_PV, MAX_PV);
    res.esquive = random_btw(MIN_ESQUIVE, MAX_ESQUIVE);
    random_name(res.name, random_btw(MIN_NAME_LEN, MAX_NAME_LEN - 1));
    return res;
}

void display_fighter(Fighter f) {
    printf("%s(pv: %d, esquive: %d%%\n", f.name, f.pv, f.esquive);
}
