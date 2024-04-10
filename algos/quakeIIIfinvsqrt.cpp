// fast inverse square root algorithm of quake III game engine
#include <iostream>
// #include <math.h>

float Q_rsqrt(float);

int main() {
  float x;
  std::cout << "Enter a number: ";
  std::cin >> x;

  // how a normal fucking person do it
  // float y = 1 / sqrt(x);

  // how a chad does it
  float y = Q_rsqrt(x);

  std::cout << "rsqrt: " << y << std::endl;
  return 0;
}

float Q_rsqrt(float number) {
  long i;
  float x2, y;
  const float threehalfs = 1.5F;

  x2 = number * 0.5F;
  y = number;
  i = *(long *)&y;           // evil floating point bit hack
  i = 0x5f3759df - (i >> 1); // what the fuck?
  y = *(float *)&i;
  y = y * (threehalfs - (x2 * y * y)); // 1st iteration
  y = y * (threehalfs - (x2 * y * y)); // 2nd iteration, can be removed

  return y;
}

/*
some might ask why the fuck would someone do this? here is a bit of info.
Quake is a game engine and game engines have to do whole lot of vector
calculations for lighting, reflections and stuff. normalizing a vector is a
standard thing to do which involves the inverse square root a lot. square root
and inverse are terribly slow operations by default. we can sacrifice some error
margin to speed up, which is exactly what is done here.

my comments on the code:

float Q_rsqrt(float number) {
  // all of the following three declarations are 32-bit
  long i; // binary number
  float x2, y; // decimal numbers ieee 754 signbit + 8 bits exponent + 23 bits
mantissa const float threehalfs = 1.5F; // fancy way to say 1.5

  // bit representation = 2^23*E + M
  // value = (1 + M/2^23) * 2^(E-127)
  // take binary log and simplify log_2 (1+M/2^23) + E-127
  // log_2(1+x) = x + mu (correction to give smallest error on average)
  // simplify
  // log_2(value) = 1/2^23 (M + 2^23*E) + mu - 127 = bit manipulation

  x2 = number * 0.5F;
  y = number;

  // where the wizardery begins
  // floats are never designed for bit manipulation but longs can be bit
manipulated i = *(long *)&y; getting the bits as exactly as it is from float is
a challenge since conversion messes it up in the above we tricked C by
converting the address of a float to an address of a long and then read the
value so that bit keep intact &y gets the address of y which is an address of a
float ( long * ) hacks c so that c now thinks that the thing under the address
is a long address itself won't change but the * operator reads the bit values as
a long and stores it in i.

  // what does bit manipulating an exponent gives you
  i = 0x5f3759df - (i >> 1);
  // normally bs => left - double, right - half
  // exponent bs => left - double => squares the number ... you got it :)
  // let's bit shift exponent bits it to right and negate
  // the magic number is the remnants of scaling factors and shifting when
solving the log terms

  y = *(float *)&i; // reversing the hack to get the approximation

  // newton method of approximation
  y = y * (threehalfs - (x2 * y * y)); // 1st iteration
  y = y * (threehalfs - (x2 * y * y)); // 2nd iteration, can be removed

  return y;
}
*/
