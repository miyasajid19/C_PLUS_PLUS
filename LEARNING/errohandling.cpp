#include <iostream>
using namespace std;
int main()
{
  int age = 14;
  try
  {
    if (age > 16)
    {
      cout << "can apply for citizenship cetificate";
    }
    else
    {
      throw(age);
    }
  }
  catch (int age)
  {
    cout << "can't apply for citizenship certfificate\n";
  }
  try
  {
    int age = 15;
    if (age >= 18)
    {
      cout << "Access granted - you are old enough.";
    }
    else
    {
      throw 505;
    }
  }
  catch (int myNum)
  {
    cout << "Access denied - You must be at least 18 years old.\n";
    cout << "Error number: " << myNum;
  }
  // this is used for handling anykind of error
  try
  {
    int age = 15;
    if (age >= 18)
    {
      cout << "Access granted - you are old enough.";
    }
    else
    {
      throw 505;
    }
  }
  catch (...)
  {
    cout << "Access denied - You must be at least 18 years old.\n";
  }
}