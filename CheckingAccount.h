//contents of CheckingAccount.h
#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H
#include <iostream>
#include<stdlib.h>
#include "BankAccount.h"
using namespace std;
class CheckingAccount :public BankAccount
{
private:  //member variable to keep track of how much is owed to the bank
double owed;
public:    
    CheckingAccount(double b,double air):BankAccount(b,air)	//constructor, will call constructor of parent class
{
    owed =0.0;
}
double getAmountOwed() const	//accessor function
{
        return owed;   
}
virtual void withdraw(double w)			//withdraw() function of the checking account
{
if(w >balance)	//first check if withdrawal will bring the balance to negative
{           		//print error message
        cout << fixed << setprecision(2);
        cout <<"Withdrawal failed! You attempted to check $";
        cout <<w <<" but current balance is$"<<balance;
        cout <<".\nYou will be charged $15.00 for this.\n";	//subtract 15 from balance
            balance -=15.0;       
}        
else	//else, simply perform withdrawal
{
        BankAccount::withdraw(w);        
}
}
virtual ServAndOwed monthlyProc()		//monthlyProc() function of checking account
{
        serviceCharges +=5.0;	//add fee to service charges
        serviceCharges +=0.1* numWithdrawal;	//also add the charges per withdrawal
        mnCharges +=serviceCharges;     //add the service charges to monthly charges   
        ServAndOwed temp;			//structure to return at the end, the service charges and total owed to bank, because they will be reset upon execution of BankAccount::monthlyProc()
        temp.servCharges =serviceCharges;	//perform monthly processing this will reset the serviceCharges variable
        BankAccount::monthlyProc(); 	//after processing, check if balance is negative
	if(balance <0)
{    
    owed =0-balance;	//update owed member variable to amount owed to bank by user
}
        temp.totalOwed =owed;  //store it in the structure 
        owed =0;        //reset owed to 0
	return temp;		//return the structure, from which can be retrieved the service charges of this month
}
};
#endif
