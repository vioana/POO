#ifndef APP_H
#define APP_H

#include <iostream>
#include "event.h"

class App
{
public:
    App() = default;
    ~App() = default;

    void run();

    // clasa App e folosita doar pentru a structura mai bine meniul
    // nu are sens sa contina operatori supraincarcati

private:
    void showMenu();
    void addEvent();

    // va urma la faza 2
    // std::vector<Event> events;
};

#endif /* APP_H */