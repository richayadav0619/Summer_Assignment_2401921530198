#include <iostream>
using namespace std;

// Interface (Abstract Class)
class Test {
public:
    virtual int square(int x) = 0;
};

// Arithmetic class
class Arithmetic : public Test {
public:
    int square(int x) override {
        return x * x;
    }
};

// ToTestInt class
class ToTestInt {
public:
    void displaySquare(int n) {
        Arithmetic obj;
        cout << "Square of " << n << " = " << obj.square(n) << endl;
    }
};

int main() {
    ToTestInt obj;
    obj.displaySquare(6);

    return 0;
}