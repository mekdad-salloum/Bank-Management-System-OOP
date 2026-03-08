#pragma once

#include <iostream>
#include "clsUtility.h"
#include "clsInputValidate.h"
#include "clsClientUI.h"
#include "clsUserUI.h"


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
	


};




