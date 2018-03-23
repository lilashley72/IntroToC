/*
 * COP 2334
 * Created by Kevin Patlis, Abraham Harfouche, Ashley Thompson
 * Date Due: 4/23/18
 */

#include <iostream>

#include "Times.h"
#include "Transportation.h"
#include "TravelExpenses.h"
#include "OutputToFile.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main() {

    // Instantiate objects of classes that we will use later
    Times time;
    Transportation trans;
    TravelExpenses travel;
    OutputToFile output;


    // Declare all needed variables
    std::string employeeName;
    int totalDays;
    double  departTime,
            returnTime,
            totalAirfareCost,
            totalRentalCost,
            totalMileageCost,
            totalParkingFees,
            totalTaxiFees,
            totalRegistrationCost,
            totalHotelCost,
            totalAllowedMealCost,
            totalAllowedTaxiCost,
            totalMealCost;

    cout << "Employee name: "; //Get employee name
    std::getline(std::cin, employeeName);

    cout << "How many days were spent on the trip? "; //Get days spent on trip. Called from the Times.cpp class.
    totalDays = time.daysSpent();

    time.times(departTime, returnTime); //Get departure and return times.

    cout << "Enter the amount of airfare: "; //Get total airfare costs
    totalAirfareCost = trans.airFare();

    cout << "Enter the amount spent for car rental: "; //Get total car rental costs
    totalRentalCost = trans.carRental();

    cout << "Enter the amount of miles driven by private vehicle: "; //Get cost of total miles driven
    totalMileageCost = trans.vehicle();

    cout << "Enter the amount of parking fees: "; //Get parking fees
    totalParkingFees = trans.parking();

    cout << "Enter the amount of taxi fees: "; //Get total taxi fees
    trans.taxi(totalDays, totalTaxiFees, totalAllowedTaxiCost);

    cout << "Enter the amount of conference registration: "; //Get registration costs
    totalRegistrationCost = travel.registration();

    cout << "Enter the nightly hotel rate: ";
    travel.hotel(totalHotelCost);

    totalHotelCost = totalHotelCost * (totalDays - 1);

    //Get total meal costs
    travel.meals(totalDays, departTime, returnTime, totalAllowedMealCost, totalMealCost);

    output.Output(employeeName, totalDays, departTime, returnTime, totalAirfareCost, totalRentalCost, totalMileageCost, totalParkingFees, totalTaxiFees, totalRegistrationCost, totalHotelCost, totalMealCost, totalAllowedMealCost, totalAllowedTaxiCost);

    return 0;
}