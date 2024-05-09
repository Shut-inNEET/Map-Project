#ifndef SCHEDULE_H
#define SCHEDULE_H

#include "scheduleItem.h"
#include "HashTable.h"
#include <iostream>
#include <fstream>
#include <string> 
#include <utility>
#include <sstream>
#include <vector>

using namespace std;

class schedule {
private:
    HashTable<string, scheduleItem> scheduleMap{220}; // Set initial table size to 100

public:
    // Precondition: The file stream is open and points to a valid CSV file.
    // Postcondition: Reads the CSV file, creates scheduleItem objects, and adds them to the scheduleMap.
    void initSchedule(ifstream& file);

    // Precondition: None
    // Postcondition: Prints the header and all scheduleItem objects in the scheduleMap to the console.
    void print();

    // Precondition: None
    // Postcondition: Prints the header and all scheduleItem objects in the scheduleMap to the console.
    void printHeader() const;

    // Precondition: None
    // Postcondition: Prints all scheduleItem objects with the provided subject to the console.
    void findBySubject(const string& subject);

    // Precondition: None
    // Postcondition : Prints all scheduleItem objects with the provided subject and catalog to the console.
    void findBySubjectAndCatalog(const string& subject, const string& catalog);

    // Precondition: None
    // Postcondition: Prints all scheduleItem objects with the provided instructor's last name to the console.
    void findByInstructorLastName(const string& lastName);

    //Added functions for HashTable

    // Precondition: Receives a pointer to a user defined hash function
    // Postcondition: Sets the hash function in HashTable.h to the user defined function
    void setHashFunction(function<size_t(const string&)> hashFunc);

    // Postcondition: Displays the size of the hash table,
    // the number of buckets in the hash table
    // the load factor of the hash table,
    // the number of collisions,
    // and the length of the longest chain
    void statistics();

    // Precondtions: The key parameter is a valid string object.
    // The HashTable object (scheduleMap) has been properly initialized and has a valid hash function set.
    // Postconditions: The function returns the hash index (bucket index) for the given key in the HashTable.
    // The returned hash index is a size_t value that falls within the range of valid bucket indices (0 to table.size() - 1).
    // The state of the HashTable object(scheduleMap) remains unchanged.
    size_t getHashIndex(const string& key);
};

#endif