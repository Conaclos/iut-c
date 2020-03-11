
Le but de cet exercice est d''écrire une petit bibliothèque pour manipuler des
chaînes de caractères qui suivent la convention de C (elles se terminent par le
craictère NUL `\0').

Vous n'utiliserez pas les fonctions de la bibliothèque `string.h`.

**1.** Écrire une fonction `streq` qui teste l'égalité de deux chaînes de
caractères.

La signature de la fonction est `int streq(char *a, char* b)`.

Le code suivant permet de tester votre fonction :

```c
#include <assert.h>

/* Votre bibliothéqiue : */
#include "str.h"

int main() {
    assert(streq("Chuck Norris", "Chuck Norris"));
    assert(streq("", ""));

    assert(! streq("Chuck", "Chuck Norris"));
    assert(! streq("Chuck Norris", "Chuck"));
    return 0;
}
```

**2.** Écrire une fonction `strreplace` qui replace toutes les occurrences d'un
caractère par un autre.

La signature de la fonction est
`void strreplace(char *s, char replaced, char replacing)`.

Le code suivant permet de tester votre fonction :

```c
#include <assert.h>

/* Votre bibliothéqiue : */
#include "str.h"

int main() {
    char a[] = "Hellx Wxrld";

    strreplace(a, 'x', 'o');
    assert(streq(a, "Hello World"));
    return 0;
}
```

Pour corser l'exercice vous pouvez vous imposer d'utiliser l'arithmétique des
pointeurs pour parcourir la châine de caractère.

