# 1 - DigitalOut
## Objectif

Le but içi est de commencer à mettre les mains de le cambouis. Pour 
celà on va d'abord suivre le tutoriel de base de mbed-os, pour configurer
correctement l'application, puis importer un premier code pour faire clignoter 
une led (dingue !). 
Ensuite, nous mettrons en place un petit code nous permettant de déplacer la Led allumée
sur la carte. 

## Le tutoriel de mbed

Rendez-vous sur [cette page](https://os.mbed.com/docs/v5.6/tutorials/blinky-on-the-arm-mbed-online-compiler.html)
pour avoir accès au tout premier tutoriel. 

Après avoir importé le projet nommé "Blinky" dans l'IDE en ligne de mbed, 
vous allez configurer pour pouvoir générer du code pour la carte initiation. 
Dans la partie "Selecting a board", choisissez la carte "Nucleo-L432KC", puis
validez. 


Le code présenté içi est plutôt minimal, et permet de faire clignoter une led. 
Regardons-le plus attentivement. 

```C++
#include "mbed.h"
``` 

La première ligne permet d'inclure la librairie mbed : on pourra donc utiliser les fonctions 
présentées en bas de [cette page](https://os.mbed.com/handbook/Homepage). 

### *Ce qui se passe :* 
> Avant la compilation, un moteur appelé *préprocesseur* lit tous les fichiers du projet, à la recherche
de _directives de préprocesseur_ (aussi appelées *macros*). Ce sont les seules lignes commencant par `#`, 
et elles stipulent une modification à faire sur les fichiers de code source (c'est-à-dire que ces opérations
modifient directement le code). Pour le coup, la directive `#include "nom_du_fichier"` permet de demander au 
préprocesseur de copier-coller le fichier `nom_du_ficher` tel quel à l'endroit du `#include`. 
> Pour les curieux, n'hésitez pas à lire [la page consacrée sur OpenClassroom](https://openclassrooms.com/courses/apprenez-a-programmer-en-c/le-preprocesseur).



## Troubleshooting
Il est possible que le programme Blinky ne fonctionne pas. Dans ce cas, il faut importer 
depuis mbed le programme "Nucleo_blink_Led" (`Import > Onglet Programs > Chercher et importer "Nucleo_blink_led"`).