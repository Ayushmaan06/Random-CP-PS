#include <iostream>
#include <cmath>

// Abstract base class
class Shape {
public:
    // Pure virtual function (abstract method)
    virtual double area() const = 0;

    // Virtual function
    virtual void print() const {
        std::cout << "Shape with area: " << area() << std::endl;
    }

    virtual ~Shape() = default; // Virtual destructor for proper cleanup
};

// Derived class: Circle
class Circle : public Shape {
public:
    Circle(double radius) : radius_(radius) {}

    double area() const override {
        return M_PI * radius_ * radius_;
    }

    void print() const override {
        std::cout << "Circle with radius: " << radius_ << " and area: " << area() << std::endl;
    }

private:
    double radius_;
};

// Derived class: Rectangle
class Rectangle : public Shape {
public:
    Rectangle(double width, double height) : width_(width), height_(height) {}

    double area() const override {
        return width_ * height_;
    }

    void print() const override {
        std::cout << "Rectangle with width: " << width_ << ", height: " << height_
                  << " and area: " << area() << std::endl;
    }

private:
    double width_, height_;
};

int main() {
    // Creating objects of derived classes
    Shape* shapes[2];
    shapes[0] = new Circle(5.0);
    shapes[1] = new Rectangle(4.0, 6.0);

    // Using polymorphism to call the appropriate print function
    for (int i = 0; i < 2; ++i) {
        shapes[i]->print();
    }

    // Clean up dynamically allocated memory
    for (int i = 0; i < 2; ++i) {
        delete shapes[i];
    }

    return 0;
}
