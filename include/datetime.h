#ifndef DATETIME_H
#define DATETIME_H

#include <iostream>

class DateTime
{
public:
    DateTime(int year = 0, int month = 0, int day = 0, int hour = 0, int minute = 0);
    ~DateTime() = default;

    int getYear() const;
    void setYear(int year);

    int getMonth() const;
    void setMonth(int month);

    int getDay() const;
    void setDay(int day);

    int getHour() const;
    void setHour(int hour);

    int getMinute() const;
    void setMinute(int minute);

    friend std::ostream &operator<<(std::ostream &out, const DateTime &dateTime);
    friend std::istream &operator>>(std::istream &in, DateTime &dateTime);

    // postfix increment
    DateTime operator++(int);

    // prefix increment
    DateTime &operator++();

    // postfix decrement
    DateTime operator--(int);

    // prefix decrement
    DateTime &operator--();

    static DateTime getCurrentDateTime();
    void add(int days, int hours, int minutes);

private:
    int year;
    int month;
    int day;
    int hour;
    int minute;
};

#endif /* DATETIME_H */