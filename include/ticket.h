#ifndef TICKET_H
#define TICKET_H

#include <string>
#include <iostream>

class Ticket
{
public:
    Ticket();
    Ticket(int id, const std::string &name, int row, int column);
    ~Ticket() = default;

    int getId() const;

    std::string getZone() const;
    void setZone(const std::string &zone);

    int getRow() const;
    void setRow(int row);

    int getColumn() const;
    void setColumn(int column);

    friend std::ostream &operator<<(std::ostream &out, const Ticket &ticket);
    friend std::istream &operator>>(std::istream &in, Ticket &ticket);

    // cast to string
    operator std::string() const;

    // cast to char*
    operator const char *() const;

    bool isFrontRow() const;
    bool isAtEntrance() const;

private:
    const int id;
    std::string zone;
    int row;
    int column;
};

#endif /* TICKET_H */