#include <iostream>
using namespace std;

int main()
{
    cout << "Selcections" << endl;
    short input;
    cin >> input;
    switch (input)
    {
    case 1:
        cout << "You selected 1";
        break;
    case 2:
        cout << "You selected 2";
        break;

    default:
        cout << "Goodbye!";
    }
    return 0;
}
