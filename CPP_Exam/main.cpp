#include<iostream>
#include<stdio.h>
#include<Windows.h>

using namespace std;


int main() {

	setlocale(LC_ALL, "ru");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	char* strArray = new char[100];

	cin.getline(strArray, 100);

	int n = strlen(strArray);

	/*char* strArray_copy = new char[n];

	for (int i = 0; i < n; i++)
	{
		strArray_copy[i] = strArray[i];
	}
	
	cout << strArray << endl;
	cout << strArray_copy << endl;*/

	
	int action;

	while (1)
	{
		cout << strArray;

		cout << "\n1 - latin characters " << endl;
		cout << "2 - cyrillic characters " << endl;
		cout << "3 - punctuation characters " << endl;
		cout << "4 - numbers " << endl;
		cin >> action;

		switch (action)
		{
		case 1: for (int i = 0; i < n; i++)
				{
					if (strArray[i] > 64 && strArray[i] < 91 || strArray[i] > 96 && strArray[i] < 123)				// latin characters
					{
						strArray[i] = '*';
					}
				} break;
		case 2: for (int i = 0; i < n; i++)
				{
					if (strArray[i] > 192 && strArray[i] <=255)				// cyrillic characters
					{
						strArray[i] = '*';
					}
				}  break;
		case 3:  for (int i = 0; i < n; i++)
				{
					if (strArray[i] > 0 && strArray[i] <= 47 || strArray[i] >= 58 && strArray[i] <= 64 ||
						strArray[i] >= 91 && strArray[i] <= 96 || strArray[i] >= 123 && strArray[i] <= 191)				// other symbols
					{
						strArray[i] = '*';
					}
				}  break;
		case 4: for (int i = 0; i < n; i++)
				{
					if (strArray[i] > 47 && strArray[i] < 58)				//numbers
					{
						strArray[i] = '*';
					}
				}  break;
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