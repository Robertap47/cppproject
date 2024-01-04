#define _CRT_SECURE_NO_WARNINGS
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
vector<EventLocation> locations;
vector<Event> events;


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
	FILE* file = fopen(fileName.c_str(), "rb");
	if (file == NULL) {
		cerr << "Error opening file for reading: " << fileName << endl;
		return;
	}

	Ticket ticket;
	while (ticket.loadFromFile(file)) {
		tickets.push_back(ticket);
		cout << "TicketID: " << ticket.getTicketID() << ", Holder: " << ticket.getHolderName();
		cout << ", Valid: " << (ticket.isExpired("2024-01-03") ? "Yes" : "No");
		cout << ", Expire Date: " << ticket.getExpireDate() << endl;
	}

	cout << "Tickets loaded successfully from " << fileName << endl;
	fclose(file);
}

void saveTickets(const vector<Ticket>& tickets, const string& fileName) {
	FILE* file = fopen(fileName.c_str(), "wb");
	if (file == NULL) {
		cerr << "Error opening file for writing: " << fileName << endl;
		return;
	}

	for (const auto& ticket : tickets) {
		ticket.saveToFile(file);
	}

	cout << "Tickets saved successfully to " << fileName << endl;
	fclose(file);
}

void createTicket(vector<Ticket>& tickets) {
	string holderName;
	cout << "Enter the name of the ticket holder: ";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin, holderName);

	string expireDate;
	cout << "Enter the expiration date (yyyy-mm-dd): ";
	cin >> expireDate;

	Ticket myTicket(holderName);
	myTicket.setExpireDate(expireDate);

	cout << "\nTicket Information:\n";
	myTicket.printTicket();

	cout << endl;
	tickets.push_back(myTicket);

	string currentDate = "2023-12-27";

	if (myTicket.isExpired(currentDate)) {
		cout << "The ticket has expired." << endl;
	}
	else {
		cout << "The ticket is valid." << endl;
	}

	cout << "\nUpdate ticket information:\n";
	myTicket.setHolderName("Rares");
	++myTicket;
	myTicket.printTicket();

	if (!myTicket) {
		cout << "\nInvalid ticket." << endl;
	}
	else {
		cout << "\nTicket is valid." << endl;
	}

	myTicket.invalidateTicket();

	if (!myTicket) {
		cout << "\nInvalid ticket." << endl;
	}
	else {
		cout << "\nTicket is valid." << endl;
	}
}

void ticketSalesReport(const vector<Ticket>& tickets) {
	int validTickets = 0, invalidTickets = 0;

	for (const auto& ticket : tickets) {
		if (ticket.getIsValid()) {
			validTickets++;
		}
		else {
			invalidTickets++;
		}
	}

	cout << "Ticket Sales Report:\n";
	cout << "Valid Tickets Sold: " << validTickets << "\n";
	cout << "Invalid or Expired Tickets: " << invalidTickets << "\n";
}

void reportingAndStatistics(const vector<Ticket>& tickets, const vector<Event>& events) {
	int choice;
	while (true) {
		cout << "\nReporting and Statistics\n";
		cout << "1. Ticket Sales Report\n";
		cout << "2. Event Attendance Report\n";
		cout << "3. Return to Main Menu\n";
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
		case 1:
			ticketSalesReport(tickets);
			break;
		/*case 2:
			eventAttendanceReport(events);
			break;*/
		case 3:
			return;
		default:
			cout << "Invalid choice, please try again.\n";
		}
	}
}

void viewAllLocations(const vector<EventLocation>& locations) {
	cout << "List of Event Locations:\n";
	for (const auto& location : locations) {
		location.printLocationInfo();
		cout << "\n";
	}
}

void inputLocationData(EventLocation& location) {
	EventLocation location1;
	cout << "Add a New Event Location\n";
	cout << "Location1 data:\n" << location1 << endl;
	locations.push_back(location1);
	cout << "New location added successfully.\n";
}

void locationManagement(vector<EventLocation>& locations) {
	int choice;
	while (true) {
		cout << "\nLocation Management\n";
		cout << "1. Add New Location\n";
		cout << "2. View All Locations\n";
		//cout << "3. Edit a Location\n";
		cout << "4. Return to Main Menu\n";
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
		case 1:
			addNewLocation(locations);
			break;
		case 2:
			viewAllLocations(locations);
			break;
		//case 3:
			//editLocation(locations);
			//break;
		case 4:
			return;
		default:
			cout << "Invalid choice, please try again.\n";
		}
	}
}

void launchMenu() {
	int choice;
	while (true) {
		cout << "\nMenu:\n";
		cout << "1. Ticket Operations\n";
		cout << "2. Event Operations\n";
		cout << "3. Manage Concert Events\n";
		cout << "4. Location Management\n";
		cout << "5. Reporting and Statistics\n";
		cout << "6. User Feedback\n";
		cout << "7. Exit\n";
		cout << "Enter your choice: ";
		cin >> choice;
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // To handle newline after cin

		switch (choice) {
		case 1: createTicket(tickets); break;
		case 2: viewEvents(); break;
		case 3: manageConcertEvents(); break;
		case 4: locationManagement(locations); break;
		case 5: reportingAndStatistics(tickets,events); break;
		//case 6: userFeedback(); break;
		case 7: cout << "Exiting program.\n"; return;
		default: cout << "Invalid choice, please try again.\n";
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
		launchMenu();
	saveTickets(tickets, "tickets.bin");
	return 0;
}

