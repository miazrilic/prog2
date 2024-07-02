#ifndef BILL_H
#define BILL_H

#include <stdio.h>

void readBillFromFile(const char*, bill_t* );
void readBuyerSeller(FILE*, bill_t* );
void readItems(FILE*, bill_t*);
void addBillItem(bill_t*);
void printBill(const bill_t*);

#endif //BILL_H