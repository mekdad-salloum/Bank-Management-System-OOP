#pragma once


class clsTransferScreen : protected clsScreen
{

private:

	static void _Transfer()
	{
		cout << "Enter Account Number To Transfer From: ";
		string FromAccountNumber = clsInputValidate::ReadString();

		cout << "\n";
		while (!clsClient::IsClientExist(FromAccountNumber))
		{
			cout << "Account Number (" + FromAccountNumber + ") Is Not Found, Choose Another One: ";
			FromAccountNumber = clsInputValidate::ReadString();
		}

		clsClient Client1 = clsClient::Find(FromAccountNumber);
		clsClientUI::PrintClientCard(Client1);

		cout << "\nEnter Account Number To Transfer To: ";
		string ToAccountNumber = clsInputValidate::ReadString();

		cout << "\n";
		while (!clsClient::IsClientExist(ToAccountNumber) || ToAccountNumber == FromAccountNumber)
		{
			cout << "Account Number (" + ToAccountNumber + ") Is Not Found, Choose Another One: ";
			ToAccountNumber = clsInputValidate::ReadString();
		}

		clsClient Client2 = clsClient::Find(ToAccountNumber);
		clsClientUI::PrintClientCard(Client2);

		cout << "\nEnter Transfer Amount: ";
		double Amount = clsInputValidate::ReadNumber<double>();

		cout << "\n";
		while (Client1.Balance < Amount)
		{
			cout << "Amount Exceeds The Available Balance, Enter Another Amount: ";
			Amount = clsInputValidate::ReadNumber<double>();
		}

		char Answer = 'N';
		cout << "\nAre You Sure You Want To Perform This Operaation? (Y/N) ";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			if (Client1.Transfer(Amount, Client2, clsGlobal::CurrentUser.UserName))
			{
				cout << "\nTransfer Done Successfully." << endl;
				clsClientUI::PrintClientCard(Client1);
				clsClientUI::PrintClientCard(Client2);

			}

			else
			{
				cout << "\nError, Try Again...\n";
			}
		}

		else
		{
			cout << "\nOperation Was Cancelled.\n";
		}
	}

public:

	static void ShowTransferScreen()
	{
		_DrawScreenHeader("Transfer Screen");

		_Transfer();
	}
};