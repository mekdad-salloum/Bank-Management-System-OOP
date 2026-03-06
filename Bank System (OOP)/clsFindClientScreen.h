#pragma once

class clsFindClientScreen : protected clsScreen
{

private:

	static void _FindClient()
	{
		cout << "Enter Client Account Number: ";
		string AccountNumber = clsInputValidate::ReadString();

		cout << "\n";
		while (!clsClient::IsClientExist(AccountNumber))
		{
			cout << "Account Number Is Not Found: Choose Another One: ";
			AccountNumber = clsInputValidate::ReadString();
		}

		cout << "Client Found :-)\n";
		clsClient Client = clsClient::Find(AccountNumber);
		clsClientUI::PrintClientCard(Client);
	}

public:
	
	static void ShowFindClient()
	{
		_DrawScreenHeader("Find Client Screen");

		_FindClient();
	}

};
