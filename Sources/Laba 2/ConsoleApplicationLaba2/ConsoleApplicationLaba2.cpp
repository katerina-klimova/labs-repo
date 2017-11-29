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
//#include <string>
#include "cmath"
#include "Money.h"
using namespace System;
using namespace std;

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
