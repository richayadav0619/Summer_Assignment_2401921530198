#include <iostream>
using namespace std;

// Package: music
namespace music {

    // Interface (Abstract Class)
    class Playable {
    public:
        virtual void play() = 0;
        virtual ~Playable() {}
    };

    // Package: music::string
    namespace string {

        class Veena : public Playable {
        public:
            void play() override {
                cout << "Playing Veena" << endl;
            }
        };

    }

    // Package: music::wind
    namespace wind {

        class Saxophone : public Playable {
        public:
            void play() override {
                cout << "Playing Saxophone" << endl;
            }
        };

    }

}

// Package: live
namespace live {

    class Test {
    public:
        static void run() {

            // a. Create an instance of Veena and call play()
            music::string::Veena veena;
            veena.play();

            // b. Create an instance of Saxophone and call play()
            music::wind::Saxophone saxophone;
            saxophone.play();

            // c. Use Playable pointer (Polymorphism)
            music::Playable* p;

            p = &veena;
            p->play();

            p = &saxophone;
            p->play();
        }
    };

}

int main() {

    live::Test::run();

    return 0;
}