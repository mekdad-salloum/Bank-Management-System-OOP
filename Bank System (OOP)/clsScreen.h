#pragma once

#include <iostream>
#include "clsUtility.h"
#include "clsInputValidate.h"
#include "clsClientUI.h"
#include "clsUserUI.h"
#include "clsGlobal.h"

using namespace std;

class clsScreen
{

protected:

	static void _DrawScreenHeader(string Title, string SubTitle = "")
	{
		system("cls");
		cout << clsUtility::Tabs(5) << "__________________________________________________\n\n";
		cout << clsUtility::Tabs(7) << Title << endl;

		if (SubTitle != "")
			cout << clsUtility::Tabs(7) << SubTitle << endl;

		cout << clsUtility::Tabs(5) << "__________________________________________________\n\n";
	}
	

	static bool CheckAccessRights(clsUser::enPermissions Permission)
	{
		if (!clsGlobal::CurrentUser.CheckAccessPermission(Permission))
		{
			system("cls");
			cout << clsUtility::Tabs(5) << "__________________________________________________\n\n";
			cout << clsUtility::Tabs(7) << "Access Denied" << endl;
			cout << clsUtility::Tabs(5) << "__________________________________________________\n\n";
			cout << clsUtility::Tabs(5) << "You Don't Have Permissions To Do This.\n";
			cout << clsUtility::Tabs(5) << "Please Contact Your Admin.\n";
			return false;
		}

		else
		{
			return true;
		}

	}


};




