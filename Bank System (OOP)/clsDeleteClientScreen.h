#pragma once

class clsDeleteClientScreen : protected clsScreen
{

private:

	static void _DeleteClient()
	{
		cout << clsColor::ColorRGB(clsColor::Yellow) << "Enter Client Account Number: ";
		string AccountNumber = clsInputValidate::ReadString();

		cout << "\n";
		while (!clsClient::IsClientExist(AccountNumber))
		{
			cout << clsColor::ColorRGB(clsColor::Red) << "Account Number Is Not Found: Choose Another One: ";
			cout << clsColor::ColorRGB(clsColor::Yellow);
			AccountNumber = clsInputValidate::ReadString();
		}

		clsClient Client = clsClient::Find(AccountNumber);
		clsClientUI::PrintClientCard(Client);

		char Answer = 'N';
		cout << clsColor::ColorRGB(clsColor::White) << "\nAre You Sure You Want To Delete This Client? (Y/N) ";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			if (Client.Delete())
			{
				cout << clsColor::ColorRGB(clsColor::Green) << "\nClient Deleted Successfully :-)\n";
				clsClientUI::PrintClientCard(Client);
			}

			else
			{
				cout << clsColor::ColorRGB(clsColor::Red) << "\nError, Account Was Not Deleted :-(\n";
			}
		}

		else
		{
			cout << clsColor::ColorRGB(clsColor::White) << "\nOperation Was Cancelled.\n";
		}
	}

public:

	static void ShowDeleteClientScreen()
	{
		if (!CheckAccessRights(clsUser::pDeleteClient))
		{
			return;
		}

		_DrawScreenHeader("Delete Client Screen");

		_DeleteClient();
	}


};

