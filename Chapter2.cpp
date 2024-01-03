#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

/// <summary>
/// This is a basic functions program of opencv
/// </summary>
/// <returns></returns>
int main()
{
	string path = "Resources/crown.jpg";
	Mat img, imgGray, imgBlur, imgEro, imgCanny, imgDilate;
	img = imread(path);
	// CONVERTING TO GRAYSCALE
	cvtColor(img, imgGray, COLOR_BGR2GRAY);
	// USING GUASSIAN BLUR TO BLUR AN IMAGE
	GaussianBlur(img, imgBlur, Size(7, 7), 5, 0);
	// EDGE DETECTION 
	Canny(imgBlur, imgCanny, 50, 150);
	// DILATING AND ERODING AN EDGE IN AN IMAGE (Thickness of the edge)
	Mat kernel = getStructuringElement(MORPH_RECT, Size(5, 5));
	dilate(imgCanny, imgDilate, kernel);
	erode(imgCanny, imgEro, kernel);

	imshow("Image", img);
	//imshow("Imagegray", imgGray);
	//imshow("Imageblur", imgBlur);
	//imshow("imageCanny", imgCanny);
	imshow("Image Dialation", imgDilate);
	imshow("image Erode", imgEro);
	waitKey(0);
	return 0;
}