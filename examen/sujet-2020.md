

## QCM

### A quoi correspond &v ?

- [ ] La valeur de la varaible v
- [ ] La valeur pointé par le pointeur v
- [ ] L'adresse de la varaible v


### Quelle déclaration alloue un tableau de 10 entiers sur la pile (plusieurs réponses à cocher) ?

- [ ] `int *tab = malloc(5 * sizeof(int));`
- [ ] `int tab[] = { 0, 0, 0, 0, 0 };`
- [ ] `int *tab[5];`
- [ ] `int tab[5];`


### En général, combien d'octet(s) occupe un pointeur sur une architecture 64bits ?

- [ ] 1 octet
- [ ] 2 octets
- [ ] 4 octets
- [ ] 8 octets


### Dans quel ordre se déroule une compilation ?

- [ ] Compilateur -> Linker -> Préprocesseur
- [ ] Linker -> Préprocesseur -> Compilateur
- [ ] Préprocesseur -> Compilateur -> Linker
- [ ] Préprocesseur -> Linker -> Compilateur


### Complétez les trous avec "la pile" ou "le tas" :

- ______________ est adapté(e) pour allouer des petits volumes de données
- L'allocation sur ______________ est plus lente que sur ______________
- Pour éviter des fuites mémoires, les espaces mémoires alloués sur ______________ doivent être libérés par un appel explicite à la fonction `free`
- Quand l'allocation est effectuée sur ______________ nous parlons d'allocation dynamique


### Quel est l'utilité de la compilation séparée (plusieurs réponses à cocher) ?

- [ ] d'avoir un programme qui s'exécute plus rapidement
- [ ] d'éviter les dépassements de tampons
- [ ] d’éviter de recompiler l'ensemble du projet à chaque modification
- [ ] de réutiliser du code dans d'autres projets


## L’exécution du programme suivant peut conduire à des comportements indéfinis. Pourquoi ?

```c
#include <stdio.h>

int main() {
    char welcoming[5] = "Hello";
    char name[50] = "Bea";
    printf("%s %s", welcoming, name);
}
```


## Manipulation de chaîne de caractères

La fonction `split` permet de récupérer le premier mot d'une chaîne de caractères.

- Elle prend en entrée une chaîne de caractères qui contient un ou plusieurs mots toujours séparés par un seul espace
- Elle remplace la première occurrence d'un espace (si existant) avec le caractère NUL ('\0')
- Elle renvoie le pointeur sur la suite de la chaîne ou NULL si la chaîne ne contient pas d'autres mots

Le programme suivant teste le bon fonctionnement de la fonction:

```c
#include <stdio.h>

char * split(char *s);

int main() {
    char s[] = "one two three";
    char *s2 = split(s);
    printf("%s\n", s); /* "one" */
    printf("%s\n", s2); /* "two three" */
    return 0;
}
```

Écrire cette fonction.


## Copie de châine de caractères

Écrire la fonction `str_alloc_copy` qui renvoie un pointeur vers une copie de la chaîne de caractère passée en entrée.

La signature de la fonction est la suivante : `char * str_alloc_copy(char *s);`

_Indication :_ vous pourrez vous aider de la fonction `strlen` présente dans la bibliothèque `string.h`.



## Pointeurs et allocation dynamique

Le programme suivant a été écrit par un programmeur qui ne connaît ni les pointeurs, ni l'allocation dynamique.
Réécrivez ce programme pour qu'il alloue moins de données sur la pile.

_Indication :_ Le type des paramètres des fonctions, et leur implémentation peut être changée.

```c
#include <string.h>
#define MAX_NAME_LEN 50

typedef struct {
    char name[MAX_NAME_LEN];
    int subscriber_count;
} Youtuber;

Youtuber new_youtuber(char name[], int sc) {
    Youtuber res;
    strcpy(res.name, name);
    res.subscriber_count = sc;
    return res;
}

int main() {
    Youtuber y1 = new_youtuber("MrMeeea", 134000);
    Youtuber y2 = new_youtuber("Ginger Force", 48300);
    return 0;
}
```


## Make

Une amie a développé un petit programme qui imprime sur le terminal des personnages animés en ASCII art. Son projet est composé des fichiers suivants :
```
$ ls
color.c color.h pattern.c pattern.h main.c perso.c perso.h
```

Chaque fichier d'extension `c` inclut le fichier d'extension `h` de même nom.
De plus :
- `perso.c` inclut `color.h` et `pattern.h`
- `main.c` inclut `perso.h`

Elle trouve particulièrement pénible de compiler son projet et a appris que vous veniez d'appendre à utiliser cet outil génial qui est `make`. En tenant compte des dépendances entre les fichiers, écrivez un `Makefile` pour
automatiser la compilation du projet de votre amie.


