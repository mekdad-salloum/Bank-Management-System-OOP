#pragma once


class clsCurrencyCalculatorScreen : protected clsScreen
{

private:

	static void _PrintCalculationResult(float Amount, clsCurrency CurrencyFrom, clsCurrency CurrencyTo)
	{
		clsCurrencyUI::PrintCurrencyCard(CurrencyFrom, "Convert From");

		float AmountInUSD = CurrencyFrom.ConvertToUSD(Amount);
		cout << clsColor::ColorRGB(clsColor::Green) << "\n" << Amount << " " << clsColor::ColorRGB(clsColor::Red) << CurrencyFrom.CurrencyCode() << clsColor::ColorRGB(clsColor::Gold) << " = " << clsColor::ColorRGB(clsColor::Green) << AmountInUSD << " " << clsColor::ColorRGB(clsColor::Red) << "USD\n";

		if (CurrencyTo.CurrencyCode() == "USD")
			return;

		cout << clsColor::ColorRGB(clsColor::DodgerBlue) << "\nConverting From USD To:\n";
		clsCurrencyUI::PrintCurrencyCard(CurrencyTo, "Convert To");

		float AmountInCurrency2 = CurrencyFrom.ConvertToOtherCurrency(Amount, CurrencyTo);
		cout << clsColor::ColorRGB(clsColor::Green) << "\n" << Amount << " " << clsColor::ColorRGB(clsColor::Red) << CurrencyFrom.CurrencyCode() << clsColor::ColorRGB(clsColor::Gold) << " = " << clsColor::ColorRGB(clsColor::Green) << AmountInCurrency2 << " " << clsColor::ColorRGB(clsColor::Red) << CurrencyTo.CurrencyCode() << "\n";
	}

	static void _CurrencyCalculator()
	{
		clsCurrency CurrencyFrom = clsCurrencyUI::GetCurrency("Enter Currency1 Code: ");
		clsCurrency CurrencyTo = clsCurrencyUI::GetCurrency("Enter Currency2 Code: ");

		cout << clsColor::ColorRGB(clsColor::Yellow) << "\nEnter Amount To Exchange: ";
		cout << clsColor::ColorRGB(clsColor::White);
		float Amount = clsInputValidate::ReadPositiveNumber<float>();

		_PrintCalculationResult(Amount, CurrencyFrom, CurrencyTo);
	}


public:

	static void ShowCurrencyCalculatorScreen()
	{
		_DrawScreenHeader("Currency Calculator Screen");

		_CurrencyCalculator();
	}

};