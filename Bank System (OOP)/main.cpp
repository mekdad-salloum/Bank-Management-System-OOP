#include <iostream>
#include <iomanip>

#include "clsClient.h"
#include "clsInputValidate.h"
#include "clsUtility.h"

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

void PrintClientRecord(clsClient& Client)
{
	cout << clsUtility::Tabs(2);
	cout << "| " << setw(15) << left << Client.AccountNumber();
	cout << "| " << setw(20) << left << Client.FullName();
	cout << "| " << setw(12) << left << Client.Phone;
	cout << "| " << setw(20) << left << Client.Email;
	cout << "| " << setw(10) << left << Client.PinCode;
	cout << "| " << setw(12) << left << Client.Balance;
	cout << "\n";
}

void PrintClientBalanceRecord(clsClient& Client)
{
	cout << clsUtility::Tabs(5);
	cout << "| " << setw(15) << left << Client.AccountNumber();
	cout << "| " << setw(20) << left << Client.FullName();
	cout << "| " << setw(12) << left << Client.Balance;
	cout << "\n";
}

void ShowClientsList()
{
	vector <clsClient> Clients = clsClient::GetAllClients();

	cout << clsUtility::Tabs(7) << "Clients List (" << Clients.size() << ")\n";
	cout << clsUtility::Tabs(2) << "__________________________________________________________________________________________________\n\n";
	cout << clsUtility::Tabs(2);
	cout << "| " << setw(15) << left << "Account Number";
	cout << "| " << setw(20) << left << "Client Name";
	cout << "| " << setw(12) << left << "Phone";
	cout << "| " << setw(20) << left << "Email";
	cout << "| " << setw(10) << left << "Pin Code";
	cout << "| " << setw(12) << left << "Balance\n";
	cout << clsUtility::Tabs(2) << "__________________________________________________________________________________________________\n\n";

	if (Clients.size() == 0)
		cout << "\t\t\t\tNo Clients Available In the System!";

	else
	{
		for (clsClient& C : Clients)
		{
			PrintClientRecord(C);
		}
	}


	cout << clsUtility::Tabs(2) << "__________________________________________________________________________________________________\n";
}

void ShowTotalBalances()
{
	vector <clsClient> Clients = clsClient::GetAllClients();

	cout << clsUtility::Tabs(7) << "Balances List (" << Clients.size() << ")\n";
	cout << clsUtility::Tabs(5) << "_________________________________________________\n\n";
	cout << clsUtility::Tabs(5);
	cout << "| " << setw(15) << left << "Account Number";
	cout << "| " << setw(20) << left << "Client Name";
	cout << "| " << setw(12) << left << "Balance\n";
	cout << clsUtility::Tabs(5) << "_________________________________________________\n\n";

	double TotalBalances = clsClient::GetTotalBalances();

	if (Clients.size() == 0)
		cout << "\t\t\t\tNo Clients Available In the System!";

	else
	{
		for (clsClient& C : Clients)
		{
			PrintClientBalanceRecord(C);
		}
	}

	cout << clsUtility::Tabs(5) << "_________________________________________________\n\n";

	cout << clsUtility::Tabs(7) << "Total Balances = " << TotalBalances << ")\n";
	cout << clsUtility::Tabs(5) << "(" << clsUtility::NumberToText(TotalBalances) << ")\n";
}


int main()
{
	ShowTotalBalances();

	system("pause>0");

	return 0;
}