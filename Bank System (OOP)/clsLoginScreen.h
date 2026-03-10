#pragma once

#include "clsMainMenuScreen.h"
#include "clsGlobal.h"
#include "clsInputValidate.h"

class clsLoginScreen : protected clsScreen
{

private:

	static void _Login()
	{
		bool LoginFailed = false;
		string UserName = "", Password = "";

		do
		{
			if (LoginFailed)
			{
				cout << "\n";
				cout << clsUtility::Tabs(5) << "Invalid UserName/Password\n\n";
			}

			cout << clsUtility::Tabs(5) << "Enter UserName: ";
			UserName = clsInputValidate::ReadString();

			cout << clsUtility::Tabs(5) << "Enter Password: ";
			Password = clsInputValidate::ReadString();

			clsGlobal::CurrentUser = clsUser::Find(UserName, Password);
			LoginFailed = clsGlobal::CurrentUser.IsEmpty();

		} while (LoginFailed);

		clsMainMenuScreen::ShowMainMenuScreen();
	}

public:

	static void ShowLoginScreen()
	{
		_DrawScreenHeader("Login Screen");

		_Login();
	}

};