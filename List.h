#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

template <class T>
struct Node
{
	T value;
	Node* next;
};


template <class T>
class List
{
private:
	/*struct Node
	{
		T value;
		Node* next;
	};*/

	Node<T>* head;
	int size;

	template <class T> friend ofstream& operator<<(ofstream& of, const List<T>& list);
	template <class T> friend ifstream& operator>>(ifstream& ifs, List<T>& list);

public:
	List() : head(nullptr), size(0) { }
	~List()
	{
		DeleteAll();
	}

	List(const List& other)
	{
		head = nullptr;
		size = 0;

		Node* current = other.head;

		while (current != nullptr) {
			AddToHead(current->value);
			current = current->next;
		}
	}

	List& operator=(const List& other) {

		if (this == &other)
			return *this;

		while (!IsEmpty())
			DeleteHead();

		Node* current = other.head;

		while (current != nullptr) {
			AddToHead(current->value);
			current = current->next;
		}

		return *this;
	}

	bool IsEmpty() const
	{
		return head == nullptr;
	}

	bool IsValidPos(int pos) {

		return (pos >= 1 && pos <= size);
	}

	void AddToHead(T value) 
	{
		Node<T>* newElem = new Node<T>;
		newElem->value = value;
		newElem->next = head;
		head = newElem;

		size++;
		
	}


	void AddToTail(T value)
	{
		Node<T>* newElem = new Node;
		newElem->value = value;
		newElem->next = nullptr;

		if (head == nullptr)
		{
			head = newElem;
		}
		else
		{
			Node* current = head;
			while (current->next != nullptr)
			{
				current = current->next;
			}
			current->next = newElem;
		}
		size++;
	}

	void DeleteHead()
	{
		if (head == nullptr) return;

		Node<T>* temp = head->next;
		delete head;

		if (temp == nullptr)
			head = nullptr;
		else
			head = temp;

		size--;
	}


	void DeleteTail()
	{
		if (head == nullptr) return;

		if (head->next == nullptr)
		{
			delete head;
			head = nullptr;
		}
		else
		{
			Node<T>* current = head;
			while (current->next->next != nullptr)
			{

				current = current->next;
			}


			delete current->next;
			current->next = nullptr;
		}

		size--;
	}

	int GetSize() {
		return size;
	}

	void Print() const
	{
		Node<T>* current = head;
		while (current != nullptr) {

			
			cout << current->value ;

			current = current->next;
		}
	}

	void DeleteAll() {
		while (!IsEmpty())
			DeleteHead();
	}

	void Find(int pos) {

		if (IsEmpty()) {
			cout << "List is empty!" << endl;
			return;
		}

		if (!IsValidPos(pos))
		{
			cout << "Incorrect position! " << endl;
			return;
		}
		Node<T>* temp;

		temp = head;
		int i = 1;
		while (i < pos) {

			temp = temp->next;
			i++;
		}
		cout << pos << " element: ";
		cout << temp->value << endl;
	}

	void FindByValue(string k) {

		bool isFound = true;

		if (IsEmpty()) {
			cout << "List is empty!" << endl;
			return;
		}
		
		Node<T>* current=head;
		while (current != nullptr) {

			if (current->value == k) {
				cout << current->value << endl;
				break;
			}
			else {
				isFound = false;
			}

			current = current->next;
		}
		if (isFound == false)
			cout << k << " not found!" << endl;
		
	}


	void Insert(int pos, T value) {

		if (pos < 1 || pos > size + 1)
		{
			cout << "Incorrect position! " << endl;
			return;
		}

		if (pos == size + 1)
		{
			AddToTail(value);
			return;
		}
		else if (pos == 1)
		{
			AddToHead(value);
			return;
		}
		else {

			int i = 1;
			Node<T>* temp = new Node;
			temp->value = value;
			Node<T>* insert = head;
			while (i < pos - 1)
			{
				insert = insert->next;
				i++;
			}
			temp->next = insert->next;
			insert->next = temp;

			size++;
		}
	}

	void DelPos(int pos) {

		if (!IsValidPos(pos))
		{
			cout << "Incorrect position! " << endl;
			return;
		}

		int i = 1;
		Node<T>* del = head;
		while (i < pos - 1)
		{
			del = del->next;
			i++;
		}

		if (pos == 1)
			DeleteHead();
		else if (pos == size)
			DeleteTail();
		else {

			Node<T>* temp = del->next;
			del->next = temp->next;
			delete temp;
			size--;
		}
	}

};

template <class T> 
ofstream& operator<<(ofstream& of, const List<T>& list)
{
	Node<T>* elem= list.head;
	of << list.size << endl;
	while (elem != nullptr)
	{
		of << elem->value << endl;
		elem = elem->next;
	}

	return of;
}

template <class T> 
ifstream& operator>>(ifstream& ifs, List<T>& list)
{
	T value;
	int size;

	if (!list.IsEmpty()) {
		list.DeleteHead();
	}

	ifs >> size;
	ifs.ignore(12345, '\n');

	for (int i = 0; i < size; i++) {

		ifs>>value;
		list.AddToHead(value);
	}

	return ifs;
}




