#ifndef __ELFTEAM__HH__
#define __ELFTEAM__HH__
#include<iostream>
#include "Elf.h"
class ElfTeam {
	char teamName[30];
	Elf teamMembers[50];
	int teamSize;
	bool member(const Elf&) const;
public:
	int getStrength()const;
	int size()const;
	ElfTeam(const char* = "default", int = 0);
	void addMember(const Elf& elem);
	bool operator < (const ElfTeam& other);
	ElfTeam operator*(const ElfTeam& other);
	ElfTeam& operator*=(ElfTeam& other);
	friend std::ostream& operator <<(std::ostream&, const ElfTeam&);//optional
};
#endif
