#include <ostream>
#include "List.h"
#include "Node.h"

template <typename T>
class ListLinked : public List<T> {

    private:
 	Node<T>* first;
	int n;
        // ...

    public:
	ListLinked() : first(nullptr), n(0){}

	~ListLinked(){
		Node<T>* aux;
		while (first != nullptr){
			aux = first->next;
			delete first;
			first = aux;
		}
	}
	
	T& operator[](int pos){
		if (pos < 0 || pos >=  n){
			throw std::out_of_range("Posición fuera del vector");
		}
		Node<T>* current = first;
		for (int i = 0; i < pos; i++){
			current = current->next;
		}
		return current->data;
	}
	
	void insert(int pos, T e) override {
		if (pos > n || pos < 0) {
			throw std::out_of_range("Posicion fuera de rango.");
		} 
		
		Node<T>* current = first;
		Node<T>* nuevo = new Node<T>(e);
		int cont = 0;
		while (cont < pos - 1) {
			current = current->next;
			cont++;
		}
		nuevo->next = current->next;
		current->next = nuevo;

		n++;

	} 


		
	void append(T e) override {
		 Node<T>* nuevo = new Node<T>(e);
		 if (first == nullptr) {
			first = nuevo;
		 } else {
		
			 Node<T>* current = first;
			 while (current->next != nullptr) {
				current = current->next;
			 }
	 		 current->next = nuevo;
		 }
		 n++;	 
	}

	void prepend(T e) override {

		Node<T>* nuevo = new Node<T>(e);

		 if (first == nullptr) {
			first = nuevo;	
		 } else {
		 
		 	nuevo->next = first;
		 	first = nuevo;
		 }
		 n++;
	}

	T remove(int pos) override {
		if (pos < 0 || pos >=  n) {
			throw std::out_of_range("Posicion fuera de rango.");
		}
		
	        Node<T>* current = first;
		Node<T>* aux;
		T savePos;
		
		if (pos == 0) {
			first = first->next;
			savePos = current->data;
			delete current;
	
		} else {

			int cont = 0;

			while (cont <  pos - 1) {
			current = current->next;
			cont++;
			}
		
			aux = current->next;
			current->next = aux->next;
	

			savePos = aux->data;
			delete aux;
		}
		n--;
		
		return savePos;
	}

	T get(int pos) override {
		if (pos < 0 || pos >=  n) {
			throw std::out_of_range("Posicion fuera de rango.");
		}

		Node<T>* current = first;
		T saveData;

		while (current->next < pos - 1) {
			current = current->next;
		}
		saveData = current->data;

		return saveData;
	}

	int search(T e) override {
		Node<T>* current = first;
		int pos = 1;

		while (current->data != e) {
			current = current->next;
			pos++;
		}

		return pos;
	}	

	bool empty() override {
		return (first->next == nullptr);

	}

	int size() override {
		return n;
	}
		
	template <typename U>
	friend std::ostream& operator<<(std::ostream &out, const ListLinked<U> &list);
};       

	template<typename U>
	std::ostream& operator<<(std::ostream &out, const ListLinked<U> &list){
		Node<U>* current = list.first;
		while(current != nullptr ){
			out << current->data << " ";
			current = current->next;
		}
		return out;
	}

