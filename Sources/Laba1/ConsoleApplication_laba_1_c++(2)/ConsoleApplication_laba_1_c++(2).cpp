// ConsoleApplication_laba_1_c++(2).cpp: определ¤ет точку входа дл¤ консольного приложени¤.
//”далить строки матрицы, не имеющие ни одного повтор¤ющеос¤ элемента.  лимова  атерина, 2 курс, 91 группа.

#include "stdafx.h" 
#include <cstdio>
#include <stdio.h> 
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;


void Show(int **Arr, int N_Str, int N_Coll)
{

	cout << endl;
	for (int i = 0; i < N_Str; i++)
	{
		for (int j = 0; j < N_Coll; j++)
		{
			cout << Arr[i][j] << "  ";
		}
		cout << endl;
	}
}

void Task(int **Arr, int N_Str, int N_Coll)
{

	for (int i = 0; i < N_Str; i++)
	{
		bool flag = false;
		for (int j = 0; j < N_Coll - 1; j++)
		{
			for (int k = j + 1; k < N_Coll; k++)
			{
				if (Arr[i][j] == Arr[i][k])
				{
					flag = true;
				}
			}
		}
		if (!flag)
		{
			delete[] Arr[i];
			Arr[i] = nullptr;
		}
	}

	int count_deleted_lines = 0;
	for (int i = 0; i < N_Str; i++)
	{
		if (Arr[i] == nullptr)
		{
			count_deleted_lines++;
		}
		else
		{
			Arr[i - count_deleted_lines] = Arr[i];
			if (count_deleted_lines > 0)
			{
				Arr[i] = nullptr;
			}
		}
	}

	N_Str -= count_deleted_lines;

	cout << endl;

	Show(Arr, N_Str, N_Coll);
	for (int i = 0; i < N_Str; i++)
	{
		if (Arr[i] != nullptr)
			delete[] Arr[i];
	}

	delete[]Arr;
}

void Enter_console()
{
	int N_Coll = 0, N_Str = 0;
	cout << "Number of lines:  ";
	cin >> N_Str;
	while (N_Str < 1)
	{
		cout << "Wrong number, try again:  ";
		cin >> N_Str;
	}

	cout << "Number of collums:  ";
	cin >> N_Coll;
	while (N_Coll < 1)
	{
		cout << "Wrong number, try again:  ";
		cin >> N_Coll;
	}

	int **Arr = new int*[N_Str];
	for (int i = 0; i < N_Str; i++)
	{
		Arr[i] = new int[N_Coll];
	}

	for (int i = 0; i < N_Str; i++)
	{
		for (int j = 0; j < N_Coll; j++)
		{
			cout << "\nElement" << i +1 << "," << j +1<< ":  ";
			cin >> Arr[i][j];
		}
	}

	Show(Arr, N_Str, N_Coll);

	Task(Arr, N_Str, N_Coll);

	system("pause");
}

void Enter_random()
{

	int N_Coll = 0, N_Str = 0;
	cout << "Number of lines:  ";
	cin >> N_Str;
	while (N_Str < 1)
	{
		cout << "Wrong number, try again:  ";
		cin >> N_Str;
	}

	cout << "Number of collums:  ";
	cin >> N_Coll;
	while (N_Coll < 1)
	{
		cout << "Wrong number, try again:  ";
		cin >> N_Coll;
	}

	int **Arr = new int*[N_Str];
	for (int i = 0; i < N_Str; i++)
	{
		Arr[i] = new int[N_Coll];
	}

	int diapazone;
	cout << "Enter diapazone:  ";
	cin >> diapazone;
	while (diapazone < 1)
	{
		cout << "Diapazone must be above zero:  ";
		cin >> N_Coll;
	}

	for (int i = 0; i < N_Str; i++)
	{
		for (int j = 0; j < N_Coll; j++)
		{
			Arr[i][j] = rand() % diapazone + 1;
			cout << "\nElement" << i << "," << j << ":  " << Arr[i][j];
		}
	}

	Show(Arr, N_Str, N_Coll);

	Task(Arr, N_Str, N_Coll);

	system("pause");
}

int Menu()
{
	int answ;

	cout << "Select: \n";
	cout << "1: Enter_console\n";
	cout << "2: Enter_random\n";

	cout << "0: Exit\n";
	cin >> answ;
	while ((answ<0) || (answ>2))
	{
		cout << "Uncorrect number, try again \n";
		cin >> answ;
	}

	getchar();
	return answ;
}

int main()
{
	switch (Menu())
	{
	case 1: Enter_console();
		break;
	case 2: Enter_random();
		break;
	}
	return 0;
}

