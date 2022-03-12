#include "database.h"

void Database::Add(const Date& date, const std::string& event) {
    if (unique_events[date].find(event) == end(unique_events[date])) {
        events[date].push_back(event);
    }
    unique_events[date].insert(event);
}

void Database::Print(std::ostream& os) const {
    for (const auto& p : events) {
        for (const std::string& event : p.second) {
             os << p.first << " " << event << "\n";
        }
    }
}

std::string Database::Last(const Date& date) const {
    if (events.find(date) != end(events)) {
        return MakeStringFromDate(date) + " " + events.at(date).back();
    }
    if (begin(events)->first > date) {
        return "No entries";
    }
    auto it = events.lower_bound(date);
    --it;
    return MakeStringFromDate(it->first) + " " + it->second.back();
}


