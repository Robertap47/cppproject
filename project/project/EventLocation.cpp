#include "EventLocation.h"
#include <vector>
#include <sstream>

int EventLocation::totalLocations = 0;
EventLocation::EventLocation() :maxSeats(0) {
	totalLocations++;
}
EventLocation::EventLocation(const vector<char>& zones, const vector<int>& seatsPerRow, int maxSeats):maxSeats(maxSeats) {
	this->zones = zones;
	this->seatsPerRow = seatsPerRow;
	totalLocations++;
}

EventLocation::EventLocation(const EventLocation& other):maxSeats(maxSeats) {
	zones = other.zones;
	seatsPerRow = other.seatsPerRow;
	totalLocations++;
}
EventLocation& EventLocation::operator= (const EventLocation& other) {
	if (this != &other)
	{
		zones = other.zones;
		seatsPerRow = other.seatsPerRow;
	}
	return *this;
}

EventLocation::~EventLocation() {
	totalLocations--;
}
vector<char>EventLocation::getZones() const {
	return zones;
}
vector<int>EventLocation::getSeatsPerRow() const {
	return seatsPerRow;
}
int EventLocation::getMaxSeats() const {
	return maxSeats;
}
 int EventLocation::getTotalLocations() {
	 return totalLocations;
}
 void EventLocation::setZones(const vector<char>& zones) {
	 this->zones = zones;
}
 void EventLocation::setSeatsPerRow(const vector<int>& seatsPerRow) {
	 this->seatsPerRow = seatsPerRow;
}

 void EventLocation::printLocationInfo() const {
	 cout << "Event location info: " << endl;
	 cout << "max seats: "<< maxSeats << endl;
	 cout << "Zones: " << endl;
	 for (char zone : zones) {
		 cout << zone << " ";
	 }
	 cout << "\nseats per row: ";
	 for (int seats : seatsPerRow) {
		 cout << seats << " ";

	 }
	 cout << endl;
}

 void EventLocation::addZone(char zone)  {
	 zones.push_back(zone);
	 
}
 int EventLocation::calculateTotalCapacity() const {
	 int totalCapacity = 0;
	 for (int seats : seatsPerRow) {
		 totalCapacity += seats * zones.size();
	 }
	 return totalCapacity;
}
 bool EventLocation::isZoneAvailable(char zone) const {
	 for (char existingZone : zones)
	 {
		 if (existingZone == zone)
			 return true;
	 }
	 return false;
}
 ostream& operator<< (ostream& os, const EventLocation& eventlocation)
 {
	 os << "max seats: " << eventlocation.maxSeats << " zones:";
	 for (char zone : eventlocation.zones)
	 {
		 os << zone << " ";
	 }
	 return os;
 }
 istream& operator>> (istream& is, EventLocation& eventlocation) {
	 string zoneinput;
	 string seatinput;
	 cout << "Enter zones: ";
	 getline(is, zoneinput);
	 stringstream zoneStream(zoneinput);
	 char zone;
	 while (zoneStream >> zone ) {
		 eventlocation.zones.push_back(zone);

	 }
	 cout << "Enter seats ";
	 getline(is, seatinput);
	 stringstream seatStream(seatinput);
	 int seat;
	 while (seatStream >> seat ) {
		 eventlocation.seatsPerRow.push_back(seat);
	 }
	 return is;
 }
 char EventLocation::operator[] (int index) const {
	 if (index >= 0 && index < zones.size())
	 {
		 return zones[index];
	 }
	 throw out_of_range("Index out of range");
}
 EventLocation EventLocation::operator+(const EventLocation& other) const {
	 vector<char> combinedZones = zones;
	 combinedZones.insert(combinedZones.end(), other.zones.begin(), other.zones.end());
	 vector<int> combinedSeats = seatsPerRow;
	 combinedSeats.insert(combinedSeats.end(), other.seatsPerRow.begin(), other.seatsPerRow.end());
	 int combinedMaxSeats = maxSeats + other.maxSeats;
	 return EventLocation(combinedZones, combinedSeats, combinedMaxSeats);

}
