# 2 - DigitalIn

## Objectif 

On a appris dans la partie précédente à se servir de la class `DigitalOut` pour écrire un état 
logique sur une sortie. 
Par la suite, on a pu utiliser des éléments de base du C++ pour faire clignoter nos leds. 

Le but maintenant est progresser un peu plus dans le monde des classes, et de découvrir des 
fonctionnalités plus avancées comme l'héritage et le polymorphisme. On va également 
utiliser la classe DigitalIn pour créer une entrée logique et interfacer les boutons.


## Créer une classe

On a vu précédemment qu'une classe est une entité qui définit le comportement d'un type
d'objet. 

Pour créer une classe, la syntaxe est la suivante : 

```C++ 
class DigitalPortOut // On définit la classe 'MaClasse'
{
	int m1; 	// Dans une classe, la portée par défaut est "privée". Ceci veut dire qu'on
	bool f1();  // ne peut pas voir de l'extérieur de la classe ce qui est içi

public: 		// On passe explicitement en portée "publique". Tout le monde peut voir m2 
	int m2;		// et utiliser f2. 
	void f2(); 

private: 		// On repasse en portée "privée". Personne en dehors de la classe ne peut
	int m3;  	// voir m3 ou utiliser f3. 
	char f3();  // NB : f2 peut utiliser f3, car ils sont dans la même classe

}; // Ne pas oublier ce point-virgule
```

## Le constructeur

Le constructeur sert à déclarer comment le programme doit initialiser un objet d'une classe
donnée, avec une jeu d'arguments donné. 

Il se déclare de cette façon : 
```C++
class DigitalPortOut
{
public: 
	DigitalPortOut() 
//  ^--- Comme vous pouver le voir, le constructeur est une *méthode* particulière, sans type de retour
// 	Son nom est forcément celui de la classe
	{
		// do construction stuff here
	} 

	DigitalPortOut(PinName pin)
	{
		// do other construction stuff here
	}
}
```

Lors de la création de constructeur, la question à se poser est : 
> "à partir de quelles données fournies par l'utilisateur peut/doit on 
initialiser l'objet et ses membres ?"

#### *Construire un objet*

Une fois le constructeur défini, on peut s'en servir pour instancier des objets
de notre classe. 

Ceci se passe comme cela : 
```C++
// Variables classiques
DigitalPortOut monPorc; 	// On utilise aucun argument, appel au constructeur "DigitalPortOut()"
DigitalPortOut monSecondPorc(A3); // On utilise "DigitalPortOut(PinName pin)"

// Pointeurs
DigitalPortOut * ptrSurPorc1 = new DigitalPortOut(); // On alloue de la mémoire à un pointeur, sans arg.
DigitalPortOut * ptrSurPorc2 = new DigitalPortOut(D3); // On alloue de la mémoire à un pointeur avec un arg.

```


#### *La liste d'initialisation*

Supposons que notre classe possède des *membres* (variables) que nous souhaitons 
initialiser grâce aux données de l'utilisateur.

```C++
class DigitalPortOut
{
private: 
	PinName connectedPin; 
	bool statePin; 
public: 
	// ...
}
```
On souhaiterais construire un PinName, initialisé par l'utilisateur, ainsi
qu'un état booléen, initialisé par défaut à `false`. 

Pour cela, on pourrait utiliser le code suivant pour le constructeur. 

```C++
DigitalPortOut(PinName pin)
{
	connectedPin = pin; 
	statePin = false; 
}
```

Le C++ nous fournit une syntaxe plus simple et à privilégier : la liste d'initialisation. 
```C++
// 							v---- C'est le début de la liste
DigitalPortOut(PinName pin) : connectedPin(pin), statePin(false)
//									^				^--- Appel au constructeur du type bool prenant comme argument un bool.
//									|--- appel du constructeur de la classe PinName() prenant en argument un PinName.
{} // <- Le corps de la fonction est vite, on a juste construit des objets.
```




## Le destructeur
On a appris la syntaxe du constructeur, permettant d'indiquer comment initialiser notre classe. 
Maintenant, on va voir comment indiquer au programme la manière de détruire un objet de notre classe. 

