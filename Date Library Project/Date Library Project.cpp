#include <iostream>
#include "clsDate.h"

using namespace std;

int main()

{
    clsDate Date1;
    Date1.Print();

    clsDate Date2("31/1/2022");
    Date2.Print();

    clsDate Date3(20, 12, 2022);
    Date3.Print();

    clsDate Date4(250, 2022);
    Date4.Print();

    Date1.IncreaseDateByOneMonth();
    Date1.Print();

    Date1.PrintMonthCalendar();
    Date2.PrintMonthCalendar();

    //Date3.PrintYearCalendar();
    //cout << Date2.IsValid() << endl;

    cout << "My Age In Days:" <<
        clsDate::CalculateMyAgeInDays(clsDate(17, 11, 2004));
    /*You can try any method at your own..*/


    system("pause>0");
    return 0;
};
