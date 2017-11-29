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

