#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

/* Commande d'éxécution
 * g++ opcv2.cpp `pkg-config --cflags --libd opencv`
 */

using namespace cv;
using namespace std;


int main(void){

    //string arg = argv[1];
    //VideoCapture sequence(arg);
    Mat image;
	//sequence >> image;
	/*
	 * Opencv:
	 * fonctionne sur des principes similaire à scilab en image
	 * on créer des matrice (couleur, etc)
	 * ensuite la fonction imshow se charge de l'afficher.
	 */
	Mat image1(320,320, CV_8UC3, Scalar(0,0,255));
	Mat image2(320,320, CV_8UC3, Scalar(0,255,0));
	int i = 0;
    for(;;){
	Mat imag(320,320, CV_64FC4, Scalar(0,0,i));
	Mat s;
	if(i%2 == 0)
		s=image1;
	else
		s=image2;
	
	imshow("image | q or esc to quit", s);
	i++;
      char key = (char)waitKey(5);
      if(key == 'q' || key == 'Q' || key == 27)
          break;
    }

    return 0;
}
