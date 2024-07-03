#include <stdio.h>
#include <stdlib.h>
#include "header.h"


MATRICA *alokacija(int n) {
    int i, j;
    MATRICA *M;

    M = (MATRICA *) malloc(sizeof(MATRICA));
    if (M == NULL) {
        printf("greska alokacije");
        return NULL;
    }

    M->n = n;
    M->mat = (int **) malloc(sizeof(int *) * n);
    if (M->mat == NULL) {
        printf("greska alokacije");
        return NULL;
    }

    for (i = 0; i < n; i++) {
        M->mat[i] = (int *) malloc(sizeof(int) * n);
        if (M->mat[i] == NULL) {
            printf("greska alokacije stupca");
            return NULL;
        }
    }

    return M;
}

void print(MATRICA *M) {
    int i, j;

    for (i = 0; i < M->n; i++) {
        for (j = 0; j < M->n; j++) {
            printf("%d ", M->mat[i][j]);
        }
        printf("\n");
    }
}

MATRICA *Oslobadjanje(MATRICA *M) {
    int i;

    for (i = 0; i < M->n; i++) {
        free(M->mat[i]);
    }

    free(M->mat);
    free(M);

    return NULL;
}

void unos_elemenata(MATRICA *M) {
    int i, j;

    for (i = 0; i < M->n; i++) {
        for (j = 0; j < M->n; j++) {
            if (i + j == 0) {
                do {
                    scanf("%d", &M->mat[i][j]);
                } while (M->mat[i][j] >= 0);
            } else if ((i + j) % 2 == 0) {
                do {
                    scanf("%d", &M->mat[i][j]);
                } while (M->mat[i][j] % 2 != 0);
            } else {
                do {
                    scanf("%d", &M->mat[i][j]);
                } while (M->mat[i][j] == 0);
            }
        }
    }
}

int sumaIznadSporedne(MATRICA *M) {
    int i, j;
    int suma = 0;

    for (i = 0; i < M->n; i++) {
        for (j = 0; j < M->n; j++) {
            if (i + j < M->n - 1) {
                suma += M->mat[i][j];
            }
        }
    }

    return suma;
}

