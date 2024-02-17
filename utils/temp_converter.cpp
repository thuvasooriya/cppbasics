#include <iostream>
#include "print.h"
using namespace std;

int main()
{
    ppl(33, "Hi there!");
    ppl(31, "I'm a little non fancy calculator made to convert temperature between scales");
    int mode;
    cout << "The calculator has 2 modes to choose from." << endl
         << "0 : fahrenheit to celsius" << endl
         << "1 : celsius to fahrenheit" << endl;
    pp(34, "Which mode (0 or 1) would you like to select? ");
    scanf("%d", &mode);
    // cin >> mode;
    if (mode < 0)
    {
        ppl(31, "What! we don't do that here!");
    }
    else
    {
        pp(35, "You've selected");
        ppi(35, mode);
    }

    // cout << "You've selected " << mode << endl;
    // BUG: Need to Solve for negative values
    double celsius;
    double fahrenheit;
    if (mode == 0)
    {
        cout << "Intput the fahrenheit value: ";
        cin >> fahrenheit;
        celsius = (fahrenheit - 32) * (5 / 9);
        cout << "It's " << celsius << " in celsius" << endl;
    }
    else
    {
        cout << "Intput the celsius value: ";
        cin >> celsius;
        fahrenheit = (celsius * 9 / 5) + 32;
        cout << "It's " << fahrenheit << " in fahrenheit" << endl;
    }
    return 0;
}
