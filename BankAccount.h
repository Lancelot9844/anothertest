/*contents of BankAccount.h*/
#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#include <iostream>
#include<stdlib.h>
using namespace std;
struct ServAndOwed	//structure to be returned by monthlyProc() function, so it can return both service charges and amount owed
{    
double servCharges;
double totalOwed;
};
class BankAccount
{
protected:
double balance;		//member variables are declared protected so they can be easily accessed by derived classes
int numDeposits;
int numWithdrawal;
double annualIntRate;
double mnCharges;
double serviceCharges;		//added member to store service charges of a month
public:   	//constructor that accepts values for balance and annual interest rate
    BankAccount(double b, double air)
{		
if(b <0)	//check for invalid input
{
            cout<<"Error! Balance cannot start with";
            cout <<" a negative amount!\n";
            cout <<"Now terminating!\n";
            exit(EXIT_FAILURE);       
}
	if(air <0)
{
            cout <<"Error! Annual interest rate";
            cout <<" cannot be negative!\n";
            cout <<"Now terminating!\n";
            exit(EXIT_FAILURE);
}
        balance =b;			//set balance and annual interest rate to argument values
        annualIntRate =air;
        numDeposits =0;			//set some initial values to other member variables
        numWithdrawal =0;
        mnCharges =0.0;    
        serviceCharges =0.0;	//set service charges member
}
double getBalance() const  //accessor functions
{
	return balance;    
}    
int getNumDeposits()const
{
	return numDeposits;
}
int getNumWithdrawals()const
{
	return numWithdrawal;
}
double getAnnualIntRate()const
{
	return annualIntRate;
}
double getMonthlyCharges()const
{ 
	return mnCharges;    
}
void setAnnualIntRate ( double air) //mutator functions
{
	while(air <0)//validate input using while loop
{
            cout <<"Negative values for annual interest ";
            cout <<"rates not accepted! Enter again: ";
            cin >>air;
}
	        annualIntRate =air;  	//store value in member variable
}
	void setMonthlyCharges(double mc)
{        
	while(mc <0)	//validate input using while loop
{
            cout <<"Negative values for monthly charges ";
            cout <<"are not accepted! Enter again: ";
            cin >>mc;        
}
        mnCharges =mc;  //store value in member variable
}
virtual void deposit(double d)	//mutator functions for number of deposits and withdrawals, and also for the balance are not necessary, because they will be controlled by the number of transactions deposit() function
{
        balance +=d;		//add the argument to the balance
        numDeposits++;   //increment number of deposits
}
	virtual void withdraw(double w)		//withdraw() function
{    
        balance -=w;     	//subtract the argument from balance  
        numWithdrawal++;    	//increment number of withdrawals
}    
	virtual void calcInt()		//calcInt() function to add the accumulated interest to the balance
{ 
    balance +=(annualIntRate/12.0)*balance;		//add to current balance the monthly interest monthly interest is monthly interest rate times balance monthly interest rate is annual interest rate divided by 12
}
virtual ServAndOwed monthlyProc()	//monthlyProc() function this is the function that is called at the end of each month, to get the monthly fee and reset transactions also, this function will return the service charges for the month
{
    balance -=mnCharges;		//subtract monthly charges from balance
    calcInt();			//add monthly interest to balance
    numDeposits =0;		//reset number of deposits and withdrawals
    numWithdrawal =0;		
    mnCharges =0.0;		//also reset monthly charges to 0
    serviceCharges =0.0;			//also reset service charges   
    ServAndOwed temp;	 //a return statement	
	return temp;    //could return any struct ServAndOwed
}
};
#endif
