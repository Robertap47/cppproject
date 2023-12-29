#include <iostream>
#include <string>
#include "Ticket.h"
#include "Event.h"
#include "EventLocation.h"
#include <vector>
using namespace std;

int main() {
	EventLocation location1;
	cout << "Enter new zones and seats per row (e.g., d e f 15 25 35 ): ";
	cin >> location1;
	string holderName;
	cout << "enter the name of the ticket holder: ";
	getline(cin,holderName);
	Ticket myTicket(holderName);
	myTicket.setExpireDate("2023-12-31");
	myTicket.printTicket();
	cout << endl;
	string currentDate = "2023-12-27";
	if (myTicket.isExpired(currentDate))
	{
		cout << "the ticket has expired: " << endl;

	}
	else
		cout << "the ticket is valid: " << endl;


	cout << "\nupdate ticket information: ";
	myTicket.setHolderName("rares");
	++myTicket;
	myTicket.printTicket();
	if (!myTicket) {
		cout << "\ninvalid ticket ";

	}
	else
		cout << "\nticket is valid ";
	myTicket.invalidateTicket();
	if (!myTicket) {
		cout << "\ninvalid ticket ";

	}
	else
		cout << "\nticket is valid ";
	string eventName, eventDate, eventTime;
	cout << "\nenter the name of the event: ";
	getline(cin, eventName);
	cout<<"\nenter the date of the event (yyyy-mm-dd):";
	getline(cin, eventDate);
	cout << "\nenter the time of the event (hh:mm):";
	getline(cin, eventTime);
	Event newEvent(eventName,eventDate,eventTime);
	cout << "\nevent details: " << endl;
	newEvent.printDetails();
	cout << "\nupdate event details: " << endl;
	newEvent.updateDetails("Untold", "2023-08-02", "18:21");
	newEvent.printDetails();
	string compareDate = "2023-12-21";
	if (newEvent.isBefore(compareDate))
	{
		cout << "The event is before: " << compareDate << endl;
	
	}
	else
		cout << "The event is not before: " << compareDate << endl;

	cout << "Postpone the event by 2 hours and 20 minutes: "<< endl;
	newEvent.postponeEvent(2, 20);
	newEvent.printDetails();
	//crerea unei locatii de eveniment cu constructor implicit

	EventLocation location( { 'a', 'b', 'c' }, { 10,15,20 }, 100 );
	location.printLocationInfo();
	cout << "Total Capacity: " << location.calculateTotalCapacity() << endl;
	char zoneToCheck = 'b';
	if (location.isZoneAvailable(zoneToCheck)) {
		cout << "Zone " << zoneToCheck << " is available" << endl;
	}
	else {
		cout << "Zone" << zoneToCheck << " is not available." << endl;

	}
	cout << "total location " << EventLocation::getTotalLocations() << endl;

	//exemple de citire si scriere folosind operatorii >> si <<
	cout << location1 << endl;

	//crearea unei locatii de eveniment cu constructorul parametrizat
	vector<char> zones = { 'd','e' }; 
	vector<int> seatsPerRow = { 10,20,30 };
	EventLocation location2(zones, seatsPerRow, 60);
	cout << "total location " << EventLocation::getTotalLocations() << endl;
	location2.printLocationInfo();
	location2.addZone('f');
	cout << "after adding a new zone " << endl;
	location2.printLocationInfo();
	//utilizarea operatorului [] 
	try {
		char zone = location2[0];
		cout << "first zone: " << zone << endl;
	}
	catch (const out_of_range& e) {
		cerr << "error " << e.what() << endl;
	}

	//exemplu utilizare operator +
	EventLocation combinedLocation = location + location2;
	cout << combinedLocation << endl;
	
	return 0;
}