#include <complex>
#include <cmath>
#include <iostream>
#include <thread>
#include <omp.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include "julia.hpp"


bool thread;


int main(void){
	
	cv::Mat matrice_im(W,H,CV_8UC3);
	run_julia(matrice_im,2,0.05);

	return 0;
}
