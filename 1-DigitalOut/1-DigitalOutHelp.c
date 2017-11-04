#include "mbed.h"

DigitalOut leds[6] = {D3, D4, D5, D6, D11, D12}; // leds est un tableau de 6 DigitalOut

// Cette fonction va nous permettre de vérifier que la fonction affecterEtat se comporte comme on veut
bool testerAffecterEtat();

// À implémenter (tout en bas du fichier)
// Prend un tableau de DigitalOut et un tableau de bool de tailles fixes, et allume/eteint les 
// leds pour respecter l'état argEtat. 
void affecterEtat(DigitalOut argLeds[6], bool argEtat[6]); 


int main()
{
    // On teste la fonction, on stocke le résultat
    bool testResult = testerAffecterEtat(); 

    bool state1[6] = {true, false, false, false, false, true}; 
    bool state2[6] = {false, true, false, false, true, false};
    bool state3[6] = {false, false, true, true, false, false}; 

    // Si le test a marché, cette boucle s'éxecute à l'infini
    while(testResult) 
    { 
        affecterEtat(leds, state1); // On affecte le premier état
        wait(0.333f); // On attends

        // Pareil pour les états 2 et 3
        affecterEtat(leds, state2); 
        wait(0.333f); 

        affecterEtat(leds, state3);
        wait(0.333f); 
    }
        // Les leds clignotent
}


// Cette fonction va nous permettre de vérifier que la fonction affecterEtat se comporte comme on veut
bool testerAffecterEtat() 
{
    bool testResult;  

    // Données de tests : on affecte un état tout éteint, tout doit être éteint
    bool tabEtatTest1[6] = {false, false, false, false, false, false}; 

    // Pareil en allumé
    bool tabEtatTest2[6] = {true, true, true, true, true, true}; 

    // Pareil en random
    bool tabEtatTest3[6] = {true, true, false, true, false, false}; 
    int tabLedsTest3[6] = {1, 1, 0, 1, 0, 0};

    // On teste de tout éteindre,
    affecterEtat(leds, tabEtatTest1); 
    for(int i = 0; i < 6; i++) 
    {
        testResult = (leds[i] == 0); // on vérifie que tout est éteint,
    }

    // de tout allumer, 
    affecterEtat(leds, tabEtatTest2); 
    for(int i = 0; i < 6; i++) 
    {
        testResult = testResult && (leds[i] == 1); // et que tout est allumé
    }

    // de mettre un état random
    affecterEtat(leds, tabEtatTest3); 
    for(int i = 0; i < 6; i++) 
    {
        testResult = testResult && (leds[i] == tabEtatTest3[i]); // et qu'il est respecté. 
    }   

    // On retourne le résultat du test, qui était un 'et' logique entre tout les tests
    return testResult;
}

// Prend un tableau de DigitalOut et un tableau de bool de tailles fixes, et allume/eteint les 
// leds pour respecter l'état argEtat. 
void affecterEtat(DigitalOut argLeds[6], bool argEtat[6])
{
    // Mettez votre code ici
}