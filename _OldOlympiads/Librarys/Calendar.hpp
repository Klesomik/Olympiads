enum
{
    Monday = 1,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday,
    Sunday
};

enum
{
    January = 1,
    February,
    March,
    April,
    May,
    June,
    July,
    August,
    September,
    October,
    November,
    December
};

std::vector <int> Days ({ 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 });
std::vector <std::string> Weeks ({ "", "Monday", "Tuesday", "Wednesday",  "Thursday", "Friday", "Saturday", "Sunday" });
std::vector <std::string> Months ({ "", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" });

struct Date
{
    int day, week, month, year;

    Date ();
    Date (int value);
    Date (int set_day, int set_week, int set_month, int set_year);

    Date& operator ++ ();
    Date& operator -- ();

    operator int ();
};

Date& Date::operator ++ ()
{
    if (LeapYear (year))
        Days[Fubruary]++;

    if (Days[month] == day)
    {
        if (month == December)
        {
            year++;

            month = January;
        }

        else
            month++;

        day = 1;
    }

    else
        day++;

    if (week == Sunday)
        week = Monday;

    else
        week++;
}

Date& Date::operator -- ()
{
}

bool operator == (const Date& a, const Date& b)
{
    return (a.day   == b.day)   &&
           (a.week  == b.week)  &&
           (a.month == b.month) &&
           (a.year  == b.year);
}

bool operator != (const Date& a, const Date& b)
{
    return !(a == b);
}

bool operator < (const Date& a, const Date& b)
{
    if (a.year != b.year)
        return a.year < b.year;

    if (a.month != b.month)
        return a.month < b.month;

    if (a.week != b.week)
        return a.week < b.week;

    return a.day < b.day;
}

bool operator <= (const Date& a, const Date& b)
{
    return (a < b) || (a == b);
}

bool operator > (const Date& a, const Date& b)
{
    if (a.year != b.year)
        return a.year > b.year;

    if (a.month != b.month)
        return a.month > b.month;

    if (a.week != b.week)
        return a.week > b.week;

    return a.day > b.day;
}

bool operator >= (const Date& a, const Date& b)
{
    return (a > b) || (a == b);
}

bool LeapYear (int year)
{
    if (year % 4 == 0 && year % 100 != 0)
        return true;

    if (year % 400 == 0)
        return true;

    return false;
}
