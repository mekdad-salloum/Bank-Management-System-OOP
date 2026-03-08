#pragma once

class clsAddNewUserScreen : protected clsScreen
{
private:

	static void _AddNewUser()
	{
		cout << "Enter UserName: ";
		string UserName = clsInputValidate::ReadString();

		cout << "\n";
		while (clsUser::IsUserExist(UserName))
		{
			cout << "UserName Is Already Used, Choose Another One: ";
			UserName = clsInputValidate::ReadString();
		}

		clsUser User = clsUser::GetAddNewUserObject(UserName);
		clsUserUI::ReadUserInfo(User);

		if (User.Save())
		{
			cout << "\nUser Added Successfully :-)\n";
			clsUserUI::PrintUserCard(User);
		}

		else
		{
			cout << "\nError Account Was Not Saved :-(\n";
		}
	}

public:


	static void ShowAddNewUserScreen()
	{
		_DrawScreenHeader("Add New User Screen");

		_AddNewUser();
	}

};

