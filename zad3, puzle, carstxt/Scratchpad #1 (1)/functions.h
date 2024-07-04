#ifndef FUNCTIONS_H
#define FUNCTIONS_H

int printCarList(CAR*);
CAR* createCarList(void);
CAR* insertCarToList(CAR*);
int deleteCarFromList(CAR**, CAR*);
CAR* deleteWholeCarList(CAR*);
CAR* maxPriceByHp(CAR*);
void printCar(CAR*);

#endif // FUNCTIONS_H