#include "Shape.h"
#include <stdexcept>

Shape::Shape() : color("red") {}

Shape::Shape(std::string c) {
    validate_color(c);
    color = c;
}

void Shape::validate_color(const std::string& c) {
    if (c != "red" && c != "green" && c != "blue") {
        throw std::invalid_argument("Color inválido. SOlo se puede: red, green, blue.");
    }
}

std::string Shape::get_color() const {
    return color;
}

void Shape::set_color(std::string c) {
    validate_color(c);
    color = c;
}

Shape::~Shape() {}
