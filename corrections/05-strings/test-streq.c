/*
    Copyright (c) 2020 Victorien Elvinger
    Licensed under the zlib license (https://opensource.org/licenses/zlib).
*/

#include <assert.h>
#include "str.h"

int main() {
    assert(streq("Chuck Norris", "Chuck Norris"));
    assert(streq("", ""));

    assert(! streq("Chuck", "Chuck Norris"));
    assert(! streq("Chuck Norris", "Chuck"));
    return 0;
}

