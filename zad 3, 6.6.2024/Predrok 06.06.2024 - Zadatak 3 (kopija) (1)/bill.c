
/*
Funkcija readBuyerSeller() čita posebno prodavača i kupca iz datoteke. Za argumente prima tok podataka datoteke iz koje čita informacije i prima memorijsku adresu računa. Funkcija ništa ne vraća.
Funkcija addBillItem() zbraja ukupni iznos računa. Za argument prima memorijsku adresu računa i ništa ne vraća.
Funkcija readItems() dinamički zauzima polje artikala, čita imena artikala kao i njihovu cijenu i količinu. Na kraju funkcije
poziva se funkcija addBillItem(). Funkcija za argumente prima tok podataka datoteke iz koje čita informacije i prima memorijsku adresu računa. Funkcija ništa ne vraća.
Funkcija readBillFromFile() otvara tok podataka prema datoteci i poziva sve funkcije za čitanje te odrađuje sav posao po pitanju 
čitanja kompletnog sadržaja iz datoteke u račun. Funkcija za argumente prima tok podataka datoteke iz koje čita informacije i 
prima memorijsku adresu računa. Funkcija ništa ne vraća.
Funkcija printBill() ispisuje sadržaj računa. Funkcija za argument prima memorijsku adresu računa i ništa ne vraća.
*/


#include <stdio.h>
#include <stdlib.h>
#include "file_type.h"
#include "memory.h"

static void readBuyerSeller(FILE* file, bill_t* bill) {
    char seller[50], buyer[50];
    fscanf(file, "%49[^\n] ", buyer);/////             !
    bill->buyer = strDuplicate(buyer);/////          !
    if (bill->buyer) {
        printf("Buyer allocated\n");
    }
    fscanf(file, "%49[^\n] ", seller);/////           !
    bill->seller = strDuplicate(seller);/////          !
    if (bill->seller) {
        printf("Seller allocated\n");
    }
}

static void addBillItem(bill_t* bill) {
  int i;
  for (i = 0; i < bill->itemNumber; i++) {
    bill->totalPrice += bill->items[i].amount * bill->items[i].price;/////     ! 
  }  
}

static void readItems(FILE* file, bill_t* bill) {
    bill->items = allocateMemory(bill->itemNumber, sizeof(item_t));/////   !
    char itemName[50];
    int i;
    for (i = 0; i < bill->itemNumber; i++) {
       fscanf(file, "%49[^\n] ", itemName);/////          !
        bill->items[i].name = strDuplicate(itemName);/////    !
        if (bill->items[i].name) {
            printf("%d. item name allocated\n", i + 1);
        }
        fscanf(file, "%f ", &bill->items[i].amount);/////          !
        fscanf(file, "%f ", &bill->items[i].price);  /////       !
                    
    }
    addBillItem(bill);/////                                         !
}

void readBillFromFile(const char* filename, bill_t* bill) {
    FILE* file = fopen(filename, "r");/////                       !
    if (file == NULL) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }else{
        printf("The file is opened\n");
    }
    readBuyerSeller(file, bill); /////                    !
    readItems(file, bill);/////           <-            !
    if (fscanf(file, "%d ", &bill->itemNumber) == 1) {
        printf("Number od items: %d\n", bill->itemNumber);
    } 
    
    if(fclose(file) == 0){ ///////////////////            !
        printf("The file is closed\n");
    }
}

void printBill(const bill_t* bill) {
    printf("Bill issued by: %s\n", bill->seller);
    printf("Bill issued to: %s\n", bill->buyer);
    printf("Items:\n");
    for (int i = 0; i < bill->itemNumber; i++) {
        printf("%d. %s - %.2f x %d\n", i + 1, bill->items[i].name, bill->items[i].price, bill->items[i].amount);
    }
    printf("Total Price: %.2f\n", bill->totalPrice);
}


/*
readBuyerSeller(file, bill);
readItems(file, bill);
//////bill->items[i].amount * bill->items[i].price;
////fscanf(file, "%d ", &bill->items[i].amount);
////addBillItem(bill);
/////fscanf(file, "%49[^\n] ", itemName);
/////strDuplicate(itemName);
/////fscanf(file, "%49[^\n] ", buyer);
/////strDuplicate(buyer);
/////fscanf(file, "%f ", &bill->items[i].price);
/////allocateMemory(bill->itemNumber, sizeof(item_t));
fopen(filename, "r");
/////fscanf(file, "%49[^\n] ", seller);
//////strDuplicate(seller);
fclose(file)
*/
