#include<cstring>
#include<iostream>
#include<fstream>
using namespace std;
class Computer
{
	char brand[30];
	char model[30];
	int yearOfProduction;
	double price;
	bool inStock;
public:
//Мутатори за всички член данни. (setters)
	void setBrand(const char*);
	void setModel(const char*);
	void setProdYear(int);
	void setPrice(double);
	void setStock(bool);// Има и други варианти за този сеттер, но е важно след работата му променливата inStock, да е коректно зададена.
//Селектори за всички член данни. (getters)
	const char* getBrand();
	const char* getModel();
	int getYear();
	double getPrice();
	bool getStock();
// Исканата функция print().
	void print();
};
void Computer::setBrand(const char* _brand)
{
	strcpy(brand, _brand);
}
void Computer::setModel(const char* _model)
{
	strcpy(model, _model);
}
void Computer::setPrice(double _price)
{
	price = _price;
}
void Computer::setProdYear(int _year)
{
	yearOfProduction = _year;
}
void Computer::setStock(bool _available)
{
	inStock = _available;
}
const char* Computer::getBrand()
{
	return brand;
}
const char* Computer::getModel()
{
	return model;
}
int Computer::getYear()
{
	return yearOfProduction;
}
double Computer::getPrice()
{
	return price;
}
bool Computer::getStock()
{
	return inStock;
}
void Computer::print()
{
	cout << "Brand: " << brand << endl;
	cout << "Model: " << model << endl;
	cout << "Year of Production: " << yearOfProduction << endl;
	cout << "Price: " << price << " lv." << endl;
	cout << "Is in stock: " << boolalpha << inStock << endl;
}
class PCStore
{
	Computer stock[30];//Указваме колко максимално компютри можем да съдържаме - като информационна единица
	int storeCapacity;//Указваме колко компютъра има в момента
public:
	PCStore(int);	//За да има смисъл програмата, трябва да посочим и подходящ конструктор
	void setCapacity(int);
	bool add(Computer&);//Подаваме по псевдоним, за да не правим копие
	bool sell(Computer&);
	void showStore();
	void report();
	void filter(bool (*pred)(Computer&));
};
PCStore::PCStore(int _capacity = 0)
{
	storeCapacity = _capacity;
}
void PCStore::setCapacity(int _capacity)
{
	storeCapacity = _capacity;
}
bool PCStore::add(Computer& pc)
{
	if (storeCapacity == 30) return false;
	stock[storeCapacity++] = pc;
	return true;
}
bool PCStore::sell(Computer& pc)
{
	for (int i = 0;i <= storeCapacity;i++)
	{
		if (strcmp(stock[i].getBrand(),pc.getBrand()) == 0 && strcmp(stock[i].getModel(),pc.getModel()) == 0)
		{
			if (stock[i].getStock())
			{
				stock[i].setStock(0);
				return true;
			}

		}
	}
	return false;

}
void PCStore::showStore()
{
	for (int i = 0;i <= storeCapacity;i++)
	{
		if (stock[i].getStock())
		{
			stock[i].print();
			cout << endl;
		}
	}
}
void PCStore::report()
{
	ofstream fout("report.txt");
	for (int i = 0;i <= storeCapacity;i++)
	{
		if (stock[i].getStock())
		{
			fout << stock[i].getBrand() << " " << stock[i].getModel() << " " << stock[i].getPrice() << " " << stock[i].getYear() << endl;
		}
	}
}
void PCStore::filter(bool(*pred)(Computer& pc))
{
	for (int i = 0;i <= storeCapacity;i++)
	{
		if (pred(stock[i])) stock[i].print();
	}
}
int main()
{
	//Тестваме си дали работи всичко по класа Computer
	Computer pc1;
	pc1.setBrand("Acer");
	pc1.setModel("V15 Nitro");
	pc1.setProdYear(2015);
	pc1.setPrice(1900);
	pc1.setStock(1);
	pc1.print();
	Computer pc2;
	pc2.setBrand("Asus");
	pc2.setModel("ZenBook");
	pc2.setProdYear(2015);
	pc2.setPrice(1877);
	pc2.setStock(1);
	cout << endl;
	//А сега и PCStore
	PCStore store;
	store.add(pc1);
	store.add(pc2);
	store.showStore();
	cout << "Second part \n";
	store.sell(pc1);
	store.showStore();
    return 0;
}
