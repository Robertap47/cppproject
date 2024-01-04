#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "Ticket.h"
#include "Event.h"
#include "EventLocation.h"
#include <vector>
#include "ConcertEvent.h"
using namespace std;
vector<Ticket> tickets;
/*
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
} */

void manageConcertEvents() {
	string artistName, venue, date, concertType;
	cout << "Concert event management: " << endl;
	cout << "Enter artist name: ";
	cin.ignore();
	getline(cin, artistName);
	cout << "Enter venue: ";
	getline(cin, venue);
	cout << "Enter date: ";
	getline(cin, date);
	cout << "Enter concert type: ";
	getline(cin, concertType);
	ConcertEvent concertEvent(artistName, venue, date, concertType);
	concertEvent.display();
}

void viewEvents() {
	string eventName, eventDate, eventTime;
	cout << "\nenter the name of the event: ";
	getline(cin, eventName);
	cout << "\nenter the date of the event (yyyy-mm-dd):";
	getline(cin, eventDate);
	cout << "\nenter the time of the event (hh:mm):";
	getline(cin, eventTime);
	Event newEvent(eventName, eventDate, eventTime);
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

	cout << "Postpone the event by 2 hours and 20 minutes: " << endl;
	newEvent.postponeEvent(2, 20);
	newEvent.printDetails();
	//crerea unei locatii de eveniment cu constructor implicit

	EventLocation location({ 'a', 'b', 'c' }, { 10,15,20 }, 100);
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
	EventLocation location1;
	cout << "Enter new zones and seats per row (e.g., d e f 15 25 35 ): ";
	cin >> location1;
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
}
void loadTickets(vector<Ticket>& tickets, const string& fileName) {
	ifstream inFile(fileName, ios::binary);
	if (!inFile) {
		cerr << "Error opening file";
		return;
	}
	cout << "Load tickets to file: " << fileName << endl;
	Ticket ticket;
	while (ticket.loadFromFile(inFile)) {
		tickets.push_back(ticket);
		cout << "TicketID: " << ticket.getTicketID() << ", Holder: " << ticket.getHolderName();
		cout << ", Valid: " << (ticket.isExpired("2024-01-03") ? "Yes" : "No");
		cout << ", Expire Date: " << ticket.getExpireDate() << endl;
	}
	//cout << "Tickets loaded successfully. Displaying tickets: " << endl;
	inFile.close();
}

void saveTickets(const vector<Ticket>& tickets, const string& fileName) {
	ofstream outFile(fileName, ios::binary|ios::app);
	if (!outFile) {
		cerr << "Error opening file";
		return;
	}
	cout << "Saving tickets to file: " << fileName << endl;
	for (const auto& ticket : tickets) {
		ticket.saveToFile(outFile);

	}
	if (!outFile.fail()) {
		cout << "Tickets saved sucessfully " << endl;
	}

	outFile.close();
}


void createTicket(vector<Ticket> &tickets) {
	string holderName;
	cout << "enter the name of the ticket holder: ";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin, holderName);
	Ticket myTicket(holderName);
	myTicket.setExpireDate("2023-12-31");
	myTicket.printTicket();
	cout << endl;
	tickets.push_back(myTicket);
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
	//saveTickets(tickets, "tickets.bin");
	//cout << "Ticket saved to file. " << endl;
	//loadTickets(tickets, "tickets.bin");
}

bool launchMenu() {
	int choice;
	while (true) {
		cout << "\nMain menu\n";
		cout << "1.Ticket operations\n";
		cout << "2.General events operations\n";
		cout << "3.Concert event management\n";
		cout << "4.Exit\n";
		cout << "Enter your choice: ";
		cin >> choice;
		switch (choice) {
		case 1:
			createTicket(tickets);
			break;
		case 2:
			viewEvents();
			break;
		case 3:
			manageConcertEvents();
			break;
		case 4:
			cout << "Exiting program\n";
			return true;
		default:
			cout << "Invalid choice, please try again\n";

		}
	}
}




void processFileData(const string& filename) {
	ifstream file(filename);
	if (!file) {
		cerr << "Unable to open file\n" << filename << endl;
		return;
	
	}
	vector<Ticket> tickets;
		string line;
		while (getline(file, line)) {
			istringstream iss(line);
			string token;
			vector<string> ticketData;
			while (getline(iss, token,',')) {
				ticketData.push_back(token);
			}
			if (ticketData.size() >=4) {
				unsigned long ticketID = stoul(ticketData[0]);
				bool isValid = ticketData[2] == "1";
				string expireDate = ticketData[3];
				Ticket ticket(ticketID, ticketData[1], isValid,expireDate);
				tickets.push_back(ticket);
			}
			
	}
		cout << "Loaded tickets\n";
		for (const auto& ticket : tickets) {
			ticket.printTicket();
			if (ticket.isExpired("29-12-2023")) {
				cout << "Ticket is valid: ";
			}
			else
				cout << "Ticket is expired or invalid";
		}
		file.close();
}





int main(int argc, char* argv[])
{

	
	loadTickets(tickets, "tickets.bin");
	if (argc > 1) {
		string filename = argv[1];
		processFileData(filename);
	}
	else
		if (!launchMenu()) {
			saveTickets(tickets, "tickets.bin");
		}
	saveTickets(tickets, "tickets.bin");
	return 0;
}

