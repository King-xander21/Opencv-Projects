#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>	

using namespace std;
using namespace cv;

///////// Resizing and croping an image

int main()
{
	string path = "Resources/crown.jpg";
	Mat img, imgRes, imgCrop;
	img = imread(path);
	// Resizing images
	resize(img, imgRes, Size(640, 220));// Its a terrible outcome image btw!!!
	resize(img, imgRes, Size(),0.5,0.5);// Resizing the image by half. Now thats a nice scale.
	//[720 x 480]
	//cout << img.size() << "\n\n\n";

	// Croping images
	// The croped part of an image in opencv is called and roi(Region Of Intrest)
	Rect ROI(100, 100, 300, 250); // Defining the roi(The points and the dimensions)
	imgCrop = img(ROI);

	imshow("Image", img);
	//imshow("Image", imgRes);
	imshow("ImageCrop", imgCrop);
	waitKey(0);
	return 0;
}