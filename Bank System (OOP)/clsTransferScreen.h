#pragma once


class clsTransferScreen : protected clsScreen
{

private:

	static void _Transfer()
	{
		cout << clsColor::ColorRGB(clsColor::Yellow) << "Enter Account Number To Transfer From: ";
		string FromAccountNumber = clsInputValidate::ReadString();

		cout << "\n";
		while (!clsClient::IsClientExist(FromAccountNumber))
		{
			cout << clsColor::ColorRGB(clsColor::Red) << "Account Number (" + FromAccountNumber + ") Is Not Found, Choose Another One: ";
			cout << clsColor::ColorRGB(clsColor::Yellow);
			FromAccountNumber = clsInputValidate::ReadString();
		}

		clsClient Client1 = clsClient::Find(FromAccountNumber);
		clsClientUI::PrintClientCard(Client1);

		cout << clsColor::ColorRGB(clsColor::Yellow) << "\nEnter Account Number To Transfer To: ";
		string ToAccountNumber = clsInputValidate::ReadString();

		cout << "\n";
		while (!clsClient::IsClientExist(ToAccountNumber) || ToAccountNumber == FromAccountNumber)
		{
			cout << clsColor::ColorRGB(clsColor::Red) << "Account Number (" + ToAccountNumber + ") Is Not Found, Choose Another One: ";
			cout << clsColor::ColorRGB(clsColor::Yellow);
			ToAccountNumber = clsInputValidate::ReadString();
		}

		clsClient Client2 = clsClient::Find(ToAccountNumber);
		clsClientUI::PrintClientCard(Client2);

		cout << clsColor::ColorRGB(clsColor::LemonYellow) << "\nEnter Transfer Amount: ";
		cout << clsColor::ColorRGB(clsColor::Gold);
		double Amount = clsInputValidate::ReadNumber<double>();

		cout << "\n";
		while (Client1.Balance < Amount)
		{
			cout << clsColor::ColorRGB(clsColor::Red) << "Amount Exceeds The Available Balance, Enter Another Amount: ";
			cout << clsColor::ColorRGB(clsColor::Gold);
			Amount = clsInputValidate::ReadNumber<double>();
		}

		char Answer = 'N';
		cout << clsColor::ColorRGB(clsColor::DodgerBlue);
		cout << "\nAre You Sure You Want To Perform This Operaation? (Y/N) ";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			if (Client1.Transfer(Amount, Client2, clsGlobal::CurrentUser.UserName))
			{
				cout << clsColor::ColorRGB(clsColor::Green) << "\nTransfer Done Successfully." << endl;
				clsClientUI::PrintClientCard(Client1);
				clsClientUI::PrintClientCard(Client2);

			}

			else
			{
				cout << clsColor::ColorRGB(clsColor::Red) << "\nError, Try Again...\n";
			}
		}

		else
		{
			cout << clsColor::ColorRGB(clsColor::White) << "\nOperation Was Cancelled.\n";
		}
	}

public:

	static void ShowTransferScreen()
	{
		_DrawScreenHeader("Transfer Screen");

		_Transfer();
	}
};