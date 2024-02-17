// #include <iostream>
#include "../print.h"
// #include <cstdlib>
using namespace std;

void passfn(int arr[], int len, int iter)
{
    for (int i = 0; i < (len - iter); ++i)
    {
        if (arr[i] > arr[i + 1])
        {
            int tmp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = tmp;
        }
    }
    // return arr;
}
int main()
{
    const int offset = 0;
    const int range = 100;
    ppl(33, "Hi there!");
    ppl(33, "Let's examine sorting together");
    // ppl(36, "Options:");
    ppl(36, "0: bubble sort");
    ppl(36, "1: merge sort");
    ppl(36, "2: insertion sort");
    ppl(36, "3: shell sort");
    ppl(36, "4: selection sort");
    int mode;
    pp(34, "Which mode (0 .. 4) would you like to select? ");
    scanf("%d", &mode);
    ppi(37, mode);
    int us_arr[10] = {23, 36, 31, 20, 22, 21, 25, 28, 24, 33};
    int pass = 0;
    const int arr_len = *(&us_arr + 1) - us_arr;
    switch (mode)
    {
    case 0:
        ppl(37, ": Bubble Sort");
        pprp(32, pass, us_arr);
        for (pass = 1; pass < 10; ++pass)
        {
            passfn(us_arr, arr_len, pass);
            pprp(32, pass, us_arr);
        }
        break;
    case 1:
        ppl(37, ": Merge Sort");
        pprp(32, pass, us_arr);
        break;
    case 2:
        ppl(37, ": Insertion Sort");
        break;
    case 3:
        ppl(37, ": Shell Sort");
        break;
    case 4:
        ppl(37, ": Selectio Sort");
        break;
    default:
        ppl(37, ": Not an option");
        break;
    }
    // if (mode < 0)
    // {
    //     ppl(31, "What! we don't do that here!");
    // }
    // else
    // {
    //     pp(35, "You've selected: ");
    //     ppi(35, mode);
    // }

    // Providing a seed value
    // srand((unsigned)time(NULL));

    // Loop to get 5 random numbers
    // for (int i = 1; i <= 5; i++)
    // {

    //     int random = offset + (rand() % range);

    // Print the random number
    // cout << random << endl;
    // }

    return 0;
}
