#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
     // characters
     char ch_a = 'a'; // single quotes
     char ch_b = 98;  // not a good practice
     cout << ch_a << endl
          << +ch_a << endl // numeric representation of ch
          << ch_b << endl;

     // strings
     string name = "Thuva Sooriya"; // double quotes

     // getting string inputs
     // method 1 * don't use this with method 2
     /*
     string input_str;
     cout << "Enter your name: ";
     cin >> input_str; // string after space or newline is ignored
     cout << "Hi there! " << input_str << endl
          << endl;
     */
     // method 2
     string street;
     cout << "Street: ";
     getline(cin, street);

     string district;
     cout << "District: ";
     getline(cin, district);

     string province;
     cout << "Province: ";
     getline(cin, province);

     string zip_code;
     cout << "Zip Code: ";
     getline(cin, zip_code);

     cout << street << "," << endl
          << district << ", " << province << ", " << zip_code << "." << endl;

     /*
     cout << left; // default is right
     // the above will apply until right is applied

     cout << "Numeric Samples" << endl
          << endl;
     cout << fixed << setprecision(10) << 12.34567 << endl
          << 34.56899 << endl
          << endl;
     */

     /*
     // printing a sample table example
     cout << "Fundamental Types Table" << endl
          << endl
          << setw(10) << "Type" << right << setw(5) << "Bytes" << setw(50) << "Range" << left << endl
          << setw(10) << "short" << right << setw(5) << sizeof(short) << setw(50) << "-32768 to 32767" << left << endl
          << setw(10) << "int" << right << setw(5) << sizeof(int) << setw(50) << "-2147483648 to 2147483647" << left << endl
          << setw(10) << "long" << right << setw(5) << sizeof(long) << setw(50) << "-9223372036854775808 to 9223372036854775807" << left << endl
          << endl;

     cout << "Range using builtin functions" << endl
          << endl
          << "Range of short: " << numeric_limits<short>::min() << " to " << numeric_limits<short>::max() << endl
          << "Range of int: " << numeric_limits<int>::min() << " to " << numeric_limits<int>::max() << endl
          << "Range of long: " << numeric_limits<long>::min() << " to " << numeric_limits<long>::max() << endl;
     // if you increase the values of specific types beyond their limits they will cycle to the other side
     */
     return 0;
}
