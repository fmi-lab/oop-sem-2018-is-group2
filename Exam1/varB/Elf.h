#ifndef __ELF__HH__
#define __ELF__HH__
#include<iostream>
class Elf {
	char* elfName;
	int elfAge;
	int elfAbility;
	void copyElf(const Elf&);
	void deleteElf();
public:
	Elf();
	Elf(const Elf&);
	~Elf();
	Elf& operator=(const Elf&);
	void setName(const char*);
	void setAge(const int&);
	void setAbility(const int&);
	const char* getName() const;
	int getAge()const;
	int getAbility()const;
	bool operator == (const Elf&) const;
	bool operator <(const Elf&) const;
	friend std::ostream& operator <<(std::ostream&, const Elf&);
};
#endif
