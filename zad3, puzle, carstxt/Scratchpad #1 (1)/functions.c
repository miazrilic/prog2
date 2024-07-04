#include <stdio.h>
#include <stdlib.h>
#include "type.h"
/*
Funkcija koju treba implementirati do kraja je static void readFromFile(CAR*);
Dopuniti kĂ´d za ÄŤitanje ÄŤlanova strukture iz tekstualne datoteke.
-----------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------------
Funkcija koju treba implementirati do kraja je CAR* maxPriceByHp(CAR*);
Funkcija treba izraÄŤunati za svaki automobil najveÄ‡u cijenu po jednoj konjskoj snazi.
Nakon toga vratiti memorijsku adresu automobila koji ima najveÄ‡u cijenu po jednoj konjskoj
snazi.
-----------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------------
Funkcija koju treba implementirati do kraja je void printCar(CAR*);
Dopuniti kĂ´d za ispis ÄŤlanova strukture.
-----------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------------
Unutar funkcije createCarList() potrebno je pozvati funkciju readFromFile(CAR*) na pravom 
mjestu s ispravnim argumentom kako bi se proÄŤitali ÄŤlanovi strukture iz tekstualne datoteke u 
ÄŤlanove trenutne strukture.
-----------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------------
Unutar funkcije insertCarToList() potrebno je pozvati funkciju readFromFile(CAR*) na pravom 
mjestu s ispravnim argumentom kako bi se proÄŤitali ÄŤlanovi strukture iz tekstualne datoteke u 
ÄŤlanove trenutne strukture.
-----------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------------
Unutar funkcije printCarList() dopuniti kĂ´d za ispis ÄŤlanova strukture i napisati ispravnu
varijablu koju funkcija mora vratiti.
-----------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------------
Unutar funkcije deleteCarFromList() potrebno je pozvati funkciju freeUpSpace(CAR*) na pravom 
mjestu s ispravnim argumentom kako bi se oslobodila memorija.
-----------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------------
Unutar funkcije deleteWholeCarList() potrebno je pozvati funkciju freeUpSpace(CAR*) na pravom 
mjestu s ispravnim argumentom kako bi se oslobodila memorija.
*/
extern FILE* stream; //tok podataka otvoren prema datoteci cars.txt

static void freeUpSpace(void* memoryToBeFree) {

	free(memoryToBeFree);/////////////////// !!!!!!!!!
	printf("Memory successfully freed!\n");
}

static void readFromFile(CAR* carNode) {

	if (carNode == NULL) {
		printf("No car list to read from!\n");
		exit(EXIT_FAILURE);
	}

	fscanf(stream, "%19s", carNode->brend);////////////////////
	fscanf(stream, "%19s", carNode->model);////////////////////
	fscanf(stream, "%d", &carNode->horsePower);////////////////////
	fscanf(stream, "%f", &carNode->maxSpeed);////////////////////
	fscanf(stream, "%d", &carNode->price);////////////////////
}

CAR* maxPriceByHp(CAR* carNode) {

	if (carNode == NULL) {
		printf("No car list to search from!\n");
		return NULL;
	}

	float prevPrice = 0.0f; //predhodna provjera omjera cijene i konjskih snaga
	float currPrice = 0.0f; //trenutna provjera omjera cijene i konjskih snaga
	CAR* traverseCars = carNode;
	CAR* maxPriceCar = NULL;

	prevPrice = (float)traverseCars->price / traverseCars->horsePower;
	maxPriceCar = traverseCars;
	traverseCars = traverseCars->nextCar;

	while (traverseCars) {
		
		/*
		Napisati kĂ´d za izraÄŤun omjera cijene i KS trenutno dohvaÄ‡enog automobila,
		napraviti usporedbu s predhodno izraÄŤunatom, ako je istina aĹľurirati i 
		zapamtiti automobil
		*/
		currPrice = (float) traverseCars->price / traverseCars->horsePower;///////////////////////////////// !!!!!!!!
		if(currPrice > prevPrice){
			maxPriceCar = traverseCars;
			prevPrice = currPrice;
		}
		traverseCars = traverseCars->nextCar;
	}

	return maxPriceCar; ////////////////// 1111111111111
}

void printCar(CAR* carNode) {

	if (carNode == NULL) {
		printf("No car to print!\n");
		exit(EXIT_FAILURE);
	}

	printf("\nCar to be deleted\n-----------------\nbrend: %s\nmodel: %s\nhorse power: %d\nmax speed: %.2f\nprice: %ld\n\n",
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

	while (traverseCars) {   ////////////
		printf("\nbrend: %s\nmodel: %s\nhorse power: %d\nmax speed: %.2f\nprice: %ld\n",
			traverseCars->brend, traverseCars->model, traverseCars->horsePower, traverseCars->maxSpeed, traverseCars->price
		);
		
		traverseCars = traverseCars->nextCar;/////////////////////////// !!!!!!!!!!!
		countCars++;
	}

	return countCars; // Koju varijablu vraÄ‡amo?
}

CAR* createCarList(void) {

	CAR* headNode = (CAR*)calloc(1, sizeof(CAR));

	if (headNode == NULL) {
		perror("Create head node");
		return NULL;
	}

	readFromFile(headNode);/////////////////////
	headNode->nextCar = NULL;//////////////////// !!!!
	return headNode;
}

CAR* insertCarToList(CAR* headNode) {

	CAR* newHeadNode = (CAR*)calloc(1, sizeof(CAR));

	if (newHeadNode == NULL) {
		perror("Create new head node");
		return headNode;
	}


	readFromFile(newHeadNode);/////////////////////mozda obrnuto
	newHeadNode->nextCar = headNode;////////////////////  !!!

	return newHeadNode;
}

int deleteCarFromList(CAR** headNode, CAR* carToDelete) {

	if (carToDelete == NULL) {
		return -1;
	}

	if (*headNode == carToDelete) {
		*headNode = (*headNode)->nextCar;
		freeUpSpace(carToDelete);/////////////////////////////////////		!!!
		return 1;
	}

	CAR* traverseCars;

	for (traverseCars = (*headNode);traverseCars->nextCar; traverseCars = traverseCars->nextCar) {  

		if (traverseCars->nextCar == carToDelete) {
			traverseCars->nextCar = carToDelete->nextCar;
		    // Osloboditi memoriju, koju funkciju pozivamo?
			freeUpSpace(carToDelete);////////////////////////////// 111
			return 1;
		}
	}

	return -1;
}

CAR* deleteWholeCarList(CAR* traverseCars) {

	while(traverseCars) {

		CAR* deleteNode = traverseCars;

		traverseCars = traverseCars->nextCar;

		freeUpSpace(deleteNode);//////////////////////////////////////////// 1111
	}

	return NULL;
}

/*
currPrice > prevPrice
fscanf(stream, "%d", &carNode->price);
carNode == NULL
headNode->nextCar = NULL;
fscanf(stream, "%d", &carNode->horsePower);
readFromFile(headNode);
traverseCars = traverseCars->nextCar;
traverseCars = (*headNode);traverseCars->nextCar; 
traverseCars = traverseCars->nextCar
fscanf(stream, "%19s", carNode->brend);
fscanf(stream, "%f", &carNode->maxSpeed);
freeUpSpace(carToDelete);
freeUpSpace(deleteNode);
free(memoryToBeFree);
currPrice = (float) traverseCars->price / traverseCars->horsePower;
freeUpSpace(carToDelete);
newHeadNode->nextCar = headNode;
readFromFile(newHeadNode);
fscanf(stream, "%19s", carNode->model);
traverseCars
return maxPriceCar; 
*/