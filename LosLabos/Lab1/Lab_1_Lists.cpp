// Lab_1_Lists.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "iostream"
#include "List.h"


int main()
{
	std::cout << "Variant 6" << std::endl;
	std::cout << "Adding previous elements to every unit of array." << std::endl;
	List* elements = new List();
	List* newArray = new List();
	int ch(-1);
	while (ch != 0) {
		std::cout << "Creating array. Enter operation:" << std::endl;
		std::cout << "1 - Add element..." << std::endl;
		std::cout << "2 - Remove 'first in' element..." << std::endl;
		std::cout << "3 - Show array..." << std::endl;
		std::cout << "0 - Finish adding elements..." << std::endl;
		std::cin >> ch;
		switch (ch) {
			int elem;
		case 0:
			std::cout << "Creating finished.";
			break;
		case 1:
			std::cout << "Enter element" << std::endl;
			std::cin >> elem;
			elements->add(elem);
			std::cout << "Element " << elem << " successfully added!" << std::endl;
			break;
		case 2:
			std::cout << "Enter element" << std::endl;
			std::cin >> elem;
			elements->deleteElem(elem);
			std::cout << "Element " << elem << " successfully removed!" << std::endl;
			break;
		case 3:
			std::cout << "Your array: " << std::endl;
			elements->print();
			std::cout << "Length: " << elements->length() << std::endl;
			break;
		}
	}

	for (int i = 0; i < elements->length(); i++) {
		ListElement* currElem = elements->getPtrByIndex(i);
		newArray->add(currElem->data);
		int currInd = 0;
		ListElement *t = elements->first;
		while (currInd != i) {
			newArray->add(t->data);
			t = t->next;
			currInd++;
		}
	}
	newArray->print();
}

