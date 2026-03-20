#pragma once

#include <iostream>
#include "clsUtility.h"
#include "clsInputValidate.h"
#include "clsClientUI.h"
#include "clsUserUI.h"
#include "clsCurrencyUI.h"
#include "clsCurrency.h"
#include "clsGlobal.h"
#include "clsColor.h"

using namespace std;

class clsScreen
{

protected:

	static void _DrawScreenHeader(string Title, string SubTitle = "")
	{
		system("cls");
		cout << clsColor::ColorRGB(clsColor::LemonYellow);
		cout << clsUtility::Tabs(5) << "__________________________________________________\n\n";

		cout << clsColor::ColorRGB(clsColor::Cyan);
		cout << clsUtility::Tabs(7) << Title << endl;

		if (SubTitle != "")
			cout << clsUtility::Tabs(7) << SubTitle << endl;

		cout << clsColor::ColorRGB(clsColor::LemonYellow);
		cout << clsUtility::Tabs(5) << "__________________________________________________\n\n";

		cout << clsColor::ColorRGB(clsColor::Crimson) << clsUtility::Tabs(5) << "User: " << clsColor::ColorRGB(clsColor::DodgerBlue) << clsGlobal::CurrentUser.FullName() << endl;
		cout << clsColor::ColorRGB(clsColor::Crimson) << clsUtility::Tabs(5) << "Date: " << clsColor::ColorRGB(clsColor::DodgerBlue) << clsDate::GetDateAndTimeNow() << endl;
		cout << clsColor::ColorRGB(clsColor::LemonYellow);
		cout << clsUtility::Tabs(5) << "__________________________________________________\n\n";
		cout << clsColor::Reset();
	}
	

	static bool CheckAccessRights(clsUser::enPermissions Permission)
	{
		if (!clsGlobal::CurrentUser.CheckAccessPermission(Permission))
		{
			system("cls");
			cout << clsColor::ColorRGB(clsColor::LemonYellow) << clsUtility::Tabs(5) << "__________________________________________________\n\n";
			cout << clsColor::ColorRGB(clsColor::Red) << clsUtility::Tabs(7) << "Access Denied" << endl;
			cout << clsColor::ColorRGB(clsColor::LemonYellow) << clsUtility::Tabs(5) << "__________________________________________________\n\n";
			cout << clsColor::ColorRGB(clsColor::Yellow) << clsUtility::Tabs(5) << "You Don't Have Permissions To Do This.\n";
			cout << clsColor::ColorRGB(clsColor::Green) << clsUtility::Tabs(5) << "Please Contact Your Admin.\n";
			return false;
		}

		else
		{
			return true;
		}

	}


};




