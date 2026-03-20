#pragma once

class clsUpdateClientScreen : protected clsScreen
{

private:

	static void _UpdateClient()
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
		cout << clsColor::ColorRGB(clsColor::White) << "\nAre You Sure You Want To Update This Client? (Y/N) ";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			cout << clsColor::ColorRGB(clsColor::Cyan) << "\n\nUpdate Client Info:";
			cout << clsColor::ColorRGB(clsColor::Magenta) << "\n_____________________\n";
			clsClientUI::ReadClientInfo(Client);

			if (Client.Save())
			{
				cout << clsColor::ColorRGB(clsColor::Green) << "\nClient Updated Successfully :-)\n";
				clsClientUI::PrintClientCard(Client);
			}

			else
			{
				cout << clsColor::ColorRGB(clsColor::Red) << "\nError Account Was Not Saved :-(\n";
			}
		}

		else
		{
			cout << clsColor::ColorRGB(clsColor::White) << "\nOperation Was Cancelled.\n";
		}
	}

public:

	static void ShowUpdateClientScreen()
	{
		if (!CheckAccessRights(clsUser::pUpdateClient))
		{
			return;
		}

		_DrawScreenHeader("Update Client Screen");

		_UpdateClient();
	}

};