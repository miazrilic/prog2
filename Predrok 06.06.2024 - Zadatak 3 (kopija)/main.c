/*
Napisan je kompletan program za kreiranje računa koji čita sadržaj iz tekstualne datoteke.

Vi smijete i morate dopuniti sadržaj koji se nalazi samo u datotekama bill.c i memory.c, sav ostali kôd ne smijete dirati. 
U obje datoteke su zakomentirane linije na čije mjesto trebate nadopisati kôd koji je na dnu stranice zakomentiran. 
I to je sve što morate, ne morate zamišljati svoj kôd, već zadatak je kao puzzla, samo uzmite kôd iz komentara i stavite ga na pravo mjesto. 

Konačni ispis treba izgledati ovako:

Bill allocated
The file is opened
String Petar Kupcevic copied
Buyer allocated
String Ivan Prodavacevic copied
Seller allocated
Number od items: 4
String Pivo Osjecko 0.5l copied
1. item name allocated
String Brandy Badel 1l copied
2. item name allocated
String Vino Crno Ribar 1l copied
3. item name allocated
String Coca Cola 2l copied
4. item name allocated
The file is closed
Bill issued by: Ivan Prodavacevic
Bill issued to: Petar Kupcevic
Items:
1. Pivo Osjecko 0.5l - 5.99 x 120
2. Brandy Badel 1l - 69.99 x 5
3. Vino Crno Ribar 1l - 12.99 x 55
4. Coca Cola 2l - 12.99 x 20
Total Price: 2043.00
1. item name deallocated
2. item name deallocated
3. item name deallocated
4. item name deallocated
Items deallocated
Buyer name deallocated
Seller name deallocated
Bill deallocated

>>>POZOR<<<

>>>Ispis iz Vašeg programa imat će razmake i drugaciji font, ne brinite zbog toga!!!<<<
>>>Važno je da Vi ne nadopisujete tekst!!!<<<

*/

#include "file_type.h"
#include "bill.h"
#include "memory.h"

int main() {
    bill_t* bill = allocateMemory(1, sizeof(bill_t));
    if(bill) {
        printf("Bill allocated\n");
    }
    readBillFromFile("bill_information.txt", bill);
    printBill(bill);
    deallocateMemory(bill);
    return 0;
}