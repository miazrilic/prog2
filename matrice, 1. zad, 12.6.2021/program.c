/* Napišite funkciju najveci() kojoj cete predati pokazivace na matricu M i matricu B. 
Funkcija treba popuniti novu matricu B cije se elementi trebaju dobiti na sljedeci nacin:
pronaci najveci element u retku matrice M te popuniti redak matrice B sa 
umnoskom sume indeksa retka i stupca nadjenog najveceg elementa retka matrice M  i vrijednosti svakog elementa retka matrice M.
Primjer:
M= 1 6 7
   2 9 5
   8 4 6
B= 2 12 14
   4 18 10
   16 8 12

Funkciju alokacija() je napisana, te joj je zadatak dinamički alocirati memoriju za matricu. Vratiti adresu kreirane matrice.

Funkciju unos_elemenata() je napisana, te joj je zadatak unijeti vrijednosti elemenata matrice s tipkovnice. 

Funkciju print() je napisana te joj je cilj ispisati  matricu na ekran u matricnom obliku. Funkcija ne vraća nikakvu vrijednost.

Funkciju Oslobadjanje() je napisana, te joj je zadatak osloboditi alociranu memoriju matrice.

Funkciju main() je napisana. Ucitava se dimenziju matrice M s tipkovnice. Pomocu definiranih funkcija, alocira se memorija za 
matricu M i unose se elementi matrice M s tipkovnice, te se ispisuje unesena matrica.
Nakon toga se alocira memorija za matricu B i pomocu funkcije najveci() popunjavamo elemente matrice B.
Nakon "REZULTATI:\n" ispisuje se novonastala matrica B.*/

#include<stdio.h>
#include<stdlib.h>
#include "header.h"


int main()
{
    int n,m;
    MATRICA *M, *B;
    scanf("%d",&n);
    scanf("%d",&m);
    
    M=alokacija(n,m);
    unos_elemenata(M);
    print(M);
    printf("REZULTATI:\n");
    B=alokacija(n,m);
    najveci(M,B);
    print(B);
    M=Oslobadjanje(M);
    B=Oslobadjanje(B);
    return 0;
}
