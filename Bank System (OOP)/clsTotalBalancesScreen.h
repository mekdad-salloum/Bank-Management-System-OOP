#pragma once

class clsTotalBalancesScreen : protected clsScreen
{

public:

	static void ShowTotalBalancesScreen()
	{
		vector <clsClient> Clients = clsClient::GetAllClients();

		_DrawScreenHeader("Balances List Screen", "   (" + to_string(Clients.size()) + ") Client(s).");

		cout << clsUtility::Tabs(3) << "_________________________________________________________________________________\n\n";
		cout << clsUtility::Tabs(3);
		cout << "| " << setw(15) << left << "Account Number";
		cout << "| " << setw(40) << left << "Client Name";
		cout << "| " << setw(12) << left << "Balance\n";
		cout << clsUtility::Tabs(3) << "_________________________________________________________________________________\n\n";

		double TotalBalances = clsClient::GetTotalBalances();

		if (Clients.size() == 0)
			cout << "\t\t\t\tNo Clients Available In the System!";

		else
		{
			for (clsClient& C : Clients)
			{
				clsClientUI::PrintClientBalanceRecord(C);
			}
		}

		cout << clsUtility::Tabs(3) << "_________________________________________________________________________________\n\n";

		cout << clsUtility::Tabs(7) << "Total Balances = " << TotalBalances << "\n";
		cout << clsUtility::Tabs(6) << "( " << clsUtility::NumberToText(TotalBalances) << ")\n";
	}


};