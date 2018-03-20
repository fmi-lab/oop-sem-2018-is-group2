#include "IntContainer.h"
#include <iostream>
#include<cassert>
IntArrayContainer::IntArrayContainer() {
	arr = new int[4];
	size = 0;
	capacity = 4;
}
IntArrayContainer::IntArrayContainer(int capacity) {
	this->capacity = capacity;
	size = 0;
	arr = new int[this->capacity];
}
IntArrayContainer::IntArrayContainer(const IntArrayContainer& other) {
	capacity = other.capacity;
	size = other.size;
	arr = new int[capacity];
	for (int i = 0; i < size; i++) {
		arr[i] = other.arr[i];
	}
}
IntArrayContainer::~IntArrayContainer() {
	delete[] arr;
}
IntArrayContainer& IntArrayContainer::operator=(const IntArrayContainer& other) {
	if (this != &other) {
		delete[] arr;
		capacity = other.capacity;
		size = other.size;
		arr = new int[capacity];
		for (int i = 0; i < size; i++) {
			arr[i] = other.arr[i];
		}
	}
	return *this;
}
bool IntArrayContainer::empty() const {
	return size == 0;
}
bool IntArrayContainer::full() const {
	return size == capacity;
}
bool IntArrayContainer::member(int element) const {
	for (int i = 0; i < size;i++) {
		if (arr[i] == element) return true;
	}
	return false;
}
int IntArrayContainer::count() const {
	return size;
}
void IntArrayContainer::print() const {
	for (int i = 0; i < size; i++) {
		std::cout << arr[i] << " ";
		
	}
	std::cout << std::endl;
}
void IntArrayContainer::resize() {
	capacity *= 2;
	int* newArr = new int[capacity];
	for (int i = 0; i < size; i++) {
		newArr[i] = arr[i];
	}
	delete [] arr;
	arr = newArr;
}
void IntArrayContainer::add(int element) {
	if (full()) resize();
	arr[size++] = element;
}
void IntArrayContainer::remove(int element) {
	//Note: We don't keep the order of elements
	int indx = 0;
	for (; indx < size; indx++) {
		if (arr[indx] == element) break;
	}
	if (indx != size) {
		int temp = arr[size-1];
		arr[size-1] = arr[indx];
		arr[indx] = temp;
		size--;
	}
}
int IntArrayContainer::find(bool(*pred)(int&)) {
	for (int i = 0; i < size; i++) {
		if (pred(arr[i])) return arr[i];
	}
	//What happens if there is no such element?
	assert(false);
}
IntArrayContainer IntArrayContainer::filter(bool(*pred)(int&)) {
	IntArrayContainer newContainer;
	for (int i = 0; i < size; i++) {
		if (pred(arr[i])) newContainer.add(arr[i]);
	}
	return newContainer;
}
void IntArrayContainer::map(void(*mod)(int& elem)) {
	for (int i = 0; i < size; i++) {
		mod(arr[i]);
	}
}
const int& IntArrayContainer::operator[](int indx) const {
	assert(indx >=0 && indx < size );
	std::cout << "access \n";
	return arr[indx];
}
int& IntArrayContainer::operator[](int indx) {
	assert(indx >= 0 && indx < size);
	std::cout << "mutate \n";
	return arr[indx];
}