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
    bb.Signe = 0;
    return bb;
}





void libereBigBinary(BigBinary bb) {
    free(bb.Tdigits);
}

int egaliteBigBinary(BigBinary bigBinary1 , BigBinary bigBinary2) {
    if (bigBinary1.taille != bigBinary2.taille || bigBinary1.Signe != bigBinary2.Signe) return 0;
    int valBool = 1;
    for (int i = 0; i < bigBinary1.taille; i++) {
        if (bigBinary1.Tdigits[i] != bigBinary2.Tdigits[i]) valBool =  0;
    }
    return valBool;
}



BigBinary soustractionBigBinary(BigBinary bigBinary1 , BigBinary bigBinary2) {
    int taille = bigBinary1.taille;
    if (bigBinary2.taille > bigBinary1.taille) taille = bigBinary2.taille;
    int* resultat = malloc((taille+1) * sizeof(int));
    int i = bigBinary1.taille -1;
    int j = bigBinary2.taille -1;
    int k = 0;
    int retenue = 0;
    while (i>=0 || j>=0 || retenue) {
        int bitBigBinary1 = (i>=0) ? bigBinary1.Tdigits[i] : 0;
        int bitBigBinary2 = (j>=0) ? bigBinary2.Tdigits[j] : 0;
        int somme = bitBigBinary1 -  bitBigBinary2 + retenue;
        switch (somme) {
            case 0:
                resultat[k] = 0;
                retenue = 0;
                break;
            case 1:
                resultat[k] = 1;
                retenue = 0;
                break;
            case -1:
                resultat[k] = 1;
                retenue = -1;
                break;
            case -2:
                resultat[k] = 0;
                retenue = -1;
                break;
        }
        i--;
        j--;
        k++;
    }
    BigBinary result = createBigBinary(k);
    result.Signe = 1;
    for (int i = 0 ; i < k ; i++) {
        result.Tdigits[i] = resultat[k- i - 1];
    }
    free(resultat);
    return result;
}



BigBinary additionBigBinary(BigBinary bigBinary1 , BigBinary bigBinary2) {
    int taille = bigBinary1.taille;
    if (bigBinary2.taille > bigBinary1.taille) {
        taille = bigBinary2.taille;
    }
    int* resultat = malloc((taille+1) * sizeof(int));
    int i = bigBinary1.taille -1;
    int j = bigBinary2.taille -1;
    int k=0;
    int retenue = 0;
    while (i>=0|| j>=0 || retenue) {
        int bitBigbinary1 = (i>=0) ? bigBinary1.Tdigits[i] : 0;
        int bitBigBinary2 = (j>=0) ? bigBinary2.Tdigits[j] : 0;
        int somme = bitBigbinary1 + bitBigBinary2 + retenue;
        switch (somme){
            case 0:
                resultat[k] = 0;
                retenue = 0;
                break;
            case 1:
                resultat[k] = 1;
                retenue = 0;
                break;
            case 2:
                resultat[k] = 0;
                retenue = 1;
                break;
            case 3:
                resultat[k] = 1;
                retenue = 1;
                break;
        }
        i--;
        j--;
        k++;
    }
    BigBinary result = createBigBinary(k);
    result.Signe = 1;
    for (int i = 0 ; i < k ; i++) {
        result.Tdigits[i] = resultat[k- i - 1];
    }
    free(resultat);
    return result;
}


int main() {
    BigBinary nb1 = createBigBinary(3);
    nb1.Tdigits[0] = 1;
    nb1.Tdigits[1] = 1;
    nb1.Tdigits[2] = 1;
    nb1.Signe = 1;

    BigBinary nb2 = createBigBinary(3);
    nb2.Tdigits[0] = 1;
    nb2.Tdigits[1] = 0;
    nb2.Tdigits[2] = 0;
    nb2.Signe = 1;

    printf("Binaire 1 : ");
    afficherBigBinary(nb1);

    printf("Binaire 2 : ");
    afficherBigBinary(nb2);

    BigBinary resultat = soustractionBigBinary(nb1, nb2);

    printf("\nRésultat : ");
    afficherBigBinary(resultat);

    free(nb1.Tdigits);
    free(nb2.Tdigits);
    free(resultat.Tdigits);

    return 0;
}

