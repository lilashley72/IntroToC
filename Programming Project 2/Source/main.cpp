/*
 * COP 2334
 * Created by Kevin Patlis, [name], [name]
 * Date Due: 4/23/18
 */

#include <iostream>
#include "../Headers/Times.h"
#include "../Headers/Transportation.h"
#include "../Headers/CompanyCosts.h"
#include "../Headers/TravelExpenses.h"

using std::cout;
using std::cin;
using std::endl;

int main() {

    // Instantiate objects of classes that we will use later
    Times time;
    Transportation trans;
    TravelExpenses travel;

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
            totalMealCost;

    cout << "Employee name: "; //Get employee name
    cin >> employeeName;

    cout << "How many days were spent on the trip? "; //Get days spent on trip. Called from the Times.cpp class.
    totalDays = time.daysSpent();

    time.times(departTime, returnTime); //Get departure and return times.

    // AS OF 3/14/18 NO FUNCTIONS HAVE BEEN DEFINED PAST THIS POINT

    cout << "Enter the amount of airfare: "; //Get total airfare costs
    totalAirfareCost = trans.airFare();

    cout << "Enter the amount spent for car rental: "; //Get total car rental costs
    totalRentalCost = trans.carRental();

    cout << "Enter the amount of miles driven by private vehicle: "; //Get cost of total miles driven
    totalMileageCost = trans.vehicle();

    cout << "Enter the amount of parking fees: "; //Get parking fees
    totalParkingFees = trans.parking();

    cout << "Enter the amount of taxi fees: "; //Get total taxi fees
    trans.taxi(totalDays, CompanyCosts::MAX_TAXI_FEE_PER_DAY, totalTaxiFees);

    cout << "Enter the amount of conference registration: "; //Get registration costs
    totalRegistrationCost = travel.registration();

    travel.hotel(totalDays, CompanyCosts::MAX_HOTEL_COST_PER_NIGHT, totalHotelCost); //Get total meal costs
    travel.meals(totalDays, departTime, returnTime, totalMealCost);

    // Debug Code : cout << departTime << " " << returnTime << " " << totalDays;

    return 0;
}