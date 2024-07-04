#include <stdio.h>
#include <stdlib.h>
#include "type.h"
/*
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
extern FILE* stream; //tok podataka otvoren prema datoteci cars.dat

static void freeUpSpace(void* memoryToBeFree) {

	free(memoryToBeFree);///////////////////  !!!!!!!!!!!!!!!!!
	printf("Memory successfully freed!\n");
}

static void readFromFile(CAR* carNode) {

	if (carNode == NULL/*//////////*/) {  //!!!!!!!!!!!!!!!!!!!
		printf("No car list to read from!\n");
		exit(EXIT_FAILURE);
	}

	fread(carNode, sizeof(CAR) - sizeof(CAR*), 1, stream);/////////////////////////////  !!!!!!!!!!!
}

CAR* minPriceByHp(CAR* carNode) {

	if (carNode == NULL/*/////////////*/) {       //!!!!!!!!!!!!
		printf("No car list to search from!\n");
		return NULL;
	}

	float prevPrice = 0.0f; //predhodna provjera omjera cijene i konjskih snaga
	float currPrice = 0.0f; //trenutna provjera omjera cijene i konjskih snaga
	CAR* traverseCars = carNode;
	CAR* minPriceCar = NULL;

	prevPrice = (float) traverseCars->price / traverseCars->horsePower;
	minPriceCar = traverseCars;
	traverseCars = traverseCars->nextCar;

	while (traverseCars) {
		
		/*
		Napisati kĂ´d za izraÄŤun omjera cijene i KS trenutno dohvaÄ‡enog automobila,
		napraviti usporedbu s predhodno izraÄŤunatom, ako je istina aĹľurirati i 
		zapamtiti automobil
		*/
		currPrice = (float) traverseCars->price / traverseCars->horsePower;////////////////////////////////////////////
		if(currPrice < prevPrice){
			minPriceCar = traverseCars;
			prevPrice = currPrice;
		}
		traverseCars = traverseCars->nextCar;//////////////////
	}

	return minPriceCar;////////////////////
}
//return minPriceCar;
//currPrice = (float) traverseCars->price / traverseCars->horsePower;
//traverseCars = traverseCars->nextCar;
void printCar(CAR* carNode) {

	if (carNode == NULL/*/////////////*/) {    //!!!!!!!!!!!!!!!
		printf("No car to print!\n");
		exit(EXIT_FAILURE);
	}

	printf("\nCar to be deleted\n-----------------\nbrend: %s\nmodel: %s\nhorse power: %d\nmax speed: %.2f\nprice: %ld\n\n",
	// Ispravno spariti ÄŤlanove strutkura s oznakama pretvorbe unutar stringa
		carNode->brend, carNode->model, carNode->horsePower, carNode->maxSpeed, carNode->price
	);
	
}

int printCarList(CAR* carNode) {

	if (carNode == NULL) {
		printf("No car list to print from!\n");
		exit(EXIT_FAILURE);
	}

	int countCars = 0;
	CAR* traverseCars = carNode;

	printf("\nCars in list\n------------");

	while (traverseCars) {
		printf("\nbrend: %s\nmodel: %s\nhorse power: %d\nmax speed: %.2f\nprice: %ld\n",
		// Ispravno spariti ÄŤlanove strutkura s oznakama pretvorbe unutar stringa
			traverseCars->brend, traverseCars->model, traverseCars->horsePower, traverseCars->maxSpeed, traverseCars->price
		);
		
        countCars++;///////////////////////////
		traverseCars = traverseCars->nextCar;//////////////////////////  !!!!!!!!!!
	}

	return countCars; // Koju varijablu vraÄ‡amo?
}

CAR* createCarList(void) {

	CAR* headNode = (CAR*)calloc(1, sizeof(CAR));

	if (headNode == NULL) {
		perror("Create head node");
		return NULL;
	}

	readFromFile(headNode);////////////////////////
	headNode->nextCar = NULL;

	return headNode;
}

CAR* insertCarToList(CAR* headNode) {

	CAR* newHeadNode = (CAR*)calloc(1, sizeof(CAR));

	if (newHeadNode == NULL) {
		perror("Create new head node");
		return headNode;
	}

	// ProÄŤitati sadrĹľaj iz datoteke, koju funkciju pozivamo?
	readFromFile(newHeadNode);///////////////////////
	newHeadNode->nextCar = headNode;
	
	return newHeadNode;
}

int deleteCarFromList(CAR** headNode, CAR* carToDelete) {

	if (carToDelete == NULL) {
		return -1;
	}

	if (*headNode == carToDelete) {
		*headNode = (*headNode)->nextCar;
		freeUpSpace(carToDelete);////////////////////// !!!!!!!!!!!!!
		return 1;
	}

	CAR* traverseCars;

	for (traverseCars = (*headNode); traverseCars->nextCar; traverseCars = traverseCars->nextCar) {

		if (traverseCars->nextCar == carToDelete) {
			traverseCars->nextCar = carToDelete->nextCar;
			freeUpSpace(carToDelete);////////////////////////   !!!!!!!!!!1
			return 1;
		}
	}

	return -1;
}

CAR* deleteWholeCarList(CAR* traverseCars) {

	while(traverseCars) {

		CAR* deleteNode = traverseCars;

		traverseCars = traverseCars->nextCar;

		freeUpSpace(deleteNode);/////////////////////////// !!!!!
	}

	return NULL;//////////////////////////////  !!!
}


/*
carNode == NULL
freeUpSpace(carToDelete);
return minPriceCar;
free(memoryToBeFree);
currPrice = (float) traverseCars->price / traverseCars->horsePower;
traverseCars = traverseCars->nextCar;
return NULL;
carNode == NULL
freeUpSpace(carToDelete);
readFromFile(newHeadNode);
carNode == NULL
readFromFile(headNode);
traverseCars = traverseCars->nextCar;
countCars++;
freeUpSpace(deleteNode);
currPrice < prevPrice
fread(carNode, sizeof(CAR) - sizeof(CAR*), 1, stream);
*/