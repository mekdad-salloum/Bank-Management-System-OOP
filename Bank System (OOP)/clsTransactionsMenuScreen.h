#pragma once

#include "clsScreen.h"
#include "clsDepositeScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTotalBalancesScreen.h"
#include "clsTransferScreen.h"
#include "clsTransfersLogScreen.h"


class clsTransactionsMenuScreen : protected clsScreen
{

private:

	enum enTransactionsMenuOptions { enDeposit = 1, enWithdraw = 2, enTotalBalances = 3, enTransfer = 4, enTransfersLog = 5, enMainMenu = 6};

	static short _ReadTransactionsMenuOption()
	{
		short Option = clsInputValidate::ReadNumberBetween(1, 6, "Invalid Input, Enter A Number Between 1 And 6: ");
		return Option;
	}

	static void _GoBackToTransactionsMenuScreen()
	{
		cout << "\n";
		cout << clsUtility::Tabs(5) << "Press Any Key To Go Back To Transactions Menu....";
		system("pause>0");
		ShowTransactionsMenuScreen();
	}


	static void _ShowDepositeScreen()
	{
		clsDepositeScreen::ShowDepositeScreen();
	}

	static void _ShowWithdrawScreen()
	{
		clsWithdrawScreen::ShowWithdrawScreen();
	}

	static void _ShowTotalBalancesScreen()
	{
		clsTotalBalancesScreen::ShowTotalBalancesScreen();
	}

	static void _ShowTransferScreen()
	{
		clsTransferScreen::ShowTransferScreen();
	}

	static void _ShowTransfersLogScreen()
	{
		clsTransfersLogScreen::ShowTransfersLogScreen();
	}

	static void _PerformTransactionsMenuScreen(enTransactionsMenuOptions Option)
	{
		switch (Option)
		{
			case enDeposit:
			{
				_ShowDepositeScreen();
				_GoBackToTransactionsMenuScreen();
				break;
			}

			case enWithdraw:
			{
				_ShowWithdrawScreen();
				_GoBackToTransactionsMenuScreen();
				break;
			}

			case enTotalBalances:
			{
				_ShowTotalBalancesScreen();
				_GoBackToTransactionsMenuScreen();
				break;
			}

			case enTransfer:
			{
				_ShowTransferScreen();
				_GoBackToTransactionsMenuScreen();
				break;
			}

			case enTransfersLog:
			{
				_ShowTransfersLogScreen();
				_GoBackToTransactionsMenuScreen();
				break;
			}

			case enMainMenu:
			{
				//Do Nothing Here, The Main Screen Will Handle It :-) ;
			}
		}
	}


public:

	static void ShowTransactionsMenuScreen()
	{
		if (!CheckAccessRights(clsUser::pTransactions))
		{
			return;
		}

		_DrawScreenHeader("Transactions Menu Screen");

		cout << clsUtility::Tabs(5) << "==================================================\n";
		cout << clsUtility::Tabs(7) << "Transactions Menu\n";
		cout << clsUtility::Tabs(5) << "==================================================\n";
		cout << clsUtility::Tabs(6) << "  1) Deposit.\n";
		cout << clsUtility::Tabs(6) << "  2) Withdraw.\n";
		cout << clsUtility::Tabs(6) << "  3) Total Balances.\n";
		cout << clsUtility::Tabs(6) << "  4) Transfer.\n";
		cout << clsUtility::Tabs(6) << "  5) Transfers Log.\n";
		cout << clsUtility::Tabs(6) << "  6) Main Menu.\n";
		cout << clsUtility::Tabs(5) << "==================================================\n";
		cout << clsUtility::Tabs(5) << "Choose What Do You Want To Do? (1 To 6)? ";

		_PerformTransactionsMenuScreen((enTransactionsMenuOptions)_ReadTransactionsMenuOption());
	}

};