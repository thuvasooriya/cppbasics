#include <iostream>
using namespace std;

int main()
{
    cout << "Enter a positive number: ";
    int num;
    cin >> num;
    if (num < 0)
        cout << "Error, number is not positive" << endl;
    else
    {
        int factorial = 1;
        for (int i = 1; i <= num; i++)
        {
            factorial *= i;
        }
        cout << "Factorial of " << num << " is " << factorial << endl;
    }

    return 0;
}