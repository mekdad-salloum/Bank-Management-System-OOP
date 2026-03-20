#pragma once


class clsUpdateCurrencyRateScreen : protected clsScreen
{

private:

	static void _UpdateCurrency()
	{
		clsCurrency Currency = clsCurrencyUI::GetCurrency("Enter Currency Code: ");
		clsCurrencyUI::PrintCurrencyCard(Currency);

		cout << clsColor::ColorRGB(clsColor::White) << "\nAre You Sure You Want To Update The Rate Of This Currency? (Y/N) ";
		char Answer = 'N';
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			cout << clsColor::ColorRGB(clsColor::Cyan) << "\nUpdate Currency Rate:";
			cout << clsColor::ColorRGB(clsColor::Magenta) << "\n________________________\n";
			cout << clsColor::ColorRGB(clsColor::Yellow) << "\nEnter New Rate: ";
			Currency.Rate = clsInputValidate::ReadPositiveNumber<double>();

			if (Currency.Save())
			{
				cout << clsColor::ColorRGB(clsColor::Green) << "\nCurrency Updated Successfully :-)\n";
				clsCurrencyUI::PrintCurrencyCard(Currency);
			}

			else
			{
				cout << clsColor::ColorRGB(clsColor::Red) << "\nError Currency Was Not Saved :-(\n";
			}
		}

		else
		{
			cout << clsColor::ColorRGB(clsColor::White) << "\nOperation Was Cancelled\n";
		}
	}

public:

	static void ShowUpdateCurrencyRateScreen()
	{
		_DrawScreenHeader("Update Currency Screen");

		_UpdateCurrency();
	}
};