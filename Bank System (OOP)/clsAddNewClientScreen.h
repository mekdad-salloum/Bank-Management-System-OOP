#pragma once

class clsAddNewClientScreen : protected clsScreen
{
private:

	static void _AddNewClient()
	{
		cout << "Enter Account Number: ";
		string AccountNumber = clsInputValidate::ReadString();

		cout << "\n";
		while (clsClient::IsClientExist(AccountNumber))
		{
			cout << "Account Number Is Already Used, Choose Another One: ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsClient Client = clsClient::GetAddNewClientObject(AccountNumber);
		clsClientUI::ReadClientInfo(Client);

		if (Client.Save())
		{
			cout << "\nClient Added Successfully :-)\n";
			clsClientUI::PrintClientCard(Client);
		}

		else
		{
			cout << "\nError Account Was Not Saved :-(\n";
		}
	}

public:


	static void ShowAddNewClientScreen()
	{
		_DrawScreenHeader("Add New Client Screen");

		_AddNewClient();
	}

};

