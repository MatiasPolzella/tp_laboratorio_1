#ifndef INFORMES_H_
#define INFORMES_H_

int sortPassengers(Passenger* list, int len, int order);

/// @brief averagPassengers Will get the total flight prices along with the average and the number of passengers who are above the average price.
/// @param list Pointer to the array of Passenger
/// @param len Array length
/// @return Zero if it could get the information correctly and -1 if it has an error.
int averagePassengers(Passenger* list, int len);

#endif /* INFORMES_H_ */
