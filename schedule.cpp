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
        addEntry(item);
    }
}

void schedule::addEntry(const scheduleItem& item) {
    string key = item.getSubject() + "_" + item.getCatalog() + "_" + item.getSection();
    scheduleMap[key] = item;
}

void schedule::print() const {
    for (const auto& pair : scheduleMap) {
        pair.second.print();
    }
}

void schedule::printHeader() const {
    cout << "\nSubject Catalog Section Component Session Units TotEnrl CapEnrl Instructor" << endl;
}

void schedule::findBySubject(const string& subject) const {
    cout << "Records with subject " << subject << ":" << endl;
    printHeader();
    for (const auto& pair : scheduleMap) {
        if (pair.second.getSubject() == subject) {
            pair.second.print();
        }
    }
}

void schedule::findBySubjectAndCatalog(const string& subject, const string& catalog) const {
    cout << "Records with subject " << subject << " and catalog " << catalog << ":" << endl;
    printHeader();
    for (const auto& pair : scheduleMap) {
        if (pair.second.getSubject() == subject && pair.second.getCatalog() == catalog) {
            pair.second.print();
        }
    }
}

void schedule::findByInstructorLastName(const string& lastName) const {
    cout << "Records with instructor last name " << lastName << ":" << endl;
    printHeader();
    for (const auto& pair : scheduleMap) {
        if (pair.second.getInstructor() == lastName) {
            pair.second.print();
        }
    }
}