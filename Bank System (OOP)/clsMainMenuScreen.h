#pragma once

#include <iostream>

#include "clsScreen.h"
#include "clsClientsListScreen.h"
#include "clsAddNewClientScreen.h"

using namespace std;

class clsMainMenuScreen : protected clsScreen
{

private:

	enum enMainMenuOptions { enShowClientsList = 1, enAddNewClient = 2, enDeleteClient = 3, enUpdateClient = 4, enFindClient = 5, enTransactions = 6, enManageUsers = 7, enLogout = 8 };

	static short _ReadMainMenuOption()
	{
		short Option = clsInputValidate::ReadNumberBetween(1, 8, "Invalid Input, Enter A Number Between 1 And 8: ");
		return Option;
	}

	static void _GoBackToMainMenuScreen()
	{
		cout << "\n";
		cout << clsUtility::Tabs(5) << "Press Any Key To Go Back To Main Menu....";
		system("pause>0");
		ShowMainMenuScreen();
	}


	static void _ShowClientsListScreen()
	{
		clsClientsListScreen::ShowClientsList();
	}

	static void _ShowAddNewClientScreen()
	{
		clsAddNewClientScreen::ShowAddNewClient();
	}


	static void _PerformMainMenuScreen(enMainMenuOptions Option)
	{
		switch (Option)
		{
			case enShowClientsList:
			{
				system("cls");
				_ShowClientsListScreen();
				_GoBackToMainMenuScreen();
				break;
			}

			case enAddNewClient:
			{
				 system("cls");
				_ShowAddNewClientScreen();
				_GoBackToMainMenuScreen();
				break;
			}
		}
	}

public:

	static void ShowMainMenuScreen()
	{
		_DrawScreenHeader("Main Menu Screen");

		cout << clsUtility::Tabs(5) << "==================================================\n";
		cout << clsUtility::Tabs(7) << "Main Menu Screen\n";
		cout << clsUtility::Tabs(5) << "==================================================\n";
		cout << clsUtility::Tabs(6) << "  1) Show Clients List.\n";
		cout << clsUtility::Tabs(6) << "  2) Add New Client.\n";
		cout << clsUtility::Tabs(6) << "  3) Delete Client.\n";
		cout << clsUtility::Tabs(6) << "  4) Update Client.\n";
		cout << clsUtility::Tabs(6) << "  5) Find Client.\n";
		cout << clsUtility::Tabs(6) << "  6) Transactions.\n";
		cout << clsUtility::Tabs(6) << "  7) Manage Users.\n";
		cout << clsUtility::Tabs(6) << "  8) Logout.\n";
		cout << clsUtility::Tabs(5) << "==================================================\n";
		cout << clsUtility::Tabs(5) << "Choose What Do You Want To Do? (1 To 8)? ";

		_PerformMainMenuScreen((enMainMenuOptions)_ReadMainMenuOption());
	}

};











