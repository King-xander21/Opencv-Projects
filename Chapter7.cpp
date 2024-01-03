#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

Mat img, imgGray, imgBlur, imgCanny, imgDil, imgErode;

void getContours(Mat imgDil, Mat img)
{
	vector<vector<Point>> contours;
	// The hierarchy is a vector data type consisting of four integer values
	vector<Vec4i> hierarchy;

	findContours(imgDil, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
	/*drawContours(img, contours, -1, Scalar(255, 0, 255), 2);*/

	vector<vector<Point>> conPoly(contours.size());

	for (int i = 0; i < contours.size(); i++)
	{
		int area = contourArea(contours[i]);
		cout << area << "\n\n";
		if (area > 1000)
		{
			float peri = arcLength(contours[i], true);
			approxPolyDP(contours[i], conPoly[i], 0.02 * peri, true);
			drawContours(img, conPoly, i, Scalar(255, 0, 255), 2);
			cout << conPoly[i].size() << "\n\n";
		}
	}
}

int main()
{
	string path = "Resources/shapes.png";
	img = imread(path);

	cvtColor(img, imgGray, COLOR_BGR2GRAY);
	// USING GUASSIAN BLUR TO BLUR AN IMAGE
	GaussianBlur(img, imgBlur, Size(3, 3), 3, 0);
	// EDGE DETECTION 
	Canny(imgBlur, imgCanny, 25, 75);
	// DILATING AND ERODING AN EDGE IN AN IMAGE (Thickness of the edge)
	// DILATING AND ERODING AN EDGE IN AN IMAGE (Thickness of the edge)
	Mat kernel = getStructuringElement(MORPH_RECT, Size(5, 5));
	dilate(imgCanny, imgDil, kernel);

	getContours(imgDil, img);

	imshow("Images", img);
	//imshow("images BLUR", imgBlur);
	//imshow("images CANN", imgCanny);
	// 
	//imshow("images ERODE", imgGray);
	imshow("images DILL", imgDil);
	waitKey(0);
	return 0;
}