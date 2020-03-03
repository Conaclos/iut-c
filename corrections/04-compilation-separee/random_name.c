/*
    Copyright (c) 2020 Victorien Elvinger
    Licensed under the zlib license (https://opensource.org/licenses/zlib).

    Explciit pointer version.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "random_name.h"


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

