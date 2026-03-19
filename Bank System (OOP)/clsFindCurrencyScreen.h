#pragma once

class clsFindCurrencyScreen : protected clsScreen
{

private:

	static void _ShowResult(clsCurrency& Currency)
	{
		if (!Currency.IsEmpty())
		{
			cout << "\nCurrency Found :-)\n";
			clsCurrencyUI::PrintCurrencyCard(Currency);
		}

		else
		{
			cout << "\nCurrency Was Not Found :-(\n";
		}
	}

	static void _FindCurrency()
	{
		cout << "Find By: 1) Code OR  2) Country ? ";
		short Option = clsInputValidate::ReadNumberBetween(1, 2);

		if (Option == 1)
		{
			cout << "\nEnter Currency Code: ";
			string CurrencyCode = clsInputValidate::ReadString();
			clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
			_ShowResult(Currency);
		}

		else
		{
			cout << "\nEnter Country Name: ";
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