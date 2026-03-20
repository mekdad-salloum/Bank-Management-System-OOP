#pragma once

class clsFindUserScreen : protected clsScreen
{

private:

	static void _FindUser()
	{
		cout << clsColor::ColorRGB(clsColor::Yellow) << "Enter User UserName: ";
		string UserName = clsInputValidate::ReadString();

		cout << "\n";
		while (!clsUser::IsUserExist(UserName))
		{
			cout << clsColor::ColorRGB(clsColor::Red) << "UserName Is Not Found: Choose Another One: ";
			cout << clsColor::ColorRGB(clsColor::Yellow);
			UserName = clsInputValidate::ReadString();
		}

		clsUser User = clsUser::Find(UserName);

		if (!User.IsEmpty())
		{
			cout << clsColor::ColorRGB(clsColor::Green) << "\nUser Found :-)\n";
		}
		else
		{
			cout << clsColor::ColorRGB(clsColor::Red) << "\nUser Was not Found :-(\n";
		}

		clsUserUI::PrintUserCard(User);
	}

public:

	static void ShowFindUserScreen()
	{
		_DrawScreenHeader("Find User Screen");

		_FindUser();
	}

};
