#pragma once

class clsUpdateClientScreen : protected clsScreen
{

private:

	static void _UpdateClient()
	{
		cout << "Enter Client Account Number: ";
		string AccountNumber = clsInputValidate::ReadString();

		cout << "\n";
		while (!clsClient::IsClientExist(AccountNumber))
		{
			cout << "Account Number Is Not Found: Choose Another One: ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsClient Client = clsClient::Find(AccountNumber);
		clsClientUI::PrintClientCard(Client);

		char Answer = 'N';
		cout << "\nAre You Sure You Want To Delete This Client? (Y/N) ";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			cout << "\n\nUpdate Client Info:";
			cout << "\n_____________________\n";
			clsClientUI::ReadClientInfo(Client);

			if (Client.Save())
			{
				cout << "\nClient Updated Successfully :-)\n";
				clsClientUI::PrintClientCard(Client);
			}

			else
			{
				cout << "\nError Account Was Not Saved :-(\n";
			}
		}

		else
		{
			cout << "\nOperation Was Cancelled.\n";
		}
	}

public:

	static void ShowUpdateClientScreen()
	{
		_DrawScreenHeader("Update Client Screen");

		_UpdateClient();
	}

};