#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>

#include "date.h"

class Database {
public:
    void Add(const Date& date, const std::string& event);
    void Print(std::ostream& os) const;
    std::string Last(const Date& date) const;

    template<typename Func>
    std::vector<std::string> FindIf(Func& f) {
        std::vector<std::string> res;
        for (const auto& p : events) {
            for (const std::string& event : p.second) {
                if (f(p.first, event)) {
                    res.push_back(MakeStringFromDate(p.first) + " " + event);
                }
            }
        }
        return res;
    }

    template<typename Func>
    int RemoveIf(Func& f) {
        int count = 0;
        for (const auto& p : events) {
            for (auto it = begin(p.second); it != end(p.second); ++it) {
                if (f(p.first, *it)) {
                    events[p.first].erase(it);
                    ++count;
                }
            }
            if (events[p.first].empty()) {
                events.erase(p.first);
            }
        }
        for (const auto& p : unique_events) {
            for (const std::string& event : p.second) {
                if (f(p.first, event)) {
                    unique_events[p.first].erase(event);
                }
            }
            if (unique_events[p.first].empty()) {
                unique_events.erase(p.first);
            }
        }
        return count;
    }
private:
    std::map<Date, std::vector<std::string>> events;
    std::map<Date, std::set<std::string>> unique_events; // используем, чтобы понять есть ли данное событие уже в базе данных
};
