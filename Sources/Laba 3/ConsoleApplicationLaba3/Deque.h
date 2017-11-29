#pragma once
template <typename Type>
class Deque {
private:
	Type *arr;
	int count_front;
	int count_back;
	int length;
	int MAX_LENGTH;


public:
	Deque(int MAX_LENGTH); //конструктор
	~Deque(); //деструктор

	int get_length() const;
	bool push_back(Type el); //добавляет к конец
	bool push_front(Type el); //добавляет в начало
	bool get_front(Type &el); // елемент из головы
	bool get_back(Type &el); // элемент из хвоста
	bool pop_front(); //удаляет первый
	bool pop_back();  //удаляет последний
	void print() const;
};

