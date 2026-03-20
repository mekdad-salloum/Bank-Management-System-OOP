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
				cout << clsColor::ColorRGB(clsColor::Red);
				cout << clsUtility::Tabs(5) << "Invalid UserName/Password\n";
				cout << clsColor::ColorRGB(clsColor::Magenta);
				cout << clsUtility::Tabs(5) << "You Have " << clsColor::ColorRGB(clsColor::Blue) << LoginFailedCounter << clsColor::ColorRGB(clsColor::Magenta) << " Trials To Login.\n\n";
			}

			if (LoginFailedCounter == 0)
			{
				cout << "\n";
				cout << clsColor::ColorRGB(clsColor::Red);
				cout << clsUtility::Tabs(5) << "You Are Locked After 3 Failed Trials.";
				return false;
			}

			cout << clsColor::ColorRGB(clsColor::Yellow);
			cout << clsUtility::Tabs(5) << "Enter UserName: ";

			cout << clsColor::ColorRGB(clsColor::White);
			UserName = clsInputValidate::ReadString();

			cout << clsColor::ColorRGB(clsColor::Yellow);
			cout << clsUtility::Tabs(5) << "Enter Password: ";

			cout << clsColor::ColorRGB(clsColor::White);
			Password = clsInputValidate::ReadString();

			cout << clsColor::Reset();

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