#pragma once
#include <string>
using namespace std;

class Money{
private:
	long rub;
	unsigned char cop;
public:
	Money(long r, unsigned char c);
	Money(long c);
	void Read();
	void Display();
	string toString();
	long Wholesum() const;
	Money operator + (Money &const mon) const;
	Money operator - (Money &const mon) const;
	double operator / (Money &const mon) const;
	Money operator / (double num) const;
	Money operator * (double num) const;
	int compare(Money mon);
	bool operator< (Money other);
	bool operator> (Money other);
	bool operator== (Money other);
};

