#include <iostream>
using namespace std;

// Class template for a generic pair
template <typename T>
class Pair {
private:
    T first, second;
public:
    Pair(T a, T b) : first(a), second(b) {}

    T getFirst() {
        return first;
    }

    T getSecond() {
        return second;
    }

    void display() {
        cout << "First: " << first << ", Second: " << second << endl;
    }
};

int main() {
    Pair<int> intPair(5, 10);    // Integer pair
    intPair.display();
    
    // Access first and second using getter functions
    cout << "Accessing individually:" << endl;
    cout << "First value: " << intPair.getFirst() << endl;    // Using getFirst()
    cout << "Second value: " << intPair.getSecond() << endl;  // Using getSecond()

    return 0;
}
