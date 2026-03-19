#pragma once


class clsCurrenciesListScreen : protected clsScreen
{

public:

	static void ShowCurrenciesListScreen()
	{
		vector <clsCurrency> Currencies = clsCurrency::GetAllCurrencies();

		_DrawScreenHeader("Currencies List Screen", "   (" + to_string(Currencies.size()) + ") Currency(s).");

		cout << clsUtility::Tabs(2) << "___________________________________________________________________________________________________________\n\n";
		cout << clsUtility::Tabs(2);
		cout << "| " << setw(30) << left << "Country";
		cout << "| " << setw(8) << left << "Code";
		cout << "| " << setw(45) << left << "Name";
		cout << "| " << setw(10) << left << "Rate/(1$)\n";
		cout << clsUtility::Tabs(2) << "___________________________________________________________________________________________________________\n\n";

		if (Currencies.size() == 0)
			cout << clsUtility::Tabs(6) << "No Currencies Available In the System!";

		else
		{
			for (clsCurrency& C : Currencies)
			{
				clsCurrencyUI::PrintCurrencyRecord(C);
			}
		}


		cout << clsUtility::Tabs(2) << "___________________________________________________________________________________________________________\n";
	}


};