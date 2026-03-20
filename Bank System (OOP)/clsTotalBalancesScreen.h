#pragma once

class clsTotalBalancesScreen : protected clsScreen
{

public:

	static void ShowTotalBalancesScreen()
	{
		vector <clsClient> Clients = clsClient::GetAllClients();

		_DrawScreenHeader("Balances List Screen", "   (" + to_string(Clients.size()) + ") Client(s).");

		cout << clsColor::ColorRGB(clsColor::Red) << clsUtility::Tabs(3) << "_________________________________________________________________________________\n\n";
		cout << clsColor::ColorRGB(clsColor::Magenta) << clsUtility::Tabs(3);
		cout << "| " << setw(15) << left << "Account Number";
		cout << "| " << setw(40) << left << "Client Name";
		cout << "| " << setw(12) << left << "Balance\n";
		cout << clsColor::ColorRGB(clsColor::Red) << clsUtility::Tabs(3) << "_________________________________________________________________________________\n\n";

		double TotalBalances = clsClient::GetTotalBalances();

		if (Clients.size() == 0)
			cout << clsColor::ColorRGB(clsColor::Lime) << "\t\t\t\tNo Clients Available In the System!";

		else
		{
			for (clsClient& C : Clients)
			{
				clsClientUI::PrintClientBalanceRecord(C);
			}
		}

		cout << clsColor::ColorRGB(clsColor::Red) << clsUtility::Tabs(3) << "_________________________________________________________________________________\n\n";

		cout << clsColor::ColorRGB(clsColor::Salmon) << clsUtility::Tabs(7) << "Total Balances = " << clsColor::ColorRGB(clsColor::Green) << TotalBalances << "\n";
		cout << clsColor::ColorRGB(clsColor::Yellow) << clsUtility::Tabs(6) << "( " << clsUtility::NumberToText(TotalBalances) << ")\n";
	}


};