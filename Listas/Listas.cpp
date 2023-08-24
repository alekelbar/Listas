// Listas.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class Node {
public:
	Node* next = NULL;
	Node* before = NULL;
	int value;

	Node(int value) { this->value = value; }
	int getValue() { return this->value; }
	void setValue(int value) { this->value = value; }
};

class CustomList {
	Node* top;
	Node* end;

public:
	CustomList() {
		top = NULL;
		end = NULL;
	}

	Node* getHead() {
		return top;
	}

	Node* getEnd() {
		return end;
	}

	CustomList sumProduct(CustomList toSum) {
		Node* second = toSum.getHead();
		CustomList result;

		for (Node* internalNode = top; internalNode != NULL; internalNode = internalNode->next)
		{
			std::cout << internalNode->value << " -> ";
			Node* node = new Node(0); // La nueva lista

			for (Node* externalNode = second; externalNode != NULL; externalNode = externalNode->next)
			{
				int value = node->getValue();
				int internalValue = internalNode->getValue();
				int externalValue = externalNode->getValue();

				node->setValue(value + internalValue * externalValue);

				std::cout << externalNode->value << " ";
			}
			result.add(node);
			std::cout << std::endl;
		}
		return result;
	}

	int add(Node* newNode) {
		if (top == NULL) {
			// NO hay ningún elemento en la lista...
			top = newNode;
			end = top; return 0;
		}

		Node* actual = top;
		int index = 0;
		while (actual->next != NULL) {
			actual = actual->next;
			index++;
		}
		actual->next = newNode;

		end = actual->next;
		return index;
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
	CustomList list = CustomList();
	CustomList list2 = CustomList();
	list.add(new Node(1));
	list.add(new Node(1));
	list.add(new Node(1));
	list2.add(new Node(2));
	list2.add(new Node(2));
	list2.add(new Node(2));

	list.showList();
	std::cout << "head: " << list.getHead()->value << std::endl;
	std::cout << "end: " << list.getEnd()->value << std::endl;
	auto result = list.sumProduct(list2);
	result.showList();

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
