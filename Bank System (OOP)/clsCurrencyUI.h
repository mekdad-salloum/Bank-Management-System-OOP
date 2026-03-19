#pragma once

#include <iostream>
#include <iomanip>

#include "clsUtility.h"
#include "clsCurrency.h"

using namespace std;

class clsCurrencyUI
{

public:

	static clsCurrency GetCurrency(string Message)
	{
		cout << Message;
		string CurrencyCode = clsInputValidate::ReadString();

		cout << "\n";
		while (!clsCurrency::IsCurrencyExist(CurrencyCode))
		{
			cout << "Currency Code Is Not Found: Choose Another One: ";
			CurrencyCode = clsInputValidate::ReadString();
		}

		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);

		return Currency;
	}

	static void PrintCurrencyRecord(clsCurrency& Currency)
	{
		cout << clsUtility::Tabs(2);
		cout << "| " << setw(30) << left << Currency.Country();
		cout << "| " << setw(8) << left << Currency.CurrencyCode();
		cout << "| " << setw(45) << left << Currency.CurrencyName();
		cout << "| " << setw(10) << left << Currency.Rate;
		cout << "\n";
	}

	static void PrintCurrencyCard(clsCurrency& Currency, string Title = "Currency Card:")
	{
		cout << "\n" << Title;
		cout << "\n____________________________________";
		cout << "\nCountry  : " << Currency.Country();
		cout << "\nCode     : " << Currency.CurrencyCode();
		cout << "\nName     : " << Currency.CurrencyName();
		cout << "\nRate(1$) : " << Currency.Rate;
		cout << "\n____________________________________\n";
	}

};