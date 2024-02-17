#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    const short min_value = 1;
    const short max_value = 6;
    srand(time(0));
    short first = (rand() % (max_value - min_value + 1)) + min_value;
    short second = (rand() % (max_value - min_value + 1)) + min_value;
    cout << first << ", " << second << endl;
    return 0;
}