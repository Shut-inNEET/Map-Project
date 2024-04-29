#include "scheduleItem.h"
#include "schedule.h"

int main() {
    schedule scheduleData;
    ifstream file("STEM - Summer 2022 Schedule of Classes as of 05-02-22.csv");

    if (file.is_open()) {
        scheduleData.initSchedule(file);
        file.close();

        int choice;
        string subject, catalog, lastName;

        do {
            cout << "Menu:\n";
            cout << "1. Print schedule\n";
            cout << "2. Find records by subject\n";
            cout << "3. Find records by subject and catalog\n";
            cout << "4. Find records by instructor's last name\n";
            cout << "5. Exit\n";
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
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
            }
            cout << endl;
        } while (choice != 5);
    }
    else {
        cout << "Unable to open the file." << endl;
    }

    return 0;
}