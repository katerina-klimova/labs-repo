// ConsoleApplicationLaba2.cpp: ������� ���� �������.
/*������� ����� Money ��� ������ � ��������� �������.
����� ������ ���� ������������ ����� ������; ���� long ��� ������ � ���� unsigned char � ��� ������.
������� ����� (�������) ��� ������ �� ����� ������ ���� �������� �� ����� ����� �������.
����������� ��������, ���������, ������� ����, ������� ����� �� ������� �����, ��������� �� �������
����� � �������� ���������.

����������� ������ ���� �����������:
-����� ������������� Init(),
-����� ����� ������ � ���������� Read(),
-����� ������ ������ �� ����� Display(),
-�������������� � ������ toString(),
���������� ��������� ���������� �������� �������� ��� ������� ������.*/

#include "stdafx.h"
#include <iostream>
#include <sstream>
//#include <string>
#include "cmath"
#include "Money.h"
using namespace System;
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	cout << "�������� ��������, ��������� � ������� 2� ���������:\n";
	cout << "1 ";
	Money money(0);
	money.Read();
	cout << "2 " ;
	Money money2(0);
	money2.Read();

	cout << "\n��������:";
	(money + money2).Display();

	cout << "\n���������:";
	(money - money2).Display();

	if (money / money2 == -1)
	{
		cout << "\n������� ����������.\n";
	}
	else
	{
		cout << "\n�������:" << (money / money2);
	}

	cout << "\n\n���������:   ";
	if (money == money2)
	{
		cout << "����� �����.";
	}
	else
	{
		if (money > money2)
			cout << "������ ����� ������ ������.";
		else
			cout << "������ ����� ������ ������.";
	}
	

	cout << "\n\n�������� ��������� � ������� �������� �� �����:\n";
	cout << "\n��������� �� �����:\n \n";
	money.Read();
	cout << "������� �����:\n";
	double num;
	cin >> num;
	(money *num).Display();
	cout << "\n";

	cout << "\n������� �� �����:\n \n";
	money.Read();
	cout << "������� �����:\n";
	cin >> num;
	(money / num).Display();
	cout << "\n";

	system("pause");
	return 0;
}
