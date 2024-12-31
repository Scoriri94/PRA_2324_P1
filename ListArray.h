#include <iostream>
#include <stdexcept>
#include <ostream>
#include "List.h"

template <typename T>
class ListArray : public List<T> {
private:
    T* arr;
    int max;
    int n;
    static const int MINSIZE = 2;

public:
    ListArray() : arr(new T[MINSIZE]), max(MINSIZE), n(0) {}

    ~ListArray() {
        delete[] arr;
    }

    T operator[](int pos) {
        if (pos < 0 || pos >= n) {
            throw std::out_of_range("Posicion no existe");
        }
        return arr[pos];
    }

    template <typename U>
    friend std::ostream& operator<<(std::ostream &out, const ListArray<U> &list);

    void resize(int new_size) {
        if (new_size < MINSIZE) {
            throw std::out_of_range("No puede ser menor a 2");
        }

        T* new_arr = new T[new_size];
        for (int i = 0; i < n; i++) {
            new_arr[i] = arr[i];
        }
        delete[] arr;
        arr = new_arr;
        max = new_size;
    }

    void insert(int pos, T e) override {
        if (pos > n || pos < 0) {
            throw std::out_of_range("Posicion fuera de rango");
        }

        if (n == max) {
            resize(max * 2);
        }

        for (int i = n; i > pos; i--) {
            arr[i] = arr[i - 1];
        }

        arr[pos] = e;
        n++;

        if (n <= max / 4 && max > MINSIZE) {
            resize(max / 2);
        }
    }

    void append(T e) override {
        if (n == max) {
            resize(max * 2);
        }

        arr[n] = e;
        n++;
    }

    void prepend(T e) override {
        if (n == max) {
            resize(max * 2);
        }

        for (int i = n; i > 0; i--) {
            arr[i] = arr[i - 1];
        }

        arr[0] = e;
        n++;
    }

    T remove(int pos) override {
        if (pos < 0 || pos >= n) {
            throw std::out_of_range("Posicion fuera de rango.");
        }

        T savePos = arr[pos];

        for (int i = pos; i < n - 1; i++) {
            arr[i] = arr[i + 1];
        }

        n--;

        if (n <= max / 4 && max > MINSIZE) {
            resize(max / 2);
        }

        return savePos;
    }

    T get(int pos) override {
        if (pos < 0 || pos >= n) {
            throw std::out_of_range("Posicion fuera de rango.");
        }
        return arr[pos];
    }

    int search(T e) override {
        int i = 0;
        while (i < n && arr[i] != e) {
            i++;
        }
        return (i < n) ? i : -1;
    }

    bool empty() override {
        return n == 0;
    }

    int size() override {
        return n;
    }
};

template <typename T>
std::ostream& operator<<(std::ostream &out, const ListArray<T> &list) {
    for (int i = 0; i < list.n; i++) {
        out << list.arr[i] << std::endl;
    }
    return out;
}
