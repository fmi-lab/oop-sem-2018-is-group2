#ifndef __LINKEDLIST__HH__
#define __LINKEDLIST__HH__
template<class T>
struct ListNode {
	T data;
	ListNode<T>* next;
	ListNode(const T&, ListNode<T>* = nullptr);
};

template<class T>
ListNode<T>::ListNode(const T& elem, ListNode<T>* next) {
	data = elem;
	this->next = next;
}

template<class T>
class LinkedList {
	ListNode<T>* start;
	ListNode<T>* end;
	int size;
	void copy(const LinkedList<T>&);
	void destroy();
public:
	LinkedList();
	LinkedList(const LinkedList&);
	LinkedList& operator=(const LinkedList&);
	~LinkedList();
	int getSize();
	bool empty();
	void toEnd(const T& data);
	//void insertBefore(ElemNode<T>*);
	//void insertAfter(ElemNode<T>*);
	//void insertBefore(const T& data);
	//void insertAfter(const T& data);
	//void removeBefore(ElemNode<T>*);
	//void removeAfter(ElemNode<T>*);
	//void remove(ElemNode<T>*);
	//void remove(const T&);
	void print();
	//T& operator[](const int);
	//void reverse();
};
template<class T>
void LinkedList<T>::copy(const LinkedList<T>& other) {
	size = other.size;
	ListNode<T>* other_holder = other.start;
	start = end = nullptr;
	while (other_holder) {
		if (!start) {
			start = new ListNode<T>(other_holder->data);
			end = start;
		}
		else {
			end->next = new ListNode<T>(other_holder->data);
			end = end->next;
		}
		other_holder = other_holder->next;
	}
}
template<class T>
void LinkedList<T>::destroy() {
	while (start) {
		ListNode<T>* temp = start;
		start = start->next;
		delete temp;
	}
	end = start;
}
template<class T>
LinkedList<T>::LinkedList() {
	start = end = nullptr;
	size = 0;
}
template<class T>
LinkedList<T>::LinkedList(const LinkedList<T>& other) {
	copy(other);
}
template<class T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& other) {
	if (this != &other) {
		destroy();
		copy(other);
	}
	return *this;
}
template<class T>
LinkedList<T>::~LinkedList() {
	destroy();
}
template<class T>
bool LinkedList<T>::empty() {
	return size == 0;
}
template<class T>
int LinkedList<T>::getSize() {
	return size;
}
template<class T>
void LinkedList<T>::toEnd(const T&data) {
	if (!start) {
		start = new ListNode<T>(data);
		end = start;
		size++;
	}
	else {
		end->next = new ListNode<T>(data);
		end = end->next;
		size++;
	}
}
template<class T>
void LinkedList<T>::print() {
	ListNode<T>* temp = start;
	while (temp) {
		std::cout << temp->data << " ";
		temp = temp->next;
	}
}
#endif