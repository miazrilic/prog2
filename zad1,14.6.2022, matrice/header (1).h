#ifndef FUNCTIONS_H
#define FUNCTIONS_H

typedef struct matrica{
    int n;
    int** mat;
}MATRICA;

MATRICA* alokacija(int n);
void print(MATRICA* M);
MATRICA* Oslobadjanje(MATRICA* M);

//deklaracija funkcije sumaIznadSporedne() i unos_elemenata()
void unos_elemenata(MATRICA* M);
int sumaIznadSporedne(MATRICA* M);
#endif
