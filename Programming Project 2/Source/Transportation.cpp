#include <iostream>

#include "../Headers/Transportation.h"
#include "../Headers/ValidateDouble.h"
#include "../Headers/CompanyCosts.h"
using std::cout;
using std::cin;
using std::endl;

ValidateDouble validate;

double Transportation::airFare()
{
    double air_fare;

    cout<< "Enter the amount of airfare:  ";
    air_fare= validate.ValidateResponse();

    return air_fare;
}

double Transportation::carRental()
{
    double car_rental;

    cout<< "Enter the amount spent for car rental:  ";
    car_rental = validate.ValidateResponse();

    return car_rental;
}

double Transportation::vehicle()
{
    double miles;

    cout<< "Enter the amount of miles driven by private vehicle: ";
    miles = validate.ValidateResponse();

    return miles * CompanyCosts::MAX_COST_PER_MILE_DRIVEN;
}

double Transportation::parking()
{
    double totalParkingFees;

    cout<< "Enter parking fee:";
    totalParkingFees = validate.ValidateResponse();

    return totalParkingFees;
}

void Transportation::taxi(int, double, double&)
{

}

 