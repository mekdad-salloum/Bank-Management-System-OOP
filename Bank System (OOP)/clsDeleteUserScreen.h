#pragma once

class clsDeleteUserScreen : protected clsScreen
{

private:

	static void _DeleteUser()
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
		clsUserUI::PrintUserCard(User);

		char Answer = 'N';
		cout << clsColor::ColorRGB(clsColor::White) << "\nAre You Sure You Want To Delete This User? (Y/N) ";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			if (User.Delete())
			{
				cout << clsColor::ColorRGB(clsColor::Green) << "\nUser Deleted Successfully :-)\n";
				clsUserUI::PrintUserCard(User);
			}

			else
			{
				cout << clsColor::ColorRGB(clsColor::Red) << "\nError, Account Was Not Deleted :-(\n";
			}
		}

		else
		{
			cout << clsColor::ColorRGB(clsColor::White) << "\nOperation Was Cancelled.\n";
		}
	}

public:

	static void ShowDeleteUserScreen()
	{
		_DrawScreenHeader("Delete User Screen");

		_DeleteUser();
	}


};

