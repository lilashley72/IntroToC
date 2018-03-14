/*
 * COP 2334
 * Created by Kevin Patlis, [name], [name]
 * Date Due: 4/23/18
 */

#include "../Headers/Times.h"
#include "../Headers/ValidateDouble.h"

#include <iostream>
#include <tgmath.h>

int Times::daysSpent() // Calculate total days spent on the trip, pass back to
{
    bool validUserInput;
    int days;

    do
    {
        validUserInput = true;

        std::cin >> days;

        if(days < 1)
        {
            validUserInput = false;
            std::cout << "This is an invalid amount of days. Please enter another number: ";
        }

    }while (!validUserInput);

    return days;
}

void Times::times(double& departTime, double& returnTime)
{
    ValidateDouble validate; // instantiate

    bool areValidTimes;

    do
    {
        std::cout << "Enter the departure time (using 24-hour HH.MM format): ";
        departTime = validate.ValidateResponse(); // Check ValidateDouble.cpp for definition

        areValidTimes = isValidTime(departTime); // Determine if time is valid.

    }while(!areValidTimes);

    do
    {
        std::cout << "Enter the return time (using 24-hour HH.MM format): ";\
        returnTime = validate.ValidateResponse(); // Check ValidateDouble.cpp for definition

        areValidTimes = isValidTime(departTime); // Determine if time is valid.
    }while(!areValidTimes);
}

bool Times::isValidTime(double inputTime) // Determine whether or not inputted time is correct.
{
    if(inputTime > 24 || std::fmod(inputTime, 1.00) > .59 )
    {
        std::cout << "Invalid time. Please enter another. " << std::endl;
        return false;
    }
    else
    {
        return true;
    }
}