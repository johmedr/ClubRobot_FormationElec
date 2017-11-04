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

### *L'inclusion préprocesseur* 

Le code présenté içi est plutôt minimal, et permet de faire clignoter une led. 
Regardons-le plus attentivement. 

```C++
#include "mbed.h"
``` 

La première ligne permet d'inclure la librairie mbed : on pourra donc utiliser les fonctions 
présentées en bas de [cette page](https://os.mbed.com/handbook/Homepage). 

> ### *Ce qui se passe :*
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
  
  On se serait donc retrouvé avec le code suivant : 
  ```C
  // Structure SortieDigitale
  typedef struct SortieDigitale_Struct
  {
    int niveaLogique; 
 //  ^----- Le type bool n'existe pas en C, on utilise à la place un entier (= 0 : faux, > 0 : vrai)
    int numeroBroche; 
  } SortieDigitale; // C'est ici qu'est réellement défini le nom de notre struct
  
  // Initialise une structure SortieDigitale
  void connecter(SortieDigitale * out, int argNumeroBroche) 
  {
    out->niveauLogique = 0; 
    out->numeroBroche = argNumeroBroche; 
  }
  
  /* Appelle une fonction constructeur permettant d'affecter un etat logique à une sortie
   *  Le prototype de la fonction serait : 
   * void fonctionConstructeurAffecterEtatBroche(int numeroBroche, int etatLogique); 
   */
  void affecterEtat(SortieDigitale * out) 
  {
    fonctionConstructeurAffecterEtatBroche(out->numeroBroche, out->etatLogique); 
  }
  
  // Allume la SortieDigitale passsée en argument
  void allumer(SortieDigitale * out) 
  {
    out->niveauLogique = 1; 
    affecterEtat(out); 
  }
  
  // Éteind la SortieDigitale passsée en argument
  void eteindre(SortieDigitale * out) 
  {
    out->niveauLogique = 0; 
  }
  ```
  
#### Ce que permet le C++ 
## Troubleshooting
Il est possible que le programme Blinky ne fonctionne pas. Dans ce cas, il faut importer 
depuis mbed le programme "Nucleo_blink_Led" (`Import > Onglet Programs > Chercher et importer "Nucleo_blink_led"`).
