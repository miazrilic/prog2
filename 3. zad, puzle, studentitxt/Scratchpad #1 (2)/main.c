/*
Potrebno je napisati C program u kojemu se kreira jednostruki povezani popis od 5 elemenata,
s sadržaj koji se učitava članove elemenata se čita iz tekstualne datoteke.

Dana je struktura koja opisuje studenta:

typedef struct student {
	char* firstName;
	char* lastName;
	int id;
	struct student* nextNode;
}STUDENT;
-----------------------------------------------------------------------------------------------
Potrebno je kreirati jednostruko povezani popis pomoću funkcije createStudentList(). 
Funkcija ne prima argument, a vraća memorijsku adresu početka popisa.
-----------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------------
Dodati nove studente na pocetak povezano popisa pomoću funkcije insertStudentToList(). 
Funkcija prima memorijsku adresu gdje počinje povezani popis, 
a vraća memorijsku adresu novog početka povezanog popisa.
-----------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------------
Ispisati informacije o svakom studentu unutar povezanog popisa, ujedno i koliko ima elemenata 
u povezanom popisu pomoću funkcije printStudentList().
Funkcija vraća broj elemenata u povezanom popisu, a prima memorijsku adresu gdje počinje 
povezani popis.
-----------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------------
Izbrisati studenta tako da ga se potraži preko id-a. 
Brisanje studenta implementirati pomoću funkcije deleteStudentFromList(), a pretragu studenta 
omogućiti pomoću funkcije searchStudent();
Funkcija deleteStudentFromList() prima memorijsku adresu pokazivača unutar kojeg je spremljena
memorijska adresa početka povezanog popisa i prima još memorijsku adresu studenta koji se treba
obrisati. Funkcija vraća 0 ako je uspješno odradila posao, a -1 ako je brisanje bilo neuspješno
Funkcija searchStudent() prima memorijsku adresu gdje počinje povezani popis i id studenta,
a vraća memorijsku adresu pronađenog studenta ili NULL memorijsku adresu u slučaju da ne može
pronaći studenta.
-----------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------------
Nakon što se obriše student, potrebno je ponovno ispisati cijeli povezani popis i ispisati 
koliko ima elemenata. 
Na kraju je potrebno obrisati cijeli povezani popis pomoću funkcije deleteWholeStudentList().
Funkcija prima memorijsku adresu gdje počinje povezani popis, a vraća NULL memorijku adresu
koja se upisuje u pokazivač u main()-u. 
-----------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------------
Podatkovni član id, kao ime i prezime studenta potrebno je dohvatiti iz datoteke studenti.txt.
Datoteka je cijelo vrijeme otvorena u načinu rada za čitanje.
Uzeti u obzir kako je potrebno dinamicki zauzeti memorijski prostor za ime i prezime u smislu
da se zauzme posebno prostora koliko je dugačko ime i posebno koliko je dugačko prezime, 
računajte i dodatno za jendo mjesto za terminirajući znak na kraju stringa.
-----------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------------
Napisati funkciju readId(), pomoću koje se dohvati id studenta. Funkcija ne vraća vrijednost, 
a za argument prima memorijsku adresu studenta.
Napisati funkciju readName(), pomocu koje se treba dohvatiti ime i prezime studenta. 
Možete iskoristiti mogućnost što funkcija fscanf() prekida kada se naidje na prazninu i na taj
način dohvatiti posebno ime i prezime.
Funkcija readName() ne vraća vrijednost, a za argument prima memorijsku adresu studenta.
Napisati pomoćnu funkciju allocateString() čija je jedina zadaća dinamički zauzeti meoriju za
string određene duljine, te vratiti referencu na zauzeti dio memorije.
Funkcija allocaeString() za argument prima ukupan broj elemenata plus jedan više za '\0', a
vraća memorijsku adresu početka uspješno zauzetog polja znakova.
*/

#include <stdio.h>
#include "functions.h"

FILE* stream = NULL;

int main(void) {
    
    printf("REZULTATI:\n");

	stream = fopen("studenti.txt", "r");

	if (stream == NULL) {
		perror("Opening stream");
		return -1;
	}else {
		printf("Stream successfully opened!\n");
	}

	STUDENT *studentList = createStudentList();

	if (studentList == NULL) {
		perror("No student list");
		return -1;
	}
	else {
		printf("Student list successfully created!\n");
	}

	int i;
	int numberOfStudents;

	scanf("%d", &numberOfStudents);

	for (i = 0; i < numberOfStudents; i++)
	{
		studentList = insertStudentToList(studentList);
	}
	printf("Number of students in list: %d\n", printStudentList(studentList));

	int idToFind;

	scanf("%d", &idToFind);

	STUDENT* studentForDeleting = searchStudent(studentList, idToFind);
	int successe = deleteStudentFromList(&studentList, studentForDeleting);

	printf("Delete student success: %s\n", successe < 0 ? "false" : "true");
	printf("Number of students in list: %d\n", printStudentList(studentList));

	studentList = deleteWholeStudentList(studentList);
	
	if (fclose(stream) == 0) {
		printf("Stream successfully closed!\n");
	}

	return 0;
}