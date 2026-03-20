#pragma once

class clsUpdateUserScreen : protected clsScreen
{

private:

	static void _UpdateUser()
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
		cout << clsColor::ColorRGB(clsColor::White) << "\nAre You Sure You Want To Update This User? (Y/N) ";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			cout << clsColor::ColorRGB(clsColor::Cyan) << "\n\nUpdate User Info:";
			cout << clsColor::ColorRGB(clsColor::Magenta) << "\n_____________________\n";
			clsUserUI::ReadUserInfo(User);

			if (User.Save())
			{
				cout << clsColor::ColorRGB(clsColor::Green) << "\nUser Updated Successfully :-)\n";
				clsUserUI::PrintUserCard(User);
			}

			else
			{
				cout << clsColor::ColorRGB(clsColor::Red) << "\nError Account Was Not Saved :-(\n";
			}
		}

		else
		{
			cout << clsColor::ColorRGB(clsColor::White) << "\nOperation Was Cancelled.\n";
		}
	}

public:

	static void ShowUpdateUserScreen()
	{
		_DrawScreenHeader("Update User Screen");

		_UpdateUser();
	}

};