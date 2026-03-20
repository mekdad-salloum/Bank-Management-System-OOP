#pragma once


class clsDepositeScreen : protected clsScreen
{

private:

	static void _Deposite()
	{
		cout << clsColor::ColorRGB(clsColor::Yellow) << "Enter Client Account Number: ";
		string AccountNumber = clsInputValidate::ReadString();

		cout << "\n";
		while (!clsClient::IsClientExist(AccountNumber))
		{
			cout << clsColor::ColorRGB(clsColor::Red) << "Account Number (" + AccountNumber + ") Is Not Found, Choose Another One: ";
			cout << clsColor::ColorRGB(clsColor::Yellow);
			AccountNumber = clsInputValidate::ReadString();
		}

		clsClient Client = clsClient::Find(AccountNumber);
		clsClientUI::PrintClientCard(Client);

		cout << clsColor::ColorRGB(clsColor::LemonYellow) << "\nEnter Deposite Amount: ";
		cout << clsColor::ColorRGB(clsColor::Gold);
		double Amount = clsInputValidate::ReadPositiveNumber<double>();

		char Answer = 'N';
		cout << clsColor::ColorRGB(clsColor::DodgerBlue);
		cout << "\nAre You Sure You Want To Perform This Transactions? (Y/N) ";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			if (Client.Deposite(Amount))
			{
				cout << clsColor::ColorRGB(clsColor::Green) << "\nAmount Deposited Successfully, New Balance Is: " << clsColor::ColorRGB(clsColor::Gold) << Client.Balance << endl;
			}

			else
			{
				cout << clsColor::ColorRGB(clsColor::Red) << "\nError, Failed.\n";
			}
		}

		else
		{
			cout << clsColor::ColorRGB(clsColor::White) << "\nOperation Was Cancelled.\n";
		}
	}

public:

	static void ShowDepositeScreen()
	{
		_DrawScreenHeader("Deposite Screen");

		_Deposite();
	}
};
