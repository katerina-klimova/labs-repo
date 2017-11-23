// ConsoleApplicationLaba3.cpp: ���������� ����� ����� ��� ����������� ����������.

/*����������� ������ ������ ��� (Deque<X>), �������� �������� ������������� ����.
����� ������ � ������������ ������� ��������� ������:

-���������� ����� ����;
-���������� ������ �������� � �����;
-���������� ������ �������� � ������;
-�������� �������� � ������;
-�������� �������� � �����;
-��������� �������� � ������;
-��������� �������� � �����;
-������.

 ���������� ���� � ������� �������;*/

#include "stdafx.h"
#include <string>
#include <iostream>

using namespace std;

//const int MAX_LENGTH = 10000;

template <typename Type>
class Deque {
private:
	Type *arr;
	int count_front;
	int count_back;
	int length;
	int MAX_LENGTH;


public:
	Deque(int MAX_LENGTH); //�����������
	~Deque(); //����������

	int get_length() const;
	bool push_back(Type el); //��������� � �����
	bool push_front(Type el); //��������� � ������
	bool get_front(Type &el); // ������� �� ������
	bool get_back(Type &el); // ������� �� ������
	bool pop_front(); //������� ������
	bool pop_back();  //������� ���������
	void print() const;
};

template<typename Type>
Deque<Type>::Deque(int length_deque) {
	MAX_LENGTH = length_deque;
	arr = new Type[MAX_LENGTH]; // ��������� ����� 
	count_front = 0;
	count_back = 0;
	length = 0;
}
//����������� � �����
//������ � ����������� ����� ����

template<typename Type>
Deque<Type>::~Deque() {
	delete[]arr;
}

template<typename Type>
int Deque<Type>::get_length() const{
	return length;
}

// len = 3
// count_front = MAX_LENGTH-3
// count_back = MAX_LENTGTH-1
template<typename Type>
bool Deque<Type>::push_back(Type el) {//���
	if (length == MAX_LENGTH) {
		cout << "Deque is full";
		return false;
	}
	
	//arr[(count_front + length) % MAX_LENGTH] = el;

	if (length != 0) {
		if (count_back == MAX_LENGTH - 1) {
			count_back == 0;
		}
		else {
			count_back++;
		}
	}
	arr[count_back] = el;
	length++;
	return true;
}

template<typename Type>
bool Deque<Type>::push_front(Type el) {//���
	if (length == MAX_LENGTH) {
		cout << "Deque is full";
		return false;
	}
	if (length != 0) {
		count_front--;
		if (count_front < 0) {
			count_front = MAX_LENGTH + count_front ;
		}
	}
	arr[count_front] = el;
	length++;
	return true;
}

template<typename Type>
bool Deque<Type>::get_front(Type &el) {
	if (length != 0){
		el = arr[count_front];
		return true;
	}

	return false;
}

template<typename Type>
bool Deque<Type>::get_back(Type &el) {
	if (length != 0) {
		el = arr[count_back];
		return true;
	}

	return false;
}

template<typename Type>
bool  Deque<Type>::pop_front() { //���������� �� 1
	if (length == 0) {
		return false;
	}
	if (count_front == MAX_LENGTH) {
		count_front = 0;
	}
	else {
		count_front++;
	}
	length--;
	return true;
}

template<typename Type>
bool  Deque<Type>::pop_back() { //���������� �� 1
	if (length == 0) {
		return false;
	}
	if (count_back == 0) {
		count_back = MAX_LENGTH - 1;
	}
	else {
		count_back--;
	}
	length--;
	return true;
}

template<typename Type>
void Deque<Type>::print() const {
	if (length == 0) {
		cout << "Deque is empty.";
		return;
	}
	cout << "\nDeque: ";
	
	if (count_front < count_back) {
		for (int i = count_front; i <= count_back; i++) {
			cout << arr[i] << "  ";
		}
	}
	else {
		for (int i = count_front; i < MAX_LENGTH; i++) {
			cout << arr[i] << "  ";
		}
		for (int i = 0; i <= count_back; i++)
		{
			cout << arr[i] << "  ";
		}
	}
}

template<typename Type>
void Test(int length_deque, Type* mas, int length_mas) {
	Deque<Type> element(length_deque);
	int i = 0;
	while ( (i < length_mas) && (element.push_front(mas[i])) ) {
		i++;
	}
	
	/*for (int i = 0; i < length_mas; i++) {//�������� ����� �������
		if(element.push_front(mas[i]));
	}*/
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

