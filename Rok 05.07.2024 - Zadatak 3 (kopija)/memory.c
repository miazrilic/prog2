/*
Funkcija allocateMemory() dinamički zauzima memoriju s calloc() funkcijom, za argumente prima broj elemenata koje mora zauzeti i broj bajtova koliko jedan element zauzima. 
Funkcija vraća zauzetu memorijsku adresu. 

Funkcija strDuplicate() dinamički zauzima precizno broj bajtova za novi string i još uzima u obzir jedno mjesto više za terminirajući null znak. 
Na kraju kopira sadržaj starog stringa u novo zauzeti. 
Za argumente prima memorijsku adresu gdje stari string počinje, a vraća memorijsku adresu gdje novi string počinje.

Funkcija freeMemory() oslobađa dinamički zauzetu memoriju. 
Za argument prima memorijsku adresu s hrpe pomoću dvostrukog pokazivača, unutar sebe oslobađa memoriju i 
postavlja prosljeđeni pokazivač na NULL memorijsku adresu te onemogućila da pokazivač bude viseći pokazivač nakon oslobađanja memorije.

Funkcija deallocateMemory() oslobađa svu dinamički zauzetu memoriju unutar računa, pozivajući funkciju freeMemory(). 
Za argument prima adresu računa s hrpe i ništa ne vraća.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file_type.h"/////

void* allocateMemory(size_t nItems, size_t size) {
    void *ptr = calloc(nItems, size);/////
    if (ptr == NULL) {
        perror("Error allocating memory");
        exit(EXIT_FAILURE);
    }
    return ptr;/////
}

char* strDuplicate(const char* str) {
    size_t length = strlen(str) + 1;/////
    char* newStr = allocateMemory(length, sizeof(char));/////
    if (strcpy(newStr, str)/*/////*/ == newStr) {
        printf("String %s copied\n", newStr);
    }
    return newStr;/////
}

static void freeMemory(void** ptr) {
    if (ptr != NULL && *ptr != NULL) {
        *ptr = NULL;/////
        free(*ptr);/////
    }    
}

void deallocateMemory(bill_t* bill) {
    int i;
    for (i = 0; i < bill->itemNumber; i++) {
        freeMemory((void*)&bill->items[i].name);/////
        if (bill->items[i].name == NULL) {
            printf("%d. item name deallocated\n", i + 1);
        }
    }
    freeMemory((void*)&bill->items);/////
        if (bill->items == NULL) {
            printf("Items deallocated\n");
        }
    freeMemory((void*)&bill->buyer);/////
        if (bill->buyer == NULL) {
            printf("Buyer name deallocated\n");
        }
    freeMemory((void*)&bill->seller);/////
        if (bill->seller == NULL) {
            printf("Seller name deallocated\n");
        }
    freeMemory((void*)&bill);/////
        if (bill == NULL) {
            printf("Bill deallocated\n");
        }
}
/*
freeMemory((void*)&bill->seller);
freeMemory((void*)&bill);
strlen(str) + 1;
allocateMemory(length, sizeof(char));
strcpy(newStr, str)
freeMemory((void*)&bill->items);
free(*ptr);
freeMemory((void*)&bill->buyer);
return newStr;
freeMemory((void*)&bill->items[i].name);
#include "file_type.h"
calloc(nItems, size);
*ptr = NULL;
return ptr;
*/