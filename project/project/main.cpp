#include <iostream>
#include <string>
#include "Ticket.h"
#include "Event.h"
using namespace std;

int main() {
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
	
	return 0;
}