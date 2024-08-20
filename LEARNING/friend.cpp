#include <iostream>
#include <cstdlib>
using namespace std;

class Y;  // Forward declaration of class Y

class X {
private:
    int x;

public:
    X() {
        this->x = 432;
    }

    friend void swap(X &x, Y &y);  // Declaring the friend function

    void display() const {
        cout << "x = " << this->x << endl;
    }
};

class Y {
private:
    int y;

public:
    Y() {
        this->y = 407;
    }

    friend void swap(X &x, Y &y);  // Declaring the friend function

    void display() const {
        cout << "y = " << this->y << endl;
    }
};

void swap(X &x, Y &y) {
    int temp = x.x;
    x.x = y.y;
    y.y = temp;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    X objX;
    Y objY;

    cout << "Before swap:" << endl;
    objX.display();
    objY.display();

    swap(objX, objY);

    cout << "After swap:" << endl;
    objX.display();
    objY.display();

    return EXIT_SUCCESS;
}
