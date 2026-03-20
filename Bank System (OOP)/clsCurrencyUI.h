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
		cout << clsColor::ColorRGB(clsColor::Yellow) << Message;
		cout << clsColor::ColorRGB(clsColor::White);
		string CurrencyCode = clsInputValidate::ReadString();

		cout << "\n";
		while (!clsCurrency::IsCurrencyExist(CurrencyCode))
		{
			cout << clsColor::ColorRGB(clsColor::Red) << "Currency Code Is Not Found: Choose Another One: ";
			cout << clsColor::ColorRGB(clsColor::White);
			CurrencyCode = clsInputValidate::ReadString();
		}

		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);

		return Currency;
	}

	static void PrintCurrencyRecord(clsCurrency& Currency)
	{
		cout << clsUtility::Tabs(2);
		cout << clsColor::ColorRGB(clsColor::Cyan) << "| " << setw(30) << left << Currency.Country();
		cout << clsColor::ColorRGB(clsColor::Red) << "| " << setw(8) << left << Currency.CurrencyCode();
		cout << clsColor::ColorRGB(clsColor::BrightYellow) << "| " << setw(45) << left << Currency.CurrencyName();
		cout << clsColor::ColorRGB(clsColor::Lime) << "| " << setw(10) << left << Currency.Rate;
		cout << "\n";
	}

	static void PrintCurrencyCard(clsCurrency& Currency, string Title = "Currency Card:")
	{
		cout << clsColor::ColorRGB(clsColor::Cyan) << "\n" << Title;
		cout << clsColor::ColorRGB(clsColor::Magenta) << "\n____________________________________";
		cout << clsColor::ColorRGB(clsColor::Cyan) << "\nCountry  : " << clsColor::ColorRGB(clsColor::Yellow) << Currency.Country();
		cout << clsColor::ColorRGB(clsColor::Cyan) << "\nCode     : " << clsColor::ColorRGB(clsColor::Yellow) << Currency.CurrencyCode();
		cout << clsColor::ColorRGB(clsColor::Cyan) << "\nName     : " << clsColor::ColorRGB(clsColor::Yellow) << Currency.CurrencyName();
		cout << clsColor::ColorRGB(clsColor::Cyan) << "\nRate(1$) : " << clsColor::ColorRGB(clsColor::Yellow) << Currency.Rate;
		cout << clsColor::ColorRGB(clsColor::Magenta) << "\n____________________________________\n";
	}

};