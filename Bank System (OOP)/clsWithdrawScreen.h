#pragma once


class clsWithdrawScreen : protected clsScreen
{

private:

	static void _Withdraw()
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

		cout << clsColor::ColorRGB(clsColor::LemonYellow) << "\nEnter Withdraw Amount: ";
		cout << clsColor::ColorRGB(clsColor::Gold);
		double Amount = clsInputValidate::ReadPositiveNumber<double>();

		char Answer = 'N';
		cout << clsColor::ColorRGB(clsColor::DodgerBlue);
		cout << "\nAre You Sure You Want To Perform This Transactions? (Y/N) ";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			if (Client.Withdraw(Amount))
			{
				cout << clsColor::ColorRGB(clsColor::Green) << "\nAmount Withdrew Successfully, New Balance Is: " << clsColor::ColorRGB(clsColor::Gold) << Client.Balance << endl;
			}

			else
			{
				cout << clsColor::ColorRGB(clsColor::Red) << "\nCannot Withdraw, Insuffecient Balance!\n";
				cout << clsColor::ColorRGB(clsColor::LemonYellow) << "\nAmout To Withdraw is: " << clsColor::ColorRGB(clsColor::Green) << Amount;
				cout << clsColor::ColorRGB(clsColor::LemonYellow) << "\nYour Balance Is: " << clsColor::ColorRGB(clsColor::Green) << Client.Balance;
			}
		}

		else
		{
			cout << clsColor::ColorRGB(clsColor::White) << "\nOperation Was Cancelled.\n";
		}
	}

public:

	static void ShowWithdrawScreen()
	{
		_DrawScreenHeader("Withdraw Screen");

		_Withdraw();
	}
};
