#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Abstract Class
class Compartment {
public:
    virtual void notice() = 0;   // Pure virtual function
    virtual ~Compartment() {}
};

// Derived Class: FirstClass
class FirstClass : public Compartment {
public:
    void notice() override {
        cout << "First Class: Reserved for premium passengers." << endl;
    }
};

// Derived Class: Ladies
class Ladies : public Compartment {
public:
    void notice() override {
        cout << "Ladies Compartment: Reserved for women passengers." << endl;
    }
};

// Derived Class: General
class General : public Compartment {
public:
    void notice() override {
        cout << "General Compartment: Open for all passengers." << endl;
    }
};

// Derived Class: Luggage
class Luggage : public Compartment {
public:
    void notice() override {
        cout << "Luggage Compartment: Only luggage is allowed." << endl;
    }
};

int main() {
    Compartment* coach[10];

    srand(time(0));

    // Create 10 random compartments
    for (int i = 0; i < 10; i++) {
        int choice = rand() % 4 + 1;

        switch (choice) {
        case 1:
            coach[i] = new FirstClass();
            break;
        case 2:
            coach[i] = new Ladies();
            break;
        case 3:
            coach[i] = new General();
            break;
        case 4:
            coach[i] = new Luggage();
            break;
        }

        cout << "Compartment " << i + 1 << ": ";
        coach[i]->notice();   // Runtime Polymorphism
    }

    // Free memory
    for (int i = 0; i < 10; i++) {
        delete coach[i];
    }

    return 0;
}