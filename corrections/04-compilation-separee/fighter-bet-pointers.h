/*
    Copyright (c) 2020 Victorien Elvinger
    Licensed under the zlib license (https://opensource.org/licenses/zlib).

    Explciit pointer version.
*/


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
 * Try to hit f.
 * If f is hit, then s·he lost 1 pv.
 * @param f
 */
void try_hit(Fighter *f);

/**
 * f0 and f1 fight until one of them is KO (pv == 0).
 *
 * @param f0
 * @param f1
 * @retuen winning fighter.
 */
Fighter *fight(Fighter *f0, Fighter *f1);

/**
 * @return randomly generated fighter.
 */
Fighter random_fighter();

/**
 * @param f fighter to print on stdout.
 */
void display(Fighter *f);

