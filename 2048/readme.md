Le readme.md default pour le project 2048

Introduction au jeu:
Le jeu se joue sur un plateau 4 × 4. Au début du jeu, le numéro 2 apparaîtra dans deux positions aléatoires. Après cela, le joueur peut choisir d'effectuer quatre opérations de diapositives: haut('w'), bas('s'), gauche('a') et droite('d'). Tous les numéros glisseront du côté sélectionné par le joueur et des deux adjacents Le même numéro sera fusionné. Chaque fois que le joueur effectue une opération, un numéro 2 (75%) ou un numéro 4 (25%) apparaîtra au hasard dans les positions libres restantes.
Conditions de victoire du jeu: 2048 apparaît.
Conditions d'échec du jeu: les joueurs ne peuvent effectuer aucune opération.

***
Premier version: un joue de 2048 sur console (le terminal)

Implémentation:
gcc -Wall main.c appear.c appear.h check.c check.h grille.c grille.h move.c move.h

***
Deuxieme version: un joue de 2048 avec le graphique
Vous pouvez appuyer sur la touche 'ESC' à mi-chemin du jeu pour quitter

Implémentation:
gcc main_sdl.c affiche_sdl.h affiche_sdl.c appear.h appear.c check.h check.c grille.h grille.c move.h move.c $(sdl-config --cflags --libs) -lSDL_image -o 2048.x

ou il est possible de compiler avec le Makefile qui inclus.
