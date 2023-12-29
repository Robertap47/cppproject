#include <iostream>
#include <string>
#include <vector>
using namespace std;

class EventLocation {
private:
	vector<char>zones;
	vector<int>seatsPerRow;
	const int maxSeats;
	static int totalLocations;
public:
	EventLocation();
	EventLocation(const vector<char>& zones, const vector<int>& seatsPerRow, int maxSeats);
	EventLocation(const EventLocation& other);
	EventLocation& operator= (const EventLocation& other);
	~EventLocation();
	vector<char>getZones() const;
	vector<int>getSeatsPerRow() const;
	int getMaxSeats() const;
	static int getTotalLocations();
	void setZones(const vector<char> &zones);
	void setSeatsPerRow(const vector<int> &seatsPerRow);
	void printLocationInfo() const;
	void addZone(char zone);
	int calculateTotalCapacity() const;
	bool isZoneAvailable(char zone) const;
	friend ostream& operator<< (ostream& os, const EventLocation& eventlocation);
	friend istream& operator>> (istream& is, EventLocation& eventlocation);
	char operator[] (int index) const;
	EventLocation operator+(const EventLocation& other) const;



};

