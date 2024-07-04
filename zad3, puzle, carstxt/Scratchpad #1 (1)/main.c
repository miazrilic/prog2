/*
-----------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------------
Potrebno je napisati C program u kojemu se kreira jednostruki povezani popis do uključujući 
10 struktura, a sadržaj se učitava u članove strukture iz tekstualne datoteke cars.txt.

Dana je struktura koja opisuje automobil:

typedef struct car {
	char brend[20];
	char model[20];
	int horsePower;
	float maxSpeed;
	long int price;
	struct car* nextCar;
}CAR;
-----------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------------
Članove strukture brend, model, horsePower, maxSpeed, price potrebno je dohvatiti iz datoteke
cars.txt, redoslijedom kako je navedeno redom.
Datoteka je cijelo vrijeme otvorena u svim datotekama izvornog kôda u načinu rada za čitanje.

Datoteka ima oblik:
Porsche TaycanTurboS 761 260.71 159663
...
...
...
...
...
Koenigsegg Regera 1479 402.34 1710000
-----------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------------
Funkcija koju treba implementirati do kraja je static void readFromFile(CAR*);
Dopuniti kôd za čitanje članova strukture iz tekstualne datoteke.
-----------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------------
Funkcija koju treba implementirati do kraja je CAR* maxPriceByHp(CAR*);
Funkcija treba izračunati za svaki automobil najveću cijenu po jednoj konjskoj snazi.
Nakon toga vratiti memorijsku adresu automobila koji ima najveću cijenu po jednoj konjskoj
snazi.
-----------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------------
Funkcija koju treba implementirati do kraja je void printCar(CAR*);
Dopuniti kôd za ispis članova strukture.
-----------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------------
Unutar funkcije createCarList() potrebno je pozvati funkciju readFromFile(CAR*) na pravom 
mjestu s ispravnim argumentom kako bi se pročitali članovi strukture iz tekstualne datoteke u 
članove trenutne strukture.
-----------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------------
Unutar funkcije insertCarToList() potrebno je pozvati funkciju readFromFile(CAR*) na pravom 
mjestu s ispravnim argumentom kako bi se pročitali članovi strukture iz tekstualne datoteke u 
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

	stream = fopen("cars.txt", "r");

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

	int i;
	int numberOfCars;
	
	scanf("%d", &numberOfCars);
	
	for (i = 0; i < numberOfCars; i++)
	{
		carList = insertCarToList(carList);
	}
	printf("\nNumber of cars in list: %d\n-----------------------\n", printCarList(carList));

    CAR* carForDeleting = maxPriceByHp(carList);
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