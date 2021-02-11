#include <fstream>
#include <dirent.h>

#include <iostream>
#include <cstdlib>

#include <cmath> // Esta librería contiene las funciones para realizar operaciones matemáticas (sin, cos, tan, log, exp, etc.)
#include <ctime>
#include <vector>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/video/video.hpp>
#include <opencv2/videoio/videoio.hpp>
#include <opencv2/imgcodecs/imgcodecs.hpp>
#include <opencv2/objdetect/objdetect.hpp> 
//Librerias del descriptor
#include <opencv2/xfeatures2d/nonfree.hpp>
#include <opencv2/features2d/features2d.hpp>


#pragma once

using namespace std;
using namespace cv;

class Prueba{
    private:

		Mat background;
		Mat getForegroundMask(Mat input);
		void removeBackground(Mat input, Mat background);	
        //int *LBP8(const int*, int, int );
        
        Scalar color_blue;
		Scalar color_green;
		Scalar color_red;
		Scalar color_black;
		Scalar color_white;
		Scalar color_yellow;
		Scalar color_purple;
		
		double findPointsDistance(Point a, Point b);
		vector<Point> compactOnNeighborhoodMedian(vector<Point> points, double max_neighbor_distance);
		double findAngle(Point a, Point b, Point c);
		bool isFinger(Point a, Point b, Point c, double limit_angle_inf, double limit_angle_sup, cv::Point palm_center, double distance_from_palm_tollerance);
		vector<Point> findClosestOnX(vector<Point> points, Point pivot);
		double findPointsDistanceOnX(Point a, Point b);
		void drawVectorPoints(Mat image, vector<Point> points, Scalar color, bool with_numbers);
        //void performOpening(Mat binaryImage, int structuralElementShapde, Point structuralElementSize);
	   

        Rect skinColorSamplerRectangle1, skinColorSamplerRectangle2;
        void calculateThresholds(Mat sample1, Mat sample2);
		void performOpening(Mat binaryImage, int structuralElementShapde, Point structuralElementSize);
        
    public:
		
		Prueba(void);
        //Mat conversorCIELab(Mat);
        void calibrate(Mat input);
		void calibrate1(Mat input);
		Mat getForeground(Mat input);
        void removeFaces(Mat input, Mat output);
		Mat bordes(Mat i);
        //Operaciones(void);
        //void FaceDetector(void);
        //void FingerCount(void);
        Mat findFingersCount(Mat input_image, Mat frame);
        void drawSkinColorSampler(Mat input);
        Mat getSkinMask(Mat imput);

		int hLowThreshold = 0;
		int hHighThreshold = 0;
		int sLowThreshold = 0;
		int sHighThreshold = 0;
		int vLowThreshold = 0;
		int vHighThreshold = 0;
		bool calibrated = false;
		bool calibrated1 = false;


		double alpha1;
		double alpha2;
		double alpha3;
		double alpha4;
		double alpha5;
		double alpha6;
		double alpha7;
		double alpha8;
		double alpha9;
		double alpha10;
		double alpha11;
		double alpha12;

};
