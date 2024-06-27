#ifndef FILE_TYPE_H
#define FILE_TYPE_H

typedef struct {
    char* name;
    float price;
    int amount;
} item_t;

typedef struct {
    char* seller;
    char* buyer;
    item_t* items;
    int itemNumber;
    float totalPrice;
} bill_t;

#endif //FILE_TYPE_H