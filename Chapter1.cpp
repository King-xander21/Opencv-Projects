#include <opencv2/imgproc.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

////////////// Importing images
//
//int main()
//{
//	string path = "Resources/batman.jpg";
//	Mat img = imread(path);
//	imshow("Image", img);
//	waitKey(0);
//	return 0;
//}


///////////// Importing videos
int main()
{
	string path = "resources/download.mp4";
	VideoCapture cap(path);
	if (!cap.isOpened())
	{
		cout << "Error opening the video file\n";
		return -1;
	}

	while (true)
	{
		Mat img;
		//cap >> img;
		cap.read(img);
		if (img.empty())
		{
			break;
		}
		imshow("image", img);
		//cap.read(img);
		waitKey(10);		
	}
	cap.release();
	destroyAllWindows();

	return 0;
}


//int main()
//{
//	//string path = "Resources/download(3).mp4";
//	VideoCapture cap(0);
//	Mat img;
//
//
//	for (int i = 0; i <= 100; i++)
//	{
//		cap.read(img);
//		imshow("Image", img);
//		waitKey(1);
//	}
//}