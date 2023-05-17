#include "Linked.h"
#include "assert.h"
#include <iostream>
using namespace std;

template <class T>
Node<T>::Node()
{
	value = 0;
	next = 0;
}

template <class T>
Node<T>::Node(T val)
{
	value = val;
	next = 0;
}

template <class T>
Linked<T>::Linked()
{
	head = tail = 0;
	count = 0;
}

template <class T>
int Linked<T>::length()
{
	return count;
}

template <class T>
bool Linked<T>::isEmpty()
{
	return (count == 0);
}

template <class T>
void Linked<T>::append(T val)
{
	Node<T>* n = new Node<T>(val);
	if (count == 0) 
	head = tail = n;
	else
	{
		tail->next = n;
		n->next = NULL;
		tail = n;
	}
	count++;
}

template <class T>
T Linked<T>::at(int pos)
{
	assert(pos >= 0 && pos < count);
	Node<T>* tmp = head;
	for (int i = 0; i < pos; i++)
		tmp = tmp->next;
	return tmp->value;
}

template <class T>
void Linked<T>::display()
{
	Node<T>* tmp = head;
	while (tmp != NULL)
	{
		cout << tmp;
		cout << endl;
		tmp = tmp->next;
	}
}

template <class T>
void Linked<T>::delete_fun(int pos)
{
	Node<T>* tmp = head;
	if (pos == 0)
	{
		head = head->next;
		delete tmp;
	}
	else
	{
		for (int i = 0; i < pos - 1; i++)
			tmp = tmp->next;
		Node<T>* d = tmp->next;
		tmp->next = d->next;
		delete d;
	}
	count--;
}

template <class T>
void Linked<T>::update(int index, T& user) {
	if (index >= count) {
		cout << "Error: Index out of range" << endl;
		return;
	}
	Node<T>* newNode = new Node<T>(user);
	Node<T>* current = head;
	for (int i = 0; i < index; i++) {
		current = current->next;
	}
	newNode->next = current->next;
	current->next = newNode;
}