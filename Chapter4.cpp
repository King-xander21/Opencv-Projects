#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;


/// <summary>
/// Drawing shapes and texts
/// </summary>
/// <returns></returns>
int main()
{
	// Creating a blank image
	Mat img(512, 512/*Size*/, CV_8UC3 /*TYPE*/, Scalar(255, 255, 255)/*BLUE, GREEN, RED*/);
	
	// Creating a circle
	circle(img, Point(256, 256), 155, Scalar(0, 69, 255), FILLED/*thickness*/);
	//  Creating a rectangle
	rectangle(img, Point(130,226), Point(382, 286), Scalar(255,255,255), FILLED/*3 thickness*/);
	// Creating a line
	line(img, Point(130, 296), Point(382, 296), Scalar(255, 255, 255), 2);
	// Adding text
	putText(img, "Xander's Workshop", Point(137, 262), FONT_HERSHEY_DUPLEX, 0.75, Scalar(0,69, 255), 2);

	imshow("Blank image", img);
	waitKey(0);
	return 0;
}