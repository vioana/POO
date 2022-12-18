#ifndef ZONE_H
#define ZONE_H

#include <string>
#include <iostream>

class Zone
{
public:
    Zone();
    Zone(const std::string &name, int rows, int columns, int *seats = nullptr);
    Zone(const Zone &zone);
    ~Zone();

    std::string getName() const;
    void setName(const std::string &name);

    int getRows() const;
    void setRows(int rows);

    int getColumns() const;
    void setColumns(int columns);

    int *getSeats() const;

    // setSeats nu ar trebui sa existe, pentru ca locurile sunt calculate in functie de randuri si coloane
    // si ar trebui sa poata fi modificate doar cu functia occupySeat sau freeSeat
    // void setSeats(int *seats);

    Zone &operator=(const Zone &zone);

    friend std::ostream &operator<<(std::ostream &out, const Zone &zone);
    friend std::istream &operator>>(std::istream &in, Zone &zone);

    // comparare dupa nume
    bool operator<=(const Zone &zone) const;
    bool operator==(const Zone &zone) const;
    bool operator>=(const Zone &zone) const;

    int getSeatsCount() const;
    void capitalizeName();
    void occupySeat(int ticketID, int row, int column);
    void freeSeat(int row, int column);

    int getSeatTicketID(int row, int column) const;

private:
    std::string name;
    int rows;
    int columns;

    // lista cu toate id-urile care ocupa locurile din zona
    // daca un loc este liber, valoarea va fi 0
    int *seats = nullptr;
};

#endif /* ZONE_H */