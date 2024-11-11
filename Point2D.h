#ifndef POINT2D_H
#define POINT2D_H

#include <ostream>
#include <cmath>

class Point2D{
	public:
		double x;
		double y;
	public:
		Point2D(double x=0, double y=0){}

		static double distance(const Point2D &a, const Point2D &b){
			double dx = b.x - a.x;
			double dy = b.y - a.y;
			return std::sqrt(dx * dx + dy * dy);	
		}

		friend bool operator==(const Point2D &a, const Point2D &b);   
		friend bool operator!=(const Point2D &a, const Point2D &b);
		friend std::ostream& operator<<(std::ostream &out, const Point2D &p);
};

	bool operator==(const Point2D &a, const Point2D &b){
		if (b.x == a.x && b.y == a.y){
		       return true;
	        } else {
			return false;//sin necesidad de if por ser tipo bool
	 	}
	}		
	
	bool operator!=(const Point2D &a, const Point2D &b){
		return (b.x != a.x) || (b.y != a.y);
	} 

	std::ostream& operator<<(std::ostream &out, const Point2D &p){
		out << "Point2D(" << p.x << "," << p.y << ")" << std::endl;
		return out;
	}

#endif
