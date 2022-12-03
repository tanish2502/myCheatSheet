#include "date.hpp"

int main()
{
    Date* ptrDate = new Date(25,02,1998);

    ptrDate->showDate();

    ptrDate->setDay(04);
    ptrDate->setMonth(12);
    ptrDate->setYear(2022);

    ptrDate->showDate();
    
    return 0;
}
