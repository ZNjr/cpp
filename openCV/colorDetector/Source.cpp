#define _USE_MATH_DEFINES
#include <opencv2\highgui.hpp>
#include <opencv2\imgproc.hpp>
#include <iostream>
#include <conio.h>
#include <cmath>
#include <string>
#include <time.h>
#include "Obj.h"
using namespace std;
using namespace cv;


void drawCord(Mat* image, Point2f center) {
	circle(*image, center, 20, Scalar(10, 10, 10), 1, 8, 0);
	Point textCenter = Point(center.x + 20, center.y);
	putText(*image, "(" + to_string((int)center.x) + "," + to_string((int)center.y) + ")", textCenter, FONT_HERSHEY_SIMPLEX, 0.3, (0, 0, 0));
}

int main() {
	Mat image;
	VideoCapture cap;
	
	Mat imageHSV,range;

	int colors[2][6] = { { 27, 99, 55, 38, 332, 257},
						 {100,106,31,150,269,269}};
		
	cap.open(0);
	
	namedWindow("window", CV_WINDOW_AUTOSIZE);
	namedWindow("HSV", CV_WINDOW_AUTOSIZE);
	namedWindow("range", CV_WINDOW_AUTOSIZE);
	namedWindow("trackbar", CV_WINDOW_AUTOSIZE);

	int min_H = 27;
	int max_H = 38;
	int min_S = 99;
	int max_S = 332;
	int min_V = 55;
	int max_V = 257;

	createTrackbar("min_H", "trackbar", &min_H, 400);
	createTrackbar("max_H", "trackbar", &max_H, 400);
	createTrackbar("min_S", "trackbar", &min_S, 400);
	createTrackbar("max_S", "trackbar", &max_S, 400);
	createTrackbar("min_V", "trackbar", &min_V, 400);
	createTrackbar("max_V", "trackbar", &max_V, 400);

	int frame = 0;
	int j = 0;
	clock_t time_end;
	time_end = clock() + 5000 * CLOCKS_PER_SEC / 1000;
	while (clock() < time_end)
	while (1) {
		if (clock() > time_end) {
			j++;
			time_end = clock() + 5000 * CLOCKS_PER_SEC / 1000;
		}
		cap.read(image);
		cvtColor(image, imageHSV, COLOR_BGR2HSV);
		imshow("HSV", imageHSV);
		int k = j % 2;
		inRange(imageHSV, Scalar(colors[k][0], colors[k][1], colors[k][2]), Scalar(colors[k][3], colors[k][4], colors[k][5]), range);
		erode(range, range, Mat(), Point(-1, 1), 2, 1, 1);
		erode(range, range, Mat(), Point(-1, 1), 2, 1, 1);
		dilate(range, range, Mat(), Point(-1, 1), 2, 1, 1);
		dilate(range, range, Mat(), Point(-1, 1), 2, 1, 1);
		
		imshow("range", range);
		
		vector<vector<Point>> contours;
		vector<Vec4i> hierarchy;
		vector<Object> obj;

		findContours(range, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0));
		vector<Moments>mm(contours.size());
		
		for (int i = 0;i < contours.size();i++) {
			Moments moment = moments(contours[i]);
			Object tmp = Object(contours[i], Point2f(moment.m10 / moment.m00, moment.m01 / moment.m00));
			obj.push_back(tmp);
		}

		Mat drawing = Mat::zeros(range.size(), CV_8UC3);
		
		RNG rng(12345);
		for (int i = 0;i < obj.size();i++) {
			Scalar color = Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
			drawContours(drawing, contours, i, color, 2, 8, hierarchy, 0, Point());
		}

		int nOcountorus = obj.size();
		int nOFullCountours = 0;
		for (int i = 0;i < obj.size();i++) {
			if (contourArea(obj[i].countours) > 2000 && contourArea(obj[i].countours) < 5000) {
				nOFullCountours++;
				drawCord(&image, obj[i].getCenter());
			}
		}

		if (nOcountorus > nOFullCountours+1) {
			putText(image, "Zmien wartosci", Point(40,60), FONT_HERSHEY_SIMPLEX, 1.5, (243, 29, 0));
			for (int i = 0;i < obj.size();i++)
				if (!(contourArea(obj[i].countours) > 2000 && contourArea(obj[i].countours) < 5000)) {
					drawCord(&image, obj[i].getCenter());
				}
			}
		
		imshow("d", drawing);
		imshow("window", image);
		
		if(waitKey(15) == 27) {
			break;
		}
	}
	cap.release();
	cvDestroyAllWindows();
}


