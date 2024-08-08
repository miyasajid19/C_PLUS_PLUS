#include <iostream>
#include <cstdlib>
using namespace std;

class Fraction
{
public:
    int numerator, denominator;

    // Default constructor
    Fraction() : numerator(0), denominator(1) {}

    // Parameterized constructor
    Fraction(int a, int b)
    {
        if (b == 0)
        {
            throw invalid_argument("Denominator cannot be zero.");
        }
        int hcf = findHCF(abs(a), abs(b));
        numerator = a / hcf;
        denominator = b / hcf;
        if (denominator < 0)
        {
            numerator = -numerator;
            denominator = -denominator;
        }
    }

    // Function to find the HCF using Euclidean algorithm
    int findHCF(int a, int b)
    {
        while (b != 0)
        {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    // Function to display the fraction
    void display() const
    {
        cout << numerator << " / " << denominator << endl;
    }

    // Function to add fractions
    Fraction sum(const Fraction f) const
    {
        int new_numerator = numerator * f.denominator + denominator * f.numerator;
        int new_denominator = denominator * f.denominator;
        return Fraction(new_numerator, new_denominator);
    }
    Fraction operator+(Fraction f)
    {
        int new_numerator = numerator * f.denominator + denominator * f.numerator;
        int new_denominator = denominator * f.denominator;
        return Fraction(new_numerator, new_denominator);
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    Fraction f1(1, 2);
    f1.display();
    Fraction f2(-6, 4);
    f2.display();
    Fraction f = f1.sum(f2);
    f.display();
    Fraction f3(12, 34);
    f3.display();
    Fraction f4(407, 432);
    f4.display();
    Fraction sum;
    sum = f3 + f4;
    sum.display();
    return EXIT_SUCCESS;
}
