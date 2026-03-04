#pragma once

#include "clsPerson.h"
#include "clsString.h"

#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

class clsClient : public clsPerson
{

private:

	enum enMode {EmptyMode = 0, AddNewMode = 1, UpdateMode = 2};

	enMode _Mode;
	string _AccountNumber;
	string _PinCode;
	double _Balance;

	
	static clsClient _ConvertLineToClientObject(string Line, string Seperator = "//")
	{
		clsClient Client;
		vector <string> sClient = clsString::Split(Line, Seperator);

		return clsClient(enMode::UpdateMode, sClient[0], sClient[1], sClient[2], sClient[3], sClient[4], sClient[5], stod(sClient[6]));
	}

	static vector <clsClient> _LoadClientsFromFile(string FileName)
	{
		vector <clsClient> Clients;
		fstream File;
		File.open(FileName, ios::in);

		if (File.is_open())
		{
			string Line = "";
			clsClient Client;

			while (getline(File, Line))
			{
				Client = _ConvertLineToClientObject(Line);
				Clients.push_back(Client);
			}

			File.close();
		}

		return Clients;
	}

	static clsClient _GetEmptyClientObject()
	{
		return clsClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}

public:

	clsClient(enMode Mode, string FirstName, string LastName, string Email, string Phone, string AccountNumber, string PinCode, double Balance)
		: clsPerson(FirstName, LastName, Email, Phone)
	{
		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_PinCode = PinCode;
		_Balance = Balance;
	}

	clsClient() : clsPerson()
	{
		_Mode = enMode::AddNewMode;
		_AccountNumber = "";
		_PinCode = "";
		_Balance = 0;
	}

	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}


	string AccountNumber()
	{
		return _AccountNumber;
	}


	void SetPinCode(string PinCode)
	{
		_PinCode = PinCode;
	}

	string GetPinCode()
	{
		return _PinCode;
	}

	__declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;


	void SetBalance(double Balance)
	{
		_Balance = Balance;
	}

	double GetBalance()
	{
		return _Balance;
	}

	__declspec(property(get = GetBalance, put = SetBalance)) double Balance;


	static clsClient Find(string AccountNumber)
	{
		fstream File;
		File.open("Clients.txt", ios::in);

		if (File.is_open())
		{
			string Line;
			clsClient Client;

			while (getline(File, Line))
			{
				Client = _ConvertLineToClientObject(Line);

				if (Client.AccountNumber() == AccountNumber)
				{
					File.close();
					return Client;
				}
			}

			File.close();
		}

		return _GetEmptyClientObject();
	}

	static clsClient Find(string AccountNumber, string PinCode)
	{
		fstream File;
		File.open("Clients.txt", ios::in);

		if (File.is_open())
		{
			string Line;
			clsClient Client;

			while (getline(File, Line))
			{
				Client = _ConvertLineToClientObject(Line);

				if (Client.AccountNumber() == AccountNumber && Client.PinCode == PinCode)
				{
					File.close();
					return Client;
				}
			}

			File.close();
		}

		return _GetEmptyClientObject();
	}

	static bool IsClientExist(string AccountNumber)
	{
		clsClient Client = Find(AccountNumber);

		return !(Client.IsEmpty());
	}

	void Print()
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << FirstName;
		cout << "\nLastName    : " << LastName;
		cout << "\nFull Name   : " << FullName();
		cout << "\nEmail       : " << Email;
		cout << "\nPhone       : " << Phone;
		cout << "\nAcc. Number : " << AccountNumber();
		cout << "\nPassword    : " << PinCode;
		cout << "\nBalance     : " << Balance;
		cout << "\n___________________\n";
	}

};