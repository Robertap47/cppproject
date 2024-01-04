#include <iostream>
#include <string>
using namespace std;
class Ticket {
private:
    bool isValid;
    unsigned long ticketID;
    string holderName;
    static long nextTicketID; // static attribute to generate unique ID
    string expireDate;

public:
    Ticket();
    Ticket(const string& holderName, bool isValid = true);
    Ticket(unsigned long id, const string& name, bool valid, const string& expireDate);
    ~Ticket();
    unsigned long getTicketID() const;
    string getHolderName() const;
    void setHolderName(const string& name);
    bool getIsValid() const; // Getter for isValid
    void setIsValid(bool valid); // Setter for isValid
    void printTicket() const;
    void invalidateTicket();
    static unsigned long generateNextTicketID();
    friend ostream& operator<<(ostream& os, const Ticket& ticket);
    friend istream& operator>>(istream& is, Ticket& ticket);
    bool operator!() const;
    Ticket& operator++();
    bool isExpired(const string& currentDate) const;
    void setExpireDate(const string& expireDate);
    string getExpireDate() const;
    void saveToFile(FILE* file) const;
    bool loadFromFile(FILE* file);
};
