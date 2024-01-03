#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;


/// <summary>
///  warping images
/// </summary>
/// <returns></returns>
int main()
{
	string path = "Resources/cards.png";
	Mat img = imread(path);
	float w = 250, h = 350;
	Mat imgWarp;
	// Declaring the array to hold the points of the desired image
	Point2f src[4] = {
		//{317,85}, // top left
		//{241,236}, // bottom left
		//{459,117}, // top right
		//{403,272} // bottom right
	
		{317,85}, // top left
		{459,117}, // top right
		{236,241}, // bottom left
		{403,272} // bottom right
	};

	// Declaring the points where the image would be displayed
	Point2f dst[4] = {
		{0.0f,0.0f}, // top left
		{w,0.0f}, // bottom left
		{0.0f,h}, // top right
		{w,h} // bottom right
	};

	// Using a transformation matrix to proccess the inputs
	Mat matrix = getPerspectiveTransform(src, dst);
	warpPerspective(img, imgWarp, matrix, Point(w, h));

	for (int i = 0; i < 4; i++)
	{
		circle(img, src[i], 5, Scalar(0, 0, 255), 4);
		circle(imgWarp, dst[i], 5, Scalar(0, 0, 255), 4);
	}

	imshow("Cards", img);
	imshow("Cards2", imgWarp);
	waitKey(0);
	return 0;
}