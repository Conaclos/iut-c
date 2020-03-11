/*
    Copyright (c) 2020 Victorien Elvinger
    Licensed under the zlib license (https://opensource.org/licenses/zlib).
*/

#include "str.h"

int streq(char *a, char *b) {
    int i = 0;
    while (a[i] != '\0' && a[i] == b[i]) {
        i++;
    }
    return a[i] == b[i];
}

void strreplace(char *s, char replaced, char replacing) {
    while (*s != '\0') {
        if (*s == replaced) {
            *s = replacing;
        }
        s++;
    }
}

