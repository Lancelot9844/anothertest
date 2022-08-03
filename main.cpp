//contents of main.cpp
#include <iostream>
#include<stdlib.h>
#include "SavingsAccount.h"
#include "CheckingAccount.h"
using namespace std;
int main ()
{

    cout <<"SAVINGS ACCOUNT\n\n";//create a savings account
	double startingBalance;
	double annualRate;
	cout <<"Enter starting balance of Savings Account: $";
	cin >>startingBalance;
    cout <<"\nEnter Annual Interest Rate in %: ";
    cin >>annualRate;	//update interest rate to be correct value because it is in %
    annualRate =annualRate/100;
    cout <<"\nCreating Savings Account with this data...";
    SavingsAccount savAcc (startingBalance,annualRate);
    cout <<"Done!\n";	//set value of monthly processing charges and set it
double initProcessCharges;
    cout <<"Enter monthly processing charges:$";
    cin >>initProcessCharges;
    savAcc.setMonthlyCharges(initProcessCharges);	//This can be also implemented as a menu driven program but for the sake of simplicity, we used while loops to get the withdrawals and deposits
double depos =0, withdr =0;
double totalDepos =0, totalWithdr =0; //get all the monthly deposits
    cout <<"\nEnter the deposits one by one. When finished,";
    cout <<" enter -1:"<<endl;
    cin >>depos;
while(depos !=-1)
{//add deposit to total
        totalDepos +=depos;
        cout << fixed << setprecision(2);
        cout <<"Performing deposit...\n";
        savAcc.deposit(depos);
        cout <<"Done!\n";		//display data of savings account
        cout <<"\nBalance: $"<< savAcc.getBalance();
        cout <<"\nNumber of deposits: "<< savAcc.getNumDeposits();
        cout <<"\nNumber of withdrawals: "<< savAcc.getNumWithdrawals();
        cout <<"\n\nEnter another deposit amount, or -1 to stop: ";
        cin >>depos;
}//use the same method to take all the monthly withdrawals
    cout <<"\nEnter the withdrawals one by one. When finished,";
    cout <<" enter -1:"<< endl;
	cin >>withdr;
	while(withdr !=-1)
{	//add withdrawal to total
        totalWithdr += withdr;
        cout << fixed << setprecision(2);
        cout <<"Performing withdrawal...\n";
        savAcc.withdraw(withdr);
        cout <<"Done!\n";		//display data of savings account
        cout <<"\nBalance:$"<<savAcc.getBalance();
        cout <<"\nNumber of deposits: "<< savAcc.getNumDeposits();
        cout <<"\nNumber of withdrawals: "<< savAcc.getNumWithdrawals();
        cout <<"\n\nEnter another withdrawal amount, or -1 to stop: ";
        cin >>withdr;
}	//display statistics
    cout <<"\nDone! Here are the monthly statistics: ";
    cout <<"\nBeginning balance: $"<< startingBalance;
    cout <<"\nNumber of deposits: "<< savAcc.getNumDeposits();
    cout <<"\nTotal amount of deposits:$"<<totalDepos;
    cout <<"\nNumber of withdrawals: "<<savAcc.getNumWithdrawals();
    cout <<"\nTotal amount of withdrawals: $"<< totalWithdr;
    cout <<"\nMonthly charges:$"<< initProcessCharges;	//get the service charges in a structure and perform monthly processing
    ServAndOwed temp =savAcc.monthlyProc();
    cout <<"\nService fees: $"<<temp.servCharges;
    cout <<"\nTotal monthly charges:$"<<initProcessCharges + temp.servCharges; 	//display ending balance
    cout <<"\nEnding balance: $"<<savAcc.getBalance();	//---------------------------------------------------------
	//now do the same thing for a checking account---------------------------------------------------------
    cout <<"\n\n\nCHECKING ACCOUNT\n\n";
    cout <<"Enter starting balance of Checking Account:$";
    cin >>startingBalance;
    cout <<"\nEnter Annual Interest Rate in %: ";
    cin >> annualRate;	//update interest rate to be correct value because it is in %
    annualRate = annualRate/100;	//create a checking account object
    cout <<"\nCreating Checking Account with this data...";
    CheckingAccount checkAcc(startingBalance, annualRate);
    cout <<"Done!\n";	//set value of monthly processing charges and set it
    cout <<"Enter monthly processing charges: $";
    cin >> initProcessCharges;
    checkAcc.setMonthlyCharges(initProcessCharges);//remember, you can only withdraw from this checking account
    withdr =0;
    totalWithdr =0;	//get the withdrawals with the same method
    cout <<"\nEnter the withdrawals one by one. When finished,";
    cout <<" enter -1:\n";
    cin >>withdr;
	while(withdr !=-1)
{	//add withdrawal to total
        totalWithdr +=withdr;
        cout << fixed <<setprecision(2);
        cout <<"Performing deposit...\n";
        checkAcc.withdraw(withdr);
        cout <<"Done!\n";	//display data of savings account
        cout <<"\nBalance: $"<<checkAcc.getBalance();
        cout <<"\nNumber of deposits: "<<checkAcc.getNumDeposits();
        cout <<"\nNumber of withdrawals: "<<checkAcc.getNumWithdrawals();
        cout <<"\n\nEnter another withdrawal amount, or -1 to stop: ";
        cin >>withdr;
 }	//display statistics
    cout <<"Done! Here are the monthly statistics: ";
    cout <<"\nBeginning balance:$"<<startingBalance;
    cout <<"\nNumber of withdrawals: $"<<checkAcc.getNumWithdrawals();
    cout <<"\nTotal amount of withdrawals:$"<<totalWithdr;
    cout <<"\nInitial monthly charges: $"<<initProcessCharges;	//get the service charges and owed amount in the structure and perform monthly processing
    temp =checkAcc.monthlyProc();
    cout <<"\nService fees:$"<<temp.servCharges;
    cout <<"\nTotal monthly charges: $"<<initProcessCharges +temp.servCharges;
    cout <<"\nEnding balance:$"<<checkAcc.getBalance();
    cout <<"\nClient owes to bank: $"<<checkAcc.getAmountOwed();
    cout <<endl ;
return 0;	//return 0 to mark successful termination
}
