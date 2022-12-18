#ifndef EVENT_H
#define EVENT_H

#include <string>
#include <vector>
#include <iostream>

#include "location.h"
#include "datetime.h"

class Event
{
public:
    Event();
    Event(const char *name, const char *description, const DateTime &dateTime, const Location &location);
    Event(const Event &event);
    ~Event();

    char *getName() const;
    void setName(const char *name);

    char *getDescription() const;
    void setDescription(const char *description);

    DateTime getDateTime() const;
    void setDateTime(const DateTime &dateTime);

    Location getLocation() const;
    void setLocation(const Location &location);

    static int getEventsCount();
    static void setEventsCount(int eventsCount);

    friend std::ostream &operator<<(std::ostream &out, const Event &event);

    friend std::istream &operator>>(std::istream &in, Event &event);

    Event &operator=(const Event &event);

    // comparare dupa nume
    bool operator<(const Event &event) const;
    bool operator==(const Event &event) const;
    bool operator>(const Event &event) const;

    void capitalizeName();
    void capitalizeDescription();

private:
    char *name = nullptr;
    char *description = nullptr;
    DateTime dateTime;
    Location location;

    static int eventsCount;

    // pentru faza 2
    // std::vector<Ticket> zones;
};

#endif /* EVENT_H */