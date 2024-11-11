#ifndef SHAPE_H
#define SHAPE_H

#include <string>
#include <stdexcept>

class Shape {
protected:
    std::string color;

    void validate_color(const std::string& c);

public:
    Shape();
    Shape(std::string c);

    std::string get_color() const;
    void set_color(std::string c);

    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual void translate(double incX, double incY) = 0;
    virtual void print() = 0;

    virtual ~Shape();
};

#endif
