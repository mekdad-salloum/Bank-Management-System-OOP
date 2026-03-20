#pragma once

class clsUsersListScreen : protected clsScreen
{

public:

	static void ShowUsersListScreen()
	{
		vector <clsUser> Users = clsUser::GetAllUsers();

		_DrawScreenHeader("Users List Screen", "   (" + to_string(Users.size()) + ") User(s).");

		cout << clsColor::ColorRGB(clsColor::Red) << clsUtility::Tabs(2) << "_______________________________________________________________________________________________________________\n\n";
		cout << clsColor::ColorRGB(clsColor::Lime) << clsUtility::Tabs(2);
		cout << "| " << setw(15) << left << "UserName";
		cout << "| " << setw(30) << left << "Full Name";
		cout << "| " << setw(12) << left << "Phone";
		cout << "| " << setw(20) << left << "Email";
		cout << "| " << setw(10) << left << "Password";
		cout << "| " << setw(12) << left << "Permissions\n";
		cout << clsColor::ColorRGB(clsColor::Red) << clsUtility::Tabs(2) << "_______________________________________________________________________________________________________________\n\n";

		if (Users.size() == 0)
			cout << clsColor::ColorRGB(clsColor::Lime) << clsUtility::Tabs(6) << "No Users Available In the System!\n";

		else
		{
			for (clsUser& C : Users)
			{
				clsUserUI::PrintUserRecord(C);
			}
		}


		cout << clsColor::ColorRGB(clsColor::Red) << clsUtility::Tabs(2) << "_______________________________________________________________________________________________________________\n";
	}


};