#include "Event.h"
#include <sstream>
#include <iomanip>

int Event::totalEvents = 0;
Event::Event(){
	name = "";
	date = "";
	time = "";
	totalEvents++;

}
Event::Event(const string& name, const string& date, const string& time) :name(name), date(date), time(time) {
	totalEvents++;
}

Event::Event(const Event& other) : name(other.name), date(other.date), time(other.time) {
	totalEvents++;
}

Event& Event::operator=(const Event& other) {
	if (this != &other) {
		name = other.name;
		date = other.date;
		time = other.time;
		
	}
	return *this;
}

Event::~Event() {
	totalEvents--;
}

string Event::getName()const {
	return name;
}
string  Event::getDate() const {
	return date;
}
string Event::getTime() const {
	return time;
}
int Event::getTotalEvents(){
	return totalEvents;
 }

void Event::setName(const string& name) {
	this->name = name;
}

void Event::setDate(const string& date) {
	this->date = date;

}

void Event::setTime(const string& time) {
	this->time = time;
}

void Event::printDetails() const {
	cout << "Event Name: " << name << endl << "Event Date: " << date << endl  << "Event time: " << time;
}
void Event::updateDetails(const string& name, const string& date, const string& time) {
	this->name = name;
	this->date = date;
	this->time = time;

}

bool Event::isBefore(const string& otherDate) const {
	return date < otherDate;
}
void Event::extractDate(int& year, int& month, int& day) {
	char delim1, delim2;
	stringstream ss(date);
	ss >> year >> delim1 >> month >> delim2 >> day;
	if (ss.fail() || delim1 != '-' || delim2 != '-' || year < 0 || month <= 0 || month > 12 || day <= 0 || day > 31)
		throw runtime_error("invalid date format");
}

void Event::postponeEvent(int hours, int minutes) {
	int hh, mm;
	char delim;
	stringstream ss(time);
	ss >> hh >> delim >> mm;
	if (ss.fail() || delim != ':' || hh < 0 || hh>23 || mm < 0 || mm > 59)
	{
		throw runtime_error("invalid time format");
		
	}
	mm += minutes;
	hh += mm / 60;
	mm %= 60;
	hh += hours;
	bool dayIncrement = false;
	if (hh >= 24) {
		hh %= 24;
		dayIncrement = true;

	}
	stringstream newTime; //sstream
	newTime << setw(2) << setfill('0') << hh << ':' << setw(2) << setfill('0') << mm; //iomanip
	time = newTime.str();
	int year, month, day;
	extractDate(year, month, day);
	//cout << "Extract date: " << year << endl << month << endl << day; 
	if (dayIncrement) {
		day++;
		if (day > 31) {
			day = 1;
			month++;
			if (month > 12) {
				month = 1;
				year++;
			}
		}
	}
	stringstream newDate; //sstream
	newDate << year << '-' << setw(2) << setfill('0') << month << '-' << setw(2) << setfill('0') << day; //iomanip
	date = newDate.str();
}
ostream& operator<< (ostream& os, const Event& event) {
	os << "Event Name: " << event.name << "Event Date: " << event.date << "Event time: " << event.time;
	return os;
}
 istream& operator>> (istream& is, Event& event) {
	is >> event.name >> event.date >> event.time;
	return is;
}
 bool Event::operator< (const Event& other) {
	 if (date < other.date)
		 return true;
	 if (date == other.date && time < other.time)
		 return true;
	 return false;
}
 bool Event::operator== (const Event& other) {
	 if (date == other.date && time == other.time && name == other.name)
		 return true;
	 return false;
		 
}


