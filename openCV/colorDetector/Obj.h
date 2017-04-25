#pragma once
#include <opencv2\highgui.hpp>
#include <opencv2\imgproc.hpp>
#include <iostream>
#include <conio.h>
#include <cmath>
#include <string>
using namespace std;
using namespace cv;

class Object {
public:

	Object(vector<Point>countours, Point center);
	Point getCenter();
	vector<Point> countours;
	
private:
	Point2f centerPoint;
};