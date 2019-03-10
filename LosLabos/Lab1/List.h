#pragma once

struct ListElement
{
public:
	ListElement * next;
	int data;
};

class List
{
public:
	ListElement *first, *last;
	List();

	void addFirst(int data);
	void add(int data);
	void print();
	void deleteElem(int data);
	int length();
	int getByIndex(int index);
	ListElement* getPtrByIndex(int index);
};

