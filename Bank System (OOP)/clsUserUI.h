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

	static void PrintLoginRegisterRecord(clsUser::strLoginRegisterRecord& Record)
	{
		cout << clsUtility::Tabs(2);
		cout << clsColor::ColorRGB(clsColor::Cyan) << "| " << setw(35) << left << Record.DateTime;
		cout << clsColor::ColorRGB(clsColor::Yellow) << "| " << setw(20) << left << Record.UserName;
		cout << clsColor::ColorRGB(clsColor::Violet) << "| " << setw(20) << left << Record.Password;
		cout << clsColor::ColorRGB(clsColor::Green) << "| " << setw(10) << left << Record.Permissions;
		cout << "\n";
		cout << clsColor::Reset();
	}

	static void PrintUserRecord(clsUser& User)
	{
		cout << clsColor::ColorRGB(clsColor::Yellow) << clsUtility::Tabs(2);
		cout << "| " << setw(15) << left << User.UserName;
		cout << "| " << setw(30) << left << User.FullName();
		cout << "| " << setw(12) << left << User.Phone;
		cout << "| " << setw(20) << left << User.Email;
		cout << "| " << setw(10) << left << User.Password;
		cout << clsColor::ColorRGB(clsColor::Lime) << "| " << setw(12) << left << User.Permissions;
		cout << "\n";
	}

	static void PrintUserCard(clsUser& User)
	{
		cout << clsColor::ColorRGB(clsColor::Cyan);
		cout << "\nUser Card:";
		cout << clsColor::ColorRGB(clsColor::Magenta) << "\n____________________________________";
		cout << clsColor::ColorRGB(clsColor::Cyan) << "\nFirstName   : " << clsColor::ColorRGB(clsColor::Yellow) << User.FirstName;
		cout << clsColor::ColorRGB(clsColor::Cyan) << "\nLastName    : " << clsColor::ColorRGB(clsColor::Yellow) << User.LastName;
		cout << clsColor::ColorRGB(clsColor::Cyan) << "\nFull Name   : " << clsColor::ColorRGB(clsColor::Yellow) << User.FullName();
		cout << clsColor::ColorRGB(clsColor::Cyan) << "\nEmail       : " << clsColor::ColorRGB(clsColor::Yellow) << User.Email;
		cout << clsColor::ColorRGB(clsColor::Cyan) << "\nPhone       : " << clsColor::ColorRGB(clsColor::Yellow) << User.Phone;
		cout << clsColor::ColorRGB(clsColor::Cyan) << "\nUserName    : " << clsColor::ColorRGB(clsColor::Yellow) << User.UserName;
		cout << clsColor::ColorRGB(clsColor::Cyan) << "\nPassword    : " << clsColor::ColorRGB(clsColor::Yellow) << User.Password;
		cout << clsColor::ColorRGB(clsColor::Cyan) << "\nPermissions : " << clsColor::ColorRGB(clsColor::Lime) << User.Permissions;
		cout << clsColor::ColorRGB(clsColor::Magenta) << "\n____________________________________\n";
	}

	static void ReadUserInfo(clsUser& User)
	{
		cout << clsColor::ColorRGB(clsColor::LemonYellow) << "\nEnter First Name: ";
		cout << clsColor::ColorRGB(clsColor::White);
		User.FirstName = clsInputValidate::ReadString();

		cout << clsColor::ColorRGB(clsColor::LemonYellow) << "Enter Last Name: ";
		cout << clsColor::ColorRGB(clsColor::White);
		User.LastName = clsInputValidate::ReadString();

		cout << clsColor::ColorRGB(clsColor::LemonYellow) << "Enter Email: ";
		cout << clsColor::ColorRGB(clsColor::White);
		User.Email = clsInputValidate::ReadString();

		cout << clsColor::ColorRGB(clsColor::LemonYellow) << "Enter Phone: ";
		cout << clsColor::ColorRGB(clsColor::White);
		User.Phone = clsInputValidate::ReadString();

		cout << clsColor::ColorRGB(clsColor::LemonYellow) << "Enter Password: ";
		cout << clsColor::ColorRGB(clsColor::White);
		User.Password = clsInputValidate::ReadString();

		cout << clsColor::ColorRGB(clsColor::LemonYellow) << "Enter Permissions: \n\n";
		cout << clsColor::ColorRGB(clsColor::White);
		User.Permissions = ReadUserPermissions();
	}

	static short ReadUserPermissions()
	{
		short Permissions = 0;
		char Answer = 'N';

		cout << clsColor::ColorRGB(clsColor::Yellow) << "Do You Want To Give Full Access? (Y/N)?  ";
		cout << clsColor::ColorRGB(clsColor::White);
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			Permissions = clsUser::pAllPermissions;
		}

		else
		{
			cout << clsColor::ColorRGB(clsColor::Yellow) << "\nDo You Want To Give Access To:\n\n";

			cout << clsColor::ColorRGB(clsColor::LemonYellow) << "Show Clients List? (Y/N)? ";
			cout << clsColor::ColorRGB(clsColor::White);
			Answer = clsInputValidate::ReadChar();

			if (toupper(Answer) == 'Y')
			{
				Permissions += clsUser::pShowClientsList;
			}

			cout << clsColor::ColorRGB(clsColor::LemonYellow) << "Add New CLient? (Y/N)? ";
			cout << clsColor::ColorRGB(clsColor::White);
			Answer = clsInputValidate::ReadChar();

			if (toupper(Answer) == 'Y')
			{
				Permissions += clsUser::pAddNewClient;
			}

			cout << clsColor::ColorRGB(clsColor::LemonYellow) << "Delete Client? (Y/N)? ";
			cout << clsColor::ColorRGB(clsColor::White);
			Answer = clsInputValidate::ReadChar();

			if (toupper(Answer) == 'Y')
			{
				Permissions += clsUser::pDeleteClient;
			}

			cout << clsColor::ColorRGB(clsColor::LemonYellow) << "Update Client? (Y/N)? ";
			cout << clsColor::ColorRGB(clsColor::White);
			Answer = clsInputValidate::ReadChar();

			if (toupper(Answer) == 'Y')
			{
				Permissions += clsUser::pUpdateClient;
			}

			cout << clsColor::ColorRGB(clsColor::LemonYellow) << "Find Client? (Y/N)? ";
			cout << clsColor::ColorRGB(clsColor::White);
			Answer = clsInputValidate::ReadChar();

			if (toupper(Answer) == 'Y')
			{
				Permissions += clsUser::pFindClient;
			}

			cout << clsColor::ColorRGB(clsColor::LemonYellow) << "Transactions? (Y/N)? ";
			cout << clsColor::ColorRGB(clsColor::White);
			Answer = clsInputValidate::ReadChar();

			if (toupper(Answer) == 'Y')
			{
				Permissions += clsUser::pTransactions;
			}

			cout << clsColor::ColorRGB(clsColor::LemonYellow) << "Manage Users? (Y/N)? ";
			cout << clsColor::ColorRGB(clsColor::White);
			Answer = clsInputValidate::ReadChar();

			if (toupper(Answer) == 'Y')
			{
				Permissions += clsUser::pManageUsers;
			}

			cout << clsColor::ColorRGB(clsColor::LemonYellow) << "Show Login Registers List? (Y/N)? ";
			cout << clsColor::ColorRGB(clsColor::White);
			Answer = clsInputValidate::ReadChar();

			if (toupper(Answer) == 'Y')
			{
				Permissions += clsUser::pLoginRegister;
			}

		}

		return Permissions;
	}


};

