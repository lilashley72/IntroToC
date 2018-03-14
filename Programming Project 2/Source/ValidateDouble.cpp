//
// Created by Owner on 3/14/2018.
//

#include <iostream>
#include "../Headers/ValidateDouble.h"

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