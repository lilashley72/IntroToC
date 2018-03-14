/*
 * COP 2334
 * Created by Kevin Patlis, [name], [name]
 * Date Due: 4/23/18
 */

#include <iostream>
#include "InputValidation.cpp"

using std::cout;
using std::endl;

int main() {

    InputValidation callValid; // instanciate object of class


    double totalTripDays;

    cout << "How many days are going to be spent on the trip?";
    totalTripDays = callValid.UserInput();

    return 0;
}
