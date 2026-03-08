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
		cout << "\nUserName    : " << User.UserName;
		cout << "\nPassword    : " << User.Password;
		cout << "\nPermissions : " << User.Permissions;
		cout << "\n____________________________________\n";
	}

	static void ReadUserInfo(clsUser& User)
	{
		cout << "\nEnter First Name: ";
		User.FirstName = clsInputValidate::ReadString();

		cout << "Enter Last Name: ";
		User.LastName = clsInputValidate::ReadString();

		cout << "Enter Email: ";
		User.Email = clsInputValidate::ReadString();

		cout << "Enter Phone: ";
		User.Phone = clsInputValidate::ReadString();

		cout << "Enter Password: ";
		User.Password = clsInputValidate::ReadString();

		cout << "Enter Permissions: \n\n";
		User.Permissions = ReadUserPermissions();
	}

	static short ReadUserPermissions()
	{
		short Permissions = 0;
		char Answer = 'N';

		cout << "Do You Want To Give Full Access? (Y/N)?  ";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			Permissions = clsUser::pAllPermissions;
		}

		else
		{
			cout << "\nDo You Want To Give Access To:\n\n";

			cout << "Show Clients List? (Y/N)? ";
			Answer = clsInputValidate::ReadChar();

			if (toupper(Answer) == 'Y')
			{
				Permissions += clsUser::pShowClientsList;
			}

			cout << "Add New CLient? (Y/N)? ";
			Answer = clsInputValidate::ReadChar();

			if (toupper(Answer) == 'Y')
			{
				Permissions += clsUser::pAddNewClient;
			}

			cout << "Delete Client? (Y/N)? ";
			Answer = clsInputValidate::ReadChar();

			if (toupper(Answer) == 'Y')
			{
				Permissions += clsUser::pDeleteClient;
			}

			cout << "Update Client? (Y/N)? ";
			Answer = clsInputValidate::ReadChar();

			if (toupper(Answer) == 'Y')
			{
				Permissions += clsUser::pUpdateClient;
			}

			cout << "Find Client? (Y/N)? ";
			Answer = clsInputValidate::ReadChar();

			if (toupper(Answer) == 'Y')
			{
				Permissions += clsUser::pFindClient;
			}

			cout << "Transactions? (Y/N)? ";
			Answer = clsInputValidate::ReadChar();

			if (toupper(Answer) == 'Y')
			{
				Permissions += clsUser::pTransactions;
			}

			cout << "Manage Users? (Y/N)? ";
			Answer = clsInputValidate::ReadChar();

			if (toupper(Answer) == 'Y')
			{
				Permissions += clsUser::pManageUsers;
			}

		}

		return Permissions;
	}


};

