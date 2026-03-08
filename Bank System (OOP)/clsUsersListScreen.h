#pragma once

class clsUsersListScreen : protected clsScreen
{

public:

	static void ShowUsersListScreen()
	{
		vector <clsUser> Users = clsUser::GetAllUsers();

		_DrawScreenHeader("Users List Screen", "   (" + to_string(Users.size()) + ") User(s).");

		cout << clsUtility::Tabs(2) << "_______________________________________________________________________________________________________________\n\n";
		cout << clsUtility::Tabs(2);
		cout << "| " << setw(15) << left << "UserName";
		cout << "| " << setw(30) << left << "Full Name";
		cout << "| " << setw(12) << left << "Phone";
		cout << "| " << setw(20) << left << "Email";
		cout << "| " << setw(10) << left << "Password";
		cout << "| " << setw(12) << left << "Permissions\n";
		cout << clsUtility::Tabs(2) << "_______________________________________________________________________________________________________________\n\n";

		if (Users.size() == 0)
			cout << clsUtility::Tabs(6) << "No Users Available In the System!\n";

		else
		{
			for (clsUser& C : Users)
			{
				clsUserUI::PrintUserRecord(C);
			}
		}


		cout << clsUtility::Tabs(2) << "_______________________________________________________________________________________________________________\n";
	}


};