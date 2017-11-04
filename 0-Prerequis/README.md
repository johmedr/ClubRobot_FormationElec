# 0 - Prerequis

## Compétences et ressources utiles

Le language C++, basé sur la syntaxe de C, est utilisé pour 
programmer avec mbed. 

La formation requiert un niveau de base en C, c'est-à-dire :
   * types et opérations élémentaires, 
   * implémentation de functions, 
   * tableaux et pointeurs. 

Si vous souhaitez acquérir ou approfondir ces compétences, on 
ne peut que vous recommander de suivre les deux premières parties
du [cours d'OpenClassroom](https://openclassrooms.com/courses/apprenez-a-programmer-en-c). 

Les notions de programmation orientée objet seront abordées au fur et à mesure 
de la formation. Comme ressource principale, nous vous conseillons le [cours d'OpenClassroom sur le C++](https://openclassrooms.com/courses/programmez-avec-le-langage-c). 

La documentation fournie par mbed peut être très utile pour comprendre 
l'utilisation des librairies (ensemble de fonctions, d'objets, ...). 
Nous vous invitons donc à aller consulter : 
   * [la doc. de mbed](https://os.mbed.com/handbook/Homepage) pour les fonctions de base, 
   * [https://github.com/ARMmbed/mbed-os](le code de mbed-os), la librairie de base utilisée (notamment 
   les fichiers dans le dossier `drivers`, contenant les briques de base). 

## Matériel 

La formation s'effectue sur un microcontrôleur STM32, proche de 
ceux utilisés en cours de 3ème et 4ème années à l'INSA. 
Ils sont programmés en C++, comme évoqué plus tôt. 

On utilise les Cartes Initiations du Club Robot pour tester nos 
programmes. Elles embarquent une carte Nucléo possédant un STM32, 
dont l'utilisation est très proche d'un Arduino. 

Les entrées/sorties de la carte ont été connectées à des composants 
électroniques pour intéragir avec elle : 
   * des leds (sortie numérique), 
   * des boutons poussoirs (entrée numérique), 
   * des potentiomètre (entrée analogique), 
   * des connecteurs pour brancher des moteurs (sortie numérique pilotée en PWM), 
   * des connecteurs pour l'UART (communication UART), 
   * des connecteurs pour le CAN (communication CAN). 

Ces différents éléments seront interfacés et utilisés au fil de la formation, en suivant
chronologiquement l'ordre présenté ci-dessus. 

## Logiciel

Nous utilisons l'applicatio mbed, accessible [en ligne](https://os.mbed.com/compiler/), pour 
écrire le code du microcontrôleur, ainsi que pour compiler (transformer le code en suite 
d'instructions binaires pour le STM32). 

Une fois la compilation terminée, mbed nous permet de télécharger le fichier binaire exécutable. 
On peut ensuite glisser-déposer ce fichier sur la carte Nucléo, comme avec une clé USB.


  
