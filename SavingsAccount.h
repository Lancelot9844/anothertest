//contents of SavingsAccount.h
#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H
#include <iostream>
#include<stdlib.h>
#include <iomanip>
#include "BankAccount.h"
using namespace std;
class SavingsAccount :public BankAccount
{
private:	//flag to hold status of account
    bool status;

    bool ACTIVE =true;

    bool INACTIVE =false;


public:		//class constructor, will also call constructor of base class

    SavingsAccount(double b,double air): BankAccount(b, air)    
{
if(balance >=25)	//check if balance is greater than 25 to set correct status
{
        status =ACTIVE;
}
else	//otherwise it must be inactive
{
            status =INACTIVE;
}
}
    bool getStatus() const		//accessor function
{
	return status;
}
	virtual void withdraw(double w)		//withdraw() function of SavingsAccount
{		
	if(status ==ACTIVE)	//check if status is active
{    
		
        BankAccount::withdraw(w);	//if yes, proceed with withdrawal	
		if(balance <25)		//update status if necessary
		status =INACTIVE;        
}    
	else
{
			//otherwise, print error message then return
            cout <<fixed <<setprecision(2);
            cout <<"Withdrawal failed! Savings account ";
            cout <<"is inactive (Current balance: $";
            cout <<balance <<")"<<endl;        
}    
}
	virtual void deposit(double d)		//deposit() function
{       
	if(status ==INACTIVE)		//check if account is inactive
{
	if(d +balance >=25)		//check if deposit will bring balance over 25
{
                BankAccount::deposit(d);         				//if yes, proceed with deposit  
}           
else
{    //if not, print error message then return
                cout <<fixed <<setprecision(2);
                cout <<"Deposit failed! Savings account will";
                cout <<" be inactive after deposit!\n($";
                cout <<balance <<" +$"<<d;
                cout <<" = $"<<balance +d <<")\n";  
	return;            
}
}
	else	//first if statement ends here otherwise
{   
        BankAccount::deposit(d);			//means account is still active simply proceed with deposit
}    
}
virtual	ServAndOwed monthlyProc()		//monthlyProc() function
{
if(numWithdrawal >4)		//first check number of withdrawals
{
            serviceCharges +=1.0*(numWithdrawal -4);	//add the relevant charges to service charges
            mnCharges +=serviceCharges;        //add the service charges to monthly charges
}
        ServAndOwed temp;			//structure to return at the end, the service charges, because they will be reset upon execution of BankAccount::monthlyProc()
        temp.servCharges =serviceCharges;
		temp.totalOwed =0.0;      //perform monthly processing
        BankAccount::monthlyProc();       //check if balance has fallen below 25 to update status if necessary
		if(balance <25)
{
        status =INACTIVE;        
}
		return temp;		//return the structure, from which can be retrieved the service charges of this month
}
};
#endif
