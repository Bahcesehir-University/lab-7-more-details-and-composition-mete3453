#include <iostream>
#include <string>
#include <cmath>
// ============================================================
// CLASS DEFINITIONS
// ============================================================
class Point {
private:
    double x;
    double y;
public:
    // Constructor
    Point(double x, double y) : x(x), y(y) {}
    // Const getters
    double getX() const { return x; }
    double getY() const { return y; }
    // Const display
    void display() const { std::cout << "(" << x << ", " << y << ")"; }
    // Friend class
    friend class Rectangle;
};

class Rectangle {
private:
    Point topLeft;
    Point bottomRight;
public:
    // Constructor
    Rectangle(double x1, double y1, double x2, double y2)
        : topLeft(x1, y1), bottomRight(x2, y2) {}
    // Const methods
    double getWidth() const {
        return std::abs(bottomRight.x - topLeft.x);
    }
    double getHeight() const {
        return std::abs(topLeft.y - bottomRight.y);
    }
    double getArea() const {
        return getWidth() * getHeight();
    }
    void display() const {
        std::cout << "Top left: ";
        topLeft.display();
        std::cout << "\nBottom right: ";
        bottomRight.display();
        std::cout << "\nWidth: " << getWidth()
<< "\nHeight: " << getHeight()
<< "\nArea: " << getArea() << std::endl;
    }
    // Friend function declaration (must be OUTSIDE functions)
    friend bool isSameSize(const Rectangle& r1, const Rectangle& r2);
};

// Friend function implementation
bool isSameSize(const Rectangle& r1, const Rectangle& r2) {
    return r1.getArea()==r2.getArea();
}

class ConstDemo {
private:
    int value;
public:
    // Constructor
    ConstDemo(int v) : value(v) {}
    // Const getter
    int getValue() const { return value; }
    // Non-const modifier
    void doubleValue() { value *= 2; }
    // Const function
    int constGetDouble() const {
        return value * 2;
    }
};

// ============================================================
// MAIN
// ============================================================
int main() {
    Rectangle rect1(0, 0, 4, 3);
    Rectangle rect2(1, 1, 4, 4);
    std::cout << "\nRect1:\n";
    rect1.display();
    std::cout << "\nRect2:\n";
    rect2.display();
    std::cout << "\nSame size?: "
<< (isSameSize(rect1, rect2) ? "Yes" : "No") << std::endl;
    const ConstDemo cd1(7);
    std::cout << "Const object value: " << cd1.getValue() << "\n";
    std::cout << "Const object doubled: " << cd1.constGetDouble() << "\n";
    ConstDemo cd2(5);
    cd2.doubleValue();
    std::cout << "Non-const object after double value: "
<< cd2.getValue() << "\n";
    return 0;
}
