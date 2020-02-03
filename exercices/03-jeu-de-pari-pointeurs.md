Cet exercice consiste à adapter le [jeu de pari](02-jeu-de-pari.md) avec des
pointeurs.
dans le cadre de cet exercice, les pointeurs nous permettrons de réduire la
consommation de mémoire et de modifier des valeurs.

**1.** Modifier la procédure `display_fighter` pour qu'elle accepte un pointeur
en paramètre.
La nouvelle signature de la procédure est :

```c
void display_fighter(Fighter *f);
```

**2.** Écrire la procédure `try_hit` qui prend en paramètre un pointeur de type
`Fighter`.
La signature de la procédure est :

```c
void try_hit(Fighter *f);
```

Cette procédure tente d'infliger un coup au combattant qui est passé en
paramètre.
Un coup est accompagné d'une rapidité d'attaque exprimée en pourcentage.
Si ce pourcentage dépasse l'esquive du combattant, alors le coup est réussi : il
perds un point de vie.

**3.** Adapter la fonction `fight` pour appeler `try_hit`.

**4.** Modifier la fonction `fight` pour qu'elle accepte deux pointeurs en
paramètre.

**5.** La fonction `fight` peut-elle être modifiée de telle manière à retourner
un pointeur ?
Si oui, modifier la fonction en conséquence.

**5.** La fonction `random_fighter` peut-elle être modifiée de telle manière à
retourner un pointeur ?
Si oui, modifier la fonction en conséquence.

