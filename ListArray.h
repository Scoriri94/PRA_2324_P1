#include <ostream>
#include "List.h"
#include <stdexcept>

template <typename T> 
class ListArray : public List<T> {

    private:
	T* arr;
	int max;
	int n;
	static const int MINSIZE = 2;	
	
	
    public:
	ListArray() : arr(new T[MINSIZE]), max(MINSIZE), n(0){
	}
	~ListArray(){
	delete[] arr;
	}

	T operator[](int pos){
		//this->pos = pos;
		if (pos < 0 || pos > n - 1){
			throw std::out_of_range("Posicion no existe");
		}
		return arr[pos];
	} 
	
	template <typename U>	
	friend std::ostream& operator<<(std::ostream &out, const ListArray<U> &list);
	
	void resize(int new_size){
		
		if (new_size < MINSIZE){
			throw std::out_of_range("No puede ser menor a 2");
		}

		T* new_arr = new T[new_size];
		for (int i = 0; i < n; i++){
			new_arr[i] = arr[i];
		}
		delete[] arr;
		arr = new_arr;
		max = new_size;

		/**if (n >= max -1){
			max *= 2;
		else (n <= (max/2)){
			max /= 2;**/
 	}

	void insert(int pos, T e) override{
	}

	void append(T e) override{
	}

	void prepend(T e) override{
	}

	T remove(int pos) override{
	}

	T get(int pos) override{
	}

	int search(T e) override{
	}

	bool empty() override{
	}

	int size() override{
	}
	
};

template <typename T>

	 std::ostream& operator<<(std::ostream &out, const ListArray<T> &list){
	       for (int i = 0; i < list.n; i++){
	   		out << list.arr[i] << std::endl;	       
	       }
	       return out;
 	}   // miIembros públicos, incluidos los heredados de List<T
