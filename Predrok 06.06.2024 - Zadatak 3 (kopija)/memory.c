/*
Funkcija allocateMemory() dinamički zauzima memoriju s calloc() funkcijom, za argumente prima broj elemenata koje mora zauzeti i broj bajtova koliko jedan element zauzima. Funkcija vraća zauzetu memorijsku adresu. 
Funkcija strDuplicate() dinamički zauzima precizno broj bajtova za novi string i još uzima u obzir jedno mjesto više za terminirajući null znak. Na kraju kopira sadržaj starog stringa u novo zauzeti. Za argumente prima memorijsku adresu gdje stari string počinje, a vraća memorijsku adresu gdje novi string počinje.
Funkcija freeMemory() oslobađa dinamički zauzetu memoriju. Za argument prima memorijsku adresu s hrpe, a vraća NULL memorijsku adresu kako bi pokazivač postavila na tu vrijednost i onemogućila da pokazivač bude viseći pokazivač nakon oslobađanja memorije.
Funkcija deallocateMemory() oslobađa svu dinamički zauzetu memoriju unutar računa, pozivajući funkciju freeMemory(). Za argument prima adresu računa s hrpe i ništa ne vraća.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file_type.h"

void* allocateMemory(size_t nItems, size_t size) {
    void *ptr = calloc(nItems, size);/////               !
    if (ptr == NULL) {
        perror("Error allocating memory");
        exit(EXIT_FAILURE);
    }
    return ptr;/////                   !
}

char* strDuplicate(const char* str) {
    size_t length = strlen(str) + 1;/////                           <-
    char* newStr = allocateMemory(length, sizeof(char));/////         <-           


    if (strcpy(newStr, str)/*/////*/ == newStr) {                        <-
        printf("String %s copied\n", newStr);
    }
    return newStr;/////                      !
}

static void* freeMemory(void* ptr) {
    if (ptr != NULL) {
        free(ptr);/////               !
    }
   return NULL; /////               !
}

void deallocateMemory(bill_t* bill) {
    int i;
    for (i = 0; i < bill->itemNumber; i++) {
        bill->items[i].name = freeMemory(bill->items[i].name);/////    !
        if (bill->items[i].name == NULL) {
            printf("%d. item name deallocated\n", i + 1);
        }
    }
    bill->items = freeMemory(bill->items);/////                  !
        if (bill->items == NULL) {
            printf("Items deallocated\n");
        }
    bill->buyer = freeMemory(bill->buyer);/////        !
        if (bill->buyer == NULL) {
            printf("Buyer name deallocated\n");
        }
    bill->seller = freeMemory(bill->seller);/////           !
        if (bill->seller == NULL) {
            printf("Seller name deallocated\n");
        }
    bill = freeMemory(bill);/////                  !
        if (bill == NULL) {
            printf("Bill deallocated\n");
        }
}

/*
/////////////////////////////////freeMemory(bill->seller);
///////////////////////////77return NULL;
////////////////////////freeMemory(bill);
strlen(str) + 1;
allocateMemory(length, sizeof(char));
strcpy(newStr, str)
//////////////////////////////////////freeMemory(bill->items);
//////////////////////////////////////////free(ptr);
//////////////////////////////////freeMemory(bill->buyer);
/////////////////////////////////return newStr;
freeMemory(bill->items[i].name);
//////////////////////////////////////calloc(nItems, size);
////////////////////////////////////return ptr;
*/
