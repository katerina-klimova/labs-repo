#include "stdafx.h"
#include "Deque.h"


template<typename Type>
Deque<Type>::Deque(int length_deque) {
	MAX_LENGTH = length_deque;
	arr = new Type[MAX_LENGTH];
	count_front = 0;
	count_back = 0;
	length = 0;
}
template<typename Type>
Deque<Type>::~Deque() {
	delete[]arr;
}

template<typename Type>
int Deque<Type>::get_length() const {
	return length;
}
template<typename Type>
bool Deque<Type>::push_back(Type el) {
	if (length == MAX_LENGTH) {
		cout << "Deque is full";
		return false;
	}

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
bool Deque<Type>::push_front(Type el) {
	if (length == MAX_LENGTH) {
		cout << "Deque is full";
		return false;
	}
	if (length != 0) {
		count_front--;
		if (count_front < 0) {
			count_front = MAX_LENGTH + count_front;
		}
	}
	arr[count_front] = el;
	length++;
	return true;
}

template<typename Type>
bool Deque<Type>::get_front(Type &el) {
	if (length != 0) {
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
bool  Deque<Type>::pop_front() {
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
bool  Deque<Type>::pop_back() {
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
