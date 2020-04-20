#include<iostream>
#include<stdio.h>
#include<Windows.h>

using namespace std;

void StatusAction(bool status) {
	if (status == true) 
	{ 
		cout << "\tON" << endl; 
	}
	else if (status == false)
	{
		cout << "\tOFF" << endl;
	}
}

int main() {

	setlocale(LC_ALL, "ru");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	char* strArray = new char[100];

	cin.getline(strArray, 100);

	int length = strlen(strArray);

	/*char* strArray_copy = new char[length + 1];

	for (int i = 0; i < length; i++)
	{
		strArray_copy[i] = strArray[i];
	}*/
	
	//cout << strArray << endl;
	//cout << strArray_copy << endl;

	bool status1 = false;
	bool status2 = false;
	bool status3 = false;
	bool status4 = false;
	
	int action;

	while (1)
	{
		cout << strArray;

		cout << "\n1 - latin "; StatusAction(status1);
		cout << "2 - cyrillic "; StatusAction(status2);
		cout << "3 - signs "; StatusAction(status3);
		cout << "4 - numbers "; StatusAction(status4);
		cin >> action;

		switch (action)
		{
		case 1: for (int i = 0; i < length; i++)
		{
			if (strArray[i] > 64 && strArray[i] < 91 || strArray[i] > 96 && strArray[i] < 123)				// latin characters
			{
				strArray[i] = '*';
			}
		} 
			  status1 = true; break;
		case 2: for (int i = 0; i < length; i++)
				{
					if (strArray[i] > 192 && strArray[i] <=255)				// cyrillic characters
					{
						strArray[i] = '*';
					}
				} status2 = true; break;
		case 3:  for (int i = 0; i < length; i++)
				{
					if (strArray[i] > 0 && strArray[i] <= 47 || strArray[i] >= 58 && strArray[i] <= 64 ||
						strArray[i] >= 91 && strArray[i] <= 96 || strArray[i] >= 123 && strArray[i] <= 191)				// other symbols
					{
						strArray[i] = '*';
					}
				} status3 = true; break;
		case 4: for (int i = 0; i < length; i++)
				{
					if (strArray[i] > 47 && strArray[i] < 58)				//numbers
					{
						strArray[i] = '*';
					}
				} status4 = true; break;
		default:
			break;
		}

		system("cls");

	}
	
	delete[] strArray;
	//delete[] strArray_copy;

	cout << "\n\n";
	system("pause");
	return 0;
}