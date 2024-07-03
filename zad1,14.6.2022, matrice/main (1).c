
/* Napišite funkciju sumaIznadSporedne() kojoj cete predati pokazivac na matricu M. 
Funkcija treba vratiti sumu elemenata iznad sporedne dijagonale:

Primjer:
M= -1 1 2 3 
   5 4 7 6
   8 9 10 11
   13 12 15 14
REZULTATI:
19

Funkciju alokacija() je napisana, te joj je zadatak dinamicki alocirati memoriju za matricu. Vratiti adresu kreirane matrice.

Funkciju unos_elemenata() treba napisati, te joj je zadatak unijeti vrijednosti elemenata matrice s tipkovnice tako da na pozicijama 
gdje je suma indeksa retka i stupca (i+j) parna, vrijednost također treba biti parna, u suprotnom neparna. Nula (0) nije ni parna ni neparna
te na tim sumama indeksa (0+0) vrijednost treba biti negativan broj.

Funkciju print() je napisana te joj je cilj ispisati  matricu na ekran u matricnom obliku. Funkcija ne vraca nikakvu vrijednost.

Funkciju Oslobadjanje() je napisana, te joj je zadatak osloboditi alociranu memoriju matrice.

Funkciju main() je napisana. Ucitava se dimenzija matrice M s tipkovnice. Pomocu definiranih funkcija, alocira se memorija za 
matricu M i unose se elementi matrice M s tipkovnice, te se ispisuje unesena matrica.
Nakon "REZULTATI:\n" ispisuje se rezultat funkcije sumaIznadSporedne().*/

#include<stdio.h>
#include<stdlib.h>
#include "header.h"


int main()
{
    int n,m;
    MATRICA *M, *B;
    scanf("%d",&n);
    
    M=alokacija(n);
    unos_elemenata(M);
    printf("Unesena matrica je:\n");
    print(M);
    printf("REZULTATI:\n");
    printf("%d", sumaIznadSporedne(M));
    M=Oslobadjanje(M);
    
    return 0;
}