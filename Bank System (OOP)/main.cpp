#include <iostream>
#include "clsClient.h"
#include "clsInputValidate.h"

using namespace std;

void ReadClientInfo(clsClient& Client)
{
	cout << "Enter First Name: ";
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
		cout << "\nClient Added Successfully :-)\n";
		Client.Print();
	}

	else
	{
		cout << "Error Account Was Not Saved :-(\n";
	}
}

int main()
{
	UpdateClient();

	system("pause>0");

	return 0;
}