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
	
		T operator[](int pos){
			if (pos < 0 || pos >=  n){
				throw std::out_of_range("Posición fuera del vector");
			}
			Node<T>* current = first;
			for (int i = 0; i < pos; i++){
				current = current->next;
			}
			return current->data;
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

