// ConsoleApplicationLaba2.cpp: главный файл проекта.
/*Создать класс Money для работы с денежными суммами.
Число должно быть представлено двумя полями; типа long для рублей и типа unsigned char – для копеек.
Дробная часть (копейки) при выводе на экран должна быть отделена от целой части запятой.
Реализовать сложение, вычитание, деление сумм, деление суммы на дробное число, умножение на дробное
число и операции сравнения.

обязательно должны быть реализованы:
-метод инициализации Init(),
-метод ввода данных с клавиатуры Read(),
-метод вывода данных на экран Display(),
-преобразование в строку toString(),
необходимо выполнить перегрузку основных операций для методов класса.*/

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
			cout << "Введите сумму в копейках:  \n";
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

	Money operator + (Money &const mon) const //сложение сумм 
	{
		return (this->Wholesum() + mon.Wholesum());
	}

	Money operator - (Money &const mon) const //вычитание сумм
	{
		return (this->Wholesum() - mon.Wholesum());
	}
	
	double operator / (Money &const mon) const //деление сумм - вернуть число
	{
		if (mon.Wholesum() == 0)
		{
			return -1;
		}
		return (double(this->Wholesum()) / double(mon.Wholesum()));
	}

	Money operator / (double num) const //деление суммы на дробное число
	{
		return (this->Wholesum()/num);
	}

	Money operator * (double num) const //умножение суммы на дробное число
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

	cout << "Проверка сложения, вычитания и деления 2х элементов:\n";
	cout << "1 ";
	Money money(0);
	money.Read();
	cout << "2 " ;
	Money money2(0);
	money2.Read();

	cout << "\nСложение:";
	(money + money2).Display();

	cout << "\nВычитание:";
	(money - money2).Display();

	if (money / money2 == -1)
	{
		cout << "\nДеление невозможно.\n";
	}
	else
	{
		cout << "\nДеление:" << (money / money2);
	}

	cout << "\n\nСравнение:   ";
	if (money == money2)
	{
		cout << "Суммы равны.";
	}
	else
	{
		if (money > money2)
			cout << "Первая сумма больше второй.";
		else
			cout << "Первая сумма меньше второй.";
	}
	

	cout << "\n\nПроверка умножения и деления элемента на число:\n";
	cout << "\nУмножение на число:\n \n";
	money.Read();
	cout << "Введите число:\n";
	double num;
	cin >> num;
	(money *num).Display();
	cout << "\n";

	cout << "\nДеление на число:\n \n";
	money.Read();
	cout << "Введите число:\n";
	cin >> num;
	(money / num).Display();
	cout << "\n";

	system("pause");
	return 0;
}
