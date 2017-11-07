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

## Le constructeurs

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
		// do stuff
	} 

	DigitalPortOut(PinName pin)
	{
		// do other stuff
	}
}
```

Lors de la création de constructeur, la question à se poser est : 
> "à partir de quelles données fournies par l'utilisateur peut/doit on 
initialiser l'objet et ses membres ?"

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


## Introduction à l'héritage

## À vous !

## [< Précédent](https://github.com/yop0/ClubRobot_FormationElec/blob/master/1-DigitalOut) | [Suivant >](https://github.com/yop0/ClubRobot_FormationElec/blob/master/3-AnalogIn)
 