#ifndef __CONTAINER_HH__
#define __CONTAINER_HH__
#include<iostream>
#include<vector>
template<class T>
using predicate = bool(*)(const T&);
template<class T>
using modifier = void(*)(const T&);

template<class T>
class Container {
public:
	virtual bool member(const T&) = 0;
	virtual int size() const = 0;
	virtual bool full() const = 0;
	virtual bool empty() const = 0;
	virtual void add(const T&) = 0;
	virtual void remove(const T&) = 0;
	virtual void printData() const = 0;
	virtual T find(predicate) = 0;
	virtual Container<T> filter(predicate) = 0;
	virtual void map(modifier) = 0;
	virtual void exportData(std::ostream&) = 0;
	
};
template<class T>
class ArrayContainer :public Container<T> {
	T* arr;
	int size;
	int capacity;
	void resize() {
		capacity *= 2;
		T* temp_holder = new T[capacity];
		for (int i = 0; i < size; i++) {
			temp_holder[i] = arr[i];
		}
		delete[] arr;
		arr = temp_holder;
	}
	void copy(const ArrayContainer<T>& other) {
		capacity = other.capacity;
		size = other.size;
		arr = new T[capacity];
		for (int i = 0; i < size; i++) {
			arr[i] = other.arr[i];
		}
	}
	void del() {
		delete[] arr;
	}
public:
	ArrayContainer():size(0),capacity(4) {
		arr = new T[capacity];
	}
	ArrayContainer(const ArrayContainer<T>& other) { copy(other); }
	~ArrayContainer() { del(); }
	ArrayContainer<T>& operator=(const ArrayContainer<T>& other) {
		if (this != &other) {
			del();
			copy(other);
		}
		return *this;
	}
};
template<class T>
class VContainer:public Container<T> {
	std::vector<T> arr;
};
#endif
