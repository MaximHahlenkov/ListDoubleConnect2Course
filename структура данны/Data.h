#pragma once

#include <iostream>
#include <string>
#include "List.h"

struct Date
{
    unsigned short day;
    unsigned short month;
    unsigned int year;
    std::string FIO;
    std::string Work;
    int Ilness;
    int Rest_days;
    
    Date();
    Date(unsigned short _day, unsigned short _month, unsigned int _year, std::string _FIO, std::string _Work, int _Ilness, int _Rest_days);
    void PrintDate();

    bool operator==(const Date& Data);
    friend std::istream& operator>>(std::istream& in, Date& date);
};