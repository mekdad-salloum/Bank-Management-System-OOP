#pragma once
#include <iostream>
#include <string>
#include <limits>
#include "clsString.h"
#include "clsDate.h"

class clsInputValidate
{

public:

	template <typename T>
	static bool IsNumberBetween(T Number, T From, T To)
	{
		return (Number >= From && Number <= To);
	}

	template <typename T>
	static T ReadNumber(string ErrorMessage = "Invalid Number, Enter Again: ")
	{
		T Number;

		while (!(cin >> Number)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;
		}

		return Number;
	}

	template <typename T>
	static T ReadPositiveNumber(string ErrorMessage = "Number Must Be Greater Than 0, Enter Again: ")
	{
		T Number = ReadNumber<T>();

		cout << "\n";
		while (Number <= 0) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;
			Number = ReadNumber<T>();
		}

		return Number;
	}

	template <typename T>
	static T ReadNumberBetween(T From, T To, string ErrorMessage = "Number Is Not Within Range, Enter Again: ")
	{
		T Number = ReadNumber<T>();

		cout << "\n";
		while (!IsNumberBetween(Number, From, To))
		{
			cout << ErrorMessage;
			Number = ReadNumber<T>();
		}

		return Number;
	}

	static bool IsDateBetween(clsDate Date, clsDate From, clsDate To)
	{
		//Date>=From && Date<=To
		if ((clsDate::IsDate1AfterDate2(Date, From) || clsDate::IsDate1EqualDate2(Date, From))
			&&
			(clsDate::IsDate1BeforeDate2(Date, To) || clsDate::IsDate1EqualDate2(Date, To))
			)
		{
			return true;
		}

		//Date>=To && Date<=From
		if ((clsDate::IsDate1AfterDate2(Date, To) || clsDate::IsDate1EqualDate2(Date, To))
			&&
			(clsDate::IsDate1BeforeDate2(Date, From) || clsDate::IsDate1EqualDate2(Date, From))
			)
		{
			return true;
		}

		return false;
	}

	static bool IsValideDate(clsDate Date)
	{
		return	clsDate::IsValidDate(Date);
	}

	static string ReadString()
	{
		string S = "";
		getline(cin >> ws, S);
		return S;
	}

};

