#include<iostream>
#include<cassert>
template<class U, class V>
struct Pair {
	U first;
	V second;
	Pair() = default;
	Pair(U _f, V _s) :first(_f), second(_s) {}
};

template<class U, class V>
class Relation {
	Pair<U,V> *pairs;
	int size;
	int capacity;
	void copy(const Relation<U, V>& other) {
		size = other.size;
		capacity = other.capacity;
		pairs = new Pair<U, V>[capacity];
		for (int i = 0; i < size; i++) {
			pairs[i] = other.pairs[i];
		}
	}
	void del() {
		delete[] pairs;
	}
	void resize() {
		Pair<U, V>* temp = new Pair<U, V>[capacity * 2];
		for (int i = 0; i < size; i++) {
			temp[i] = pairs[i];
		}
		delete[]pairs;
		pairs = temp;
	}
public:
	Relation() {
		
		size = 0;
		capacity = 4;
		pairs = new Pair<U, V>[capacity];
	}
	Relation(const Relation<U, V>& other) {
		copy(other);
	}
	Relation<U, V>& operator=(const Relation<U, V>& other) {
		if (this != &other) {
			del();
			copy();
		}
		return *this;
	}
	~Relation() { del(); }
	bool related(Pair<U, V>& p) {
		for (int i = 0; i < size; i++) {
			if (pairs[i].first == p.first && pairs[i].second == p.second) return true;
		}
		return false;
	}
	V operator[](const U& u) {
		for (int i = 0; i < size; i++) {
			if (pairs[i].first == u) return pairs[i].second;
		}
		assert(false);
	}
	Relation<U, V> operator+(const Relation<U, V>& r) {
		Relation<U, V> result;
		for (int i = 0; i < size; i++) {
			result.addPair(pairs[i]);
		}
		for (int i = 0; i < size; i++) {
			if (!result.related(r.pairs[i])) result.addPair(r.pairs[i]);
		}
		return result;
	}
	void addPair(const Pair<U, V>& p) {
		if (size == capacity) resize();
		pairs[size++] = p;
	}
	Relation<U, V>& operator+=(const Relation<U, V>& r) {
		return operator=(operator+(r));
	}
	bool isFunction() {
		for (int i = 0; i < size; i++) {
			U search = pairs[i].first;
			for (int j = i + 1; j < size; j++) {
				if (search == pairs[j].first) return false;
			}
		}
		return true;
	}
};
int main() {
	Pair<int, double> p1(1, 2);
	Pair<int, double> p2(1, 3);
	Pair<int, double> p3(2, 3);
	Pair<int, double> p4(15, 26);
	Relation<int, double> r;
	r.addPair(p1);
	r.addPair(p3);
	r.addPair(p4);
	Relation<int, double> r1;
	r1.addPair(p2);
	std::cout << std::boolalpha << r.isFunction() << std::endl;
	std::cout << std::boolalpha << r.related(p1)<< std::endl;
	std::cout <<r[2]<< std::endl;
	Relation<int, double> r2=(r + r1);
	std::cout << std::boolalpha << r2.isFunction() << std::endl;
	int i; std::cin >> i;
	return 0;
}