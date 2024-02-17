#include <cmath>
#include <iostream>
using namespace std;

int main() {
  int option = 0;
  do {
    cout << endl
         << "mastar functional calculator..." << endl
         << "1: Calculate the area of the circle." << endl
         << "2: Simple Calculator." << endl
         << "0: Exit" << endl
         << endl
         << "What do you want to do (select a number): ";
    cin >> option;
    cout << endl;
    if (option == 1) {
      cout << "Let's calculate the area of a circle..." << endl
           << "What would be the radius of your dream circle: ";
      double radius;
      cin >> radius;
      // TODO: Improved assignment of PI
      double circle_area = pow(radius, 2) * 22 / 7;
      cout << "The area of that would be " << circle_area << endl;
    } else if (option == 2) {
      cout << "Let's calculate something" << endl
           << "What do you wanna do (+ - * /) : ";
      char op;
      cin >> op;
      short num1;
      short num2;
      cout << "Enter the first number: ";
      cin >> num1;
      cout << "Enter the second number: ";
      cin >> num2;
      double ans;
      switch (op) {
      case '+':
        ans = num1 + num2;
        break;
      case '-':
        ans = num1 - num2;
        break;
      case '*':
        ans = num1 * num2;
        break;
      case '/':
        ans = num1 / num2;
        break;
      default:
        cout << "Error" << endl;
      }
      cout << "Calculating " << num1 << op << num2 << endl
           << "Answer is " << ans << endl;
    } else if (option != 0) {
      cout << "Invalid Option" << endl;
    }

  } while (option != 0);
  cout << "Have a great day!" << endl;
}
