#pragma once

class clsFindCurrencyScreen : protected clsScreen
{

private:

	static void _ShowResult(clsCurrency& Currency)
	{
		if (!Currency.IsEmpty())
		{
			cout << clsColor::ColorRGB(clsColor::Green) << "\nCurrency Found :-)\n";
			clsCurrencyUI::PrintCurrencyCard(Currency);
		}

		else
		{
			cout << clsColor::ColorRGB(clsColor::Red) << "\nCurrency Was Not Found :-(\n";
		}
	}

	static void _FindCurrency()
	{
		cout << clsColor::ColorRGB(clsColor::Yellow) << "Find By: 1) Code OR  2) Country ? ";
		cout << clsColor::ColorRGB(clsColor::White);
		short Option = clsInputValidate::ReadNumberBetween(1, 2);

		if (Option == 1)
		{
			cout << clsColor::ColorRGB(clsColor::Yellow) << "\nEnter Currency Code: ";
			cout << clsColor::ColorRGB(clsColor::White);
			string CurrencyCode = clsInputValidate::ReadString();
			clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
			_ShowResult(Currency);
		}

		else
		{
			cout << clsColor::ColorRGB(clsColor::Yellow) << "\nEnter Country Name: ";
			cout << clsColor::ColorRGB(clsColor::White);
			string CurrencyName = clsInputValidate::ReadString();
			clsCurrency Currency = clsCurrency::FindByName(CurrencyName);
			_ShowResult(Currency);
		}
	}

public:

	static void ShowFindCurrencyScreen()
	{
		_DrawScreenHeader("Find Currency Screen");

		_FindCurrency();
	}
};