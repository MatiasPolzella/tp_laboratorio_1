#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_

#define NAME_LEN 51
#define LASTNAME_LEN 51
#define FLYCODE 10

typedef struct{
	int id;
	char name[NAME_LEN];
	char lastName[LASTNAME_LEN];
	float price;
	char flyCode[FLYCODE];
	int typePassenger;
	int statusFlight;
	int isEmpty;
}Passenger;

int initPassengers(Passenger* list, int len);
int addPassengers(Passenger* list, int len, int id, char* name,char* lastName,float price,int typePassenger,char* flycode);
int getEmptyIndex(Passenger* list, int len);
int findPassengerById(Passenger* list, int len,int id);
int removePassenger(Passenger* list, int len, int id);
int printPassenger(Passenger* list, int lenght);
int contPassenger(Passenger* list, int len);
int modifPassenger(Passenger* list, int len, int id, int option);



#endif /* ARRAYPASSENGER_H_ */
