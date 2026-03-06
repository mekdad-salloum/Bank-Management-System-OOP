#pragma once

class clsAddNewClientScreen : protected clsScreen
{
private:

	static void _ReadClientInfo(clsClient & Client)
	{
		cout << "\nEnter First Name: ";
		Client.FirstName = clsInputValidate::ReadString();

		cout << "Enter Last Name: ";
		Client.LastName = clsInputValidate::ReadString();

		cout << "Enter Email: ";
		Client.Email = clsInputValidate::ReadString();

		cout << "Enter Phone: ";
		Client.Phone = clsInputValidate::ReadString();

		cout << "Enter PinCode: ";
		Client.PinCode = clsInputValidate::ReadString();

		cout << "Enter Balance: ";
		Client.Balance = clsInputValidate::ReadNumber<double>();
	}

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
		_ReadClientInfo(Client);

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


	static void ShowAddNewClient()
	{
		_DrawScreenHeader("Add New Client Screen");

		_AddNewClient();
	}

};

