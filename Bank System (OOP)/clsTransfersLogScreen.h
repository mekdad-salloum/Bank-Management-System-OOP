#pragma once


class clsTransfersLogScreen : protected clsScreen
{

public:

	static void ShowTransfersLogScreen()
	{
		vector <clsClient::strTransferLogRecord> vTransfersLogRecords = clsClient::GetTransfersLogList();

		_DrawScreenHeader("Transfers Log List Screen", "   (" + to_string(vTransfersLogRecords.size()) + ") Record(s).");

		cout << clsUtility::Tabs(2) << "___________________________________________________________________________________________________________\n\n";
		cout << clsUtility::Tabs(2);
		cout << "| " << setw(25) << left << "Date - Time";
		cout << "| " << setw(15) << left << "S.AccNum";
		cout << "| " << setw(15) << left << "D.AccNum";
		cout << "| " << setw(10) << left << "Amount";
		cout << "| " << setw(10) << left << "S.Balance";
		cout << "| " << setw(10) << left << "D.Balance";
		cout << "| " << setw(10) << left << "UserName\n";
		cout << clsUtility::Tabs(2) << "___________________________________________________________________________________________________________\n\n";

		if (vTransfersLogRecords.size() == 0)
			cout << clsUtility::Tabs(6) << "No Records Available In the System!";

		else
		{
			for (clsClient::strTransferLogRecord& R : vTransfersLogRecords)
			{
				clsClientUI::PrintTransferLogRecord(R);
			}
		}


		cout << clsUtility::Tabs(2) << "___________________________________________________________________________________________________________\n";
	}
};