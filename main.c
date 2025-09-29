#include <stdio.h>
#include <stdlib.h>
#define BASE 2

typedef struct{
    int *Tdigits;
    int taille;
    int Signe;

} BigBinary;




void afficherBigBinary(BigBinary bigBinary) {
    if (bigBinary.Signe == -1) printf("-");
    else if (bigBinary.Signe == 0 || bigBinary.taille == 0 ) printf("0");
    else {
        for (int i = 0 ; i < bigBinary.taille ; i++) {
            printf("%d", bigBinary.Tdigits[i]);
        }
        printf("\n");
    }
}

BigBinary createBigBinary(int taille) {
    BigBinary bb;
    bb.Tdigits = malloc(taille * sizeof(int));
    bb.taille = taille;
    bb.Signe =0;
    return bb;
}


int main(){
    return 0;
}
