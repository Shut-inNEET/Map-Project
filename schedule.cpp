#include "schedule.h"

void schedule::schedule::initSchedule(ifstream& file) {
    string line;
    getline(file, line); // Skip the header line

    while (getline(file, line)) {
        string subject, catalog, section, component, session, acadOrg, instructor;
        int minUnits, units, totEnrl, capEnrl;

        // Parse the line and extract the required fields
        stringstream ss(line);
        getline(ss, subject, ',');
        getline(ss, catalog, ',');
        getline(ss, section, ',');
        getline(ss, component, ',');
        getline(ss, session, ',');
        string minUnitsStr, unitsStr, totEnrlStr, capEnrlStr;
        getline(ss, minUnitsStr, ','); // Skip the column
        getline(ss, unitsStr, ',');
        getline(ss, totEnrlStr, ',');
        getline(ss, capEnrlStr, ',');
        getline(ss, acadOrg, ','); // Skip the column
        getline(ss, instructor, ',');

        // Remove leading and trailing double quotes from the instructor's name
        if (!instructor.empty() && instructor.front() == '"') {
            instructor = instructor.substr(1, instructor.length() - 1);
        }

        units = stoi(unitsStr);
        totEnrl = stoi(totEnrlStr);
        capEnrl = stoi(capEnrlStr);

        scheduleItem item(subject, catalog, section, component, session, units, totEnrl, capEnrl, instructor);
        string key = item.getSubject() + "_" + item.getCatalog() + "_" + item.getSection();
        scheduleMap.insert(key, item);
    }
}

/*
In this modified print() and find() functions, we're using a nested loop to iterate over the buckets 
of the HashTable and then over the scheduleItem objects within each bucket.

The outer loop for (size_t i = 0; i < scheduleMap.getSize(); ++i) 
iterates over the indices from 0 to scheduleMap.getSize() - 1, 
where scheduleMap.getSize() returns the total number of elements in the hash table.

The inner loop for (const auto& item : bucket) 
iterates over the scheduleItem objects within the bucket at the current index i, 
using the getByIndex function provided by the HashTable class.

The item.print() function is called to print the details of each scheduleItem object in the hash table.

Note that this approach assumes that the HashTable class provides a getSize function 
that returns the total number of elements in the hash table, and a getByIndex function that takes an index as input 
and returns a vector<V> (where V is the value type, in this case, 
scheduleItem containing the values in the bucket at that index.

If the HashTable class has different function names or signatures, 
you may need to adjust the code accordingly.
*/

void schedule::print() {
    for (size_t i = 0; i < scheduleMap.getSize(); ++i) {
        vector<scheduleItem> bucket = scheduleMap.getByIndex(i);
        for (const auto& item : bucket) {
            item.print();
        }
    }
}

void schedule::printHeader() const {
    cout << "\nSubject Catalog Section Component Session Units TotEnrl CapEnrl Instructor" << endl;
}

void schedule::findBySubject(const string& subject) {
    cout << "Records with subject " << subject << ":" << endl;
    printHeader();
    for (size_t i = 0; i < scheduleMap.getSize(); ++i) {
        vector<scheduleItem> bucket = scheduleMap.getByIndex(i);
        for (const auto& item : bucket) {
            if (item.getSubject() == subject) {
                item.print();
            }
        }
    }
}

void schedule::findBySubjectAndCatalog(const string& subject, const string& catalog) {
    cout << "Records with subject " << subject << " and catalog " << catalog << ":" << endl;
    printHeader();
    for (size_t i = 0; i < scheduleMap.getSize(); ++i) {
        vector<scheduleItem> bucket = scheduleMap.getByIndex(i);
        for (const auto& item : bucket) {
            if (item.getSubject() == subject && item.getCatalog() == catalog) {
                item.print();
            }
        }
    }
}

void schedule::findByInstructorLastName(const string& lastName) {
    cout << "Records with instructor last name " << lastName << ":" << endl;
    printHeader();
    for (size_t i = 0; i < scheduleMap.getSize(); ++i) {
        vector<scheduleItem> bucket = scheduleMap.getByIndex(i);
        for (const auto& item : bucket) {
            if (item.getInstructor() == lastName) {
                item.print();
            }
        }
    }
}

// Added functions for HashTable

void schedule::setHashFunction(function<size_t(const string&)> hashFunc) {
    scheduleMap.setHashFunction(hashFunc);
}

void schedule::statistics() {
    cout << "\nHash table size: " << scheduleMap.getSize() << endl;
    cout << "Number of buckets: " << scheduleMap.getBuckets() << endl;
    cout << "Load factor: " << scheduleMap.getLoadFactor() << endl;
    cout << "Number of collisions: " << scheduleMap.countCollisions() << endl;
    cout << "Length of longest chain: " << scheduleMap.maxBucketSize() << endl;
}

size_t schedule::getHashIndex(const string & key) {
    return scheduleMap.hash(key);
}