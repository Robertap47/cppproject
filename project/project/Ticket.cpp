#include "Ticket.h"
long Ticket::nextTicketID = 1;
Ticket::Ticket() :ticketID(nextTicketID++) {

}
Ticket::Ticket(const string& holderName) :holderName(holderName), ticketID(nextTicketID++)
{

}
Ticket::~Ticket() {

}
unsigned long Ticket::getTicketID() const {
	return ticketID;
}

string Ticket::getHolderName() const {
	return holderName;
}

void Ticket::setHolderName(const string& name)  {
	holderName = name;
}

void Ticket::printTicket() const {
	cout << "TicketID: " << ticketID << endl << "holder: " << holderName << endl << "expire date: " << expireDate << endl;

}

void Ticket::invalidateTicket() {
	isValid = false;
}

Ticket& Ticket::operator++() {
	++ticketID;
	return *this;
}

bool Ticket::operator!() const {
	return !isValid;
}
unsigned long Ticket::generateNextTicketID() {
	return nextTicketID++;
}
ostream& operator << (ostream& os, const Ticket& ticket){
	os <<  "TicketID: " << ticket.ticketID << ",holder: " << ticket.holderName << "expire date: " << ticket.expireDate << endl;
	return os;
}
istream& operator>> (istream& is, Ticket& ticket) {
	is >> ticket.holderName;
	ticket.ticketID = Ticket::generateNextTicketID();
	return is;
}

bool Ticket::isExpired(const string& currentDate)const {
	return currentDate > expireDate;
}

void Ticket::setExpireDate(const string& expireDate) {
	this->expireDate = expireDate;

}

string Ticket::getExpireDate()const {
	return expireDate;
}

