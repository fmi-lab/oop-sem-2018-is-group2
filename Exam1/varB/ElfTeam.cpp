#include<iostream>
#include<cstring>
#include "ElfTeam.h"
bool ElfTeam::member(const Elf& elem) const {
	for (int i = 0; i < teamSize; i++) {
		if (teamMembers[i] == elem) return true;
	}
	return false;
}
int ElfTeam::getStrength()const {
	if (teamSize == 0) return 0;
	Elf max = teamMembers[0];
	for (int i = 1; i < teamSize; i++) {
		if (max < teamMembers[i]) {
			max = teamMembers[i];
		}
	}
	return max.getAbility();
}
int ElfTeam::size()const { return teamSize; }
ElfTeam::ElfTeam(const char* name, int size) {
	strcpy_s(teamName, name);
	teamSize = size;
}
//void ElfTeam::setSize(int s) { teamSize = s; }
//void ElfTeam::setName(const char* n) { strcpy_s(teamName, n); }
void ElfTeam::addMember(const Elf& elem) {
	if (teamSize < 50) {
		teamMembers[teamSize++] = elem;
	}
}
bool ElfTeam::operator < (const ElfTeam& other) {
	return getStrength() < other.getStrength();
}
ElfTeam ElfTeam::operator*(const ElfTeam& other) {
	ElfTeam newTeam;
	for (int i = 0; i < teamSize; i++) {
		if (other.member(teamMembers[i])) {
			newTeam.addMember(teamMembers[i]);
			//newTeam.teamMembers[newTeam.teamSize++] = teamMembers[i];
		}
	}
	return newTeam;
}
ElfTeam& ElfTeam::operator*=(ElfTeam& other) {
	operator=(operator *(other));//*this = *this * other;
	return *this;
}
std::ostream& operator <<(std::ostream& out, const ElfTeam& team) {
	for (int i = 0; i < team.teamSize; i++) {
		out << team.teamName << " " << team.teamMembers[i];
	}
	return out;
}
