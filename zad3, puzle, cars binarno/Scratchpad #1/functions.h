#ifndef FUNCTIONS_H
#define FUNCTIONS_H

int printCarList(CAR*);
CAR* createCarList(void);
CAR* insertCarToList(CAR*);
int deleteCarFromList(CAR**, CAR*);
CAR* deleteWholeCarList(CAR*);
CAR* minPriceByHp(CAR*);
void printCar(CAR*);

#endif // FUNCTIONS_H