Pour cela, on va utiliser le destructeur, dont la syntaxe est la suivante. 

```C++
class DigitalPortOut
{
public: 
//  v--- Le nom du destructeur est le nom de la classe avec un tilde ('~') devant. 
	~DigitalPortOut()
	// 				^--- La liste d'argument du destructeur DOIT être vide. 
	{
		// do destruction stuff here
	}
}
``` 

Son intérêt est de désallouer la mémoire qui aurait pu être explicitement allouée lors de la construction
ou l'utilisation de l'objet. 

Ceci est illustré dans le code suivant : 

```C++
// Classe représentant un polygone
class Polygone
{
private: 
	int nombreCotes; 	// avec un certain nombre de côtés, 
	int * longueurCotes; // chacun ayant une certaine longueur 
						 //(notre pointeur représente la premiere case d'un tableau) 
						 // (Si cette ligne vous pose problème, 
						 // revoyez le lien entre tableau et pointeur)
public: 
	
	// À la construction d'un polygone 
	Polygone(int nCotes) : 
		nombreCotes(nCotes),    // On construit nombreCotes à partir de nCotes
		longueurCotes(new int[nCotes])    // On alloue de la mémoire pour pouvoir stocker la longueur de chaque côté
	{}

	// À la destruction d'un polygone
	~Polygone() 
	{
		delete longueurCotes; 	// On a alloué cette mémoire à la construction. 
		// Si on ne la désalloue pas, une fois la classe détruite, 
		// le pointeur longueurCotes ne pointera plus sur l'emplacement mémoire,
		// mais ce dernier sera toujours marqué comme utilisé : on aura une fuite mémoire. 
		// On appelle donc le destructeur défini pour un tableau d'entier. 
		// On a pas besoin de supprimer la variable nombreCotes : 
		// celle-ci est détruite automatiquement (on n'a pas explicitement alloué de 
		// la mémoire) 
	}
}:
```

## Ajouter une méthode à notre classe

Prenons la classe `Polygone` créée ci-dessus. On souhaite désormais pouvoir affecter 
une longueur à chaque côté, individuellement. Pour celà, on souhaite que notre classe 
fournisse un *service* en proposant une *méthode* de *portée publique* répondant
à notre problème. 

Pour celà, on va *déclarer* notre fonction dans la classe (on n'est cependant pas
obligés de la *définir* dans la classe). Cette fonction prendra en argument un numéro
de côté et une longueur, et retournera un booléen vrai si le numéro de côté est inférieur
au nombre de côtés. 

```C++
class Polygone
{
	// ... On remet ici ce qui était ci-dessus

	bool affecterLongueur(int cote, int longueur) 
	{
		bool opResult = false; 
		if(cote < nombreCotes) 
		{
			longueurCotes[cote] = longueur; 
			opResult = true; 
		}
		return true; 
	}
}
```

On pourra ensuite appeller la méthode de la manière suivante : 
```C++ 
Polygone lopoly(3); // Construction du polygône à trois côté

// Côté 1, longueur 12
lopoly.affecterLongueur(1, 12); 

// Côté 2, longueur 19
lopoly.affecterLongueur(2, 19); 

// Côté 3, longueur 2
lopoly.affecterLongueur(3, 2); 
```


## Récapitulatif

Les classes, ainsi que leur construction, destruction et l'utilisation de leur méthodes, on été abordées ici
sous un certain angle. 

Vous êtes invités à enrichir vos compétences en suivant la partie du tutoriel d'OpenClassroom qui y est consacrée (à savoir
[cette page](https://openclassrooms.com/courses/programmez-avec-le-langage-c/les-classes-partie-1-2) et 
[celle-ci](https://openclassrooms.com/courses/programmez-avec-le-langage-c/les-classes-partie-2-2).)

## À vous !

## [< Précédent](https://github.com/yop0/ClubRobot_FormationElec/blob/master/1-DigitalOut) | [Suivant >](https://github.com/yop0/ClubRobot_FormationElec/blob/master/3-AnalogIn)
 