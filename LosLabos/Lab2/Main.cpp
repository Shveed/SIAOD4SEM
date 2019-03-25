// LabWork2 - SAOD.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"

/* 
	Струкртура "Звено", имеющая следующие параметры:
	x - значение звена
	*l - указатель на левого потомка 
	*r - указатель на правого потомка
*/
struct Node
{
public:
	int x;
	Node *l, *r;
};

/*
	Метод вывода значений звеньев на экран
	@param Node *&Tree
*/
void show(Node *& Tree)
{
	if (Tree != NULL) {
		show(Tree->l);
		std::cout << Tree->x << "\n";
		show(Tree->r);
	}
}
/*
	Метод добавления звена в дерево
*/
void addNode(int c, Node *& MyTree) {
	// если дерево не существует (ещё не создано) - создаём
	if (MyTree == NULL) {
		MyTree = new Node;
		MyTree->x = c;
		MyTree->l = MyTree->r = NULL;
	}
	// если добавляемый элемент меньше элемента в старшем звене дерева 
	if (c < MyTree->x) {
		// если левый потомок звена существует
		if (MyTree->l != NULL) {
			addNode(c, MyTree->l);
		}
		/*
			в противном случае выделяем память для левого 
			потомка и заносим наше значение в значение 
			левого потомка 
		*/
		else {
			MyTree->l = new Node;
			MyTree->l->l = MyTree->l->r = NULL;
			MyTree->l->x = c;
		}
	}
	// аналогично для правого потомка (если значение больше имеющегося)
	if (c > MyTree->x) {
		if (MyTree->r != NULL) {
			addNode(c, MyTree->r);
		}
		else {
			MyTree->r = new Node;
			MyTree->r->l = MyTree->r->r = NULL;
			MyTree->r->x = c;
		}
	}
}
//	Очистка памяти
void clearMemory(Node *&Tree) {
	if (Tree != NULL) {
		clearMemory(Tree->l);
		clearMemory(Tree->r);
		delete Tree;
		Tree = NULL;
	}
}

int main()
{
	Node *Tree = NULL;
	for (int i = 0; i < 10; i++) {
		if (i % 2 == 0) {
			addNode(i, Tree);
		}
		else {
			addNode(10 - i, Tree);
		}
	}
	show(Tree);
	clearMemory(Tree);


	std::cin.get();
	return 0;
}
