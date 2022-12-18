#include <app.h>

#include <iostream>
#include <event.h>
#include <location.h>

void App::run()
{
    while (true)
    {
        showMenu();

        std::string choice;
        getline(std::cin, choice);

        if (choice == "1")
        {
            this->addEvent();
        }
        else if (choice == "2")
        {
            break;
        }
        else
        {
            std::cout << "Optiune invalida. Reincercati." << std::endl;
        }
    }
}

void App::showMenu()
{
    std::cout << "Meniu" << std::endl;

    std::cout << "1. Adaugare eveniment" << std::endl;
    std::cout << "2. Iesire" << std::endl;
}

void App::addEvent()
{
    Event event;

    std::cin >> event;

    std::cout << event << std::endl;

    // va urma la faza 2
    // this->events.push_back(event);
}