#include <iostream>
#include <iomanip>

#include "clsClient.h"
#include "clsInputValidate.h"
#include "clsUtility.h"
#include "clsMainMenuScreen.h"

using namespace std;


void PrintClientBalanceRecord(clsClient& Client)
{
	cout << clsUtility::Tabs(5);
	cout << "| " << setw(15) << left << Client.AccountNumber();
	cout << "| " << setw(20) << left << Client.FullName();
	cout << "| " << setw(12) << left << Client.Balance;
	cout << "\n";
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
	clsMainMenuScreen::ShowMainMenuScreen();

	system("pause>0");

	return 0;
}