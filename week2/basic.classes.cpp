#include<iostream>
using namespace std;
class Student;
class A {
	Student s;
public:
	void temp() {
		s.print();
	}
};
class Student {
private:
	char name[20];
	int fN;
	double marks;
public:


	bool operator ==(Student s) {
		return fN == s.fN;
	}
	void setFN(int _fn) {
		fN = _fn;
	}
	int getFN() const {
		return fN;
	 }
	void print() {
		cout << this->fN << marks;
	}


};
//public private protected
int main() {
	Student st;
	//st.fN;
	//st.print();
	Student st1;
	st.setFN(81564);
	cout << st.getFN();
	A a;
	a.temp();
	//st.isEqual(st1); //st == st1
	//cout << (st == st1);//st.operator == (st1);
	//int a = 3, b = 5;
	//a + b;// + - * / % == && || & * << >> = bool() new() delete() ++ --
}