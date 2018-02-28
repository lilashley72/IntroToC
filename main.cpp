/*
 * Developed by Kevin Patlis for Intro To C++, COP2334
 */

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

double validateResponse();

int main()
{
    double startingBalance, rate;
    cout << "Enter the starting balance on the account: $";
    startingBalance = validateResponse();
}

double validateResponse()
{
    double userInput;
    bool  isUserInputTrue;
    cin >> userInput;

}