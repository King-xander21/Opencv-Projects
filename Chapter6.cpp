#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;


int main()
{
	int hmin = 0, hmax = 19;
	int smin = 110, smax = 240;
	int vmin = 153, vmax = 255;
	string path = "Resources/shapes.png";
	Mat imgHSV, /*lower, upper, */ mask;
	Mat img;
	img = imread(path);
	
	// Creating an HSV image from the original image
	cvtColor(img, imgHSV, COLOR_BGR2HSV);
	namedWindow("Trackbars", (640, 200));
	createTrackbar("Hue min", "Trackbars", &hmin, 179);
	createTrackbar("Hue max", "Trackbars", &hmax, 179);
	createTrackbar("Sat min", "Trackbars", &smin, 255);
	createTrackbar("Sat max", "Trackbars", &smax, 255);
	createTrackbar("Val min", "Trackbars", &vmin, 255);
	createTrackbar("Val max", "Trackbars", &vmax, 255);

	while (true) 
	{
		Scalar lower(hmin, smin, vmin);
		Scalar upper(hmax, smax, vmax);
		inRange(imgHSV, lower, upper, mask);

		imshow("Labmo", img);
		//imshow("Lambo2", imgHSV);
		imshow("Lambo mask", mask);
		waitKey(1);
	}


	return 0;
}