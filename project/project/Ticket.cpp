#include "Ticket.h"
long Ticket::nextTicketID = 1;
Ticket::Ticket() :ticketID(nextTicketID++) {

}
Ticket::Ticket(const string& holderName) :holderName(holderName), ticketID(nextTicketID++)
{

}
Ticket::Ticket(unsigned long id, const string& name, bool valid,const string& expireDate):ticketID(id),holderName(name), isValid(valid),expireDate(expireDate) {
	nextTicketID++;

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

void Ticket::saveToFile(ostream& out) const {
	out.write(reinterpret_cast<const char*> (&ticketID), sizeof(ticketID));
	size_t nameL = holderName.size();
	out.write(reinterpret_cast<const char*> (&nameL), sizeof(nameL));
	out.write(holderName.c_str(), nameL);
	size_t dateL = expireDate.size();
	out.write(reinterpret_cast<const char*> (&dateL), sizeof(dateL));
	out.write(expireDate.c_str(), dateL);
	out.write(reinterpret_cast<const char*> (&isValid), sizeof(isValid));
	if (out.fail()) {
		cerr << "Error writing ticket, data to file. ";
	}
}

bool Ticket::loadFromFile(istream& in) {
	if (!in.read(reinterpret_cast<char*>(&ticketID), sizeof(ticketID))) {
		return false;
	}

	size_t nameLength;
	if (!in.read(reinterpret_cast<char*>(&nameLength), sizeof(nameLength)) || nameLength > 1000) {
		return false;
	}
	holderName.resize(nameLength);
	in.read(&holderName[0], nameLength);

	if (!in.read(reinterpret_cast<char*>(&isValid), sizeof(isValid))) {
		return false;
	}

	size_t dateLength;
	if (!in.read(reinterpret_cast<char*>(&dateLength), sizeof(dateLength)) || dateLength > 100) {
		return false;
	}
	expireDate.resize(dateLength);
	in.read(&expireDate[0], dateLength);

	return in.good();
}

string Ticket::getExpireDate()const {
	return expireDate;
}

