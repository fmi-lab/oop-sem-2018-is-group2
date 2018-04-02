#ifndef __ELFTEAM__HH__
#define __ELFTEAM__HH__
#include "Elf.h"
class ElfTeam {
	char teamName[30];
	Elf teamMembers[50];
	int teamSize;
	bool member(const Elf& elem) const;
public:
	int getStrength()const;
	int size()const;
	ElfTeam(const char* name = "default", int size = 0);
	void addMember(const Elf& elem);
	bool operator < (const ElfTeam& other);
	ElfTeam operator*(const ElfTeam& other);
	ElfTeam& operator*=(ElfTeam& other);
	friend std::ostream& operator <<(std::ostream& out, const ElfTeam& team);//optional
};
#endif
