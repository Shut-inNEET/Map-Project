#ifndef SCHEDULE_H
#define SCHEDULE_H

#include "scheduleItem.h"
#include <iostream>
#include <fstream>
#include <map>
#include <string> 
#include <utility>
#include <sstream>
#include <vector>

using namespace std;

class schedule {
private:
    map<string, scheduleItem> scheduleMap;

public:
    // Precondition: The file stream is open and points to a valid CSV file.
    // Postcondition: Reads the CSV file, creates scheduleItem objects, and adds them to the scheduleMap.
    void initSchedule(ifstream& file);

    // Precondition: None
    // Postcondition: Adds the provided scheduleItem object to the scheduleMap.
    void addEntry(const scheduleItem& item);

    // Precondition: None
    // Postcondition: Prints the header and all scheduleItem objects in the scheduleMap to the console.
    void print() const;

    // Precondition: None
    // Postcondition: Prints the header and all scheduleItem objects in the scheduleMap to the console.
    void printHeader() const;

    // Precondition: None
    // Postcondition: Prints all scheduleItem objects with the provided subject to the console.
    void findBySubject(const string& subject) const;

    // Precondition: None
    // Postcondition : Prints all scheduleItem objects with the provided subject and catalog to the console.
    void findBySubjectAndCatalog(const string& subject, const string& catalog) const;

    // Precondition: None
    // Postcondition: Prints all scheduleItem objects with the provided instructor's last name to the console.
    void findByInstructorLastName(const string& lastName) const;
};

#endif