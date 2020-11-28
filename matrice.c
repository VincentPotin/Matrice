#include "matrice.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>

struct matrice {
    int n;
    int m;
    float **matrice;
};

T_matrice creationMatrice(const int n, const int m){
    int i;
    errno = 0;
    T_matrice mat = (struct matrice *)malloc(sizeof(struct matrice));
    if (errno){
        perror("Erreur allocation structure matrice");
        return NULL;
    }
    mat->matrice = (float **)calloc(n,sizeof(float *));
    if (errno){
        perror("Erreur allocation dim1 matrice");
        return NULL;
    } 
    for(i=0;i<n;i++){
        mat->matrice[i] = (float *)calloc(m,sizeof(float));
    }
    if (errno){
        perror("Erreur allocation dim2 matrice");
        return NULL;
    }
    mat->n = n;
    mat->m = m;
    return mat;
}

void detruireMatrice(T_matrice mat){
    int i;
    errno = 0;
    if (mat != NULL) {
        if (mat->matrice != NULL) {
            for (i=0;i<mat->n;i++) {
                if (mat->matrice[i] != NULL) {
                    free(mat->matrice[i]);
                } else {
                    errno = ENOMEM;
                    return;
                }                
            }
            free(mat->matrice);
        } else {
            errno = ENOMEM;
            return;
        }
        free(mat);
    } else {
        errno = ENOMEM;
        return;
    }
}

void scanElement(float * val) {
    scanf("%f",val);
}
void printElement(float * val) {
    printf("%6.2f",*val);
}

void traiteMatrice(T_matrice mat, void (*traite) (float *)){
    int i,j;
    errno = 0;
    
    if (mat != NULL) {
        if ((mat->matrice) != NULL) {
            for(i=0;i<mat->n;i++) {
                if(mat->matrice[i] != NULL) {
                    for(j=0;j<mat->m;j++) {
                        traite(&(mat->matrice[i][j]));
                        /*scanf("%f",&(mat->matrice[i][j]));*/
                    }
                    if (traite != &scanElement){    /* on compare les adresses des fonctions traite et scanElement donc pas de soucis*/
                        printf("\n");
                    }
                } else {
                    errno = EINVAL;
                    return;
                }
            }            
        } else {
            errno = EINVAL;
            return;
        }
    } else {
        errno = EINVAL;
        return;
    }    
}

void saisieMatrice(T_matrice mat) {
    if (mat != NULL) {
        printf("Mat[%d,%d] = \n",mat->n,mat->m);
    } else {
        errno = EINVAL;
        return;
    }
    traiteMatrice(mat,scanElement);
}

void afficheMatrice(const T_matrice mat){
    if (mat != NULL) {
        printf("Mat[%d,%d] = [\n",mat->n,mat->m);
    } else {
        errno = EINVAL;
        return;
    }
    traiteMatrice(mat,printElement);
    printf("]\n");
}

char * matriceEnChaine(const T_matrice mat){ /* fonction matriceEnChaine qui renvoie un pointeur de chaine de caractères char */
    char *ch = (char *)calloc(1000,sizeof(char));   /*j'alloue mon tableau de caractères*/
    char chfloat[10]; /*variable locale*/
    int i,j;

    if (mat != NULL) {
        sprintf(ch,"Mat[%d,%d] = [\n",mat->n,mat->m);
    } else {
        errno = EINVAL;
        return NULL;
    }
    errno = 0;
    if (mat != NULL) {
        if ((mat->matrice) != NULL) {
            for(i=0;i<mat->n;i++) {
                if(mat->matrice[i] != NULL) {
                    for(j=0;j<mat->m;j++) {
                        sprintf(chfloat,"%6.2f",mat->matrice[i][j]); /*j'affiche, dans chfloat, la valeur matrice[i][j]*/
                        memcpy(&ch[strlen(ch)],chfloat,strlen(chfloat)*sizeof(char)); /*premier paramètre est adresse de départ, second paramètre est adresse de destination, troisieme paramètre est taille du tableau*/
                    }
                    sprintf(chfloat,"\n");
                    memcpy(&ch[strlen(ch)],&chfloat,strlen(chfloat)*sizeof(char));
                } else {
                    errno = EINVAL;
                    return NULL;
                }
            }            
        } else {
            errno = EINVAL;
            return NULL;
        }
    } else {
        errno = EINVAL;
        return NULL;
    }    
    sprintf(chfloat,"]\n");
    memcpy(&ch[strlen(ch)],&chfloat,strlen(chfloat)*sizeof(char));
    return ch;
}



