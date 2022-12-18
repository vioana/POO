#ifndef LOCATION_H
#define LOCATION_H

#include <string>
#include "../include/zone.h"

class Location
{
public:
    Location();
    Location(const std::string &name, int zonesCount, Zone *zones);
    Location(const Location &location);
    ~Location();

    std::string getName() const;
    void setName(const std::string &name);

    int getZonesCount() const;
    Zone *getZones() const;
    void setZones(Zone *zones, int zonesCount);

    Location &operator=(const Location &location);

    friend std::ostream &operator<<(std::ostream &out, const Location &location);

    friend std::istream &operator>>(std::istream &in, Location &location);

    // returneaza zona cu indexul respectiv
    Zone &operator[](int index);

    // operator + adauga o zona la sfarsitul listei de zone
    Location operator+(const Zone &zone) const;

private:
    std::string name;
    int zonesCount;
    Zone *zones = nullptr;
};

#endif /* LOCATION_H */