#include<iostream>
#include<vector>
class IntReader {
public:
	virtual bool read() = 0;
	virtual int getData()= 0;
	virtual bool isEmpty() const = 0;
	virtual ~IntReader() {};
};

using predicate = bool(*)(const int&);
//typedef bool(*pred)(const int&); -> alternative
class IntFilterReader:public IntReader {
	predicate p;
//	bool(*p)(const int&); -> alternative
//	pred pr; -> alternative
	int data;
public:
	IntFilterReader(predicate pred) :p(pred),data(-1) {}
	bool read() override {
			int temp;
			std::cin >> temp;
			if (temp != 0 && p(temp)) {
				data = temp;
				return true;
			}
			else {
				data = -1;
				return false;
			}

	}
	int getData()override {
		if (!isEmpty()) {
			int temp = data;
			data = -1;
			return temp;
		}
		else return -1;
	}
	bool isEmpty()const { return data ==-1; }
};
class IntBufferedReader :public IntReader {
	std::vector<int> buffer;
	int capacity;
public:
	IntBufferedReader(const int& cap) :capacity(cap) {}
	bool read() override {
		while (!full()) {
			int temp;
			std::cin >> temp;
			if (temp != 0) {
				buffer.push_back(temp);
				return true;
			}
		}
		return false;
	}
	int getData() {
		if (!buffer.empty()) {
			int temp = buffer[buffer.size()-1];
			buffer.pop_back();
			return temp;
		}
		else return -1;
	}
	bool full() { return buffer.size() == capacity; }
	bool isEmpty() const{ return buffer.size() == 0; }
};
bool isEven(const int& elem) { return elem % 2 == 0; }
int main() {
	IntFilterReader f(isEven);
	IntBufferedReader b(3);
	std::cout << "Initialising b..." << std::endl;
	while (b.read()) {}
	std::cout << "End of initialising b..." << std::endl;
	std::cout << "Initialising f..." << std::endl;
	f.read();
	std::cout << "End of initialising f..." << std::endl;
	//std::cout << "B: " << b.getData() << std::endl;
	IntReader* arr[2];
	arr[0] = &f;
	arr[1] = &b;
	int sum = 0;
	for (int i = 0; i < 5; i++) {
		//std::cout<<"Iter: " << i << std::endl;
		for (int j = 0; j < 2; j++) {
			if (!arr[j]->isEmpty()) {
				int t = arr[j]->getData();
				//std::cout << "TOSUM: " << t << std::endl;
				sum += t;
			}
		}
	}
	std::cout << "RES: " << sum << std::endl;
	int c;
	std::cin >> c;
	
}


