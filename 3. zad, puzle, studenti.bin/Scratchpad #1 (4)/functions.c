#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

extern FILE* stream;

/*
Podatkovni član id, kao ime i prezime studenta potrebno je dohvatiti iz datoteke studenti.dat.
Datoteka je cijelo vrijeme otvorena u načinu rada za čitanje.
Uzeti u obzir kako je potrebno dinamicki zauzeti memorijski prostor za ime i prezime u smislu
da se zauzme posebno prostora koliko je dugačko ime i posebno koliko je dugačko prezime,
računajte i dodatno za jendo mjesto za terminirajući znak na kraju stringa.
-----------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------------
Informacije o studentima se nalaze u binarnoj datoteci studenti.dat.
Datoteka ima oblik:
 ___ ______________ _____________________________________________________________________________
|   |     |        |   |     |     |   |       |        |   |      |         |   |      |        |
|125|Matko|Perkovic|222|Vanja|Matic|356|Zdravko|Matkovic|444|Zdenko|Saravanja|543|Sinisa|Vuckovic|
|___|_____|________|___|_____|_____|___|_______|________|___|______|_________|___|______|________|

Napisati funkciju readId(), pomoću koje se dohvati id studenta. Funkcija ne vraća vrijednost,
a za argument prima memorijsku adresu studenta.
Napisati funkciju readName(), pomocu koje se treba dohvatiti ime i prezime studenta.
Funkcija readName() ne vraća vrijednost, a za argument prima memorijsku adresu studenta.
Napisati pomoćnu funkciju allocateString() čija je jedina zadaća dinamički zauzeti meoriju za
string određene duljine, te vratiti referencu na zauzeti dio memorije.
Funkcija allocaeString() za argument prima ukupan broj elemenata plus jedan više za '\0', a
vraća memorijsku adresu početka uspješno zauzetog polja znakova.
*/

static void readId(STUDENT* node) {
	fread(&(node->id), sizeof(int), 1, stream);////////////////////////
}

static char* allocateString(int n) {

	// dovrĹˇiti implemenetaciju
	char* tmp = (char*) calloc (n, sizeof(char));//////////////////// !!!
	if (tmp == NULL) {
		perror("Creating field for name");
		return NULL;
	}
	else {
		printf("Memory successfully allocated!\n");
	}

	return tmp;////////////////////////// !!!
}

static void readName(STUDENT* node) {

	char tmpField[50] = { 0 };/////////////////////// !!!

	// dohvatiti ime u privremeno polje
	fread(tmpField, sizeof(char), 50, stream);
	node->firstName = allocateString(strlen(tmpField + 1));
	strcpy(node->firstName, tmpField);//////////////////////////// !!!


	// dohvatiti prezime u privremeno polje
	fread(tmpField, sizeof(char), 50, stream);
	node->lastName = allocateString(strlen(tmpField + 1));
    strcpy(node->lastName, tmpField);////////////////////////// !!!
}

/*
Za oslobaÄ‘anje memorije od bilo kojeg tipa podatka za koji se dinamiÄŤki zauzela memorija
potrebno je pozvati funkciju freeUpSpace(), koja niĹˇta ne vraÄ‡a, a za argument prima referencu
na dinamiÄŤki zauzetu memoriju.
*/

static void freeUpSpace(void* memoryToBeFree) {

	free(memoryToBeFree);////////////////////////////// !!!
    printf("Memory successfully freed!\n");
}

/*
Potrebno je kreirati jednostruko povezani popis pomoÄ‡u funkcije createStudentList().
Funkcija ne prima argument, a vraÄ‡a memorijsku adresu poÄŤetka popisa.
*/

STUDENT* createStudentList(void) {

	// dovrĹˇiti implementaciju
	STUDENT* headNode = (STUDENT*) calloc (1, sizeof(STUDENT));
	if (headNode == NULL) {
		perror("Create head node");
		return NULL;
	}

	
    readId(headNode);/////////////////////
	readName(headNode);/////////////////////

	headNode->nextStudent = NULL;
	return headNode;
}

/*
Dodati nove studente na pocetak povezano popisa pomoÄ‡u funkcije insertStudentToList().
Funkcija prima memorijsku adresu gdje poÄŤinje povezani popis,
a vraÄ‡a memorijsku adresu novog poÄŤetka povezanog popisa.
*/

STUDENT* insertStudentToList(STUDENT *headNode) {

	// dovrĹˇiti implementaciju
	STUDENT* newHeadNode = (STUDENT*) calloc (1, sizeof(STUDENT));////////////////////////////////// !!!
	if (newHeadNode == NULL) {
		perror("Create new head node");
		return headNode;
	}

	//pozvati funkcije za ÄŤitanje id-a, imena i prezimena
	readId(newHeadNode);
	readName(newHeadNode);
	newHeadNode->nextStudent = headNode;////////////////////////////// !!!
	return newHeadNode;
}

