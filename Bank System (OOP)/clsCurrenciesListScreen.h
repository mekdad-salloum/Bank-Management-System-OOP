#pragma once


class clsCurrenciesListScreen : protected clsScreen
{

public:

	static void ShowCurrenciesListScreen()
	{
		vector <clsCurrency> Currencies = clsCurrency::GetAllCurrencies();

		_DrawScreenHeader("Currencies List Screen", "   (" + to_string(Currencies.size()) + ") Currency(s).");

		cout << clsColor::ColorRGB(clsColor::Magenta) << clsUtility::Tabs(2) << "___________________________________________________________________________________________________________\n\n";
		cout << clsUtility::Tabs(2);
		cout << clsColor::ColorRGB(clsColor::Cyan) << "| " << setw(30) << left << "Country";
		cout << clsColor::ColorRGB(clsColor::Red) << "| " << setw(8) << left << "Code";
		cout << clsColor::ColorRGB(clsColor::BrightYellow) << "| " << setw(45) << left << "Name";
		cout << clsColor::ColorRGB(clsColor::Lime) << "| " << setw(10) << left << "Rate/(1$)\n";
		cout << clsColor::ColorRGB(clsColor::Magenta) << clsUtility::Tabs(2) << "___________________________________________________________________________________________________________\n\n";

		if (Currencies.size() == 0)
			cout << clsColor::ColorRGB(clsColor::Lime) << clsUtility::Tabs(6) << "No Currencies Available In the System!";

		else
		{
			for (clsCurrency& C : Currencies)
			{
				clsCurrencyUI::PrintCurrencyRecord(C);
			}
		}


		cout << clsColor::ColorRGB(clsColor::Magenta) << clsUtility::Tabs(2) << "___________________________________________________________________________________________________________\n";
	}


};