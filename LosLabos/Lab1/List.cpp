#include "stdafx.h"
#include "List.h"
#include <iostream>


List::List() {}

void List::add(int data) {
	ListElement* newElem = new ListElement;
	newElem->data = data;
	newElem->next = NULL;

	if (first == NULL) {
		first = newElem;
		last = newElem;
	}
	else {
		last->next = newElem;
		last = newElem;
		newElem = NULL;
	}
}

void List::addFirst(int data) {
	ListElement* newElem = new ListElement;
	newElem->data = data;

	if (first == NULL) {
		first = newElem;
		last = newElem;
	}
	else {
		newElem->next = first;
		newElem->data = data;
	}
}

void List::print() {
	ListElement* p = new ListElement;
	p = first;
	while (p != NULL) {
		std::cout << p->data << " ";
		p = p->next;
	}
	std::cout << std::endl;
}

void List::deleteElem(int data) {
	if (first == NULL) { return; }
	if (first == last) { 
		first = NULL;
		last = NULL;
		return;
	}
	if (first->data = data) {
		first = first->next;
		return;
	}
	ListElement *t = first;
	while (t->next != NULL) {
		if (t->data == data) {
			if (last = t->next) {
				last = t;
			}
			t->next = t->next->next;
			return;
		}
		t = t->next;
	}
}

int List::length()
{
	int count = 1;
	ListElement *t = first;
	while (t->next != NULL) {
		count++;
		t = t->next;
	}
	return count;
}

int List::getByIndex(int index)
{
	ListElement *t = first;
	int currIndex = 0;
	while (currIndex != index) {
		if (t->next != NULL) {
			currIndex++;
			t = t->next;
		}
	}
	return t->data;
}

ListElement* List::getPtrByIndex(int index)
{
	ListElement *t = first;
	int currIndex = 0;
	while (currIndex != index) {
		if (t->next != NULL) {
			currIndex++;
			t = t->next;
		}
		else {
			std::cout << "Wrong index" << std::endl;
			return NULL;
		}
	}
	return t;
}



