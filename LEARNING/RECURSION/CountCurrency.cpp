#include <iostream>
#include <cstdlib>
using namespace std;

void CurRencyCount(int money, int *&Rs1000, int *&Rs500, int *&Rs100, int *&Rs50, int *&Rs20, int *&Rs10, int *&Rs5, int *&Rs2, int *&Re1)
{
    if (money == 0)
    {
        return;
    }

    if (money / 1000 >= 1)
    {
        *Rs1000 = money / 1000;
        CurRencyCount(money % 1000, Rs1000, Rs500, Rs100, Rs50, Rs20, Rs10, Rs5, Rs2, Re1);
    }
    else if (money / 500 >= 1)
    {
        *Rs500 = money / 500;
        CurRencyCount(money % 500, Rs1000, Rs500, Rs100, Rs50, Rs20, Rs10, Rs5, Rs2, Re1);
    }
    else if (money / 100 >= 1)
    {
        *Rs100 = money / 100;
        CurRencyCount(money % 100, Rs1000, Rs500, Rs100, Rs50, Rs20, Rs10, Rs5, Rs2, Re1);
    }
    else if (money / 50 >= 1)
    {
        *Rs50 = money / 50;
        CurRencyCount(money % 50, Rs1000, Rs500, Rs100, Rs50, Rs20, Rs10, Rs5, Rs2, Re1);
    }
    else if (money / 20 >= 1)
    {
        *Rs20 = money / 20;
        CurRencyCount(money % 20, Rs1000, Rs500, Rs100, Rs50, Rs20, Rs10, Rs5, Rs2, Re1);
    }
    else if (money / 10 >= 1)
    {
        *Rs10 = money / 10;
        CurRencyCount(money % 10, Rs1000, Rs500, Rs100, Rs50, Rs20, Rs10, Rs5, Rs2, Re1);
    }
    else if (money / 5 >= 1)
    {
        *Rs5 = money / 5;
        CurRencyCount(money % 5, Rs1000, Rs500, Rs100, Rs50, Rs20, Rs10, Rs5, Rs2, Re1);
    }
    else if (money / 2 >= 1)
    {
        *Rs2 = money / 2;
        CurRencyCount(money % 2, Rs1000, Rs500, Rs100, Rs50, Rs20, Rs10, Rs5, Rs2, Re1);
    }
    else
    {
        *Re1 = money;
        CurRencyCount(0, Rs1000, Rs500, Rs100, Rs50, Rs20, Rs10, Rs5, Rs2, Re1);
    }
}

void MinimumCurRency(int money)
{
    int Rs1000 = 0, Rs500 = 0, Rs100 = 0, Rs50 = 0, Rs20 = 0, Rs10 = 0, Rs5 = 0, Rs2 = 0, Re1 = 0;

    while (money != 0)
    {
        if (money / 1000 >= 1)
        {
            Rs1000 = money / 1000;
            money %= 1000;
        }
        else if (money / 500 >= 1)
        {
            Rs500 = money / 500;
            money %= 500;
        }
        else if (money / 100 >= 1)
        {
            Rs100 = money / 100;
            money %= 100;
        }
        else if (money / 50 >= 1)
        {
            Rs50 = money / 50;
            money %= 50;
        }
        else if (money / 20 >= 1)
        {
            Rs20 = money / 20;
            money %= 20;
        }
        else if (money / 10 >= 1)
        {
            Rs10 = money / 10;
            money %= 10;
        }
        else if (money / 5 >= 1)
        {
            Rs5 = money / 5;
            money %= 5;
        }
        else if (money / 2 >= 1)
        {
            Rs2 = money / 2;
            money %= 2;
        }
        else
        {
            Re1 = money;
            money %= 1;
            break;
        }
    }

    if (Rs1000 > 0)
        cout << "No. of Rs. 1000 :: " << Rs1000 << endl;
    if (Rs500 > 0)
        cout << "No. of Rs. 500 :: " << Rs500 << endl;
    if (Rs100 > 0)
        cout << "No. of Rs. 100 :: " << Rs100 << endl;
    if (Rs50 > 0)
        cout << "No. of Rs. 50 :: " << Rs50 << endl;
    if (Rs20 > 0)
        cout << "No. of Rs. 20 :: " << Rs20 << endl;
    if (Rs10 > 0)
        cout << "No. of Rs. 10 :: " << Rs10 << endl;
    if (Rs5 > 0)
        cout << "No. of Rs. 5 :: " << Rs5 << endl;
    if (Rs2 > 0)
        cout << "No. of Rs. 2 :: " << Rs2 << endl;
    if (Re1 > 0)
        cout << "No. of Re. 1 :: " << Re1 << endl;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << "all i want was the love and what i get is the pain" << endl;
    cout << "enter amount :: " << endl;
    int money;
    cin >> money;

    MinimumCurRency(money);
    cout << endl
         << endl;

    int *Rs1000 = new int();
    int *Rs500 = new int();
    int *Rs100 = new int();
    int *Rs50 = new int();
    int *Rs20 = new int();
    int *Rs10 = new int();
    int *Rs5 = new int();
    int *Rs2 = new int();
    int *Re1 = new int();

    CurRencyCount(money, Rs1000, Rs500, Rs100, Rs50, Rs20, Rs10, Rs5, Rs2, Re1);

    if (*Rs1000 > 0)
        cout << "No. of Rs. 1000 :: " << *Rs1000 << endl;
    if (*Rs500 > 0)
        cout << "No. of Rs. 500 :: " << *Rs500 << endl;
    if (*Rs100 > 0)
        cout << "No. of Rs. 100 :: " << *Rs100 << endl;
    if (*Rs50 > 0)
        cout << "No. of Rs. 50 :: " << *Rs50 << endl;
    if (*Rs20 > 0)
        cout << "No. of Rs. 20 :: " << *Rs20 << endl;
    if (*Rs10 > 0)
        cout << "No. of Rs. 10 :: " << *Rs10 << endl;
    if (*Rs5 > 0)
        cout << "No. of Rs. 5 :: " << *Rs5 << endl;
    if (*Rs2 > 0)
        cout << "No. of Rs. 2 :: " << *Rs2 << endl;
    if (*Re1 > 0)
        cout << "No. of Re. 1 :: " << *Re1 << endl;

    delete Rs1000;
    delete Rs500;
    delete Rs100;
    delete Rs50;
    delete Rs20;
    delete Rs10;
    delete Rs5;
    delete Rs2;
    delete Re1;

    return EXIT_SUCCESS;
}
