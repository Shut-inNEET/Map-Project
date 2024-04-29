#include "scheduleItem.h"

scheduleItem::scheduleItem(string subject, string catalog, string section, string component,
    string session, int units, int totEnrl, int capEnrl, string instructor) {
    this->subject = subject;
    this->catalog = catalog;
    this->section = section;
    this->component = component;
    this->session = session;
    this->units = units;
    this->totEnrl = totEnrl;
    this->capEnrl = capEnrl;
    this->instructor = instructor;
}

bool scheduleItem::operator==(const scheduleItem& other) const {
    return subject == other.subject && catalog == other.catalog && section == other.section;
}

bool scheduleItem::operator!=(const scheduleItem& other) const {
    return !(*this == other);
}

bool scheduleItem::operator>=(const scheduleItem& other) const {
    return subject >= other.subject && catalog >= other.catalog && section >= other.section;
}

void scheduleItem::print() const {
    cout << left << setw(8) << subject
        << setw(8) << catalog
        << setw(8) << section
        << setw(10) << component
        << setw(8) << session
        << setw(6) << units
        << setw(8) << totEnrl
        << setw(8) << capEnrl
        << setw(20) << instructor << endl;
}
