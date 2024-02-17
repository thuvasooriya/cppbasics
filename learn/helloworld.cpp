#include <iostream>

using namespace std;

// Variables and Constants
int main()
{
    // initialization
    // method 1
    int integer1 = 1'000'000;
    // method 2: brace initialization
    int zero{}; // automatically initializes to zero and not to some garbage
    // short sint1{integer1};    // brace init doesn't allow implicit casting or narrowing,
    // technically it means you cannot do type conversion
    short sint2{23};
    cout << "Integer1: " << integer1 << endl
         << "Short int: " << sint2 << endl;
    int bin_num = 0b11111111; // binary number
    int hexnum = 0xFF;        // hexadecimal number
    // unsigned int unsignednum = 0b11111111; // unsigned number
    cout << "Brace init to none: " << zero << endl
         << "Binary: " << bin_num << endl
         << "Hexadecimal: " << hexnum << endl;

    // constants
    const double PI = 3.14;
    int x = 10;
    x++;         // increment operator
    x--;         // decrement operator
    int y = x++; // x is incremented after assignment
    int z = ++x; // x is incremented before assignment

    // process of swapping variables
    int slot1{32}, slot2{14};
    int temp = slot1;
    slot1 = slot2;
    slot2 = temp;

    // math operations
    double x1 = 2, y1 = 3;
    double ans = (x1 + 10) / (3 * y1);
    cout << ans << endl;

    // output to console
    double sales = 95000.00;
    const double STATE_TAX_RATE = .04;
    const double COUNTY_TAX_RATE = .02;
    double state_tax = sales * STATE_TAX_RATE;
    double county_tax = sales * COUNTY_TAX_RATE;

    cout << "Sales is $" << sales << endl
         << "State Tax is $" << state_tax << endl
         << "County Tax is $" << county_tax << endl
         << "Total Tax is $" << state_tax + county_tax << endl;

    // booleans
    bool comitted = false;
    cout << boolalpha << comitted << endl    // prints false
         << noboolalpha << comitted << endl; // prints 0 :default behavior

    // comparision and logical operators
    int box1 = 4;
    int box2 = 5;
    bool same_boxes = box1 == box2;
    bool small_boxes = box1 < 10 && box2 < 10;
    bool small_box = box1 < 10 || box2 < 10;
    // order of logical ops: () ! && ||
    cout << boolalpha << !same_boxes << endl;
    cout << boolalpha << small_boxes << endl;
    cout << boolalpha << small_box << endl;

    return 0;
}

// cout - Standard output stream
// << - Stream insertion operator