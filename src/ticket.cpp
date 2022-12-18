#include <ticket.h>
#include <helper_functions.h>

Ticket::Ticket()
    : Ticket(0, "", 0, 0)
{
}

Ticket::Ticket(int id, const std::string &name, int row, int column)
    : id(id), zone(name), row(row), column(column)
{
}

int Ticket::getId() const
{
    return this->id;
}

std::string Ticket::getZone() const
{
    return this->zone;
}

void Ticket::setZone(const std::string &zone)
{
    this->zone = zone;
}

int Ticket::getRow() const
{
    return this->row;
}

void Ticket::setRow(int row)
{
    this->row = row;
}

int Ticket::getColumn() const
{
    return this->column;
}

void Ticket::setColumn(int column)
{
    this->column = column;
}

std::ostream &operator<<(std::ostream &out, const Ticket &ticket)
{
    out << "Id: " << ticket.id << ", Zona: " << ticket.zone << ", Rand: " << ticket.row << ", Coloana: " << ticket.column;

    return out;
}

std::istream &operator>>(std::istream &in, Ticket &ticket)
{
    // id-ul nu se citeste, pentru ca e constant si va fi setat in constructor ca sa se asigure unicitatea

    std::string zone;
    getline(in, zone);

    std::string input;

    while (true)
    {
        std::cout << "Rand: ";
        getline(in, input);

        try
        {
            int row = validatedStringToInt(input, "Randul");
            ticket.setRow(row);

            break;
        }
        catch (const std::invalid_argument &e)
        {
            std::cout << e.what() << std::endl;
        }
    }

    while (true)
    {
        std::cout << "Coloana: ";
        getline(in, input);

        try
        {
            int column = validatedStringToInt(input, "Coloana");
            ticket.setColumn(column);

            break;
        }
        catch (const std::invalid_argument &e)
        {
            std::cout << e.what() << std::endl;
        }
    }

    return in;
}

Ticket::operator std::string() const
{
    return "Id: " + std::to_string(this->id) + ", Zona: " + this->zone + ", Rand: " + std::to_string(this->row) + ", Coloana: " + std::to_string(this->column);
}

Ticket::operator const char *() const
{
    return this->operator std::string().c_str();
}

bool Ticket::isFrontRow() const
{
    return this->row == 0;
}

bool Ticket::isAtEntrance() const
{
    return this->column == 0;
}
