/*
 * COP 2334
 * Created by Kevin Patlis, Abraham Harfouche, Ashley Thompson
 * Date Due: 4/23/18
 */

#include "TravelExpenses.h"
#include "ValidateDouble.h"
#include "CompanyCosts.h"

#include <iostream>

double TravelExpenses::registration()
{
    ValidateDouble validate;

    double registrationCost;

    registrationCost = validate.ValidateResponse();

    return registrationCost;
}

void TravelExpenses::hotel(double& totalHotelCosts)
{
    ValidateDouble validate;

    totalHotelCosts = validate.ValidateResponse();
}
void TravelExpenses::meals(int days, double departureTime, double returnTime, double& totalAllowedMealCost, double& totalMealCost)
{
    totalAllowedMealCost = 0;

    double mealCost;

    ValidateDouble validate;

    for(int x = 1; x <= days; x++)
    {

        if(x == 1)
        {
            std::cout << "Day " << x << ":" << std::endl;

            if(departureTime < 7.00)
            {
                std::cout << "Enter the amount for breakfast: ";
                mealCost = validate.ValidateResponse();

                totalMealCost += mealCost;
                totalAllowedMealCost += CompanyCosts::MAX_BREAKFAST_COST;
            }
            if(departureTime < 12.00)
            {
                std::cout << "Enter the amount for lunch: ";
                mealCost = validate.ValidateResponse();

                totalMealCost += mealCost;
                totalAllowedMealCost += CompanyCosts::MAX_LUNCH_COST;
            }
            if(departureTime < 18.00)
            {
                std::cout << "Enter the amount for dinner: ";
                mealCost = validate.ValidateResponse();

                totalMealCost += mealCost;
                totalAllowedMealCost += CompanyCosts::MAX_DINNER_COST;
            }
        }
        else if(x == days)
        {
            std::cout << "Day " << x << ":" << std::endl;

            if(returnTime > 8.00)
            {
                std::cout << "Enter the amount for breakfast: ";
                mealCost = validate.ValidateResponse();

                totalMealCost += mealCost;
                totalAllowedMealCost += CompanyCosts::MAX_BREAKFAST_COST;
            }
            if(returnTime > 13.00)
            {
                std::cout << "Enter the amount for lunch: ";
                mealCost = validate.ValidateResponse();

                totalMealCost += mealCost;
                totalAllowedMealCost += CompanyCosts::MAX_LUNCH_COST;
            }
            if(returnTime > 19.00)
            {
                std::cout << "Enter the amount for dinner: ";
                mealCost = validate.ValidateResponse();

                totalMealCost += mealCost;
                totalAllowedMealCost += CompanyCosts::MAX_DINNER_COST;
            }
        }
        else
        {
            std::cout << "Day " << x << ":" << std::endl;

            std::cout << "Enter the amount for breakfast: ";
            mealCost = validate.ValidateResponse();

            totalMealCost += mealCost;
            totalAllowedMealCost += CompanyCosts::MAX_BREAKFAST_COST;

            std::cout << "Enter the amount for lunch: ";
            mealCost = validate.ValidateResponse();

            totalMealCost += mealCost;
            totalAllowedMealCost += CompanyCosts::MAX_LUNCH_COST;

            std::cout << "Enter the amount for dinner: ";
            mealCost = validate.ValidateResponse();

            totalMealCost += mealCost;
            totalAllowedMealCost += CompanyCosts::MAX_DINNER_COST;
        }

    }
}