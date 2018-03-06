#include <iostream>
//Важно: Има два варианта на оператора * - веднъж като изцяло външна функция и веднъж като приятелска за класа.
//Към момента екоментирана външната имплементация - за да я тествате закоментирайте приятелската от дефиницията и разкоментирайте вече коментираната.
class Time {
	int hours;
	int minutes;
public:
	Time();
	int getHours() const;
	int getMins() const;
	void setTimeFromMins(int);
	void setH(int);
	void setM(int);
	void addMins(int);
	int allInMinutes() const;
	bool operator <(const Time&);
	Time operator + (const Time&);
	Time operator -(const Time&);
	Time operator * (int);
	void print()const;
	friend Time operator*(int, const Time&);
};
Time::Time() {
	hours = 0;
	minutes = 0;
}
int Time::getHours() const {
	return hours;
}
int Time::getMins() const{
	return minutes;
}
void Time::setH(int hours) {
	if (hours >= 0 && hours <= 23) {
		this->hours = hours;
	}
	else this->hours = 0;
}
void Time::setM(int mins) {
	if (mins >= 0 && mins <= 59) {
		this->minutes = mins;
	}
	else this->minutes = 0;
}
void Time::addMins(int minutes) {
	int hoursToAdd = minutes / 60;
	int minutesToAdd = minutes % 60;
	this->hours += hoursToAdd;
	this->minutes += minutesToAdd;
}
int Time::allInMinutes() const {
	return hours * 60 + minutes;
}
bool Time::operator <(const Time& other) {
	return allInMinutes() < other.allInMinutes();
}
void Time::setTimeFromMins(int minutes) {

}
Time Time::operator + (const Time& other) {
	int sumOfHours = hours + other.hours;
	int sumOfMinutes = minutes + other.minutes;
	Time newTime;
	newTime.setH(sumOfHours % 24);
	newTime.addMins(sumOfMinutes);
	return newTime;
}
Time Time::operator-(const Time& other) {
	int divOfHours = hours - other.hours;
	int divOfMinutes = minutes - other.minutes;
	Time newTime;
	if (divOfMinutes < 0) {
		if (divOfHours <= 0) newTime.setH(24 + divOfHours - 1);
		else newTime.setH(divOfHours - 1);
		newTime.setM(60 + divOfMinutes);
	}
	else {
		if (divOfHours < 0) newTime.setH(24 + divOfHours);
		else newTime.setH(divOfHours);
		newTime.setM(divOfMinutes);
	}
	return newTime;
}
Time Time::operator*(int mult) {
	int newHours = hours * mult;
	int newMinutes = minutes*mult;
	Time newTime;
	newTime.setH((newHours % 24)+(newMinutes/60));
	newTime.setM(newMinutes % 60);
	return newTime;
}
void Time::print()const {
	std::cout << hours << ":" << minutes << '\n';
}
//Time operator *(int mult, const Time& elem) {
//	std::cout << "Not a class member\n";
//	int newHours = elem.getHours() * mult;
//	int newMinutes = elem.getMins()*mult;
//	Time newTime;
//	newTime.setH((newHours % 24) + (newMinutes / 60));
//	newTime.setM(newMinutes % 60);
//	return newTime;
//}
Time operator *(int mult, const Time& elem) {
	std::cout << "Not a class member\n";
	int newHours = elem.hours * mult;
	int newMinutes = elem.minutes*mult;
	Time newTime;
	newTime.setH((newHours % 24) + (newMinutes / 60));
	newTime.setM(newMinutes % 60);
	return newTime;
}
int main()
{
	Time a;
	a.setH(15);
	a.setM(30);
	a.print();
	Time b;
	b.setH(2);
	b.setM(30);
	b.print();
	(a + b).print();
	(a - b).print();
	(b * 2).print();
	(2 * b).print();
	return 0;
}
