#ifndef MATRICE_H_
#define MATRICE_H_

typedef struct matrice * T_matrice;

/* Création d'une matrice n*m */
T_matrice creationMatrice(const int n, const int m);

/* saisie clavier de la matrice mat*/
void saisieMatrice(const T_matrice mat);

/* Affichage Ecran de la matrice mat */
void afficheMatrice(const T_matrice mat);

/* Désalloue une matrice mat */
void detruireMatrice(T_matrice mat);

/* Retourne la représentation d'une matrice au format chaine de caractères */
char * matriceEnChaine(const T_matrice mat);

#endif