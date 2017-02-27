#include <opencv2\highgui\highgui.hpp>
#include "opencv2\imgproc\imgproc.hpp" 

#include <iostream>
#include <conio.h>

using namespace std;
using namespace cv;

int main() {
	Mat image,grey,edge;
	VideoCapture cap;

	cap.open("mv.avi");
	namedWindow("window", CV_WINDOW_NORMAL);
	namedWindow("grey", CV_WINDOW_NORMAL);
	namedWindow("edge", CV_WINDOW_NORMAL);
	resizeWindow("window", 300, 150);
	resizeWindow("grey", 300, 150);
	resizeWindow("edge", 300, 150);

	double dWidth = cap.set(CV_CAP_PROP_FRAME_WIDTH,640);
	double dHeight = cap.set(CV_CAP_PROP_FRAME_HEIGHT,480);
	
	while (1){
		cap.read(image);
		cvtColor(image, grey, CV_RGB2GRAY);
		Canny(image, edge, 50, 150, 3);
		imshow("window", image);
		imshow("grey", grey);
		imshow("edge", edge);
		
		if (waitKey(15) == 27){
			break;
		}
	}

}
