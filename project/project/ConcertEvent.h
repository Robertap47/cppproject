#include "AbstractEvent.h"
#include <iostream>
using namespace std;

class ConcertEvent :public AbstractEvent{
private:
	string artistName; string venue; string date; string concertType;

public:
	ConcertEvent(const string& artist, const string& venue, const string& date, const string& type);

		void display() const override;
		string getEventType() const;
		//string description() const override;
};
