#include <zone.h>
#include <stdexcept>
#include <helper_functions.h>

Zone::Zone()
    : Zone("", 0, 0)
{
}

Zone::Zone(const std::string &name, int rows, int columns, int *seats)
{
    this->setName(name);
    this->setRows(rows);
    this->setColumns(columns);

    if (seats == nullptr)
    {
        this->seats = new int[rows * columns];
        for (int i = 0; i < rows * columns; i++)
            this->seats[i] = 0;
    }
    else
    {
        this->seats = new int[rows * columns];
        for (int i = 0; i < rows * columns; i++)
            this->seats[i] = seats[i];
    }
}

Zone::Zone(const Zone &zone)
{
    this->setName(zone.getName());
    this->setRows(zone.getRows());
    this->setColumns(zone.getColumns());

    this->seats = new int[zone.getRows() * zone.getColumns()];
    for (int i = 0; i < zone.getRows() * zone.getColumns(); i++)
        this->seats[i] = zone.getSeats()[i];
}

Zone::~Zone()
{
    if (this->seats)
        delete[] this->seats;
}

std::string Zone::getName() const
{
    return this->name;
}

void Zone::setName(const std::string &name)
{
    this->name = name;
}

int Zone::getRows() const
{
    return this->rows;
}

void Zone::setRows(int rows)
{
    if (rows < 0)
    {
        throw std::invalid_argument("Numarul de randuri trebuie sa fie pozitiv.");
    }

    this->rows = rows;
}

void Zone::setColumns(int columns)
{
    if (columns < 0)
    {
        throw std::invalid_argument("Numarul de coloane trebuie sa fie pozitiv.");
    }

    this->columns = columns;
}

int *Zone::getSeats() const
{
    return this->seats;
}

Zone &Zone::operator=(const Zone &zone)
{
    if (this != &zone)
    {
        this->setName(zone.getName());
        this->setRows(zone.getRows());
        this->setColumns(zone.getColumns());

        if (this->seats)
            delete[] this->seats;

        this->seats = new int[zone.getRows() * zone.getColumns()];
        for (int i = 0; i < zone.getRows() * zone.getColumns(); i++)
            this->seats[i] = zone.getSeats()[i];
    }

    return *this;
}

bool Zone::operator<=(const Zone &zone) const
{
    return this->name <= zone.name;
}

bool Zone::operator>=(const Zone &zone) const
{
    return this->name >= zone.name;
}

int Zone::getSeatsCount() const
{
    return this->rows * this->columns;
}

void Zone::capitalizeName()
{
    for (int i = 0; i < this->name.length(); i++)
    {
        if (i == 0 || this->name[i - 1] == ' ')
        {
            this->name[i] = toupper(this->name[i]);
        }
    }
}

void Zone::occupySeat(int ticketID, int row, int column)
{
    if (row < 0 || row >= this->rows)
    {
        throw std::invalid_argument("Randul trebuie sa fie intre 0 si " + std::to_string(this->rows - 1) + ".");
    }

    if (column < 0 || column >= this->columns)
    {
        throw std::invalid_argument("Coloana trebuie sa fie intre 0 si " + std::to_string(this->columns - 1) + ".");
    }

    this->seats[row * this->columns + column] = ticketID;
}

int Zone::getSeatTicketID(int row, int column) const
{
    if (row < 0 || row >= this->rows)
    {
        throw std::invalid_argument("Randul trebuie sa fie intre 0 si " + std::to_string(this->rows - 1) + ".");
    }

    if (column < 0 || column >= this->columns)
    {
        throw std::invalid_argument("Coloana trebuie sa fie intre 0 si " + std::to_string(this->columns - 1) + ".");
    }

    return this->seats[row * this->columns + column];
}

void Zone::freeSeat(int row, int column)
{
    this->occupySeat(0, row, column);
}

bool Zone::operator==(const Zone &zone) const
{
    return this->name == zone.name;
}

int Zone::getColumns() const
{
    return this->columns;
}

std::istream &operator>>(std::istream &in, Zone &zone)
{
    std::cout << "Numele zonei: ";
    getline(in, zone.name);

    std::string input;

    while (true)
    {
        std::cout << "Numarul de randuri: ";
        getline(in, input);

        try
        {
            int rows = validatedStringToInt(input, "Numarul de randuri");
            zone.setRows(rows);

            break;
        }
        catch (const std::invalid_argument &e)
        {
            std::cout << e.what() << std::endl;
        }
    }

    while (true)
    {
        std::cout << "Numarul de coloane: ";
        getline(in, input);

        try
        {
            int columns = validatedStringToInt(input, "Numarul de coloane");
            zone.setColumns(columns);

            break;
        }
        catch (const std::invalid_argument &e)
        {
            std::cout << e.what() << std::endl;
        }
    }

    return in;
}

std::ostream &operator<<(std::ostream &out, const Zone &zone)
{
    out << zone.name << ", randuri: " << zone.rows << ", coloane: " << zone.columns;

    return out;
}
