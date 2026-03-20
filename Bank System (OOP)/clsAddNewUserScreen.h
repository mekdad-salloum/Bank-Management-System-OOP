#pragma once

class clsAddNewUserScreen : protected clsScreen
{
private:

	static void _AddNewUser()
	{
		cout << clsColor::ColorRGB(clsColor::Yellow) << "Enter UserName: ";
		string UserName = clsInputValidate::ReadString();

		cout << "\n";
		while (clsUser::IsUserExist(UserName))
		{
			cout << clsColor::ColorRGB(clsColor::Red) << "UserName Is Already Used, Choose Another One: ";
			cout << clsColor::ColorRGB(clsColor::Yellow);
			UserName = clsInputValidate::ReadString();
		}

		clsUser User = clsUser::GetAddNewUserObject(UserName);
		clsUserUI::ReadUserInfo(User);

		if (User.Save())
		{
			cout << clsColor::ColorRGB(clsColor::Green) << "\nUser Added Successfully :-)\n";
			clsUserUI::PrintUserCard(User);
		}

		else
		{
			cout << clsColor::ColorRGB(clsColor::Red) << "\nError Account Was Not Saved :-(\n";
		}
	}

public:


	static void ShowAddNewUserScreen()
	{
		_DrawScreenHeader("Add New User Screen");

		_AddNewUser();
	}

};

