#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "matrice.h"


int main (int argc, char *argv[]){
    T_matrice lamatrice;
    lamatrice = creationMatrice(3,3);
    
    if(errno){
        perror("Ouuppss ....");
    }
    saisieMatrice(lamatrice);
    afficheMatrice(lamatrice);
    printf("%s",matriceEnChaine(lamatrice));
    detruireMatrice(lamatrice);
    return 0;
}