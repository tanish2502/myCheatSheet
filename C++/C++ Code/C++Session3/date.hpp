#ifndef _DATE_H
#define _DATE_H

#define SUCCESS 0
#define TRUE 0
#define FALSE 1

class Date
{
    private:
        int day;
        int month;
        int year;

        bool static isDateValid(int day, int month, int year);

    public:
        Date(int initDay, int initMonth, int initYear);

        int getDay() const;
        int setDay(int newDay);

        int getMonth() const;
        int setMonth(int newMonth);

        int getYear() const;
        int setYear(int newYear);

        void showDate() const;

};

#endif /*_DATE_H*/
