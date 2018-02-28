/*
 * Developed by Kevin Patlis for Intro To C++, COP2334
 */

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;


// Declaring functions
double ValidateResponse();
double EvalQuarter(double bal, double &endBal, double &totalDeposits, double &totalWithdrawals, double &totalInterest, double rate, int month);
void Statement(double bal, double totalDeposits, double totalWithdrawals, double totalInterest, double endBal);
void printStatement(double bal, double totalDeposits, double totalWithdrawals, double totalInterest, double endBal);

int main()
{
    double bal, startingBalance, rate, totalDeposits, totalWithdrawals, totalInterest, endBal; // Initalize all variables to use in calculations


    cout << "Enter the starting balance on the account: $"; // Output prompt to user to enter data
    startingBalance = ValidateResponse(); // Call function to validate that response is greater than 0
    bal = startingBalance; // set the Starting Balance to use later in code

    cout << "Enter the annual interest rate on the account (e.g. .04): ";
    rate = ( ValidateResponse() / 12.00); // Find monthly interest rate

    endBal = startingBalance; // Declare endBal to use in function later in code
    
    // For loop to start month count
    for(int i = 1; i < 4; i++)
    {
        // Pass needed variables to evaluate the month in question ( 1 , 2 , 3.. )
        startingBalance = EvalQuarter(startingBalance, endBal, totalDeposits, totalWithdrawals, totalInterest, rate, i);
    }

    Statement(bal, totalDeposits, totalWithdrawals, totalInterest, endBal); // Print Quarterly Statement to console
    printStatement(bal, totalDeposits, totalWithdrawals, totalInterest, endBal); // Output Quarterly Statement to file
}

double ValidateResponse()
{
    double userInput; // var to handle user input
    bool  isUserInputInvalid; // boolean var to use in doWhile loop

    do
    {
        isUserInputInvalid = false; 

        cin >> userInput;

        if(userInput < 0)
        {
            cout << "Invalid Response. Try again." << endl;
            isUserInputInvalid = true;

            cout << "Enter a new value :";
        }

    }
    while(isUserInputInvalid);

    return userInput; // return clean value
}

double EvalQuarter(double bal, double &endBal, double &totalDeposits, double &totalWithdrawals, double &totalInterest, double rate, int month) // passing multiple vars by reference to call them later in code
{
    // variables declared to use for handling withdrawal and deposit amounts, as well as boolean var to handle doWhile loop
    double deposit, withdrawal;
    bool isUserInputInvalid;

    cout << "\nMonth " << month << endl;

    cout << "Total deposits for this month: $";
    deposit = ValidateResponse();

    endBal += deposit;
    totalDeposits += deposit; // add deposits to the ending balance, 

    do
    {
        isUserInputInvalid = false;

        cout << "Total withdrawals for this month: $";
        withdrawal = ValidateResponse();

        if(withdrawal > endBal) // check for invalid withdrawal amount
        {
            cout << "You have withdrawn too much money. Please try again." << endl;
            isUserInputInvalid = true;
        }
        else
        {
            endBal -= withdrawal;
            totalWithdrawals += withdrawal;
        }

    }while(isUserInputInvalid);

    double runningInterest = rate * ((bal + endBal) / 2); // calculate interest rate for month
    totalInterest += runningInterest;

    endBal += runningInterest;

    cout << "Interest Recieved this month: $" << fixed << setprecision(2) << runningInterest << endl;
    cout << "Ending monthly balance: $" << endBal << endl;

    return endBal; // return end monthly balance
}

void Statement(double bal, double totalDeposits, double totalWithdrawals, double totalInterest, double endBal)
{
    cout << left;
    cout << "\nQuarterly Savings Account Statement\n";
    cout << left << "\nStarting balance:    $" << right << setw(10) << bal;
    cout << left << "\nTotal deposits:    + $" << right << setw(10) << totalDeposits;
    cout << left << "\nTotal withdrawals: - $" << right << setw(10) << totalWithdrawals;
    cout << left << "\nTotal interest:    + $" << right << setw(10) << totalInterest;
    cout << left << "\n                      __________";
    cout << left << "\nEnding balance       $" << right << setw(10) << endBal;
}


void printStatement(double bal, double totalDeposits, double totalWithdrawals, double totalInterest, double endBal)
{
    ofstream fileOut;

    fileOut.open("AccountStatement.txt");

    fileOut << left << fixed << setprecision(2);
    fileOut << "\nQuarterly Savings Account Statement\n";
    fileOut << left << "\nStarting balance:    $" << right << setw(10) << bal;
    fileOut << left << "\nTotal deposits:    + $" << right << setw(10) << totalDeposits;
    fileOut << left << "\nTotal withdrawals: - $" << right << setw(10) << totalWithdrawals;
    fileOut << left << "\nTotal interest:    + $" << right << setw(10) << totalInterest;
    fileOut << left << "\n                      __________";
    fileOut << left << "\nEnding balance       $" << right << setw(10) << endBal;

    fileOut.close();
}
