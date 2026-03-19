#pragma once


class clsCurrencyCalculatorScreen : protected clsScreen
{

private:

	static void _PrintCalculationResult(float Amount, clsCurrency CurrencyFrom, clsCurrency CurrencyTo)
	{
		clsCurrencyUI::PrintCurrencyCard(CurrencyFrom, "Convert From");

		float AmountInUSD = CurrencyFrom.ConvertToUSD(Amount);
		cout << "\n" << Amount << " " << CurrencyFrom.CurrencyCode() << " = " << AmountInUSD << " " << "USD\n";

		if (CurrencyTo.CurrencyCode() == "USD")
			return;

		cout << "\nConverting From USD To:\n";
		clsCurrencyUI::PrintCurrencyCard(CurrencyTo, "Convert To");

		float AmountInCurrency2 = CurrencyFrom.ConvertToOtherCurrency(Amount, CurrencyTo);
		cout << "\n" << Amount << " " << CurrencyFrom.CurrencyCode() << " = " << AmountInCurrency2 << " " << CurrencyTo.CurrencyCode() << "\n";
	}

	static void _CurrencyCalculator()
	{
		clsCurrency CurrencyFrom = clsCurrencyUI::GetCurrency("Enter Currency1 Code: ");
		clsCurrency CurrencyTo = clsCurrencyUI::GetCurrency("Enter Currency2 Code: ");

		cout << "Enter Amount To Exchange: ";
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