/*
 * COP 2334
 * Created by Kevin Patlis, Abraham Harfouche, Ashley Thompson
 * Date Due: 4/23/18
 */

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

#include "OutputToFile.h"
#include "CompanyCosts.h"
using std::endl;

void OutputToFile::Output(std::string name, int days, double departTime, double returnTime, double totalAirfareCost, double totalRentalCost, double totalMileageCost, double totalParkingFees, double totalTaxiFees, double totalRegistrationCost, double totalHotelCost, double totalMealCost, double totalAllowedMealCost, double totalAllowedTaxiCost)
{
    std::cout << endl << "The expense report has been written to the Expense.rpt file.";

    std::ofstream file;

    file.open("Expense.rpt");

    double totalCosts = totalAirfareCost + totalHotelCost + totalMealCost + totalMileageCost + totalParkingFees + totalRegistrationCost + totalRentalCost + totalTaxiFees;
    double totalCompanyCosts = totalAirfareCost + totalRentalCost + totalMileageCost + (CompanyCosts::MAX_PARKING_FEE_PER_DAY * days) + totalAllowedTaxiCost + totalRegistrationCost + (CompanyCosts::MAX_HOTEL_COST_PER_NIGHT * (days-1) + totalAllowedMealCost);

    file << endl << "     Employee Expense Report for " << name << std::setprecision(2) << std::fixed << endl << endl;

    file << "Total Days: " << days << endl;
    file << "Departure Time: " << departTime << "     " << "Return time: " << returnTime << endl << endl;

    file << "                 Spent     Allowed" << endl;
    file << "                 _____     _______" << endl;
    file << "Airfare         " << totalAirfareCost << "     " << totalAirfareCost << endl;
    file << "Car rental      " << totalRentalCost <<  "     " << totalRentalCost << endl;
    file << "Milage           " << totalMileageCost << "      " << totalMileageCost << endl;
    file << "Parking          " << totalParkingFees << "      " << CompanyCosts::MAX_PARKING_FEE_PER_DAY * days << endl;
    file << "Taxis             " << totalTaxiFees <<    "       " << totalAllowedTaxiCost << endl;
    file << "Registration    " << totalRegistrationCost << "     " << totalRegistrationCost << endl;
    file << "Hotels          " << totalHotelCost <<    "     " << CompanyCosts::MAX_HOTEL_COST_PER_NIGHT * (days-1) << endl;
    file << "Meals            " << totalMealCost << "     " << totalAllowedMealCost << endl << endl;

    file << "TOTALS         _______   _________" << endl;
    file << "               " << totalCosts << "     " << totalCompanyCosts;

    file.close();
}