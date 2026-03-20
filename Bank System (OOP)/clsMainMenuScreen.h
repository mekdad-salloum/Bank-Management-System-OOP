#pragma once

#include "clsScreen.h"
#include "clsClientsListScreen.h"
#include "clsAddNewClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsFindClientScreen.h"
#include "clsTransactionsMenuScreen.h"
#include "clsManageUsersMenuScreen.h"
#include "clsLoginRegisterScreen.h"
#include "clsCurrencyExchangeScreen.h"
#include "clsGlobal.h"

using namespace std;

class clsMainMenuScreen : protected clsScreen
{

private:

	enum enMainMenuOptions { enShowClientsList = 1, enAddNewClient = 2, enDeleteClient = 3, enUpdateClient = 4, enFindClient = 5, enTransactions = 6, enManageUsers = 7, enLoginRegister = 8, enCurrencyExchange = 9, enLogout = 10 };



	static short _ReadMainMenuOption()
	{
		short Option = clsInputValidate::ReadNumberBetween(1, 10, "Invalid Input, Enter A Number Between 1 And 10: ");
		return Option;
	}

	static void _GoBackToMainMenuScreen()
	{
		cout << "\n";
		cout << clsColor::ColorRGB(clsColor::DodgerBlue) << clsUtility::Tabs(5) << "Press Any Key To Go Back To Main Menu....";
		system("pause>0");
		ShowMainMenuScreen();
	}


	static void _ShowClientsListScreen()
	{
		clsClientsListScreen::ShowClientsListScreen();
	}

	static void _ShowAddNewClientScreen()
	{
		clsAddNewClientScreen::ShowAddNewClientScreen();
	}

	static void _ShowDeleteClientScreen()
	{
		clsDeleteClientScreen::ShowDeleteClientScreen();
	}

	static void _ShowUpdateClientScreen()
	{
		clsUpdateClientScreen::ShowUpdateClientScreen();
	}

	static void _ShowFindClientScreen()
	{
		clsFindClientScreen::ShowFindClientScreen();
	}

	static void _ShowTransactionsMenuScreen()
	{
		clsTransactionsMenuScreen::ShowTransactionsMenuScreen();
	}

	static void _ShowManageUsersMenuScreen()
	{
		clsManageUsersMenuScreen::ShowManageUsersMenuScreen();
	}

	static void _ShowLoginRegisterScreen()
	{
		clsLoginRegisterScreen::ShowLoginRegisterScreen();
	}

	static void _ShowCurrencyExchangeScreen()
	{
		clsCurrencyExchangeScreen::ShowCurrencyExchangeScreen();
	}


	static void _Logout()
	{
		clsGlobal::CurrentUser = clsUser::Find("", "");
		
		//Then It Will Go Back To Main Function.
	}

	
	static void _PerformMainMenuScreen(enMainMenuOptions Option)
	{
		switch (Option)
		{
			case enShowClientsList:
			{
				_ShowClientsListScreen();
				_GoBackToMainMenuScreen();
				break;
			}

			case enAddNewClient:
			{
				_ShowAddNewClientScreen();
				_GoBackToMainMenuScreen();
				break;
			}

			case enDeleteClient:
			{
				_ShowDeleteClientScreen();
				_GoBackToMainMenuScreen();
				break;
			}

			case enUpdateClient:
			{
				_ShowUpdateClientScreen();
				_GoBackToMainMenuScreen();
				break;
			}

			case enFindClient:
			{
				_ShowFindClientScreen();
				_GoBackToMainMenuScreen();
				break;
			}

			case enTransactions:
			{
				_ShowTransactionsMenuScreen();
				_GoBackToMainMenuScreen();
				break;
			}

			case enManageUsers:
			{
				_ShowManageUsersMenuScreen();
				_GoBackToMainMenuScreen();
				break;
			}

			case enLoginRegister:
			{
				_ShowLoginRegisterScreen();
				_GoBackToMainMenuScreen();
				break;
			}

			case enCurrencyExchange:
			{
				_ShowCurrencyExchangeScreen();
				_GoBackToMainMenuScreen();
				break;
			}

			case enLogout:
			{
				_Logout();
				break;
			}
		}
	}

public:


	static void ShowMainMenuScreen()
	{
		_DrawScreenHeader("Main Menu Screen");

		cout << clsColor::ColorRGB(clsColor::BrightGreen) << clsUtility::Tabs(5) << "==================================================\n";
		cout << clsColor::ColorRGB(clsColor::Green) << clsUtility::Tabs(7) << "Main Menu\n";
		cout << clsColor::ColorRGB(clsColor::BrightGreen) << clsUtility::Tabs(5) << "==================================================\n";
		cout << clsColor::ColorRGB(clsColor::Yellow) << clsUtility::Tabs(6) << "  1) " << clsColor::ColorRGB(clsColor::Cyan) << "Show Clients List.\n";
		cout << clsColor::ColorRGB(clsColor::Yellow) << clsUtility::Tabs(6) << "  2) " << clsColor::ColorRGB(clsColor::Cyan) << "Add New Client.\n";
		cout << clsColor::ColorRGB(clsColor::Yellow) << clsUtility::Tabs(6) << "  3) " << clsColor::ColorRGB(clsColor::Cyan) << "Delete Client.\n";
		cout << clsColor::ColorRGB(clsColor::Yellow) << clsUtility::Tabs(6) << "  4) " << clsColor::ColorRGB(clsColor::Cyan) << "Update Client.\n";
		cout << clsColor::ColorRGB(clsColor::Yellow) << clsUtility::Tabs(6) << "  5) " << clsColor::ColorRGB(clsColor::Cyan) << "Find Client.\n";
		cout << clsColor::ColorRGB(clsColor::Yellow) << clsUtility::Tabs(6) << "  6) " << clsColor::ColorRGB(clsColor::Cyan) << "Transactions.\n";
		cout << clsColor::ColorRGB(clsColor::Yellow) << clsUtility::Tabs(6) << "  7) " << clsColor::ColorRGB(clsColor::Cyan) << "Manage Users.\n";
		cout << clsColor::ColorRGB(clsColor::Yellow) << clsUtility::Tabs(6) << "  8) " << clsColor::ColorRGB(clsColor::Cyan) << "Login Registers.\n";
		cout << clsColor::ColorRGB(clsColor::Yellow) << clsUtility::Tabs(6) << "  9) " << clsColor::ColorRGB(clsColor::Cyan) << "Currency Exchange.\n";
		cout << clsColor::ColorRGB(clsColor::Yellow) << clsUtility::Tabs(6) << "  10) " << clsColor::ColorRGB(clsColor::Cyan) << "Logout.\n";
		cout << clsColor::ColorRGB(clsColor::BrightGreen) << clsUtility::Tabs(5) << "==================================================\n";
		cout << clsColor::ColorRGB(clsColor::Magenta) << clsUtility::Tabs(5) << "Choose What Do You Want To Do? (1 To 10)? ";

		_PerformMainMenuScreen((enMainMenuOptions)_ReadMainMenuOption());
	}

};


