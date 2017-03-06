#include <opencv2\highgui\highgui.hpp>
#include "opencv2\imgproc\imgproc.hpp" 

#include <iostream>
#include <conio.h>
#include <time.h>

using namespace std;
using namespace cv;

int main() {
	Mat image,grey,mv;
	VideoCapture cap,cap2;
	vector<int> compression_param;
	compression_param.push_back(CV_IMWRITE_JPEG_QUALITY);
	compression_param.push_back(100);
	cap.open(0);
	cap2.open("mv.avi");
	namedWindow("window", CV_WINDOW_NORMAL);
	namedWindow("mv", CV_WINDOW_NORMAL);
	resizeWindow("window", 300, 150);
	resizeWindow("mv", 300, 150);

	double dWidth = cap.set(CV_CAP_PROP_FRAME_WIDTH,640);
	double dHeight = cap.set(CV_CAP_PROP_FRAME_HEIGHT,480);
	
	cout << "fps:" << cap2.get(CV_CAP_PROP_FPS) << endl;
	
	int imgNumber = 0;

	Size frameSize(dWidth, dHeight);
	
	VideoWriter writer("out.avi", CV_FOURCC('3', 'I', 'V', 'D'), 20, frameSize, true);
	
	clock_t time;
	time = clock() + 50;

	while(1){
		cap.read(image);
		cap2.read(mv);
		cvtColor(image, grey, COLOR_BGR2GRAY);

		for (int x = 0;x < grey.rows;x++) {
			for (int y = 0;y < grey.cols;y++) {
				grey.at<uchar>(x, y) = 255 - grey.at<uchar>(x, y);
			}
		}
		
		imshow("window", grey);
		imshow("mv", mv);
		writer.write(grey);
		
		int key = waitKey(15);
			if (key == 27) break;
				if (clock() > time && imgNumber < 20) {
					imwrite("zdj_0" + to_string(imgNumber) + ".jpg", grey, compression_param);
					imwrite("mv_0" + to_string(imgNumber) + ".jpg", mv, compression_param);
					imgNumber++;
				}
			}	
		}
