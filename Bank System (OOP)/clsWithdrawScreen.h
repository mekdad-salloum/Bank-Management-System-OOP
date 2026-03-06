#pragma once


class clsWithdrawScreen : protected clsScreen
{

private:

	static void _Withdraw()
	{
		cout << "Enter Client Account Number: ";
		string AccountNumber = clsInputValidate::ReadString();

		cout << "\n";
		while (!clsClient::IsClientExist(AccountNumber))
		{
			cout << "Account Number (" + AccountNumber + ") Is Not Found: Choose Another One: ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsClient Client = clsClient::Find(AccountNumber);
		clsClientUI::PrintClientCard(Client);

		cout << "\nEnter Withdraw Amount: ";
		double Amount = clsInputValidate::ReadNumber<double>();

		char Answer = 'N';
		cout << "\nAre You Sure You Want To Perform This Transactions? (Y/N) ";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			if (Client.Withdraw(Amount))
			{
				cout << "\nAmount Withdrew Successfully, New Balance Is: " << Client.Balance << endl;
			}

			else
			{
				cout << "\nCannot Withdraw, Insuffecient Balance!\n";
				cout << "\nAmout To Withdraw is: " << Amount;
				cout << "\nYour Balance Is: " << Client.Balance;
			}
		}

		else
		{
			cout << "\nOperation Was Cancelled.\n";
		}
	}

public:

	static void ShowWithdrawScreen()
	{
		_DrawScreenHeader("Withdraw Screen");

		_Withdraw();
	}
};
