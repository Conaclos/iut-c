Le but de cet exercice est de programmer un jeu de pari sur des combats.
Le jeu génère aléatoirement deux combattant·e·s. Le joueur pari sur l'un d'eux.
Si le joueur a parié sur le vainqueur, il remporte la partie.
Pour simplifier la programmation de ce jeu, nous allons procéder en plusieurs
étapes.

## Générateur de noms

Le nom d'un·e combattant·e est généré aléatoirement à l'aide de la procédure
`random_name`.

**1.** Écrire la procédure `random_name` dont la signature est la suivante :

```c
void random_name(char res[], int len);
```

Nous supposons qu'un nom est composé de lettres en minuscule de l'alphabet
latin.
Pour avoir un nom qui puisse être épelé, les consonnes et les voyelles sont
alternées.
Des appels successifs à `random_name(name, 4)` peut ainsi générer des noms tel que `pory` ou `lila`.

## Générateur de combattant·e·s

Un·e combattant·e est caractérisé·e par un nom, des points de vie et une
probabilité d'esquive.

**2.** Écrire le type composite `Fighter` correspondant.
Le nom est une chaîne de caractères.
Les points de vie sont représentés par un entier.
La probabilité d'esquive est exprimée en pourcentage par un entier compris
entre 0 et 100.

**3.** Écrire la fonction `random_fighter` qui génère un·e combattant·e de
manière aléatoire. Cette fonction a la signature suivante :

```c
Fighter random_fighter();
```

Le nom du combattant est généré à l'aide de la procédure `random_name`.
Pour ne pas avoir de grandes différences de niveau entre nos combattant·e·s :

- Le nombre de points de vie généré est compris entre 4 et 6
- L'esquive générée est comprise entre 40 et 60

Ces valeurs devraient être facilement modifiables. Vous pouvez bien sûr en
choisir d'autres.

**4.** Écrire la procédure `display_fighter` qui affiche sur la sortie standard
en une ligne les caractéristiques d'un combattant. Exemple de sortie :

```
pory(pv: 4, esquive: 52%)
```

## Combat

Un combat permet à deux combattant·e·s de s'affronter en tour par tour.
Celui/celle qui donne le premier coup est choisi·e aléatoirement.
Les coups sont ensuite donnés à tour de rôle.
Un coup est accompagné d'une rapidité d'attaque exprimée en pourcentage.
Si ce pourcentage dépasse l'esquive de l'adversaire, alors le coup est réussi :
l’adversaire perd un point de vie.
Le combat se termine une fois que l'un·e des combattant·e·s est
KO (0 point de vie).
Par exemple si nous considérons les combattante·e·s suivants :

```
pory(pv: 2, esquive: 52%)
lila(pv: 2, esquive: 48%)
```

Nous pouvons obtenir le combat suivant :

```
lila débute le combat.
lila donne un coup avec une rapidité d'attaque de 57%.
pory n'arrive pas à esquiver le coup (57% > 52%). pory perd 1 pv.
pory donne un coup avec une rapidité d'attaque de 45%.
lila esquive le coup (45% < 48%). lila ne perd pas de pv.
lila donne un coup avec une rapidité d'attaque de 54%.
pory n'arrive pas à esquiver le coup (54% > 52%). pory perd 1 pv.
pory est KO. lila remporte le combat.
```

**5.** Écrire la fonction `fight` dont la signature est la suivante :

```c
Fighter fight(Fighter f1, Fighter f2);
```

La fonction prend en paramètre les combattant·e·s et retourne le vainqueur.

## "Faites vos jeux, rien ne va plus !"

**6.** Écrire le programme principal qui génère deux combattant·e·s, demande au
joueur de parier sur l'un·e des combattant·e·s, lance le combat, et alors
informe le joueur si il remporte son pari. Le joueur choisi l'un·e des
combattant·e·s en entrant son nom.
Par exemple :

```
pory(pv: 2, esquive: 52%)
lila(pv: 2, esquive: 48%)
Sur quel·le combattant·e pariez-vous ? lila
...
lila a remporté le combat.
Vous avez remporté votre pari !
```
