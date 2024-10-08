#include <iostream>
#include <string>
#include "List.h"

using namespace std;

Date::Date()
{
    month = rand() % 12 + 1;
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
        day = rand() % 31 + 1;
    if (month == 4 || month == 6 || month == 9 || month == 11)
        day = rand() % 30 + 1;
    if (month == 2)
        day = rand() % 28 + 1;
    year = rand() % 10 + 2024;
    Ilness = rand() % 10 + 1;
    Rest_days = rand() % 30 + 10;

    std::string Works[10]{ "Программист","Столяр","Плотник" ,"Сварщик" ,"Хирург" ,"Водитель" ,"Фермер" ,"Пилот" ,"Преподаватель" ,"Маляр" };

    string firstNames[8] = { "Иван", "Максим", "Стас", "Илья", "Игорь", "Мурат", "Никита", "Святослав" };
    string secondNames[8] = { "Попов", "Хахленков", "Поляков", "Болгов", "Военкоров", "Богатский", "Чудинов", "Даунов" };
    string lastNames[8] = { "Иванович", "Сергеевич", "Александрович", "Валерьевич", "Владимирович", "Максимович", "Вадимович", "Романович" };

    FIO = secondNames[rand() % 8] + ' ' + firstNames[rand() % 8] + ' ' + lastNames[rand() % 8];
    Work = Works[rand() % 10];

}


Date::Date(unsigned short _day, unsigned short _month, unsigned int _year, std::string _FIO, std::string _Work, int _Ilness, int _Rest_days)
{
    day = _day;
    month = _month;
    year = _year;
    FIO = _FIO;
    Work = _Work;
    Ilness = _Ilness;
    Rest_days = _Rest_days;
}

bool Date::operator==(const Date& Data)
{
    if (this == &Data)
        return true;
    if (this->day == Data.day && this->FIO == Data.FIO && this->Ilness == Data.Ilness && this->month == Data.month && this->Rest_days == Data.Rest_days && this->Work == Data.Work && this->year == Data.year)
        return true;
    return false;
}

void Date::PrintDate()
{
    cout << day << '.' << month << '.' << year << ' ' << FIO << ' ' << Work << "   " << Ilness << ':' << IlnessPrint(Ilness) << "   " << Rest_days << "\n";
}

std::istream& operator>>(std::istream& in, Date& date)
{
    in >> date.day >> date.month >> date.year;
    in.ignore();
    std::getline(in, date.FIO);
    std::getline(in, date.Work);
    in >> date.Ilness >> date.Rest_days;

    return in;
}