#ifndef SCHEDULEITEM_H
#define SCHEDULEITEM_H

#include <iostream>
#include <iomanip>

using namespace std;

class scheduleItem 
{
private:
    string subject, catalog, section, component, session, instructor;
    int units, totEnrl, capEnrl;

public:
    // Constructor
    scheduleItem(string subject = "", string catalog = "", string section = "", string component = "",
        string session = "", int units = 0, int totEnrl = 0, int capEnrl = 0, string instructor = "");

    // Getter functions
    string getSubject() const { return subject; }
    string getCatalog() const { return catalog; }
    string getSection() const { return section; }
    string getComponent() const { return component; }
    string getSession() const { return session; }
    int getUnits() const { return units; }
    int getTotEnrl() const { return totEnrl; }
    int getCapEnrl() const { return capEnrl; }
    string getInstructor() const { return instructor; }

    // Operator overload for == 
    // Precondition: None
    // Postcondition: Returns true if the subject, catalog, and section of the scheduleItem 
    //                are equal to the other scheduleItem, false otherwise.
    bool operator==(const scheduleItem& other) const;

    // Operator overload for != 
    // Precondition: None
    // Postcondition: Returns true if the subject, catalog, and section of the scheduleItem 
    //                are not equal to the other scheduleItem, false otherwise.
    bool operator!=(const scheduleItem& other) const;

    // Operator overload for >= 
    // Precondition: None
    // Postcondition: Returns true if the subject, catalog, and section of the scheduleItem 
    //                are greater than or equal to the other scheduleItem, false otherwise.
    bool operator>=(const scheduleItem& other) const;

    // Precondition: None
    // Postcondition: Prints the details of the scheduleItem (subject, catalog, section, 
    //                component, session, units, totEnrl, capEnrl, instructor) to the console.
    void print() const;
};

#endif