#ifndef _INTCONTAINER_HH_
#define _INTCONTAINER_HH_
class IntArrayContainer {
	int* arr;
	int size;
	int capacity;
	void resize();
public:
	IntArrayContainer();
	IntArrayContainer(int);
	IntArrayContainer(const IntArrayContainer&);
	~IntArrayContainer();
	IntArrayContainer& operator=(const IntArrayContainer&);
	const int& operator[](int)const;
	int& operator[](int);
	bool empty() const;
	bool full() const;
	bool member(int) const;
	int count()const;
	void print()const;
	void add(int);
	void remove(int);
	int find(bool(*pred)(int&));
	IntArrayContainer filter(bool(*pred)(int&));
	void map(void(*mod)(int&));
};
#endif