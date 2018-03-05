#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
class City {
	char name[30];
	char country[30];
	int population;
	bool capital;
public:
	City(char* _name = "", char* _country = "", int _population = 0, bool _capital = 0) //конструктор 2 в 1 (по подразбиране и с параметри)
	{
		strcpy(name, _name);
		strcpy(country, _country);
		population = _population;
		capital = _capital;
	}
	void set_name(const char* _name) {
		strcpy(name, _name);
	}
	void set_country(const char* _country) {
		strcpy(country, _country);
	}
	void set_population(int _population) {
		population = _population;
	}
	void set_capital(bool _capital) {
		capital = _capital;
	}
	const char* get_name() {
		return name;
	}
	const char* get_country() {
		return country;
	}
	int get_population() {
		return population;
	}
	bool get_capital() {
		return capital;
	}
	void print() {
		cout << "Name: " << name << endl;
		cout << "Country: " << country << endl;
		cout << "Population: " << population << endl;
		cout << "Capital: " << boolalpha << capital << endl;
	}
};
class Map {
	City cities[30];
	int capacity;
public:
	Map(int _capacity = 0) : capacity(_capacity){} //друг начин за дефиниране на конструктор
	void set_capacity(int _capacity) {
		capacity=_capacity;
	}
	bool addCity(City x) //функция за добавяне на градове в масива
	{
		if (capacity == 30) return false;
		else {
			cities[capacity].set_name(x.get_name());
			cities[capacity].set_country(x.get_country());
			cities[capacity].set_population(x.get_population());
			cities[capacity].set_capital(x.get_capital());
			capacity++;
			return true;
		}
	}
	void allCapitals() {
		for (int i = 0; i < capacity; i++) {
			if (cities[i].get_capital()) cout << cities[i].get_country() << " - " << cities[i].get_name() << endl;
		}
	}
	void moreThan(int number) {
		for (int i = 0; i < capacity; i++) {
			if (cities[i].get_population() > number) cities[i].print();
		}
	}
	void filter(bool(*pred)(City)) {
		ofstream bout;
		bout.open("file.bin", ios::binary);
		for (int i = 0; i < capacity; i++) {
			if (pred(cities[i])) bout.write((char*)&cities[i], sizeof(City));
		}
		bout.close();
	}
	bool member(City x) {
		for (int i = 0; i < capacity; i++) {
			if (!strcmp(cities[i].get_name(), x.get_name())) return true;
		}
		return false;
	}
};
//примерна булева функция, която да използваме във филтъра
bool Aussie(City x) {
	return !strcmp(x.get_country(), "Australia");
}
int main() {
	//примерни градчета
	City c1;
	c1.set_name("Paris");
	c1.set_country("France");
	c1.set_population(2240621);
	c1.set_capital(1);
	City c2;
	c2.set_name("Rome");
	c2.set_country("Italy");
	c2.set_population(2869461);
	c2.set_capital(1);
	City c3;
	c3.set_name("Sydney");
	c3.set_country("Australia");
	c3.set_population(4840600);
	c3.set_capital(0);
	Map m;
	m.addCity(c1);
	m.addCity(c2);
	m.addCity(c3);
	m.allCapitals();
	m.moreThan(3000000);
	cout<<boolalpha<<m.member(c2)<<endl;
	m.filter(Aussie);
	//за тези, които искат да проверят дали филтърът е записал правилните данни в двоичния файл
	City c4;
	ifstream bin;
	bin.open("file.bin", ios::binary);
	bin.read((char*)&c4, sizeof(City));
	c4.print();
	bin.close();
	//system("pause");
	return 0;
}
