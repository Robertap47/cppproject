
#include <iostream>
#include <string>
using namespace std;

class Ticket {
private:
	bool isValid;
	unsigned long ticketID;
	string holderName;
	static long nextTicketID; //static attribute to generate unique ID

public:
	Ticket();
	Ticket(const string& holderName);
	~Ticket();
	unsigned long getTicketID() const;
	string getHolderName() const;
	void setHolderName(const string& name);
	void printTicket() const;
	void invalidateTicket();
	static unsigned long generateNextTicketID();
	friend ostream& operator<< (ostream& os, const Ticket& ticket);
	friend istream& operator>> (istream& is, Ticket& ticket);
	bool operator!() const;
	Ticket& operator++();
};