// ConsoleApplicationLaba3.cpp: определяет точку входа для консольного приложения.

/*Реализовать шаблон класса дек (Deque<X>), хранящий элементы произвольного типа.
Класс должен в обязательном порядке содержать методы:

-Вычисление длины дека;
-Добавление нового элемента в конец;
-Добавление нового элемента в начало;
-Удаление элемента с начала;
-Удаление элемента с конца;
-Получение элемента с начала;
-Получение элемента с конца;
-Печать.

 Реализация дека с помощью массива;*/

#include "stdafx.h"
#include <string>
#include <iostream>
#include "Deque.cpp"

using namespace std;

template<typename Type>
void Test(int length_deque, Type* mas, int length_mas) {
	Deque<Type> element(length_deque);
	int i = 0;
	while ( (i < length_mas) && (element.push_front(mas[i])) ) {
		i++;
	}
	element.print();

	cout << "\nTake element from head and delete:";
	Type first ;
	if (element.get_front(first)){
		cout << "\nElement from head:  ";
		cout << first;
	}
	else {
		cout << "\nDeque is empty.";
	}

	if (element.pop_front()) {
		cout << "   First element delete.";
	}
	element.print();

	cout << "\nTake element from back and delete:";
	Type last;
	if (element.get_back(last)) {
		cout << "\nElement from back:  ";
		cout << last;
	}
	else {
		cout << "\nDeque is empty.";
	}

	if (element.pop_back()) {
		cout << "   Last element delete.";
	}
	element.print();

	if (length_mas > length_deque) {
		for (int j = 0; j < 5; j++) {
			if (element.pop_front());
		}
		i = length_deque;
		while ((i < length_mas) && (element.push_back(mas[i]))) {
			i++;
		}
		element.print();
	}
}

int main()
{
	int length_deque;
	cout << "Enter deque length: \n";
	cin >> length_deque;
	while (length_deque < 1)
	{
		cout << "Diapazone must be above zero:  ";
		cin >> length_deque;
	}

	cout << "\nTest 1, string: \n";
	string arrStr[] = { "qwerty", "allen", "kikiki", "hvatit" };
	Test<string>(length_deque,arrStr, 4);
	cout << endl;

	cout << "\nTest 2, boolean: \n";
	bool arrBool[] = {true, false, false, true };
	Test<bool>(length_deque,arrBool, 4);
	cout << endl;

	cout << "\nTest 3, float: \n";
	float arrFl[] = { 2.3, 4.2, -12, 90.666 };
	Test<float>(length_deque,arrFl, 4);
	cout << endl;

	cout << "\nTest 4, char: \n";
	char arr[] = { 'a', 'h', '4', 'z' };
	Test<char>(length_deque,arr, 4);
	cout << endl;

    
	cout << "\nTest 5, int: \n" ;
	int *arrInt = new int[length_deque+20];
	for (int i = 0; i < length_deque + 20; i++) {
		arrInt[i] = rand() % 100;
	}
	Test<int>(length_deque,arrInt, length_deque + 20);
	cout << endl;

	system("pause");
    return 0;
}

