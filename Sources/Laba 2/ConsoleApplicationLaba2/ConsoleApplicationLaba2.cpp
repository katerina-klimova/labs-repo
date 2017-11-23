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
#include <string>
#include "cmath"
using namespace System;
using namespace std;

class Money
{
	long rub;
	unsigned char cop;
public:

	Money(long r, unsigned char c) {
		rub = r + c / 100;
		cop = c % 100;
	}

	Money(long c) {
		rub = c / 100;
		c %= 100;
		if (c < 0)
		{
			c = 0 - c;
		}
		cop = unsigned char (c);
	}

	void Read()
	{
		long c;
		do
		{
			cout << "������� ����� � ��������:  \n";
			cin >> c;
		} while (c <= 0);
		rub = c / 100;
		cop = c % 100;
	}

	void Display()
	{
		cout << this->toString() << "\n";
	}

	string toString()
	{
		string str = "";
		str = to_string(rub);
		str += ",";
		if (int(cop) < 10)
		{
			str += "0";
		}
		str += to_string(int(cop));
		return str;
	}

	long Wholesum() const {
		return (this->rub * 100 + this->cop);
	}

	Money operator + (Money &const mon) const //�������� ���� 
	{
		return (this->Wholesum() + mon.Wholesum());
	}

	Money operator - (Money &const mon) const //��������� ����
	{
		return (this->Wholesum() - mon.Wholesum());
	}
	
	double operator / (Money &const mon) const //������� ���� - ������� �����
	{
		if (mon.Wholesum() == 0)
		{
			return -1;
		}
		return (double(this->Wholesum()) / double(mon.Wholesum()));
	}

	Money operator / (double num) const //������� ����� �� ������� �����
	{
		return (this->Wholesum()/num);
	}

	Money operator * (double num) const //��������� ����� �� ������� �����
	{
		return (this->Wholesum() * num);
	}

	int compare(Money mon)
	{
		if (this->Wholesum() == mon.Wholesum())
		{
			return 0;
		}
		if (this->Wholesum() > mon.Wholesum())
		{
			return 1;
		}
			return -1;
	}

	bool operator< (Money other) {
		return this->compare(other) < 0;
	}

	bool operator> (Money other) {
		return this->compare(other) > 0;
	}

	bool operator== (Money other) {
		return this->compare(other) == 0;
	}
};

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
