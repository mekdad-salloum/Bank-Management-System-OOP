#pragma once

#include "clsCurrenciesListScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateCurrencyRateScreen.h"
#include "clsCurrencyCalculatorScreen.h"



class clsCurrencyExchangeScreen : protected clsScreen
{

private:

	enum enCurrencyExxchangeMenuOptions { enShowCurrenciesList = 1, enFindCurrency = 2, enUpdateCurrencyRate = 3, enCurrencyCalculator = 4, MainMenu = 5};

	static short _ReadCurrencyExchangeMenuOption()
	{
		short Option = clsInputValidate::ReadNumberBetween(1, 5, "Invalid Input, Enter A Number Between 1 And 5: ");
		return Option;
	}

	static void _GoBackToCurrencyExchangeMenuScreen()
	{
		cout << "\n";
		cout << clsColor::ColorRGB(clsColor::DodgerBlue) << clsUtility::Tabs(5) << "Press Any Key To Go Back To Currency Exchange Menu....";
		system("pause>0");
		ShowCurrencyExchangeScreen();
	}


	static void _ShowCurrenciesListScreen()
	{
		clsCurrenciesListScreen::ShowCurrenciesListScreen();
	}

	static void _ShowFindCurrencyScreen()
	{
		clsFindCurrencyScreen::ShowFindCurrencyScreen();
	}

	static void _ShowUpdateCurrencyRateScreen()
	{
		clsUpdateCurrencyRateScreen::ShowUpdateCurrencyRateScreen();
	}

	static void _ShowCurrencyCalculatorScreen()
	{
		clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
	}


	static void _PerformMainMenuScreen(enCurrencyExxchangeMenuOptions Option)
	{
		switch (Option)
		{
			case enShowCurrenciesList:
			{
				_ShowCurrenciesListScreen();
				_GoBackToCurrencyExchangeMenuScreen();
				break;
			}

			case enFindCurrency:
			{
				_ShowFindCurrencyScreen();
				_GoBackToCurrencyExchangeMenuScreen();
				break;
			}

			case enUpdateCurrencyRate:
			{
				_ShowUpdateCurrencyRateScreen();
				_GoBackToCurrencyExchangeMenuScreen();
				break;
			}

			case enCurrencyCalculator:
			{
				_ShowCurrencyCalculatorScreen();
				_GoBackToCurrencyExchangeMenuScreen();
				break;
			}

			case MainMenu:
			{
				//Do Nothing, Here The Main Screen Will Handle It :-) ;
			}
		}
	}

public:

	static void ShowCurrencyExchangeScreen()
	{
		_DrawScreenHeader("Currency Exchange Screen");

		cout << clsColor::ColorRGB(clsColor::BrightGreen) << clsUtility::Tabs(5) << "==================================================\n";
		cout << clsColor::ColorRGB(clsColor::Green) << clsUtility::Tabs(7) << "Currency Exchange Menu\n";
		cout << clsColor::ColorRGB(clsColor::BrightGreen) << clsUtility::Tabs(5) << "==================================================\n";
		cout << clsColor::ColorRGB(clsColor::Yellow) << clsUtility::Tabs(6) << "  1) " << clsColor::ColorRGB(clsColor::Cyan) << "Show Currencies List.\n";
		cout << clsColor::ColorRGB(clsColor::Yellow) << clsUtility::Tabs(6) << "  2) " << clsColor::ColorRGB(clsColor::Cyan) << "Find Currency.\n";
		cout << clsColor::ColorRGB(clsColor::Yellow) << clsUtility::Tabs(6) << "  3) " << clsColor::ColorRGB(clsColor::Cyan) << "Update Currency Rate.\n";
		cout << clsColor::ColorRGB(clsColor::Yellow) << clsUtility::Tabs(6) << "  4) " << clsColor::ColorRGB(clsColor::Cyan) << "Currency Calculator.\n";
		cout << clsColor::ColorRGB(clsColor::Yellow) << clsUtility::Tabs(6) << "  5) " << clsColor::ColorRGB(clsColor::Cyan) << "Main Menu.\n";
		cout << clsColor::ColorRGB(clsColor::BrightGreen) << clsUtility::Tabs(5) << "==================================================\n";
		cout << clsColor::ColorRGB(clsColor::Magenta) << clsUtility::Tabs(5) << "Choose What Do You Want To Do? (1 To 5)? ";

		_PerformMainMenuScreen((enCurrencyExxchangeMenuOptions)_ReadCurrencyExchangeMenuOption());
	}


};