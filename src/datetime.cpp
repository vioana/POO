#include <datetime.h>
#include <datetime.h>
#include </helper_functions.h>

DateTime::DateTime(int year, int month, int day, int hour, int minute) : year(year), month(month), day(day), hour(hour), minute(minute)
{
}

int DateTime::getYear() const
{
    return this->year;
}

void DateTime::setYear(int year)
{
    if (year < 2020 || year > 2030)
    {
        throw std::invalid_argument("Anul trebuie sa fie intre 2020 si 2030 (inclusiv)!");
    }

    this->year = year;
}

void DateTime::setMonth(int month)
{
    if (month < 1 || month > 12)
    {
        throw std::invalid_argument("Luna trebuie sa fie intre 1 si 12 (inclusiv)!");
    }

    this->month = month;
}

int DateTime::getHour() const
{
    return this->hour;
}

void DateTime::setHour(int hour)
{
    if (hour < 0 || hour > 23)
    {
        throw std::invalid_argument("Ora trebuie sa fie intre 0 si 23 (inclusiv)!");
    }

    this->hour = hour;
}

void DateTime::setMinute(int minute)
{
    if (minute < 0 || minute > 59)
    {
        throw std::invalid_argument("Minutul trebuie sa fie intre 0 si 59 (inclusiv)!");
    }

    this->minute = minute;
}

DateTime DateTime::operator++(int)
{
    DateTime copy = *this;
    ++(*this);
    return copy;
}

DateTime &DateTime::operator++()
{
    this->minute++;

    if (this->minute == 60)
    {
        this->minute = 0;
        this->hour++;
    }

    if (this->hour == 24)
    {
        this->hour = 0;
        this->day++;
    }

    if (this->day == 32)
    {
        this->day = 1;
        this->month++;
    }

    if (this->month == 13)
    {
        this->month = 1;
        this->year++;
    }

    return *this;
}

DateTime DateTime::operator--(int)
{
    DateTime copy = *this;
    --(*this);
    return copy;
}

DateTime &DateTime::operator--()
{
    this->minute--;

    if (this->minute == -1)
    {
        this->minute = 59;
        this->hour--;
    }

    if (this->hour == -1)
    {
        this->hour = 23;
        this->day--;
    }

    if (this->day == 0)
    {
        this->day = 31;
        this->month--;
    }

    if (this->month == 0)
    {
        this->month = 12;
        this->year--;
    }

    return *this;
}

DateTime DateTime::getCurrentDateTime()
{
    time_t now = time(0);
    tm *ltm = localtime(&now);

    return DateTime(1900 + ltm->tm_year, 1 + ltm->tm_mon, ltm->tm_mday, ltm->tm_hour, ltm->tm_min);
}

void DateTime::add(int days, int hours, int minutes)
{
    this->minute += minutes;
    this->hour += hours;
    this->day += days;

    if (this->minute >= 60)
    {
        this->hour += this->minute / 60;
        this->minute %= 60;
    }

    if (this->hour >= 24)
    {
        this->day += this->hour / 24;
        this->hour %= 24;
    }

    if (this->day >= 32)
    {
        this->month += this->day / 32;
        this->day %= 32;
    }

    if (this->month >= 13)
    {
        this->year += this->month / 13;
        this->month %= 13;
    }
}
int DateTime::getMinute() const
{
    return this->minute;
}

void DateTime::setDay(int day)
{
    if (day < 1 || day > 31)
    {
        throw std::invalid_argument("Ziua trebuie sa fie intre 1 si 31 (inclusiv)!");
    }

    this->day = day;
}

int DateTime::getDay() const
{
    return this->day;
}

int DateTime::getMonth() const
{
    return this->month;
}

std::ostream &
operator<<(std::ostream &out, const DateTime &dateTime)
{
    out << dateTime.year << "-" << dateTime.month << "-" << dateTime.day << " "
        << dateTime.hour << ":" << dateTime.minute;

    return out;
}

std::istream &operator>>(std::istream &in, DateTime &dateTime)
{
    std::string input;

    while (true)
    {
        std::cout << "Anul: ";
        std::getline(in, input);
        try
        {
            dateTime.setYear(validatedStringToInt(input, "Anul"));
            break;
        }
        catch (std::invalid_argument &e)
        {
            std::cout << e.what() << std::endl;
        }
    }

    while (true)
    {
        std::cout << "Luna: ";
        std::getline(in, input);
        try
        {
            dateTime.setMonth(validatedStringToInt(input, "Luna"));
            break;
        }
        catch (std::invalid_argument &e)
        {
            std::cout << e.what() << std::endl;
        }
    }

    while (true)
    {
        std::cout << "Ziua: ";
        std::getline(in, input);
        try
        {
            dateTime.setDay(validatedStringToInt(input, "Ziua"));
            break;
        }
        catch (std::invalid_argument &e)
        {
            std::cout << e.what() << std::endl;
        }
    }

    while (true)
    {
        std::cout << "Ora: ";
        std::getline(in, input);
        try
        {
            dateTime.setHour(validatedStringToInt(input, "Ora"));
            break;
        }
        catch (std::invalid_argument &e)
        {
            std::cout << e.what() << std::endl;
        }
    }

    while (true)
    {
        std::cout << "Minutul: ";
        std::getline(in, input);
        try
        {
            dateTime.setMinute(validatedStringToInt(input, "Minutul"));
            break;
        }
        catch (std::invalid_argument &e)
        {
            std::cout << e.what() << std::endl;
        }
    }

    return in;
}
