#pragma once

#include <iostream>
#include <iomanip>
#include "clsClient.h"
#include "clsUtility.h"
#include "clsInputValidate.h"

using namespace std;

class clsClientUI
{

public:

	static void PrintTransferLogRecord(clsClient::strTransferLogRecord& Record)
	{
		cout << clsUtility::Tabs(2);
		cout << "| " << setw(25) << left << Record.DateTime;
		cout << "| " << setw(15) << left << Record.SourceAccountNumber;
		cout << "| " << setw(15) << left << Record.DestinationAccountNumber;
		cout << "| " << setw(10) << left << Record.Amount;
		cout << "| " << setw(10) << left << Record.SourceBalanceAfter;
		cout << "| " << setw(10) << left << Record.DestinationBalanceAfter;
		cout << "| " << setw(10) << left << Record.UserName;
		cout << "\n";
	}

	static void PrintClientBalanceRecord(clsClient& Client)
	{
		cout << clsUtility::Tabs(3);
		cout << "| " << setw(15) << left << Client.AccountNumber();
		cout << "| " << setw(40) << left << Client.FullName();
		cout << "| " << setw(12) << left << Client.Balance;
		cout << "\n";
	}

	static void PrintClientRecord(clsClient& Client)
	{
		cout << clsUtility::Tabs(2);
		cout << "| " << setw(15) << left << Client.AccountNumber();
		cout << "| " << setw(30) << left << Client.FullName();
		cout << "| " << setw(12) << left << Client.Phone;
		cout << "| " << setw(20) << left << Client.Email;
		cout << "| " << setw(10) << left << Client.PinCode;
		cout << "| " << setw(12) << left << Client.Balance;
		cout << "\n";
	}

	static void PrintClientCard(clsClient& Client)
	{
		cout << "\nClient Card:";
		cout << "\n____________________________________";
		cout << "\nFirstName      : " << Client.FirstName;
		cout << "\nLastName       : " << Client.LastName;
		cout << "\nFull Name      : " << Client.FullName();
		cout << "\nEmail          : " << Client.Email;
		cout << "\nPhone          : " << Client.Phone;
		cout << "\nAccount Number : " << Client.AccountNumber();
		cout << "\nPassword       : " << Client.PinCode;
		cout << "\nBalance        : " << Client.Balance;
		cout << "\n____________________________________\n";
	}

	static void ReadClientInfo(clsClient& Client)
	{
		cout << "\nEnter First Name: ";
		Client.FirstName = clsInputValidate::ReadString();

		cout << "Enter Last Name: ";
		Client.LastName = clsInputValidate::ReadString();

		cout << "Enter Email: ";
		Client.Email = clsInputValidate::ReadString();

		cout << "Enter Phone: ";
		Client.Phone = clsInputValidate::ReadString();

		cout << "Enter PinCode: ";
		Client.PinCode = clsInputValidate::ReadString();

		cout << "Enter Balance: ";
		Client.Balance = clsInputValidate::ReadNumber<double>();
	}


};

