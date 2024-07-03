#include <stdlib.h>
#include<stdio.h>
#include "Functions.h"


void UpisOsobe(COVID* headNode)
{
    headNode->ime = (char*) malloc (50);
    headNode->prezime = (char*) malloc (50);
    headNode->osoba = (DETALJI*) malloc (sizeof(DETALJI));

    if(headNode->ime == NULL || headNode->prezime == NULL || headNode->osoba == NULL){
        exit(EXIT_FAILURE);
    }
    
	printf("Unesi ime:\n");
    getchar();
    scanf("%[^\n]", headNode->ime);

	printf("Unesi prezime:\n");
    getchar();
    scanf("%[^\n]", headNode->prezime);

	printf("Unesi broj kontakata:\n");
    scanf("%d", &headNode->osoba->brKontakti);

	printf("Unesi ocjenu razine simptoma:\n");
    do
    {
        scanf("%d", &headNode->osoba->ocjena);
    } while (!(headNode->osoba->ocjena >= 1 && headNode->osoba->ocjena <= 10));
    
	printf("Cijepljen DA/NE:\n");
    do
    {
        scanf("%d", &headNode->osoba->cijepljeni);
    } while (headNode->osoba->cijepljeni != 0 && headNode->osoba->cijepljeni != 1);
}

void IspisOsobe(COVID* traverseNode){    
    while (traverseNode) {  
            printf("Ime: %s, prezime: %s, broj kontakata: %d, ocjena simptoma: %d, cijepljen/a: %d\n", traverseNode->ime, traverseNode->prezime, traverseNode->osoba->brKontakti, traverseNode->osoba->ocjena, traverseNode->osoba->cijepljeni);
            traverseNode = traverseNode->noviCvor;
    }
}

void IspisZeljeneOsobe(COVID* traverseNode){    
    if (traverseNode)
    {
        printf("Ime: %s, prezime: %s, broj kontakata: %d, ocjena simptoma: %d, cijepljen/a: %d\n", traverseNode->ime, traverseNode->prezime, traverseNode->osoba->brKontakti, traverseNode->osoba->ocjena, traverseNode->osoba->cijepljeni);
    }
}


COVID* kreiranjeListe() {    
	COVID *headNode = (COVID*)calloc(1, sizeof(COVID));
    if (headNode == NULL) {
        perror("Kreiranje");
        return NULL;
    }
    else {
        UpisOsobe(headNode);
        headNode->noviCvor = NULL;
    }
    return headNode;
}


COVID* ubaciNoviCvor(COVID* headNode) {
	COVID *newHeadNode = (COVID*)calloc(1, sizeof(COVID));
    if (newHeadNode == NULL) {
        perror("Kreiranje");
        return headNode;
    }
    else {
        UpisOsobe(newHeadNode);
        newHeadNode->noviCvor = headNode;
    }
    return newHeadNode;
}

COVID* OslobadjanjeOsoba(COVID* glavniCvor)
{
   COVID* tmp = NULL;

    while (glavniCvor) {
        tmp = glavniCvor;
        glavniCvor = glavniCvor->noviCvor;
        free(tmp->osoba);
        free(tmp);
    }
    return NULL;
}

COVID* PretragaPopisa(COVID* headNode, int brojKontakata){	
    if (headNode == NULL) {
        return NULL;
    }
    else {
        while (headNode) {
            if (headNode->osoba->brKontakti == brojKontakata)
            {
                return headNode;
            }            
            headNode = headNode->noviCvor;
        }
    }
    return NULL;
	
}
