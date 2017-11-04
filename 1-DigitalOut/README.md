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
Le code qui apparaît est expliqué ci-dessous. Un bon plan est de finir le tuto. de mbed, 
télécharger et tester l'exécutable. Si ça marche, vous pouvez lire la suite, sinon, checkez [la dernière 
section](https://github.com/yop0/ClubRobot_FormationElec/tree/master/1-DigitalOut#troubleshooting).

### *L'inclusion préprocesseur* 

Le code présenté içi est plutôt minimal, et permet de faire clignoter une led. 
Regardons-le plus attentivement. 

```C++
#include "mbed.h"
``` 

La première ligne permet d'inclure la librairie mbed : on pourra donc utiliser les fonctions 
présentées en bas de [cette page](https://os.mbed.com/handbook/Homepage). 

> ### *Ce qu'il se passe :*
  > Avant la compilation, un moteur appelé *préprocesseur* lit tous les fichiers du projet, à la recherche
  de _directives de préprocesseur_ (aussi appelées *macros*). Ce sont les seules lignes commencant par `#`, 
  et elles stipulent une modification à faire sur les fichiers de code source (c'est-à-dire que ces opérations
  modifient directement le code). Pour le coup, la directive `#include "nom_du_fichier"` permet de demander au 
  préprocesseur de copier-coller le fichier `nom_du_ficher` tel quel à l'endroit du `#include`. 
  > Pour les curieux, n'hésitez pas à lire [la page consacrée sur OpenClassroom](https://openclassrooms.com/courses/apprenez-a-programmer-en-c/le-preprocesseur).
  

### *La classe DigitalOut* 

La ligne suivante permet de déclarer une variable globale, de type DigitalOut, en l'initialisant sur 
la broche sur laquelle est connectée la `LED1`. En réalité, il s'agit d'une led directement soudée sur 
la carte Nucleo. 

```C++
DigitalOut myled(LED1);
``` 

  > Pour les adeptes du C, cette syntaxe peut être perturbante : qu'est-ce qui peut bien se cacher derrière 
  DigitalOut ? 
  
#### The C solution 
  Prenons le problème à l'envers. Supposons que l'on souhaite créer *quelque chose* qui représente une broche de
  la carte électronique. Ce *quelque chose* aurait un numéro de broche, et un état - son niveau logique, 0 ou 1 - 
  que l'on pourrait manipuler grâce à des fonctions (par exemple, *allumer()* et *eteindre()*). 
  La première idée qu'aurait un développeur C serait de faire une structure `SortieDigitale`, constituée d'une variable 
  entière `numeroBroche`, et une variable `niveauLogique`.
  On créerait ensuite une fonction `connecterSortie`, qui initialise une structure `SortieDigitale` avec un numéro de broche
  passé en argument, et un niveau logique bas. 
  On aurait ensuite développé nos deux fonctions de manipulation de structure, `allumer()` et `eteindre()`, qui nous auraient
  permis de manipuler l'état de la broche, sans avoir à le faire à chaque fois à la main. 
  
  On se serait donc retrouvé avec [ce code](https://github.com/yop0/ClubRobot_FormationElec/blob/master/1-DigitalOut/StructSortieDigitale.c).

  
#### Ce que permet le C++ 
  Ce que l'on peut constater dans la solution précédente, c'est que l'utilisateur peut modifier *à la main* la 
  valeur des variables interne à notre structure. Et ça, c'est problématique. 
  Imaginons qu'on écrive une fonction permettant de vérifier que la broche passée à la fonction `connecterSortie`
  existe bien. En utilisant cette fonction pour initialiser une structure `SortieDigitale`, on serait sûrs 
  que le champ `numeroBroche` correspond à une broche existante. 
  Cependant, rien ne nous empêche d'écrire :
  ```C
  	maSortieDigitale.numeroBroche = 42; // On suppose que la broche 42 n'existe pas, of course
  ``` 
  Et là, c'est la cata : on ne sait pas ce qui va se passer quand on va écrire un niveau logique sur 
  une broche qui n'existe pas ... Et si ça faisait exploser la carte ? 

  Pour pallier à celà, le C++ utilise le principe *d'encapsulation des données* à travers les _classes_. 
  L'encapsulation de données, c'est faire en sorte que personne ne vienne gratouiller à sa sauce dans l'objet si on 
  ne l'a pas autorisé. On fournit à la place des fonctions de manipulation, appellées *méthodes*, pour modifier 
  l'objet. 

  Ainsi, si on fait le parallèle avec l'automobile : 
   * une classe, c'est une voiture : ça définit des propriétés communes (4 roues, un volant, un moteur)
   * une instance de classe, c'est *cette* voiture : ça définit des un ensemble de variables propres à cette voiture 
   (nombre de chevaux, longueur, ...) 
   * une variable membre, c'est une des propriétés de la voiture (par exemple sa vitesse actuelle, le débit 
   d'injection), 
   * une méthode, c'est quelque chose que l'utilisateur peut utiliser pour manipuler l'instance de classe : pour la
   voiture, il s'agit du volant, des pédales, ... 


  En tant que conducteurs, on va donc utiliser les pédales (*méthodes* accessible par l'utilisateur) 
  pour modifier des propriétés de la voiture comme la vitesse ou le débit d'injection (*variables membres*,
  inaccessibles par l'utilisateur).

  Enfin, on revient à notre `DigitalOut`. Il s'agit donc d'une classe représentant une sortie digitale connectée 
  à une broche, qui possède des méthodes réalisant les modifications d'état sur la broche en question. 
  Et c'est tout ! Pour bien voir ceci, nous vous conseillons de lire 
  [ce fichier](https://github.com/ARMmbed/mbed-os/blob/master/drivers/DigitalOut.h), qui définit la classe 
  DigitalOut`. 

  Retrouvez d'autres explications, ainsi que la syntaxe pour la définition d'une classe sur
   [cette page](https://openclassrooms.com/courses/programmez-avec-le-langage-c/les-classes-partie-1-2). 


### *La fonction principale*

Continuons la lecture du code ... 

```C++
int main() {
    while(1) {
        myled = 1; // LED is ON
        wait(0.2); // 200 ms
        myled = 0; // LED is OFF
        wait(1.0); // 1 sec
    }
}
```

Ceci est la fonction principale du code, c'est elle qui sera lancée en première et qui définira
ce que notre programme va faire. 

À l'intérieur, on trouve une boucle `while(1)`, et à l'intérieur de cette boucle des instructions. 

#### *La boucle infinie* 
Le code `while(1)` (i.e. `tant que vrai, faire`) créé une boucle infinie. Le programme est censé faire
clignoter une led, opération pour laquelle on a pas défini de date d'expiration : il faut donc que 
la led clignotte pour une durée infinie, tant que la carte est alimentée. 

En général, il est très rare que l'on souhaite que le code de la fonction `main()` ne s'éxecute qu'une seule fois, 
pour une application sur microcontôleur. Les programmes sont donc souvent découpés en deux phases : 
  * une phase *d'initialisation*, qui permet de créer et de préparer ce dont le microcontrôleur à besoin, 
  * une phase *d'exécution*, de durée infinie, pendant laquelle le microcontrôleur effectue certaines tâches 
  de manière répétitive. 

#### *Les instructions de la boucle* 
Les lignes `myled = 1` et `myled = 0` utilisent un comportement que nous n'aborderons pas en détail 
pour le moment : une surcharge de l'opérateur `=`. Il faut juste se dire que, si à priori l'opération 
`objet de type DigitalOut = int` parraît abhérante, un comportement à adopter dans ce cas à été défini.

Ce comportement est du type : 
```
Si : on essaye d'affecter un entier 'x' à un DigitalOut 'd',
Alors : appeler la méthode "d.write(x)" permettant
d'écrire l'état 'x' sur la broche 'd'.
```

Ainsi, on peut comprendre le code suivant : 
```C++
  myled = 1; // LED is ON
  wait(0.2); // 200 ms
  myled = 0; // LED is OFF
  wait(1.0); // 1 sec
```

## À vos claviers ! 

Normalement, vous êtes maintenant capables de comprendre et de modifier le code du projet ! 
L'idée va donc être de jouer avec, pour revoir les bases de la programmation en C++ (on codera
des classes plus tard, là on va rester sur des tableaux, des fonctions, les bases quoi !). 

Le but est de créer une sortie numérique pour chaque led connectée sur la carte initiation, puis
de passer un tableau représentant l'état de chaque led à une fonction, qui va affecter l'état
de chaque led. 

La fonction ne retourne pas d'argument, et prend en argument :
 * le tableau d'état, constitué de nombres booléens, 
 * une structure de données représentant des leds, qui contient ce qu'il faut pour allumer/éteindre les leds. Aucune structure imposée, débrouillez-vous ! 
 
Vous pouvez trouver le numéro des broches auxquelles sont connectées les leds dans [ce fichier](https://github.com/yop0/ClubRobot_FormationElec/blob/master/0-Prerequis/Pinout_CarteInitiation.pdf). 

### *Pour aller plus loin* :+1: 
Créez une classe `LedsSet`, qui permet de contruire un objet représentant toutes les leds de la 
carte initiation. Cette classe possède des méthodes pour allumer ou éteindre toutes les leds, 
et une méthode permettant d'affecter un tableau d'état aux leds. 
<details>
<summary>Indice</summary>
Servez-vous de la fonction implémentée dans la partie précédente ! ;)
</details>

## Troubleshooting
Il est possible que le programme Blinky ne fonctionne pas. Dans ce cas, il faut importer 
depuis mbed le programme "Nucleo_blink_Led" (`Import > Onglet Programs > Chercher et importer "Nucleo_blink_led"`).

### [< Précédent](https://github.com/yop0/ClubRobot_FormationElec/tree/master/0-Prerequis) | [Suivant >](https://github.com/yop0/ClubRobot_FormationElec/tree/master/2-DigitalIn)
