#include <iostream>
#include <string>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * dayOfProgrammer
 *
 * The function is expected to return a STRING.
 * The function accepts INTEGER year as parameter.
 */
string dayOfProgrammer(int year) {
  string y_str = to_string(year);
  if (year < 1918) {
    // julian
    if (year % 4 == 0) {
      // julian leap
      return "12.09." + y_str;
    } else {
      return "13.09." + y_str;
    }
  } else if (year == 1918) {
    // transition year
    return "26.09." + y_str;
  } else {
    // gregorian
    if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
      // gregorian leap
      return "12.09." + y_str;
    } else {
      return "13.09." + y_str;
    }
  }
}

int main() {
  string year_temp;
  getline(cin, year_temp);

  int year = stoi(ltrim(rtrim(year_temp)));

  string result = dayOfProgrammer(year);

  cout << result << "\n";

  return 0;
}

string ltrim(const string &str) {
  string s(str);
  s.erase(s.begin(), find_if(s.begin(), s.end(),
                             [](unsigned char c) { return !isspace(c); }));
  return s;
}

string rtrim(const string &str) {
  string s(str);
  s.erase(
      find_if(s.rbegin(), s.rend(), [](unsigned char c) { return !isspace(c); })
          .base(),
      s.end());
  return s;
}

/*
Marie invented a Time Machine and wants to test it by time-traveling to visit
Russia on the Day of the Programmer (the 256th day of the year) during a year in
the inclusive range from 1700 to 2700. From 1700 to 1917, Russia's official
calendar was the Julian calendar; since 1919 they used the Gregorian calendar
system. The transition from the Julian to Gregorian calendar system occurred in
1918 when the next day after January 31st was February 14th. This means that in
1918, February 14th was the 32nd day of the year in Russia.

In both calendar systems, February is the only month with a variable amount of
days; it has 29 days during a leap year, and 28 days during all other years. In
the Julian calendar, leap years are divisible by 4; in the Gregorian calendar,
leap years are either of the following: Divisible by 400. Divisible by 4 and not
divisible by 100.

Given a year,y, find the date of the 256th day of that year according to the
official Russian calendar during that year. Then print it in the format
dd.mm.yyyy, where dd is the two-digit day, mm is the two-digit month, and yyyy
is y. For example, the given  = 1984. 1984 is divisible by 4, so it is a leap
year. The 256th day of a leap year after 1918 is September 12, so the answer
is 12.09.1984.

Function Description
Complete the dayOfProgrammer function in the editor below. It should return a
string representing the date of the 256th day of the year given. dayOfProgrammer
has the following parameter(s): year: an integer

Input Format
A single integer denoting year .

Constraints
1700 ≤ y ≤ 2700

For example:
Input	Result
2017  13.09.2017
2016  12.09.2016
*/
