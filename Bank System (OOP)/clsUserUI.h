#pragma once

#include <iostream>
#include <iomanip>
#include "clsUser.h"
#include "clsUtility.h"
#include "clsInputValidate.h"

using namespace std;

class clsUserUI
{

public:

	static void PrintUserRecord(clsUser& User)
	{
		cout << clsUtility::Tabs(2);
		cout << "| " << setw(15) << left << User.UserName;
		cout << "| " << setw(30) << left << User.FullName();
		cout << "| " << setw(12) << left << User.Phone;
		cout << "| " << setw(20) << left << User.Email;
		cout << "| " << setw(10) << left << User.Password;
		cout << "| " << setw(12) << left << User.Permissions;
		cout << "\n";
	}

	static void PrintUserCard(clsUser& User)
	{
		cout << "\nUser Card:";
		cout << "\n____________________________________";
		cout << "\nFirstName   : " << User.FirstName;
		cout << "\nLastName    : " << User.LastName;
		cout << "\nFull Name   : " << User.FullName();
		cout << "\nEmail       : " << User.Email;
		cout << "\nPhone       : " << User.Phone;
		cout << "\nAcc. Number : " << User.UserName;
		cout << "\nPassword    : " << User.Password;
		cout << "\nBalance     : " << User.Permissions;
		cout << "\n____________________________________\n";
	}

	//static void ReadUserInfo(clsUser& User)
	//{
	//	cout << "\nEnter First Name: ";
	//	User.FirstName = clsInputValidate::ReadString();

	//	cout << "Enter Last Name: ";
	//	User.LastName = clsInputValidate::ReadString();

	//	cout << "Enter Email: ";
	//	User.Email = clsInputValidate::ReadString();

	//	cout << "Enter Phone: ";
	//	User.Phone = clsInputValidate::ReadString();

	//	cout << "Enter PinCode: ";
	//	User.PinCode = clsInputValidate::ReadString();

	//	cout << "Enter Balance: ";
	//	User.Balance = clsInputValidate::ReadNumber<double>();
	//}


};

