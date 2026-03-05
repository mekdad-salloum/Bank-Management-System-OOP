#pragma once

#include <iostream>

using namespace std;

class clsClientsListScreen : clsScreen
{

public:

	static void PrintClientRecord(clsClient& Client)
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

	static void ShowClientsList()
	{
		vector <clsClient> Clients = clsClient::GetAllClients();

		_DrawScreenHeader("Clients List Screen", "   (" + to_string(Clients.size()) + ") Clients.");

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

};

