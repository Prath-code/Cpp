#include <iostream>
using namespace std;

class Number {
    int value;
public:
    Number(int v = 0) : value(v) {}

    Number& operator++() {
        ++value;
        return *this;
    }

    Number operator++(int) {
        Number temp = *this;
        value++;
        return temp;
    }

    Number& operator--() {
        --value;
        return *this;
    }

    Number operator--(int) {
        Number temp = *this;
        value--;
        return temp;
    }

    void display() const {
        cout << "Value: " << value << endl;
    }
};

int main() {
    Number n(5);
    cout << "Original: "; n.display();

    Number n1 = ++n;
    cout << "Prefix increment: "; n1.display();

    Number n2 = n++;
    cout << "Postfix increment (before): "; n2.display();
    cout << "Postfix increment (after): "; n.display();

    Number n3 = --n;
    cout << "Prefix decrement: "; n3.display();

    Number n4 = n--;
    cout << "Postfix decrement (before): "; n4.display();
    cout << "Postfix decrement (after): "; n.display();

    return 0;
}
