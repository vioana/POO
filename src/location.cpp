#include <location.h>
#include <helper_functions.h>

Location::Location()
    : Location("", 0, nullptr)
{
}

Location::Location(const std::string &name, int zonesCount, Zone *zones)
{
    this->setName(name);

    if (zonesCount > 0 && zones)
        this->setZones(zones, zonesCount);
    else
    {
        this->zonesCount = 0;
        this->zones = nullptr;
    }
}

Location::Location(const Location &location)
{
    this->setName(location.getName());

    this->setZones(location.getZones(), location.getZonesCount());
}

Location::~Location()
{
    if (this->zones)
        delete[] this->zones;
}

std::string Location::getName() const
{
    return this->name;
}

void Location::setName(const std::string &name)
{
    this->name = name;
}

int Location::getZonesCount() const
{
    return this->zonesCount;
}

Zone *Location::getZones() const
{
    return this->zones;
}

void Location::setZones(Zone *zones, int zonesCount)
{
    if (this->zones)
        delete[] this->zones;

    this->zonesCount = zonesCount;
    this->zones = new Zone[zonesCount];
    for (int i = 0; i < zonesCount; i++)
        this->zones[i] = zones[i];
}

Location &Location::operator=(const Location &location)
{
    if (this == &location)
        return *this;

    this->setName(location.getName());

    this->setZones(location.getZones(), location.getZonesCount());

    return *this;
}

Zone &Location::operator[](int index)
{
    if (index < 0 || index >= this->zonesCount)
        throw std::out_of_range("Indexul este in afara intervalului");

    return this->zones[index];
}

Location Location::operator+(const Zone &zone) const
{
    Location location = *this;

    Zone *zones = new Zone[location.getZonesCount() + 1];
    for (int i = 0; i < location.getZonesCount(); i++)
        zones[i] = location.getZones()[i];

    zones[location.getZonesCount()] = zone;

    location.setZones(zones, location.getZonesCount() + 1);

    return location;
}

std::ostream &operator<<(std::ostream &out, const Location &location)
{
    out << "Nume: \"" << location.getName() << "\", numar zone: " << location.getZonesCount() << ", zone: (";

    for (int i = 0; i < location.getZonesCount(); i++)
    {
        out << location.getZones()[i];
        if (i < location.getZonesCount() - 1)
            out << ", ";
    }

    out << ")";

    return out;
}

std::istream &operator>>(std::istream &in, Location &location)
{
    std::cout << "Nume locatie: ";
    getline(in, location.name);

    int zonesCount = 0;
    while (true)
    {
        std::string input;
        std::cout << "Numar zone: ";
        getline(in, input);
        try
        {
            int value = validatedStringToInt(input, "Numarul de zone");

            if (value == 0)
                throw std::invalid_argument("Trebuie sa existe cel putin o zona.");

            zonesCount = value;

            break;
        }
        catch (std::invalid_argument &e)
        {
            std::cout << e.what() << "\n";
        }
    }

    Zone *zones = new Zone[zonesCount];
    for (int i = 0; i < zonesCount; i++)
    {
        std::cout << "Zona " << i + 1 << ":\n";
        in >> zones[i];
    }

    location.setZones(zones, zonesCount);

    delete[] zones;

    return in;
}