#pragma once

#include <iostream>
#include <iomanip>
#include "clsClient.h"
#include "clsUtility.h"
#include "clsInputValidate.h"
#include "clsColor.h"

using namespace std;

class clsClientUI
{

public:

	static void PrintTransferLogRecord(clsClient::strTransferLogRecord& Record)
	{
		cout << clsUtility::Tabs(2);
		cout << clsColor::ColorRGB(clsColor::Cyan) << "| " << setw(25) << left << Record.DateTime;
		cout << clsColor::ColorRGB(clsColor::Red) << "| " << setw(15) << left << Record.SourceAccountNumber;
		cout << clsColor::ColorRGB(clsColor::Green) << "| " << setw(15) << left << Record.DestinationAccountNumber;
		cout << clsColor::ColorRGB(clsColor::Magenta) << "| " << setw(10) << left << Record.Amount;
		cout << clsColor::ColorRGB(clsColor::Red) << "| " << setw(10) << left << Record.SourceBalanceAfter;
		cout << clsColor::ColorRGB(clsColor::Green) << "| " << setw(10) << left << Record.DestinationBalanceAfter;
		cout << clsColor::ColorRGB(clsColor::Yellow) << "| " << setw(10) << left << Record.UserName;
		cout << "\n";
	}

	static void PrintClientBalanceRecord(clsClient& Client)
	{
		cout << clsColor::ColorRGB(clsColor::Cyan) << clsUtility::Tabs(3);
		cout << "| " << setw(15) << left << Client.AccountNumber();
		cout << "| " << setw(40) << left << Client.FullName();
		cout << "| " << setw(12) << left << Client.Balance;
		cout << "\n";
	}

	static void PrintClientRecord(clsClient& Client)
	{
		cout << clsColor::ColorRGB(clsColor::Yellow) << clsUtility::Tabs(2);
		cout << "| " << setw(15) << left << Client.AccountNumber();
		cout << "| " << setw(30) << left << Client.FullName();
		cout << "| " << setw(12) << left << Client.Phone;
		cout << "| " << setw(20) << left << Client.Email;
		cout << "| " << setw(10) << left << Client.PinCode;
		cout << clsColor::ColorRGB(clsColor::Lime) << "| " << setw(12) << left << Client.Balance;
		cout << "\n";
	}

	static void PrintClientCard(clsClient& Client)
	{
		cout << clsColor::ColorRGB(clsColor::Cyan);
		cout << "\nClient Card:";
		cout << clsColor::ColorRGB(clsColor::Magenta) << "\n____________________________________";
		cout << clsColor::ColorRGB(clsColor::Cyan) << "\nFirstName      : " << clsColor::ColorRGB(clsColor::Yellow) << Client.FirstName;
		cout << clsColor::ColorRGB(clsColor::Cyan) << "\nLastName       : " << clsColor::ColorRGB(clsColor::Yellow) << Client.LastName;
		cout << clsColor::ColorRGB(clsColor::Cyan) << "\nFull Name      : " << clsColor::ColorRGB(clsColor::Yellow) << Client.FullName();
		cout << clsColor::ColorRGB(clsColor::Cyan) << "\nEmail          : " << clsColor::ColorRGB(clsColor::Yellow) << Client.Email;
		cout << clsColor::ColorRGB(clsColor::Cyan) << "\nPhone          : " << clsColor::ColorRGB(clsColor::Yellow) << Client.Phone;
		cout << clsColor::ColorRGB(clsColor::Cyan) << "\nAccount Number : " << clsColor::ColorRGB(clsColor::Yellow) << Client.AccountNumber();
		cout << clsColor::ColorRGB(clsColor::Cyan) << "\nPassword       : " << clsColor::ColorRGB(clsColor::Yellow) << Client.PinCode;
		cout << clsColor::ColorRGB(clsColor::Cyan) << "\nBalance        : " << clsColor::ColorRGB(clsColor::Lime) << Client.Balance;
		cout << clsColor::ColorRGB(clsColor::Magenta) << "\n____________________________________\n";
		cout << clsColor::Reset();
	}

	static void ReadClientInfo(clsClient& Client)
	{
		cout << clsColor::ColorRGB(clsColor::LemonYellow) << "\nEnter First Name: ";
		cout << clsColor::ColorRGB(clsColor::White);
		Client.FirstName = clsInputValidate::ReadString();

		cout << clsColor::ColorRGB(clsColor::LemonYellow) << "Enter Last Name: ";
		cout << clsColor::ColorRGB(clsColor::White);
		Client.LastName = clsInputValidate::ReadString();

		cout << clsColor::ColorRGB(clsColor::LemonYellow) << "Enter Email: ";
		cout << clsColor::ColorRGB(clsColor::White);
		Client.Email = clsInputValidate::ReadString();

		cout << clsColor::ColorRGB(clsColor::LemonYellow) << "Enter Phone: ";
		cout << clsColor::ColorRGB(clsColor::White);
		Client.Phone = clsInputValidate::ReadString();

		cout << clsColor::ColorRGB(clsColor::LemonYellow) << "Enter PinCode: ";
		cout << clsColor::ColorRGB(clsColor::White);
		Client.PinCode = clsInputValidate::ReadString();

		cout << clsColor::ColorRGB(clsColor::LemonYellow) << "Enter Balance: ";
		cout << clsColor::ColorRGB(clsColor::White);
		Client.Balance = clsInputValidate::ReadNumber<double>();
		cout << clsColor::Reset();
	}


};
