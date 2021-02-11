#include "Principal.hpp"

using namespace cv;
using namespace std;
//CascadeClassifier face_cascade;  // Para rostros
//CascadeClassifier eyes_cascade; // Para ojos
 Mat binarizada;
 Mat hsv;
 //int hMin=10, sMin=11, vMin=121, hMax=30, sMax=255, vMax=255;
 int cont=0;

int v=0;
void on_trackbarHmin( int , void *) {
    
    // Creamos el structring element (que puede ser una cruz, un rectángulo o una elipse):
    // MORPH_CROSS, MORPH_RECT, MORPH_ELLIPSE
    //Mat elemento = getStructuringElement(MORPH_CROSS, Size(alpha_slider+1,alpha_slider+1), Point(-1,-1));
    // Aplicamos la operación de dilatación
    //morphologyEx(imagen, frame, MORPH_DILATE,elemento);
    //inRange(prueba, Scalar(1,1,1), Scalar(100,100,100), hsv);
    /*
    Mat elemento = getStructuringElement(MORPH_CROSS, Size(alpha_slider_max5-alpha_slider5+1,alpha_slider_max5-alpha_slider5+1), Point(-1,-1));
     // Aplicamos la operación de erosión
    cvtColor(hsv, hsv, COLOR_BGR2HSV);
    GaussianBlur(hsv, hsv, Size(9,9),2,2);
    morphologyEx(hsv, hsv, MORPH_TOPHAT,elemento);
*/
}

int main(int, char**) {

    Mat frameOut, handMask, foreground, fingerCountDebug;
    Prueba skinDetector, backgroundRemover, faceDetector, fingerCount;
    Prueba num, detector;
    Mat binarizada;
    Mat imagen_nueva;
    Mat bordes;
    Mat elementoBorrarPuntos = getStructuringElement(MORPH_CROSS, Size(9,9), Point(-1,-1));
    Mat elementoInundar = getStructuringElement(MORPH_ELLIPSE, Size(7, 7), Point(-1,-1));

    //namedWindow("Original", WINDOW_AUTOSIZE);
    //namedWindow("output", WINDOW_AUTOSIZE);
    //namedWindow("foreground", WINDOW_AUTOSIZE);
    //namedWindow("handMask", WINDOW_AUTOSIZE);
    namedWindow("handDetection", WINDOW_AUTOSIZE);

	VideoCapture videoCapture(0);

    if(videoCapture.isOpened()){

        Mat frame;
    
        while (3==3) {

            videoCapture >> frame;

            resize(frame, frame, Size(), 0.8,0.8);
            //cout << frame.rows << "||" << frame.cols << endl;
            
            cvtColor(frame, hsv, COLOR_BGR2HSV);
            //inRange(hsv,Scalar(hMin,sMin,vMin),Scalar(hMax,sMax,vMax),binarizada);

            frameOut = frame.clone();
            detector.drawSkinColorSampler(frameOut);
            foreground = detector.getForeground(hsv);
            detector.removeFaces(hsv, foreground);
            handMask = detector.getSkinMask(foreground);
            
            Mat bordes = imread("borde.png",CV_LOAD_IMAGE_GRAYSCALE);
            resize(bordes,bordes,Size(),2.15,2.15);
            Canny(bordes, bordes, 50, 150, 3);

            flip(frame,frame,1);
            imagen_nueva = detector.bordes(frame);
            imshow("Imagen", imagen_nueva);
            fingerCountDebug = detector.findFingersCount(imagen_nueva, frameOut); 
            
            
            //inRange(hsv, Scalar(1,1,1), Scalar(100,100,100), hsv);
            
            /*resize(hsv, hsv, Size(), 0.5,0.5);
            cout << hsv.rows << "||" << hsv.cols << endl;
            
            cvtColor(hsv, hsv, COLOR_BGR2HSV);
            inRange(hsv,Scalar(alpha_slider1,11,121),Scalar(30,255,255),prueba);           
            */
            int key = waitKey(1);

            if (key == 27) // esc
                break;
            else if (key == 98) // b
                detector.calibrate1(hsv);
            else if (key == 115) // s
                detector.calibrate(hsv);
            else if (key == 99) // c
                imwrite("patrones"+to_string(cont)+".png",frameOut);
                cont++;

            //imshow("Original", hsv);
            //imshow("handMask", handMask);
            imshow("handDetection", fingerCountDebug);
            //imshow("output", frameOut);
            //imshow("foreground", foreground);
            //
        }

        videoCapture.release();
        destroyAllWindows();
        return 0;
        
    }

}
