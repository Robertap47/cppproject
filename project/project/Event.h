#include <iostream>
#include <string>
using namespace std;

class Event {
private:
	string name;
	string date;
	string time;
	static int totalEvents;
public:
	Event();
	Event(const string& name, const string& date, const string& time);
	Event(const Event& other);
	Event& operator=(const Event& other);
	~Event();
	string getName()const;
	string getDate() const;
	string getTime() const;
	static int getTotalEvents();
	void setName(const string& name);
	void setDate(const string& date);
	void extractDate(int& year, int& month, int& day);
	void setTime(const string& time);
	void printDetails() const;
	void updateDetails(const string& name, const string& date, const string& time);
	bool isBefore(const string& otherDate) const;
	void postponeEvent(int hours, int minutes);
	friend ostream& operator<< (ostream& os, const Event& event);
	friend istream& operator>> (istream& is, Event& event);
	bool operator< (const Event& other);
	bool operator== (const Event& other);
	


	

	
};

