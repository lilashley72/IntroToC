/*
 * COP 2334
 * Created by Kevin Patlis, [name], [name]
 * Date Due: 4/23/18
 */

#include <iostream>
#include "InputValidation.cpp"

// #include "../Headers/CompanyCosts.h" ** INCLUDE THIS IF YOU ARE USING THE VARIABLES IN CompanyCosts.h"

using std::cout;
using std::endl;

int main() {

    InputValidation callValid; // instanciate object of class

    double totalTripDays;

    cout << "How many days are going to be spent on the trip?";
    totalTripDays = callValid.UserInput(); //UserInput() is a child function of the object totalTripDays. We call it here to set the variable totalTripDays to the input we recieve from UserInput in InputValidation.cpp.
    
    // totalTripDays = PROGRAMMING_PROJECT_2_COMPANYCOSTS_H::MAX_TAXI_FEE_PER_DAY; ** EXAMPLE CODE. **
    // Above is an example of how you might use the variables that are defined in CompanyCosts.h
    
    return 0;
}