/*
Ispisati informacije o svakom studentu unutar povezanog popisa, ujedno i koliko ima elemenata
u povezanom popisu pomoÄ‡u funkcije printStudentList().
Funkcija vraÄ‡a broj elemenata u povezanom popisu, a prima memorijsku adresu gdje poÄŤinje
povezani popis.
*/

int printStudentList(STUDENT* traverseNode) {

	int counter = 0;

	//dovrsiti implementaciju
	if (traverseNode == NULL) {
        return -1;
    }
    else {
        while (traverseNode) {
            counter++;/////////////// !!!
			printf("ID: %d, %s %s\n", traverseNode->id, traverseNode->firstName, traverseNode->lastName);
            traverseNode = traverseNode->nextStudent;////////////// !!!
        }
    }

	return counter;
}

/*
Izbrisati studenta kojega se prvi puta kreiralo i to tako da ga se potraĹľi preko id-a.
Brisanje studenta implementirati pomoÄ‡u funkcije deleteStudentFromList(), a pretragu studenta
omoguÄ‡iti pomoÄ‡u funkcije searchStudent();
Funkcija deleteStudentFromList() prima memorijsku adresu pokazivaÄŤa unutar kojeg je spremljena
memorijska adresa poÄŤetka povezanog popisa i prima joĹˇ memorijsku adresu studenta koji se treba
obrisati. Funkcija vraÄ‡a 0 ako je uspjeĹˇno odradila posao, a -1 ako je brisanje bilo neuspjeĹˇno
Funkcija searchStudent() prima memorijsku adresu gdje poÄŤinje povezani popis i id studenta,
a vraÄ‡a memorijsku adresu pronaÄ‘enog studenta ili NULL memorijsku adresu u sluÄŤaju da ne moĹľe
pronaÄ‡i studenta.
*/

STUDENT* searchStudent(STUDENT* traverseNode, int id) {

	// dovrĹˇiti implementaciju
	while (traverseNode) {
			if(traverseNode->id == id){
				return traverseNode;////////////// !!!
			}
			traverseNode = traverseNode->nextStudent;
		}

	return NULL;
}

int deleteStudentFromList(STUDENT** headNode, STUDENT* student) {

	if (student == NULL) {
		return -1;
	}

	// dovrĹˇiti implementaciju
	if (*headNode == student) {
        *headNode = (*headNode)->nextStudent;/////////////////////
		freeUpSpace(student->firstName);
		freeUpSpace(student->lastName);
        freeUpSpace(student);////////////////////// !!!
		return 0;
    }

	STUDENT* traverseNode;

	for (traverseNode = (*headNode); traverseNode->nextStudent != NULL; traverseNode = traverseNode->nextStudent) {
	// dovrĹˇiti implementaciju
		if (traverseNode->nextStudent == student) {
			traverseNode->nextStudent = student->nextStudent;
			freeUpSpace(student->firstName);////////////////////////// !!!
			freeUpSpace(student->lastName);///////////////////////// !!!
			freeUpSpace(student);///////////////////////// !!!
			return 0;
		}
	}

	return -1;
}

/*
Na kraju je potrebno obrisati cijeli povezani popis pomoÄ‡u funkcije deleteWholeStudentList().
Funkcija prima memorijsku adresu gdje poÄŤinje povezani popis, a vraÄ‡a NULL memorijku adresu
koja se upisuje u pokazivaÄŤ u main()-u.
*/

STUDENT* deleteWholeStudentList(STUDENT* traverseNode) {
	STUDENT* deleteNode = NULL;
	while(traverseNode != NULL){
	// dovrĹˇiti implementaciju	
		deleteNode = traverseNode;
        traverseNode = traverseNode->nextStudent;
		freeUpSpace(deleteNode->firstName);
		freeUpSpace(deleteNode->lastName);
        freeUpSpace(deleteNode);	
	}

	return NULL;
}

/*
counter++;
return traverseNode;
readName(headNode);
freeUpSpace(student);
traverseNode = traverseNode->nextStudent;
*headNode = (*headNode)->nextStudent;
STUDENT* newHeadNode = (STUDENT*) calloc (1, sizeof(STUDENT));
free(memoryToBeFree);
readId(headNode);
(char*) calloc (n, sizeof(char));
traverseNode->id == id
fread(&(node->id), sizeof(int), 1, stream);
return tmp;
strcpy(node->firstName, tmpField);
freeUpSpace(student);
freeUpSpace(student->firstName);
strcpy(node->lastName, tmpField);
char tmpField[50] = { 0 };
newHeadNode->nextStudent = headNode;
freeUpSpace(student->lastName);
*/