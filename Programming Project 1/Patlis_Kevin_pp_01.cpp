/*
 * Developed by Kevin Patlis for Intro To C++, COP2334
 */

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

double ValidateResponse();
double EvalQuarter(double bal, double &endBal, double &totalDeposits, double &totalWithdrawals, double &totalInterest, double rate, int month);
void Statement(double bal, double totalDeposits, double totalWithdrawals, double totalInterest, double endBal);
void printStatement(double bal, double totalDeposits, double totalWithdrawals, double totalInterest, double endBal);

int main()
{
    double bal, startingBalance, rate, totalDeposits, totalWithdrawals, totalInterest, endBal;


    cout << "Enter the starting balance on the account: $";
    startingBalance = ValidateResponse();
    bal = startingBalance;

    cout << "Enter the annual interest rate on the account (e.g. .04): ";
    rate = ( ValidateResponse() / 12.00);

    endBal = startingBalance;
    for(int i = 1; i < 4; i++)
    {
        startingBalance = EvalQuarter(startingBalance, endBal, totalDeposits, totalWithdrawals, totalInterest, rate, i);
    }

    Statement(bal, totalDeposits, totalWithdrawals, totalInterest, endBal);
    printStatement(bal, totalDeposits, totalWithdrawals, totalInterest, endBal);
}

double ValidateResponse()
{
    double userInput;
    bool  isUserInputInvalid;

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

    return userInput;
}

double EvalQuarter(double bal, double &endBal, double &totalDeposits, double &totalWithdrawals, double &totalInterest, double rate, int month)
{
    double deposit, withdrawal;
    bool isUserInputInvalid;

    cout << "\nMonth " << month << endl;

    cout << "Total deposits for this month: $";
    deposit = ValidateResponse();

    endBal += deposit;
    totalDeposits += deposit;

    do
    {
        isUserInputInvalid = false;

        cout << "Total withdrawals for this month: $";
        withdrawal = ValidateResponse();

        if(withdrawal > endBal)
        {
            cout << "You have withdrawn too much money. Please try again." << endl;
            isUserInputInvalid = true;
        }
        else{
            endBal -= withdrawal;
            totalWithdrawals += withdrawal;
        }

    }while(isUserInputInvalid);

    double runningInterest = rate * ((bal + endBal) / 2);
    totalInterest += runningInterest;

    endBal += runningInterest;

    cout << "Interest Recieved this month: $" << fixed << setprecision(2) << runningInterest << endl;
    cout << "Ending monthly balance: $" << endBal << endl;

    return endBal;
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