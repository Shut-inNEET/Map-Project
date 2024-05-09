#include "scheduleItem.h"
#include "schedule.h"
#include <functional>

size_t hashFunction1(const std::string& key) {
    size_t hashVal = 0;
    for (char ch : key) {
        hashVal += ch;
    }
    return hashVal;
}

size_t hashFunction2(const std::string& key) {
    size_t hashVal = 0;
    if (!key.empty()) {
        hashVal = key[0] + 27 * (key.length() > 1 ? key[1] : 0) + 729 * (key.length() > 2 ? key[2] : 0);
    }
    return hashVal;
}

size_t hashFunction3(const std::string& key) {
    size_t hashVal = 0;
    for (char ch : key) {
        hashVal = 37 * hashVal + ch;
    }
    return hashVal;
}

size_t customHashFunction(const std::string& key) {
    size_t hashVal = 0;
    for (char ch : key) {
        hashVal = (hashVal * 31) + ch;
    }
    return hashVal;
}

int main() {
    schedule scheduleData;
    ifstream file("STEM - Summer 2022 Schedule of Classes as of 05-02-22.csv");

    if (file.is_open()) {
        int hashFunctionChoice;
        cout << "Choose a hash function:\n";
        cout << "1. Hash Function 1\n";
        cout << "2. Hash Function 2\n";
        cout << "3. Hash Function 3\n";
        cout << "4. Custom Hash Function\n";
        cout << "Enter your choice: ";
        cin >> hashFunctionChoice;
        cout << endl;

        switch (hashFunctionChoice) {
        case 1:
            scheduleData.setHashFunction(hashFunction1);
            break;
        case 2:
            scheduleData.setHashFunction(hashFunction2);
            break;
        case 3:
            scheduleData.setHashFunction(hashFunction3);
            break;
        case 4:
            scheduleData.setHashFunction(customHashFunction);
            break;
        default:
            cout << "Invalid choice. Using default hash function.\n" << endl;
            scheduleData.setHashFunction(hashFunction3);
            break;
        }
       
        scheduleData.initSchedule(file);
        file.close();

        int choice;
        string subject, catalog, lastName, key;

        do {
            cout << "Menu:\n";
            cout << "1. Print schedule\n";
            cout << "2. Find records by subject\n";
            cout << "3. Find records by subject and catalog\n";
            cout << "4. Find records by instructor's last name\n";
            cout << "5. Display table statistics\n";
            cout << "6. Get hash index for a key\n";
            cout << "7. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
            case 1:
                scheduleData.printHeader();
                scheduleData.print();
                break;
            case 2:
                cout << "Enter subject: ";
                cin >> subject;
                scheduleData.findBySubject(subject);
                break;
            case 3:
                cout << "Enter subject: ";
                cin >> subject;
                cout << "Enter catalog: ";
                cin >> catalog;
                scheduleData.findBySubjectAndCatalog(subject, catalog);
                break;
            case 4:
                cout << "Enter instructor's last name: ";
                cin >> lastName;
                scheduleData.findByInstructorLastName(lastName);
                break;
            case 5:
                scheduleData.statistics();
                break;
            case 6:
                cout << "Enter the key: ";
                cin >> key;
                cout << "Hash index for '" << key << "' is: " << scheduleData.getHashIndex(key) << endl;
                break;
            case 7:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
            }
            cout << endl;
        } while (choice != 7);
    }
    else {
        cout << "Unable to open the file." << endl;
    }

    return 0;
}