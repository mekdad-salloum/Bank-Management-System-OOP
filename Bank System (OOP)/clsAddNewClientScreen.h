#pragma once

class clsAddNewClientScreen : protected clsScreen
{
private:

	static void _AddNewClient()
	{
		cout << clsColor::ColorRGB(clsColor::Yellow) << "Enter Account Number: ";
		string AccountNumber = clsInputValidate::ReadString();

		cout << "\n";
		while (clsClient::IsClientExist(AccountNumber))
		{
			cout << clsColor::ColorRGB(clsColor::Red) << "Account Number Is Already Used, Choose Another One: ";
			cout << clsColor::ColorRGB(clsColor::Yellow);
			AccountNumber = clsInputValidate::ReadString();
		}

		clsClient Client = clsClient::GetAddNewClientObject(AccountNumber);
		clsClientUI::ReadClientInfo(Client);

		if (Client.Save())
		{
			cout << clsColor::ColorRGB(clsColor::Green) << "\nClient Added Successfully :-)\n";
			clsClientUI::PrintClientCard(Client);
		}

		else
		{
			cout << clsColor::ColorRGB(clsColor::Red) << "\nError Account Was Not Saved :-(\n";
		}
	}

public:


	static void ShowAddNewClientScreen()
	{
		if (!CheckAccessRights(clsUser::pAddNewClient))
		{
			return;
		}

		_DrawScreenHeader("Add New Client Screen");

		_AddNewClient();
	}

};

