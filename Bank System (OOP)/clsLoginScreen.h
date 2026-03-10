#pragma once

#include "clsMainMenuScreen.h"
#include "clsGlobal.h"
#include "clsInputValidate.h"

class clsLoginScreen : protected clsScreen
{

private:

	static bool _Login()
	{
		bool LoginFailed = false;
		string UserName = "", Password = "";
		short LoginFailedCounter = 3;

		do
		{
			if (LoginFailed)
			{
				LoginFailedCounter--;
				cout << "\n";
				cout << clsUtility::Tabs(5) << "Invalid UserName/Password\n";
				cout << clsUtility::Tabs(5) << "You Have " << LoginFailedCounter << " Trials To Login.\n\n";
			}

			if (LoginFailedCounter == 0)
			{
				cout << "\n";
				cout << clsUtility::Tabs(5) << "You Are Locked After 3 Failed Trials.";
				return false;
			}

			cout << clsUtility::Tabs(5) << "Enter UserName: ";
			UserName = clsInputValidate::ReadString();

			cout << clsUtility::Tabs(5) << "Enter Password: ";
			Password = clsInputValidate::ReadString();

			clsGlobal::CurrentUser = clsUser::Find(UserName, Password);
			LoginFailed = clsGlobal::CurrentUser.IsEmpty();

		} while (LoginFailed);

		if (clsGlobal::CurrentUser.LoginRegister())
		{
			clsMainMenuScreen::ShowMainMenuScreen();
			return true;
		}
	
	}

public:

	static bool ShowLoginScreen()
	{
		_DrawScreenHeader("Login Screen");

		return _Login();
	}

};