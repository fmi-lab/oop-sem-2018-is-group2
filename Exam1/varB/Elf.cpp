#include <iostream>
#include<cstring>
#include "Elf.h"
void Elf::copyElf(const Elf& other) {
	elfName = new char[strlen(other.elfName) + 1];
	strcpy_s(elfName, strlen(other.elfName) + 1, other.elfName);
	elfAge = other.elfAge;
	elfAbility = other.elfAbility;
}
void Elf::deleteElf() {
	delete[] elfName;
}
Elf::Elf() {
	elfName = new char[2];
	strcpy_s(elfName, 2, "D");
	elfAge = 0;
	elfAbility = 0;
}
Elf::Elf(const Elf& other) {
	copyElf(other);
}
Elf::~Elf() {
	deleteElf();
}
Elf& Elf::operator=(const Elf& other) {
	if (this != &other) {
		deleteElf();
		copyElf(other);
	}
	return *this;
}
void Elf::setName(const char* name) {
	if (!elfName) {
		elfName = new char[strlen(name) + 1];
		strcpy_s(elfName, strlen(name) + 1, name);
	}
	else {
		delete[] elfName;
		elfName = new char[strlen(name) + 1];
		strcpy_s(elfName, strlen(name) + 1, name);
	}
}
void Elf::setAge(const int& age) {
	if (age >= 0 && age <= 300) {
		elfAge = age;
	}
	else elfAge = 0;
}
void Elf::setAbility(const int& ability) {
	if (ability >= 1 && ability <= 15) {
		elfAbility = ability;
	}
	else elfAbility = 1;
}
const char* Elf::getName() const { return elfName; }
int Elf::getAge()const { return elfAge; }
int Elf::getAbility()const { return elfAbility; }
bool Elf::operator == (const Elf& other) const {
	return (strcmp(elfName, other.elfName) == 0) && (elfAge == other.elfAge) && (elfAbility == other.elfAbility);
}
bool Elf::operator <(const Elf& other) const {
	return elfAbility < other.elfAbility && elfAge > other.elfAge;
}

std::ostream& operator <<(std::ostream& out, const Elf& elem) {
	out << elem.elfName << " " << elem.elfAge << " " << elem.elfAbility << '\n';
	return out;
}