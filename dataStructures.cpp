// dataStructures.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <list>

using namespace std;

// Declaration of a doubly-linked list
class List {

private:
	// Internal struct for list nodes
	struct Node {
		int value;
		Node* next;
		Node* prev;

		Node(int val) : value(val), next(nullptr), prev(nullptr) {} 
	};

	// List internals
	Node* first = nullptr;
	Node* last = nullptr;
	unsigned int num_elems = 0;

public:
	// Constructor and destructor
	List() : first(nullptr), last(nullptr), num_elems(0){};
	~List() 
	{
		clear();
	};

	// Modifiers
	void push_front(const int& value)
	{
		Node* new_node = new Node(value);
		if (first == nullptr) 
		{
			first = last = new_node;
		} else {
			new_node->next = first;
			first->prev = new_node;
			first = new_node;
		}
		num_elems++;
	}

	void push_back(const int& value) 
	{
		Node* new_node = new Node{value};
		if (last) {
			last->next = new_node;  // Connect the last node to the new node
		}
		else {
			first = new_node;  // If the list is empty, the new node is both first and last
		}
		last = new_node;  // Set the new node as the last node
		num_elems++;
	}
	
	void insert(unsigned int position, const int& value) 
	{
		if (position == 0) {
			push_front(value);  // Insert at the front if position is 0
		}
		else if (position == num_elems) {
			push_back(value);  // Insert at the end if position is equal to size
		}
		else if (position < num_elems) {
			Node* new_node = new Node{value};
			Node* it = first;

			// Traverse to the correct position
			for (unsigned int i = 0; i < position; i++) {
				it = it->next;
			}

			// Insert the new node
			new_node->next = it;
			new_node->prev = it->prev;
			if (it->prev) {
				it->prev->next = new_node;
			}
			it->prev = new_node;

			num_elems++;
		}
	}

	void clear() 
	{
		Node* it = first;
		while (it) {
			Node* next_node = it->next;
			delete it;  // Free the current node
			it = next_node;
		}
		first = last = nullptr;
		num_elems = 0;
	}

	void printList() 
	{
		Node *it = first;

		while (it != nullptr) 
		{
			cout << it->value << "  ";
			it = it->next;
		}
		cout << endl;
	}
};


int main()
{
	List myList;

	myList.insert(0, 10);
	myList.printList();

	myList.insert(0, 20);
	myList.printList();

	myList.insert(0, 50);
	myList.printList();

	myList.insert(0, 12);
	myList.printList();
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
