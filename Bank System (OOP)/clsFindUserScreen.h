#pragma once

class clsFindUserScreen : protected clsScreen
{

private:

	static void _FindUser()
	{
		cout << "Enter User UserName: ";
		string UserName = clsInputValidate::ReadString();

		cout << "\n";
		while (!clsUser::IsUserExist(UserName))
		{
			cout << "UserName Is Not Found: Choose Another One: ";
			UserName = clsInputValidate::ReadString();
		}

		clsUser User = clsUser::Find(UserName);

		if (!User.IsEmpty())
		{
			cout << "\nUser Found :-)\n";
		}
		else
		{
			cout << "\nUser Was not Found :-(\n";
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
