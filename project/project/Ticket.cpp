#include "Ticket.h"
long Ticket::nextTicketID = 1;

Ticket::Ticket() : ticketID(nextTicketID++), isValid(true) {}

Ticket::Ticket(const string& holderName, bool isValid) : holderName(holderName), ticketID(nextTicketID++), isValid(isValid) {}

Ticket::Ticket(unsigned long id, const string& name, bool valid, const string& expireDate) : ticketID(id), holderName(name), isValid(valid), expireDate(expireDate) {
    nextTicketID++;
}

Ticket::~Ticket() {}

unsigned long Ticket::getTicketID() const {
    return ticketID;
}

string Ticket::getHolderName() const {
    return holderName;
}

void Ticket::setHolderName(const string& name) {
    holderName = name;
}

bool Ticket::getIsValid() const {
    return isValid;
}

void Ticket::setIsValid(bool valid) {
    isValid = valid;
}

void Ticket::printTicket() const {
    cout << "TicketID: " << ticketID << endl << "Holder: " << holderName << endl << "Expire date: " << expireDate << endl;
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

ostream& operator<<(ostream& os, const Ticket& ticket) {
    os << "TicketID: " << ticket.ticketID << ", Holder: " << ticket.holderName << ", Expire date: " << ticket.expireDate << endl;
    return os;
}

istream& operator>>(istream& is, Ticket& ticket) {
    is >> ticket.holderName;
    ticket.ticketID = Ticket::generateNextTicketID();
    return is;
}

bool Ticket::isExpired(const string& currentDate) const {
    return currentDate > expireDate;
}

void Ticket::setExpireDate(const string& expireDate) {
    this->expireDate = expireDate;
}

void Ticket::saveToFile(FILE* file) const {
    fwrite(&ticketID, sizeof(ticketID), 1, file);

    size_t nameLength = holderName.size();
    fwrite(&nameLength, sizeof(nameLength), 1, file);
    fwrite(holderName.c_str(), sizeof(char), nameLength, file);

    size_t dateLength = expireDate.size();
    fwrite(&dateLength, sizeof(dateLength), 1, file);
    fwrite(expireDate.c_str(), sizeof(char), dateLength, file);

    fwrite(&isValid, sizeof(isValid), 1, file);
}

bool Ticket::loadFromFile(FILE* file) {
    if (fread(&ticketID, sizeof(ticketID), 1, file) != 1) {
        return false;
    }

    size_t nameLength;
    if (fread(&nameLength, sizeof(nameLength), 1, file) != 1) {
        return false;
    }
    holderName.resize(nameLength);
    fread(&holderName[0], sizeof(char), nameLength, file);

    size_t dateLength;
    if (fread(&dateLength, sizeof(dateLength), 1, file) != 1) {
        return false;
    }
    expireDate.resize(dateLength);
    fread(&expireDate[0], sizeof(char), dateLength, file);

    if (fread(&isValid, sizeof(isValid), 1, file) != 1) {
        return false;
    }

    return true;
}

string Ticket::getExpireDate() const {
    return expireDate;
}

