/*
 * COP 2334
 * Created by Kevin Patlis, Abraham Harfouche, Ashley Thompson
 * Date Due: 4/23/18
 */

#include <iostream>

#include "Transportation.h"
#include "ValidateDouble.h"
#include "CompanyCosts.h"
using std::cout;
using std::cin;
using std::endl;

ValidateDouble validate;


double Transportation::airFare()
{
    double air_fare;

    air_fare = validate.ValidateResponse();

    return air_fare;
}

double Transportation::carRental()
{
    double car_rental;

    car_rental = validate.ValidateResponse();

    return car_rental;
}

double Transportation::vehicle()
{
    double miles;

    miles = validate.ValidateResponse();

    return miles * CompanyCosts::MAX_COST_PER_MILE_DRIVEN;
}

double Transportation::parking()
{
    double totalParkingFees;

    totalParkingFees = validate.ValidateResponse();

    return totalParkingFees;
}

void Transportation::taxi(int days, double& totalTaxiFees, double& totalAllowedTaxiFees)
{
    totalTaxiFees = validate.ValidateResponse();

    if(totalTaxiFees == 0)
    {
        totalAllowedTaxiFees = 0;
    }
    else
    {
        totalAllowedTaxiFees = days * CompanyCosts::MAX_TAXI_FEE_PER_DAY;
    }
}

 