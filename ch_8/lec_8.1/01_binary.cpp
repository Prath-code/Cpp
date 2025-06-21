#include <iostream>
using namespace std;

class Points
{
    int x, y, max;
public:
    Points() {
        x = 0;
        y = 0;
        max = 0;
        cout << "Enter the maximum value for x and y: ";
        cin >> max;
        for (int i = 1; i <= max; i++) {
            cout << "which point do you want to add (x/y): ";
            string choice;
            cin >> choice;
            if (choice == "x" || choice == "X") {
                x++;
            } else if (choice == "y" || choice == "Y") {
                y++;
            } else {
                cout << "Invalid choice. Please enter 'x' or 'y'." << endl;
                i--;
            }
            if (x == max) {
                cout << "X won!" << endl;
            } else if (y == max) {
                cout << "Y won!" << endl;
            } else {
                cout << "Current score - X: " << x << ", Y: " << y << endl;
            }
        }
    }
    Points(int xVal, int yVal) {
        x = xVal;
        y = yVal;
        max = 0;
    }
    Points operator+(const Points& p) {
        Points temp;
        temp.x = this->x + p.x;
        temp.y = this->y + p.y;
        return temp;
    }
    Points operator-(const Points& p) {
        Points temp;
        temp.x = this->x - p.x;
        temp.y = this->y - p.y;
        return temp;
    }
    Points operator*(const Points& p) {
        Points temp;
        temp.x = this->x * p.x;
        temp.y = this->y * p.y;
        return temp;
    }
    Points operator/(const Points& p) {
        Points temp;
        temp.x = this->x / p.x;
        temp.y = this->y / p.y;
        return temp;
    }
    Points operator%(const Points& p) {
        Points temp;
        temp.x = this->x % p.x;
        temp.y = this->y % p.y;
        return temp;
    }
    Points operator&(const Points& p) const {
        return Points(x & p.x, y & p.y);
    }
    Points operator|(const Points& p) const {
        return Points(x | p.x, y | p.y);
    }
    Points operator^(const Points& p) const {
        return Points(x ^ p.x, y ^ p.y);
    }
    Points operator<<(int shift) const {
        return Points(x << shift, y << shift);
    }
    Points operator>>(int shift) const {
        return Points(x >> shift, y >> shift);
    }
    Points& operator+=(const Points& p) {
        x += p.x; y += p.y; return *this;
    }
    Points& operator-=(const Points& p) {
        x -= p.x; y -= p.y; return *this;
    }
    Points& operator*=(const Points& p) {
        x *= p.x; y *= p.y; return *this;
    }
    Points& operator/=(const Points& p) {
        x /= p.x; y /= p.y; return *this;
    }
    Points& operator%=(const Points& p) {
        x %= p.x; y %= p.y; return *this;
    }
    // Logical operators
    bool operator&&(const Points& p) const {
        return (x && p.x) && (y && p.y);
    }
    bool operator||(const Points& p) const {
        return (x || p.x) || (y || p.y);
    }
    bool operator!() const {
        return (!x) && (!y);
    }
    // Bitwise NOT
    Points operator~() const {
        return Points(~x, ~y);
    }
    // Assignment operator
    Points& operator=(const Points& p) {
        if (this != &p) {
            x = p.x; y = p.y; max = p.max;
        }
        return *this;
    }
    bool operator==(const Points& p) const {
        return (x == p.x) && (y == p.y);
    }
    bool operator!=(const Points& p) const {
        return !(*this == p);
    }
    bool operator<(const Points& p) const {
        return (x < p.x) && (y < p.y);
    }
    bool operator>(const Points& p) const {
        return (x > p.x) && (y > p.y);
    }
    bool operator<=(const Points& p) const {
        return (x <= p.x) && (y <= p.y);
    }
    bool operator>=(const Points& p) const {
        return (x >= p.x) && (y >= p.y);
    }
    void display() {
        cout << "X: " << x << ", Y: " << y << endl;
    }
};

int main() {
    Points p1(2, 3);
    Points p2(4, 1);
    Points p3 = p1 + p2;
    Points p4 = p1 - p2;
    Points p5 = p1 * p2;
    Points p6 = p1 / p2;
    Points p7 = p1 % p2;
    Points p8 = p1 & p2;
    Points p9 = p1 | p2;
    Points p10 = p1 ^ p2;
    Points p11 = p1 << 1;
    Points p12 = p2 >> 1;
    Points p13 = p1 += p2;
    Points p14 = p1 -= p2;
    Points p15 = p1 *= p2;
    Points p16 = p1 /= p2;
    Points p17 = p1 %= p2;
    cout << "p1: "; p1.display();
    cout << "p2: "; p2.display();
    cout << "p1 + p2: "; p3.display();
    cout << "p1 - p2: "; p4.display();
    cout << "p1 * p2: "; p5.display();
    cout << "p1 / p2: "; p6.display();
    cout << "p1 %% p2: "; p7.display();
    cout << "p1 & p2: "; p8.display();
    cout << "p1 | p2: "; p9.display();
    cout << "p1 ^ p2: "; p10.display();
    cout << "p1 << 1: "; p11.display();
    cout << "p2 >> 1: "; p12.display();
    cout << "p1 += p2: "; p13.display();
    cout << "p1 -= p2: "; p14.display();
    cout << "p1 *= p2: "; p15.display();
    cout << "p1 /= p2: "; p16.display();
    cout << "p1 %%= p2: "; p17.display();
    cout << boolalpha;
    cout << "p1 == p2: " << (p1 == p2) << endl;
    cout << "p1 != p2: " << (p1 != p2) << endl;
    cout << "p1 < p2: " << (p1 < p2) << endl;
    cout << "p1 > p2: " << (p1 > p2) << endl;
    cout << "p1 <= p2: " << (p1 <= p2) << endl;
    cout << "p1 >= p2: " << (p1 >= p2) << endl;
    cout << "p1 && p2: " << (p1 && p2) << endl;
    cout << "p1 || p2: " << (p1 || p2) << endl;
    cout << "!p1: " << (!p1) << endl;
    Points p18 = ~p1;
    cout << "~p1: "; p18.display();
    Points p19 = p1;
    cout << "p19 = p1: "; p19.display();
    return 0;
}
