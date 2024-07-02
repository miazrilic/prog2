/* Strukture su deklarirane te ih ne trebate mijenjati već samo koristiti u svom programu.

Tijek programa je slijedeći:
 - korisnik unosi sve podatke za jednu aktivnost (lokaciju, datum, opis i cijenu)
 - nakon toga, korisnik bira da li želi unijeti još jednu aktivnost. 
 - Ako unese na tipkovnici 'y', onda unosi podatke za novu aktivnost. Za bilo koji drugi unos, prekida se unos aktivnosti.
 - korisnik može unijeti maksimalno 10 aktivnosti
 - po završetku unosa ispisati poruku o broju aktivnosti i ukupnom budgetu za njih u obliku:

	REZULTATI:  
    Broj aktivnosti je: 3
    Potrositi cu: 20.34 eura
    
    Primjer test case-a:
        Vodice
        30.06.2024.
        Koncert omiljenog benda
        50.74
        y
        Vodice
        1.7.2024.
        Rent a boat
        100.50
        n
        REZULTATI:
        Broj aktivnosti je: 2
        Potrositi cu: 151.24 eura/

    */
    
#include <stdio.h>
#include <string.h>

#define MAX_ACTIVITIES 10
#define MAX_LOCATION_LENGTH 50


struct Activity {
    char location[MAX_LOCATION_LENGTH];
    char date[11]; 
    char description[100];
    float budget;  
};

struct SummerHoliday {
    struct Activity activities[MAX_ACTIVITIES];
    int numActivities;
};


int main(){
        float totalBudget=0;
        char charY;
    struct SummerHoliday holiday;
    holiday.numActivities=0;
    
    do{
        if(holiday.numActivities>=MAX_ACTIVITIES){
            break;
        }
        getchar();
        scanf(" %[^\n]",holiday.activities[holiday.numActivities].location);
        getchar();
        scanf(" %[^\n]",holiday.activities[holiday.numActivities].date);
        getchar();
        scanf(" %[^\n]",holiday.activities[holiday.numActivities].description);
        
        scanf("%f", &holiday.activities[holiday.numActivities].budget);
        totalBudget+=holiday.activities[holiday.numActivities].budget;
        holiday.numActivities++;
        getchar();
        scanf("%c", &charY);
        
    }while(charY=='y');
    printf("REZULTATI:\n");
    printf("Broj aktivnosti je: %d\n",holiday.numActivities);
    printf("Potrositi cu: %.2f eura",totalBudget);
    return 0;
}
