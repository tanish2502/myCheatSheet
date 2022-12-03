#include <iostream>
#include <exception>
#include "date.hpp"

Date::Date(int initDay, int initMonth, int initYear)
{
    if(!isDateValid(initDay, initMonth, initYear))
    {
        throw std::range_error("Date value/s is out of range");
    }
    this->day = initDay;
    this->month = initMonth;
    this->year = initYear;
}

bool static isDateValid(int day, int month, int year)
{
    const int MAX_VALID_YEAR = 9999;
    const int MIN_VALID_YEAR = 1800;

    if (year < MIN_VALID_YEAR || year > MAX_VALID_YEAR)
        return false;
    
    if(month < 1 || month > 12)
        return false;

    if(day < 1 || day > 31)
        return false;
    
    if(month==2)
    {
        if((year%4==0 && year%100!=0) || (year%400==0)) //leapyear
            return (day<=29);
        else
            return (day<=28);
    }

    if(month == 4 || month == 6 || month == 9 || month == 11)
        return (day<=30);    
    
    return TRUE;
};

int Date::getDay() const
{
    return this->day;
}
int Date::setDay(int newDay)
{
    if(!isDateValid(newDay, this->month, this->year))
    {
        throw std::range_error("Day value/s is out of range");
    }
    this->day = newDay;
    return SUCCESS;
}

int Date::getMonth() const
{
    return this->month;
}
int Date::setMonth(int newMonth)
{
    if(!isDateValid(this->day, newMonth, this->year))
    {
        throw std::range_error("Month value/s is out of range");
    }
    this->month = newMonth;
    return SUCCESS;
}

int Date::getYear() const
{
    return this->year;
}
int Date::setYear(int newYear)
{
    if(!isDateValid(this->day, this->month, newYear))
    {
        throw std::range_error("Year value/s is out of range");
    }
    this->year = newYear;
    return SUCCESS;
}

void Date::showDate() const
{
    std::cout << day << "/" << month << "/" << year << std::endl;
}
