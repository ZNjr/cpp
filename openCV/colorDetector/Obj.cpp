#include "Obj.h"
	Object::Object(vector<Point>countours, Point center) :countours(countours),centerPoint(center)
	{}

	Point Object::getCenter() {
		return centerPoint;
	}