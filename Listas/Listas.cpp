// Listas.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class Node {
public:
	Node* next = NULL;
	Node* before = NULL;
	int value;

	Node(int value) { this->value = value; }
};

class Lista {
	Node* top;
	Node* end;

public:
	Lista() {
		top = NULL;
		end = NULL;
	}

	Node* getHead() {
		return top;
	}

	Node* getEnd() { return end; }

	int add(int value) {
		if (top == NULL) {
			// NO hay ningún elemento en la lista...
			top = new Node(value);
			end = top; return 0;
		}

		Node* actual = top;
		int index = 0;
		while (actual->next != NULL) {
			actual = actual->next;
			index++;
		}
		actual->next = new Node(value);

		end = actual->next;
		return index;
	}

	int remove(int index) {
		if (top == NULL) return -1;

		if (index == 0) {
			auto before = top;
			top = top->next;
			delete before;
			return index;
		};

		Node* before = NULL;
		Node* act = top;
		int count = 0;
		while (act->next != NULL && count != index)
		{
			before = act;
			act = act->next;
			count++;
		}

		std::cout << "\n - " << before->value << " - \n";

		// ultimo nodo...
		if (act->next == NULL && count == index) {
			before->next = NULL;
			end = before;
			delete act;
			return index;
		}

		// Nodo medio...
		if (count == index) {
			before->next = act->next;
			delete act;
		}

		return index;

		// Valor en medio....
		// x vacia ()
		// . ()
		// .___ primer elemento ()
		// ____. último elemento
		// -.-- Elemento medio
	}


	void showList() {
		Node* actual = this->top;
		while (actual != NULL)
		{
			std::cout << actual->value << " ";
			actual = actual->next;
		}
		std::cout << std::endl;
	}
};

int main()
{
	Lista list = Lista();
	list.add(1);
	list.add(2);
	list.add(3);
	list.showList();
	std::cout << "head: " << list.getHead()->value << std::endl;
	std::cout << "end: " << list.getEnd()->value << std::endl;
	list.remove(2);
	list.showList();
	std::cout << "head: " << list.getHead()->value << std::endl;
	std::cout << "end: " << list.getEnd()->value << std::endl;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
