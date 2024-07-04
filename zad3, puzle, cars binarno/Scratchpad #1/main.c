/*
-----------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------------
Potrebno je napisati C program u kojemu se kreira jednostruki povezani popis do uključujući 
10 struktura, a sadržaj se učitava u članove strukture iz binarne datoteke cars.dat.

Dana je struktura koja opisuje automobil:

typedef struct car {
	char brend[20];
	char model[20];
	int horsePower;
	float maxSpeed;
	int price;
	struct car* nextCar;
}CAR;
-----------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------------
Članove strukture brend, model, horsePower, maxSpeed, price potrebno je dohvatiti iz datoteke
cars.dat, redoslijedom kako je navedeno redom.
Datoteka je cijelo vrijeme otvorena u svim datotekama izvornog kôda u načinu rada za čitanje.

Datoteka ima oblik:
 _____ ______ ____ ______ _______ ___ ___ ___ ___ ___ _______ ______________ ___ ______ ______
|     |      |    |      |       |   |   |   |   |   |       |              |   |      |      |
|Rimac|Nevera|1914|415.21|1940000|...|...|...|...|...|Porsche|Taycan Turbo S|761|260.71|159663|
|_____|______|____|______|_______|___|___|___|___|___|_______|______________|___|______|______|
-----------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------------
Funkcija koju treba implementirati do kraja je static void readFromFile(CAR*);
Dopuniti kôd za čitanje članova strukture iz binarne datoteke.
-----------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------------
Funkcija koju treba implementirati do kraja je CAR* minPriceByHp(CAR*);
Funkcija treba izračunati za svaki automobil najmanju cijenu po jednoj konjskoj snazi.
Nakon toga vratiti memorijsku adresu automobila koji ima najmanju cijenu po jednoj konjskoj
snazi.
-----------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------------
Funkcija koju treba implementirati do kraja je void printCar(CAR*);
Dopuniti kôd za ispis članova strukture.
-----------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------------
Unutar funkcije createCarList() potrebno je pozvati funkciju readFromFile(CAR*) na pravom 
mjestu s ispravnim argumentom kako bi se pročitali članovi strukture iz binarne datoteke u 
članove trenutne strukture.
-----------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------------
Unutar funkcije insertCarToList() potrebno je pozvati funkciju readFromFile(CAR*) na pravom 
mjestu s ispravnim argumentom kako bi se pročitali članovi strukture iz binarne datoteke u 
članove trenutne strukture.
-----------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------------
Unutar funkcije printCarList() dopuniti kôd za ispis članova strukture i napisati ispravnu
varijablu koju funkcija mora vratiti.
-----------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------------
Unutar funkcije deleteCarFromList() potrebno je pozvati funkciju freeUpSpace(CAR*) na pravom 
mjestu s ispravnim argumentom kako bi se oslobodila memorija.
-----------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------------
Unutar funkcije deleteWholeCarList() potrebno je pozvati funkciju freeUpSpace(CAR*) na pravom 
mjestu s ispravnim argumentom kako bi se oslobodila memorija.
-----------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------------
*/

#include <stdio.h>
#include "type.h"
#include "functions.h"

FILE* stream = NULL;

int main(void) {
    
    printf("REZULTATI:\n");

	stream = fopen("cars.dat", "rb");

	if (stream == NULL) {
		perror("Opening stream");
		return -1;
	}
	else {
		printf("Stream successfully opened!\n");
	}

	CAR* carList = createCarList();

	if (carList == NULL) {
		perror("No car list");
		return -1;
	}
	else {
		printf("Car list successfully created!\n");
	}
	printf("\nNumber of cars in list: %d\n-----------------------\n", printCarList(carList));
	int i;
	int numberOfCars;
	
	scanf("%d", &numberOfCars);
	
	for (i = 0; i < numberOfCars; i++)
	{
		carList = insertCarToList(carList);
	}
	printf("\nNumber of cars in list: %d\n-----------------------\n", printCarList(carList));

    CAR* carForDeleting = minPriceByHp(carList);
	printCar(carForDeleting);
	int successe = deleteCarFromList(&carList, carForDeleting);

	printf("Delete car success: %s\n", successe < 0 ? "false" : "true");
	printf("\nNumber of cars in list: %d\n-----------------------\n", printCarList(carList));
	
	carList = deleteWholeCarList(carList);

	if (fclose(stream) == 0) {
		printf("Stream successfully closed!\n");
	}

	return 0;
}