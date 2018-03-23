/*
 * COP 2334
 * Created by Kevin Patlis, Abraham Harfouche, Ashley Thompson
 * Date Due: 4/23/18
 */

#include <iostream>
#include "ValidateDouble.h"

double ValidateDouble::ValidateResponse() // Validate a non-negative double from the user.
{
    double input;
    bool isUserInputValid;

    do
    {
        isUserInputValid = true;

        std::cin >> input;

        if (input < 0)
        {
            isUserInputValid = false;
            std::cout << "Invalid entry. Enter another number: ";
        }

    }while(!isUserInputValid);

    return input;
}