#include "Point2D.h"

Point2D::Point2D(double x, double y) : x(x), y(y) {}

double Point2D::distance(const Point2D &a, const Point2D &b) {
    double dx = b.x - a.x;
    double dy = b.y - a.y;
    return std::sqrt(dx * dx + dy * dy);    
}

bool operator==(const Point2D &a, const Point2D &b) {
    return (a.x == b.x && a.y == b.y);
}

bool operator!=(const Point2D &a, const Point2D &b) {
    return !(a == b);
}

std::ostream& operator<<(std::ostream &out, const Point2D &p) {
    out << "Point2D(" << p.x << ", " << p.y << ")";
    return out;
}




