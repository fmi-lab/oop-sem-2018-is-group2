#include<iostream>
#include<cstring>
#include<fstream>
#include "Elf.h"
#include "ElfTeam.h"
void analyse(const ElfTeam* teams, int size) {
	if (teams) {
		ElfTeam max = teams[0];
		for (int i = 1; i < size; i++) {
			if (max < teams[i]) {
				max = teams[i];
			}
		}
		std::cout << max;
	}
	else std::cout << "No teams!\n";
}
int main() {
	Elf a;
	a.setName("A");
	a.setAge(100);
	a.setAbility(2);
	std::cout << a.getName() << " " << a.getAge() << " " << a.getAbility() << '\n';
	Elf b;
	b.setName("B");
	b.setAge(101);
	b.setAbility(3);
	std::cout << b.getName() << " " << b.getAge() << " " << b.getAbility() << '\n';
	Elf c;
	c.setName("C");
	c.setAge(102);
	c.setAbility(4);
	std::cout << c.getName() << " " << c.getAge() << " " << c.getAbility() << '\n';
	Elf d;
	d.setName("D");
	d.setAge(103);
	d.setAbility(5);
	std::cout << d.getName() << " " << d.getAge() << " " << d.getAbility() << '\n';
	Elf e;
	e.setName("E");
	e.setAge(104);
	e.setAbility(6);
	std::cout << e.getName() << " " << e.getAge() << " " << e.getAbility() << '\n';
	ElfTeam one("ONE");
	one.addMember(a);
	one.addMember(b);
	ElfTeam two("TWO");
	//two.addMember(a);
	two.addMember(c);
	two.addMember(d);
	two.addMember(e);
	//std::cout << one;
	//std::cout << two;
	//std::cout << (a == a);
	std::cout << "MULT:\n";
	ElfTeam res = one * two;
	std::cout << res;
	std::cout << "MULT END!\n";
	//one *= two;
	//std::cout << one;
	ElfTeam arr[2];
	arr[0] = one;
	arr[1] = two;
	analyse(arr, 2);
	std::ofstream out("test.txt");
	out << one;
}