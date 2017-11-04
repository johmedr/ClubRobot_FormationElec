
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
  affecterEtat(out);
}
