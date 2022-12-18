#include <event.h>
#include <cstring>
#include <helper_functions.h>

int Event::eventsCount = 0;

Event::Event()
    : Event("", "", DateTime(), Location())
{
    Event::eventsCount++;
}

Event::Event(const char *name, const char *description, const DateTime &dateTime, const Location &location)
{
    this->setName(name);

    this->setDescription(description);

    this->setDateTime(dateTime);

    this->setLocation(location);
}

Event::Event(const Event &event)
{
    this->setName(event.name);

    this->setDescription(event.description);

    this->dateTime = event.dateTime;

    this->location = event.location;
}

Event::~Event()
{
    if (this->name)
        delete[] this->name;

    if (this->description)
        delete[] this->description;
}

char *Event::getName() const
{
    return this->name;
}

void Event::setName(const char *name)
{
    if (this->name)
        delete[] this->name;

    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}

char *Event::getDescription() const
{
    return this->description;
}

void Event::setDescription(const char *description)
{
    if (this->description)
        delete[] this->description;

    this->description = new char[strlen(description) + 1];
    strcpy(this->description, description);
}

DateTime Event::getDateTime() const
{
    return this->dateTime;
}

void Event::setDateTime(const DateTime &dateTime)
{
    this->dateTime = dateTime;
}

Location Event::getLocation() const
{
    return this->location;
}

void Event::setLocation(const Location &location)
{
    this->location = location;
}

int Event::getEventsCount()
{
    return Event::eventsCount;
}

void Event::setEventsCount(int eventsCount)
{
    Event::eventsCount = eventsCount;
}

Event &Event::operator=(const Event &event)
{
    if (this != &event)
    {
        this->setName(event.name);

        this->setDescription(event.description);

        this->dateTime = event.dateTime;

        this->location = event.location;
    }

    return *this;
}

bool Event::operator<(const Event &event) const
{
    if (strcmp(this->name, event.name) < 0)
        return true;
    else
        return false;
}

bool Event::operator>(const Event &event) const
{
    if (strcmp(this->name, event.name) > 0)
        return true;
    else
        return false;
}

void Event::capitalizeName()
{
    for (int i = 0; this->name[i] != '\0'; i++)
        this->name[i] = toupper(this->name[i]);
}

void Event::capitalizeDescription()
{
    for (int i = 0; this->description[i] != '\0'; i++)
        this->description[i] = toupper(this->description[i]);
}

bool Event::operator==(const Event &event) const
{
    if (strcmp(this->name, event.name) == 0)
        return true;
    else
        return false;
}

std::ostream &operator<<(std::ostream &out, const Event &event)
{
    out << "Event: \"" << event.name
        << "\", descriere: \"" << event.description << "\""
        << ", data si ora: " << event.dateTime
        << ", locatie: " << event.location;

    return out;
}

std::istream &operator>>(std::istream &in, Event &event)
{
    std::string name;

    std::cout << "Nume: ";
    std::getline(in, name);
    event.setName(name.c_str());

    std::string description;

    std::cout << "Descriere: ";
    std::getline(in, description);
    event.setDescription(description.c_str());

    std::cout << "Data si ora:\n";
    in >> event.dateTime;

    std::cout << "Locatie:\n";
    in >> event.location;

    return in;
}
