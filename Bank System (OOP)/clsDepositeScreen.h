#pragma once


class clsDepositeScreen : protected clsScreen
{

private:

	static void _Deposite()
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

		cout << "\nEnter Deposite Amount: ";
		double Amount = clsInputValidate::ReadPositiveNumber<double>();

		char Answer = 'N';
		cout << "\nAre You Sure You Want To Perform This Transactions? (Y/N) ";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			if (Client.Deposite(Amount))
			{
				cout << "\nAmount Deposited Successfully, New Balance Is: " << Client.Balance << endl;
			}

			else
			{
				cout << "\nError, Failed.\n";
			}
		}

		else
		{
			cout << "\nOperation Was Cancelled.\n";
		}
	}

public:

	static void ShowDepositeScreen()
	{
		_DrawScreenHeader("Deposite Screen");

		_Deposite();
	}
};
