#include <iostream>
#include "clsClient.h"
#include "clsInputValidate.h"

using namespace std;

void ReadClientInfo(clsClient& Client)
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

void AddNewClient()
{
	cout << "Enter Account Number: ";
	string AccountNumber = clsInputValidate::ReadString();

	while (clsClient::IsClientExist(AccountNumber))
	{
		cout << "Account Number Is Already Used, Choose Another One: ";
		AccountNumber = clsInputValidate::ReadString();
	}

	clsClient Client = clsClient::GetAddNewClientObject(AccountNumber);
	ReadClientInfo(Client);

	if (Client.Save())
	{
		cout << "\nClient Added Successfully :-)\n";
		Client.Print();
	}

	else
	{
		cout << "\nError Account Was Not Saved :-(\n";
	}
}

void UpdateClient()
{
	cout << "Enter Client Account Number: ";
	string AccountNumber = clsInputValidate::ReadString();

	while (!clsClient::IsClientExist(AccountNumber))
	{
		cout << "Account Number Is Not Found: Choose Another One: ";
		AccountNumber = clsInputValidate::ReadString();
	}
	
	clsClient Client = clsClient::Find(AccountNumber);
	Client.Print();

	cout << "\n\nUpdate Client Info:";
	cout << "\n---------------------\n";
	ReadClientInfo(Client);

	if (Client.Save())
	{
		cout << "\nClient Updated Successfully :-)\n";
		Client.Print();
	}

	else
	{
		cout << "\nError Account Was Not Saved :-(\n";
	}
}

void DeleteClient()
{
	cout << "Enter Client Account Number: ";
	string AccountNumber = clsInputValidate::ReadString();

	while (!clsClient::IsClientExist(AccountNumber))
	{
		cout << "Account Number Is Not Found: Choose Another One: ";
		AccountNumber = clsInputValidate::ReadString();
	}

	clsClient Client = clsClient::Find(AccountNumber);
	Client.Print();

	char Answer = 'N';
	cout << "\nAre You Sure You Want To Delete This Client? (Y/N) ";
	cin >> Answer;

	if (toupper(Answer) == 'Y')
	{
		if (Client.Delete())
		{
			cout << "\nClient Deleted Successfully :-)\n";
			Client.Print();
		}

		else
		{
			cout << "\nError, Account Was Not Deleted :-(\n";
		}
	}
}

int main()
{
	DeleteClient();

	system("pause>0");

	return 0;
}