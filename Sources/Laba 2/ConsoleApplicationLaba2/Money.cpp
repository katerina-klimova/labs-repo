#include "stdafx.h"
#include "Money.h"
#include "cmath"

#include <iostream>
using namespace std;

Money::Money(long r, unsigned char c) {
	rub = r + c / 100;
	cop = c % 100;
}

Money::Money(long c) {
	rub = c / 100;
	c %= 100;
	if (c < 0)
	{
		c = 0 - c;
	}
	cop = unsigned char(c);
}

void Money::Read(){
	long c;
	do
	{
		cout << "¬ведите сумму в копейках:  \n";
		cin >> c;
	} while (c <= 0);
	rub = c / 100;
	cop = c % 100;
}

string Money::toString() {
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

void Money::Display(){
	cout << this->toString() << "\n";
}

long Money::Wholesum() const {
	return (this->rub * 100 + this->cop);
}

Money Money::operator + (Money &const mon) const //сложение сумм 
{
	return (this->Wholesum() + mon.Wholesum());
}

Money Money::operator - (Money &const mon) const //вычитание сумм
{
	return (this->Wholesum() - mon.Wholesum());
}

double Money::operator / (Money &const mon) const //деление сумм - вернуть число
{
	if (mon.Wholesum() == 0)
	{
		return -1;
	}
	return (double(this->Wholesum()) / double(mon.Wholesum()));
}

Money Money::operator / (double num) const //деление суммы на дробное число
{
	return (this->Wholesum() / num);
}

Money Money::operator * (double num) const //умножение суммы на дробное число
{
	return (this->Wholesum() * num);
}

int Money::compare(Money mon)
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

bool Money::operator< (Money other) {
	return this->compare(other) < 0;
}

bool Money::operator> (Money other) {
	return this->compare(other) > 0;
}

bool Money::operator== (Money other) {
	return this->compare(other) == 0;
}


