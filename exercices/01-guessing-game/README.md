
Le but de cet exercice est de programmer un jeu qui génère aléatoirement un
nombre et laisse le joueur deviner ce nombre.
Lorsque le joueur entre un nombre, le jeu lui informe si le nombre à deviner est
plus grand ou plus petit que le nombre entré.
Le joueur gagne une fois qu'il devine le nombre.

Pour ce faire, vous vous aiderez des fonction `printf` et `scanf` présentes dans
la bibliothèque `stdio.h`, ainsi que de la fonction `rand` présente dans la
bibliothèque `stdlib.h`.

Pour générer des nombres aléatoires distincts à chaque exécution du programme,
il vous est nécessaire d'initialiser le générateur de nombre aléatoire.
Vous pouvez par exemple l'initialiser avec l'horloge de la machine :

```c
srand(time(NULL));
```

Cette instruction est à placer avant l'appel à la fonction `rand`.
La fonction `time` est présente dans la bibliothèque `time`.

