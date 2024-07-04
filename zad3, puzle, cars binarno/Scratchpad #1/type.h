#ifndef TYPE_H
#define TYPE_H

typedef struct car {

	char brend[20];
	char model[20];
	int horsePower;
	float maxSpeed;
	int price;
	struct car* nextCar;

}CAR;

#endif // TYPE_H