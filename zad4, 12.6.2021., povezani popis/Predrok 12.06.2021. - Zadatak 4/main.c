/*Napisati C program koji koristi jednostruko povezani popis za strukturu COVID. 
Struktura ima pokazivace na ime,  prezime i pokazivac na strukturu DETALJI,
koja ima clanove: broj kontakata, ocjena razine simptoma [od 1 do 10], cijepljeni [da - 1, ne - 0].
Napisati funkcije za kreiranje povezanog popisa, umetanje novog clana na pocetak popisa,
pretraživanje popisa po broju kontakta, ispis popisa.

Napisati funkciju unosOsobe() koja ima pokazivac na strukturu COVID s kojom se unose podaci u clanove strukture.
Napisati funkciju ispisOsobe() koja ispiuje sve osobe.
Napisati funkciju PretragaPopisa() za pretrazivanje popisa
koji ima zeljeni broj kontakta. 
Napisati funkciju IspisZeljeneOsobe() koja ce ispisivati nadjenu osobu u popisu.
Napisati funkciju OslobadjanjeOsoba() koja oslobađa dinamički zauzetu memoriju
za povezani popis.

U potpunosti rukovati memorijom.
*/


#include <stdio.h>
#include "Functions.h"

int main() {

	int n,i, x;

	COVID* headNode = NULL;
	COVID* OsobaKontakt = NULL;
	
	
	printf("Koliko osoba zelis upisati u registar COVID osoba?\n");
	scanf("%d", &n);
	
    headNode = kreiranjeListe();

	 for (i = 0; i < n - 1; i++)
 	 {
 	 	headNode = ubaciNoviCvor(headNode);
 	 }

	 
 	 	IspisOsobe(headNode);
 	 	printf("Osoba s koliko kontakta?\n");  
	    scanf("%d", &x);
 	 	OsobaKontakt = PretragaPopisa(headNode, x); 
 	 	IspisZeljeneOsobe(OsobaKontakt);
 	 	printf("REZULTATI:\n");
 	 	if (OsobaKontakt == NULL) {
		printf("Osoba s toliko kontakata nije pronadjena!");   
	        }
 	 	else IspisZeljeneOsobe(OsobaKontakt);
 	 
 	 
        headNode = OslobadjanjeOsoba(headNode);
		if (headNode == NULL)
			printf("Oslobodjen cvor!\n");
    
	
	
	




	return 0;
}