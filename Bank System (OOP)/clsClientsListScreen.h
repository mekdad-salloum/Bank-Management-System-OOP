#pragma once

class clsClientsListScreen : protected clsScreen
{

public:

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
				clsClientUI::PrintClientRecord(C);
			}
		}


		cout << clsUtility::Tabs(2) << "__________________________________________________________________________________________________\n";
	}

};

