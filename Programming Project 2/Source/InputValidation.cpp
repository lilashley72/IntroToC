#include <iostream>
#include "../Headers/InputValidation.h"

using std::cin;
using std::cout;

inline double InputValidation::UserInput() // Call this function to validate input
{
    bool validUserInput;
    double input;

    do
    {
    
        validUserInput = true;

        cin >> input;

        if(input < 0)
        {
            validUserInput = false; // If user enters negative number, continue loop.

            cout << "That is not valid input. Please try again." << std::endl;
        }

    }while(!validUserInput);

    return input; //After do-while loop clears, return user's number.
}
