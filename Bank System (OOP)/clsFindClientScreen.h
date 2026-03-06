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

		clsClient Client = clsClient::Find(AccountNumber);

		if (!Client.IsEmpty())
		{
			cout << "\nClient Found :-)\n";
		}
		else
		{
			cout << "\nClient Was not Found :-(\n";
		}

		clsClientUI::PrintClientCard(Client);
	}

public:
	
	static void ShowFindClientScreen()
	{
		_DrawScreenHeader("Find Client Screen");

		_FindClient();
	}

};
