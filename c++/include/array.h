#ifndef ARRAY_H_
#define ARRAY_H_

#include <stdexcept>

#define DEFAULT_SIZE 20

template<class T>
class Array {
private:
	int s;
	int c;
	T* data;
	void resize(int new_capacity) {
		T* tmp = new T[new_capacity];
		int length = s > new_capacity ? new_capacity : s;
		for(int i = 0; i < length; i++) {
			tmp[i] = data[i];
		}
		delete[] data;
		data = tmp;
		c = new_capacity;
	}
public:
	Array(int initial_capacity) {
		data = new T[initial_capacity];
		s = 0;
		c = initial_capacity;
	}

	Array() : Array(DEFAULT_SIZE) {
	}

	virtual ~Array() {
		delete[] data;
	}
	
	int size() {
		return s;
	}

	int capacity() {
		return c;
	}

	bool isEmpty() {
		return s == 0;
	}

	T at(int index) {
		if(index < 0 || index >= s) {
			throw std::out_of_range("Invalid index");
		}
		return data[index];
	}

	void push(const T& item) {
		if(s == c) {
			resize(c * 2);
		}
		data[s] = item;
		s++;
	}

	T& pop() {
		return data[--s];
	}

	void insert(int index, const T& item) {
		if(s == c) {
			resize(c * 2);
		}
		for(int i = s; i > index; i++) {
			data[i] = data[i - 1];
		}
		data[index] = item;
	}

	void prepend(const T& item) {
		insert(0, item);
	}

	//void delete(int index);
	void remove(const T& item) {
		int index = find(item);
		if(index != -1) {
			for(int i = index + 1; i < s - 1; i++) {
				data[i] = data[i + 1];
			}
		}
		s--;
	}

	int find(const T& item) {
		return -1;
	}
};
#endif