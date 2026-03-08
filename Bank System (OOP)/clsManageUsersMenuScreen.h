#pragma once

#include "clsScreen.h"
#include "clsUsersListScreen.h"
#include "clsAddNewUserScreen.h"
#include "clsDeleteUserScreen.h"
#include "clsUpdateUserScreen.h"
#include "clsFindUserScreen.h"

class clsManageUsersMenuScreen : clsScreen
{

private:

	enum enManageUsersMenuOptions { enShowUsersList = 1, enAddNewUser = 2, enDeleteUser = 3, enUpdateUser = 4, enFindUser = 5, eMainMenu = 6 };

	static short _ReadManageUsersMenuOption()
	{
		short Option = clsInputValidate::ReadNumberBetween(1, 6, "Invalid Input, Enter A Number Between 1 And 6: ");
		return Option;
	}

	static void _GoBackToManageUsersMenuScreen()
	{
		cout << "\n";
		cout << clsUtility::Tabs(5) << "Press Any Key To Go Back To Manage Users Menu....";
		system("pause>0");
		ShowManageUsersMenuScreen();
	}


	static void _ShowUsersListScreen()
	{
		clsUsersListScreen::ShowUsersListScreen();
	}

	static void _ShowAddNewUserScreen()
	{
		clsAddNewUserScreen::ShowAddNewUserScreen();
	}

	static void _ShowDeleteUserScreen()
	{
		clsDeleteUserScreen::ShowDeleteUserScreen();
	}

	static void _ShowUpdateUserScreen()
	{
		clsUpdateUserScreen::ShowUpdateUserScreen();
	}

	static void _ShowFindUserScreen()
	{
		clsFindUserScreen::ShowFindUserScreen();
	}



	static void _PerformManageUsersMenuScreen(enManageUsersMenuOptions Option)
	{
		switch (Option)
		{
			case enShowUsersList:
			{
				_ShowUsersListScreen();
				_GoBackToManageUsersMenuScreen();
				break;
			}

			case enAddNewUser:
			{
				_ShowAddNewUserScreen();
				_GoBackToManageUsersMenuScreen();
				break;
			}

			case enDeleteUser:
			{
				_ShowDeleteUserScreen();
				_GoBackToManageUsersMenuScreen();
				break;
			}

			case enUpdateUser:
			{
				_ShowUpdateUserScreen();
				_GoBackToManageUsersMenuScreen();
				break;
			}

			case enFindUser:
			{
				_ShowFindUserScreen();
				_GoBackToManageUsersMenuScreen();
				break;
			}

			case eMainMenu:
			{
				//Do Nothing Here, The Main Screen Will Handle It :-) ;
			}
		}
	}

public:

	static void ShowManageUsersMenuScreen()
	{
		_DrawScreenHeader("Manage Users Menu Screen");

		cout << clsUtility::Tabs(5) << "==================================================\n";
		cout << clsUtility::Tabs(7) << "Manage Users Menu\n";
		cout << clsUtility::Tabs(5) << "==================================================\n";
		cout << clsUtility::Tabs(7) << "1) Show Users List.\n";
		cout << clsUtility::Tabs(7) << "2) Add New User.\n";
		cout << clsUtility::Tabs(7) << "3) Delete User.\n";
		cout << clsUtility::Tabs(7) << "4) Update User.\n";
		cout << clsUtility::Tabs(7) << "5) Find User.\n";
		cout << clsUtility::Tabs(7) << "6) Main Menu.\n";
		cout << clsUtility::Tabs(5) << "==================================================\n";
		cout << clsUtility::Tabs(5) << "Choose What Do You Want To Do? (1 To 6)? ";

		_PerformManageUsersMenuScreen((enManageUsersMenuOptions)_ReadManageUsersMenuOption());
	}

};