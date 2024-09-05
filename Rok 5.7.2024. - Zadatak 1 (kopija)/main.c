/* Strukture su deklarirane te ih ne trebate mijenjati već samo koristiti u svom programu.

Tijek programa je slijedeći:
 - administrator unosi sve podatke za jednog pacijenta (ime pacijenta, datum pregleda, dijagnoza i ime liječnika)
 - nakon toga, administrator bira želi li upisati još jednog pacijenta. 
 - Ako unese na tipkovnici 'y', onda unosi podatke za novog pacijenta. Za bilo koji drugi unos, prekida se unos pacijenata.
 - administrator može unositi jednog po jednog pacijenta. Administrator može unijeti maksimalno 4 pacijenta 
 - po završetku unosa ispisati poruku o broju pacijenata, ispis svih upisanih datuma.

NAPOMENA: za potrebe pregledavanja rješenja, ista će se evaluirati nakon ispita dodatnim test case-om.

1 primjer test case-a:

Marko Maric
12.12.2024.
astma
dr. Josip
y
Josip Josić
11.11.2024.
upala uha
dr. Kruno
n


REZULTATI:
Ukupan broj unesenih pacijenata: 2
Datumi svih pregleda:
12.12.2024.
11.11.2024.




	*/
	
#include <stdio.h>
#include "Moj_header.h"



    
  
    
   int main() {
       struct Pacijent pacijenti[4];
       int i;
       int brojPacijenata=0;
       char charY;
       for(i=0;i<4;i++){
           unosPacijenta(&pacijenti[i]);
           brojPacijenata++;
           getchar();
           scanf("%c\n",&charY);
           if(charY!='y' ){
               break;
           }
       }
    
printf("REZULTATI:\n");
if(brojPacijenata==4){
    printf("Dosegnut je maksimalan broj pacijenata.\n");
}
printf("Ukupan broj unesenih pacijenata: %d\n",brojPacijenata);
printf("Datumi svih pregleda:\n");
for(i=0;i<brojPacijenata;i++){
    printf("%s\n",pacijenti[i].pregled.datumPregleda);
}


    return 0;
}


   