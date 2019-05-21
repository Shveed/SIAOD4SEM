#include "stdafx.h"
#include "Finder.h"
#include <ctype.h>

Finder::Finder(string line)
{
	this->Line = line;
}

Finder::~Finder()
{
}

string Finder::getLine() {
	return this->Line;
}

string Finder::toLower(string line)
{
	for (unsigned int i = 0; i < line.length(); i++) {
		if (!islower(line[i])) {
			line[i] = tolower(line[i]);
		}
	}
	return line;
}

int Finder::Excercise1(string shape, bool caseSensitive)
{
	if (!caseSensitive) {
		shape = toLower(shape);
		this->Line = toLower(this->Line);
	}
	unsigned int currentPos = 0;
	bool isFound = false;
	while (currentPos != this->Line.length() && !isFound && this->Line.length() - shape.length() >= currentPos) {
		if (this->Line[currentPos] == shape[0]) {
			unsigned int curr = 0;
			while (curr != shape.length() && this->Line[currentPos + curr] == shape[curr]) {
				curr++;
			}
			if (curr == shape.length()) {
				isFound = true;
				break;
			}
			currentPos += curr;
		}
		else {
			currentPos++;
		}
	}
	if (isFound) {
		return currentPos;
	}
	else {
		return -1;

	}
}
