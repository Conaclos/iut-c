/*
    Copyright (c) 2020 Victorien Elvinger
    Licensed under the zlib license (https://opensource.org/licenses/zlib).
*/

#include <assert.h>
#include "str.h"

int main() {
    char a[] = "Hellx Wxrld";

    strreplace(a, 'x', 'o');
    assert(streq(a, "Hello World"));
    return 0;
}

