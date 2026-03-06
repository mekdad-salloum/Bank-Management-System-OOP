#pragma once

class clsDeleteClientScreen : protected clsScreen
{

private:

	static void _DeleteClient()
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
			if (Client.Delete())
			{
				cout << "\nClient Deleted Successfully :-)\n";
				clsClientUI::PrintClientCard(Client);
			}

			else
			{
				cout << "\nError, Account Was Not Deleted :-(\n";
			}
		}

		else
		{
			cout << "\nOperation Was Cancelled.\n";
		}
	}

public:

	static void ShowDeleteClientScreen()
	{
		_DrawScreenHeader("Delete Client Screen");

		_DeleteClient();
	}


};

