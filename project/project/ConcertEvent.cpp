#include "ConcertEvent.h"
#include <iostream>


ConcertEvent::ConcertEvent(const string& artist, const string& venue, const string& date, const string& type) :artistName(artist), venue(venue), date(date), concertType(type)
{ }
		
void ConcertEvent::display() const {
	cout << "Concert event details: " << endl;
	cout << "Artist " << artistName << endl;
	cout << "Venue " << venue << endl;
	cout << "Date " << date << endl;
	cout << "Concert type " << concertType << endl;
		}
string ConcertEvent::getEventType() const {
	string eventType = "concert - " + concertType;
	return eventType;

		}

//string ConcertEvent::description() const {
//	return "Concert event featuring " + artistName + " At " + venue + " On " + date;
//
//}