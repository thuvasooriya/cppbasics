#include <iostream>
using namespace std;

int main()
{
    string names[3];
    cout << "Name 1: ";
    getline(cin, names[0]);
    cout << "Name 2: ";
    getline(cin, names[1]);
    cout << "Name 3: ";
    getline(cin, names[2]);
    cout << names[0] << endl;
    cout << names[1] << endl;
    cout << names[2] << endl;
    return 0;
}
