#pragma once

template <class T>
class Node
{
public:
	Node<T>* next;
	T value;

	Node();
	Node(T val);
};

template <class T>
class Linked
{
	int count;
	Node<T>* head;
	Node<T>* tail;
public:
	Linked();
	int length();
	void append(T val);
	T at(int pos);
	bool isEmpty();
	void display();
	void delete_fun(int pos);
	void update(int index, T& user);
	//~Linked(void);
};