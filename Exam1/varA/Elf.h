#ifndef __ELF__HH__
#define __ELF__HH__
#include<iostream>
#include<cstring>
#include<fstream>
class Elf {
	char* elfName;
	int elfAge;
	int elfAbility;
	void copyElf(const Elf& other);
	void deleteElf();
public:
	Elf();
	Elf(const Elf& other);
	~Elf();
	Elf& operator=(const Elf& other);
	void setName(const char* name);
	void setAge(const int& age);
	void setAbility(const int& ability);
	const char* getName() const;
	int getAge()const;
	int getAbility()const;
	bool operator == (const Elf& other) const;
	bool operator <(const Elf& other) const;
	friend std::ostream& operator <<(std::ostream&, const Elf&);
};
#endif