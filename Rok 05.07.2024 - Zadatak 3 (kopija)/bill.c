/*
Sadržaj binarne datoteke:

|----------------|-------------------|---|-------------------|------|-----|-----------------|-------|---|--------------------|-------|----|--------------|-------|----|
| Petar Kupcevic | Ivan Prodavacevic | 4 | Pivo Osjecko 0.5l | 5.99 | 120 | Brandy Badel 1l | 69.99 | 5 | Vino Crno Ribar 1l | 12.99 | 55 | Coca Cola 2l | 12.99 | 20 | 
|----------------|-------------------|---|-------------------|------|-----|-----------------|-------|---|--------------------|-------|----|--------------|-------|----|

Funkcija readBuyerSeller() čita posebno prodavača i kupca iz datoteke. 
Za argumente prima tok podataka datoteke iz koje čita informacije i prima memorijsku adresu računa. 
Funkcija ništa ne vraća.

Funkcija addBillItem() zbraja ukupni iznos računa. 
Za argument prima memorijsku adresu računa i ništa ne vraća.

Funkcija readItems() dinamički zauzima polje artikala, čita imena artikala kao i njihovu cijenu i količinu. 
Na kraju funkcije poziva se funkcija addBillItem(). 
Funkcija za argumente prima tok podataka datoteke iz koje čita informacije i prima memorijsku adresu računa. 
Funkcija ništa ne vraća.

Funkcija readBillFromFile() otvara tok podataka prema datoteci i poziva sve funkcije za čitanje te odrađuje sav posao po pitanju čitanja kompletnog sadržaja iz datoteke u račun. 
Funkcija za argumente prima tok podataka datoteke iz koje čita informacije i prima memorijsku adresu računa. 
Funkcija ništa ne vraća.

Funkcija printBill() ispisuje sadržaj računa. Funkcija za argument prima memorijsku adresu računa i ništa ne vraća.
*/

#include <stdio.h>
#include <stdlib.h>
#include "file_type.h"/////
#include "memory.h"/////


static void readBuyerSeller(FILE* file, bill_t* bill) {
    char seller[50], buyer[50];

    fread(buyer, sizeof(char), 50, file);/////
    bill->buyer = strDuplicate(buyer);/////
    if (bill->buyer) {
        printf("Buyer allocated\n");
    }

    fread(seller, sizeof(char), 50, file);/////
    bill->seller = strDuplicate(seller);/////
    if (bill->seller) {
        printf("Seller allocated\n");
    }
}

static void addBillItem(bill_t* bill) {
  int i;

  for (i = 0; i < bill->itemNumber; i++) {
    bill->totalPrice += bill->items[i].amount * bill->items[i].price;/////
  }  
}

static void readItems(FILE* file, bill_t* bill) {
      bill->items=allocateMemory(bill->itemNumber, sizeof(item_t));/////
   
    char itemName[50];
    int i;

    for (i = 0; i < bill->itemNumber; i++) {
        fread(itemName, sizeof(char), 50, file);/////
        bill->items[i].name = strDuplicate(itemName);/////
        if (bill->items[i].name) {
            printf("%d. item name allocated\n", i + 1);
        }
         fread(&bill->items[i].price, sizeof(float), 1, file);
         fread(&bill->items[i].amount, sizeof(int), 1, file);/////
       /////
    }
    addBillItem(bill);/////
}

void readBillFromFile(const char* filename, bill_t* bill) {
    FILE* file = fopen(filename, "r");/////
    if (file == NULL) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }else{
        printf("The file is opened\n");
    }
    
    
    
    readBuyerSeller(file, bill);/////
    
    if (fread(&bill->itemNumber, sizeof(int), 1, file)/*/////*/ == 1) {
        printf("Number od items: %d\n", bill->itemNumber);
    } 
 readItems(file, bill);/////
  

    if(fclose(file)/*/////*/ == 0){
        printf("The file is closed\n");
    }
}

void printBill(const bill_t* bill) {
    printf("Bill issued by: %s\n", bill->seller);
    printf("Bill issued to: %s\n", bill->buyer);
    printf("Items:\n");
    for (int i = 0; i < bill->itemNumber; i++) {
        printf("%d. %s - %.2f x %d\n", i + 1, bill->items[i].name, bill->items[i].price, bill->items[i].amount);/////
    }
    printf("Total Price: %.2f\n", bill->totalPrice);/////
}
/*
printf("Total Price: %.2f\n", bill->totalPrice);
fopen(filename, "r");
strDuplicate(itemName);
strDuplicate(seller);
bill->items[i].amount * bill->items[i].price;
fread(itemName, sizeof(char), 50, file);
strDuplicate(buyer);
printf("%d. %s - %.2f x %d\n", i + 1, bill->items[i].name, bill->items[i].price, bill->items[i].amount);
fread(&bill->items[i].amount, sizeof(int), 1, file);
#include "memory.h"
fread(seller, sizeof(char), 50, file);
readBuyerSeller(file, bill);
fread(&bill->itemNumber, sizeof(int), 1, file)
readItems(file, bill);
fread(buyer, sizeof(char), 50, file);
allocateMemory(bill->itemNumber, sizeof(item_t));
fclose(file)
#include "file_type.h"
addBillItem(bill);
fread(&bill->items[i].price, sizeof(float), 1, file);
*/