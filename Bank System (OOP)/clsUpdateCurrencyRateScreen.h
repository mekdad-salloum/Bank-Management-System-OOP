#pragma once


class clsUpdateCurrencyRateScreen : protected clsScreen
{

private:

	static void _UpdateCurrency()
	{
		clsCurrency Currency = clsCurrencyUI::GetCurrency("Enter Currency Code: ");
		clsCurrencyUI::PrintCurrencyCard(Currency);

		cout << "\nAre You Sure You Want To Update The Rate Of This Currency? (Y/N) ";
		char Answer = 'N';
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			cout << "\nUpdate Currency Rate:";
			cout << "\n________________________\n";
			cout << "\nEnter New Rate: ";
			Currency.Rate = clsInputValidate::ReadPositiveNumber<double>();

			if (Currency.Save())
			{
				cout << "\nCurrency Updated Successfully :-)\n";
				clsCurrencyUI::PrintCurrencyCard(Currency);
			}
		}

		else
		{
			cout << "\nOperation Was Cancelled\n";
		}
	}

public:

	static void ShowUpdateCurrencyRateScreen()
	{
		_DrawScreenHeader("Update Currency Screen");

		_UpdateCurrency();
	}
};