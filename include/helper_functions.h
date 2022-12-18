#ifndef HELPER_FUNCTIONS_H
#define HELPER_FUNCTIONS_H

#include <string>
#include <iostream>

inline bool isOnlyDigits(const std::string &str)
{
    for (int i = 0; i < str.length(); i++)
        if (!isdigit(str[i]))
            return false;

    return true;
}

inline int validatedStringToInt(const std::string &str, const std::string &object_name)
{

    if (!isOnlyDigits(str))
    {
        throw std::invalid_argument(object_name + " trebuie sa contina doar cifre!");
    }
    else if (str.length() > 6)
    {
        throw std::invalid_argument(object_name + " nu poate contine atat de multe cifre!");
    }

    int value = std::stoi(str);

    return value;
}

#endif /* HELPER_FUNCTIONS_H */