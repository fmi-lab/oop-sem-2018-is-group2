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

#endif
