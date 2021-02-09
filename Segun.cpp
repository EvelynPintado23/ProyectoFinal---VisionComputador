#include <stdio.h>
#include <string.h>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

void on_trackbar( int, void* ){}

int main(){
	/// Create Windows
	string win1 = "HSV";
	namedWindow(win1, 0);
	namedWindow("1", 0);
	namedWindow("2", 0);

	/// Create Trackbars
	int H_low,H_high;
	int S_low,S_high;
	int V_low,V_high;
	const int Hmax = 255;
	const int Smax = 255;
	const int Vmax = 255;
	createTrackbar( "H_low", win1, 	&H_low, Hmax, on_trackbar);
	createTrackbar( "H_high", win1, &H_high, Hmax, on_trackbar);
	createTrackbar( "S_low", win1, 	&S_low, Smax, on_trackbar);
	createTrackbar( "S_high", win1, &S_high, Smax, on_trackbar);
	createTrackbar( "V_low", win1, 	&V_low, Vmax, on_trackbar);
	createTrackbar( "V_high", win1, &V_high, Vmax, on_trackbar);
	setTrackbarPos("H_low",	win1,0);
	setTrackbarPos("H_high",win1,0);
	setTrackbarPos("S_low",	win1,0);
	setTrackbarPos("S_high",win1,0);
	setTrackbarPos("V_low",	win1,0);
	setTrackbarPos("V_high",win1,0);
    
    VideoCapture cap(0);
    Mat image;

    while(true)
    {
        cap >> image; // get a new frame from camera
        blur(image, image, Size(10,10));
        imshow( "1", image);    
        cvtColor(image, image, cv::COLOR_BGR2HSV); 
        inRange(image, Scalar(H_low,S_low,V_low), Scalar(H_high,S_high,V_high), image);
        imshow( "2", image);                   // Show our image inside it.
        int c;
        c = waitKey(1);
        if( (char)c == 27 ){ break; }
    }
    return 0;
}