#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "clsString.h"

using namespace std;

class clsCurrency
{

private:

	enum enMode {EmptyMode = 0, UpdateMode = 1};

	enMode _Mode;
	string _Country;
	string _CurrencyCode;
	string _CurrencyName;
	double _Rate;

	
	static string _ConvertCurrencyObjectToLine(clsCurrency Currency, string Seperator = "//")
	{
		string sCurrency = "";

		sCurrency += Currency.Country() + Seperator;
		sCurrency += Currency.CurrencyCode() + Seperator;
		sCurrency += Currency.CurrencyName() + Seperator;
		sCurrency += to_string(Currency.Rate);

		return sCurrency;
	}

	static clsCurrency _ConvertLineToCurrencyObject(string Line, string Seperator = "//")
	{
		vector <string> vCurrency = clsString::Split(Line, Seperator);

		return clsCurrency(enMode::UpdateMode, vCurrency[0], vCurrency[1], vCurrency[2], stod(vCurrency[3]));
	}

	static clsCurrency _GetEmptyCurrencyObject()
	{
		return clsCurrency(enMode::EmptyMode, "", "", "", 0);
	}

	static vector <clsCurrency> _LoadCurrenciesFromFile()
	{
		vector <clsCurrency> Currencies;

		fstream File;
		File.open("Currencies.txt", ios::in);

		if (File.is_open())
		{
			string Line = "";
			clsCurrency Currency;

			while (getline(File, Line))
			{
				Currency = _ConvertLineToCurrencyObject(Line);
				Currencies.push_back(Currency);
			}

			File.close();
		}

		return Currencies;
	}

	static bool _SaveCurrenciesToFile(vector <clsCurrency>& Currencies)
	{
		fstream File;
		File.open("Currencies.txt", ios::out);

		if (!File.is_open())
			return false;

		string Line = "";

		for (clsCurrency& C : Currencies)
		{
			Line = _ConvertCurrencyObjectToLine(C);
			File << Line << endl;
		}

		File.close();
		return true;
	}

	bool _Update()
	{
		vector <clsCurrency> Currencies = _LoadCurrenciesFromFile();

		for (clsCurrency& C : Currencies)
		{
			if (C.CurrencyCode() == CurrencyCode())
			{
				C = *this;
				return _SaveCurrenciesToFile(Currencies);
			}
		}

		return false;
	}


public:

	clsCurrency()
	{
		_Mode = enMode::EmptyMode;
		_Country = "";
		_CurrencyCode = "";
		_CurrencyName = "";
		_Rate = 0;
	}

	clsCurrency(enMode Mode, string Currency, string CurrencyCode, string CurrencyName, double Rate)
	{
		_Mode = Mode;
		_Country = Currency;
		_CurrencyCode = CurrencyCode;
		_CurrencyName = CurrencyName;
		_Rate = Rate;
	}

	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}

	
	string Country()
	{
		return _Country;
	}

	string CurrencyCode()
	{
		return _CurrencyCode;
	}

	string CurrencyName()
	{
		return _CurrencyName;
	}


	void SetRate(double Rate)
	{
		_Rate = Rate;
	}

	double GetRate()
	{
		return _Rate;
	}

	__declspec(property(get = GetRate, put = SetRate)) double Rate;

	bool Save()
	{
		switch (_Mode)
		{
			case enMode::EmptyMode:
			{
				if (IsEmpty())
					return false;

				break;
			}

			case enMode::UpdateMode:
			{
				return _Update();
				break;
			}
		}
	}

	
	static vector <clsCurrency> GetAllCurrencies()
	{
		return _LoadCurrenciesFromFile();
	}

	static clsCurrency FindByCode(string Code)
	{
		Code = clsString::UpperAllString(Code);

		fstream File;
		File.open("Currencies.txt", ios::in);

		if (File.is_open())
		{
			string Line = "";
			clsCurrency Currency;

			while (getline(File, Line))
			{
				Currency = _ConvertLineToCurrencyObject(Line);

				if (Currency.CurrencyCode() == Code)
				{
					File.close();
					return Currency;
				}
			}

			File.close();
		}

		return _GetEmptyCurrencyObject();
	}

	static clsCurrency FindByName(string Name)
	{
		Name = clsString::UpperAllString(Name);

		fstream File;
		File.open("Currencies.txt", ios::in);

		if (File.is_open())
		{
			string Line = "";
			clsCurrency Currency;

			while (getline(File, Line))
			{
				Currency = _ConvertLineToCurrencyObject(Line);

				if (clsString::UpperAllString(Currency.Country()) == Name)
				{
					File.close();
					return Currency;
				}
			}

			File.close();
		}

		return _GetEmptyCurrencyObject();
	}

	static bool IsCurrencyExist(string Code)
	{
		clsCurrency Currency = FindByCode(Code);

		return !(Currency.IsEmpty());
	}


	float ConvertToUSD(float Amount)
	{
		return (Amount / Rate);
	}

	float ConvertToOtherCurrency(float Amount, clsCurrency Currency2)
	{
		float AmountInUSD = ConvertToUSD(Amount);

		return (AmountInUSD * Currency2.Rate);
	}


};