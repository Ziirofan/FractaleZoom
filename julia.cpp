// filtrage.cpp

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <complex>
#include "GSImage.hpp"
#include "julia.hpp"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>


/*
 *cv::Mat::convertTo(outarry,int rtype(-1),scale factor );
 *cv::Mat::copyTo(mat);
 *  *(mat.data +offset)=value
 * */


float pix_nb(float x, float y){
	//std::cout << x << "  " << y << "\n";
	std::complex<float> myc(-0.5f,0.64f);
	std::complex<float> z(x,y);
	float borne = 10.f;
	int nb_test = 40;
	//std::cout << "debut boucle" << "\n";
	for(int i = 0; i<nb_test;i++){
		//std::cout << norm(z) << "\n";
		if(norm(z)>borne)
			return powf(float(i)/nb_test,0.5f);
		z=z*z+myc;
	}
	return 0.f;
}

cv::Mat filtre(cv::Mat image,int w, int h, float zoom) {
    float filtered_row[w];
	//float filtered_row255[image.w()];
	auto temp =0.0f;
    for(int r = 0; r < h; ++r) {
		float y = (float(r)-h/2) /h*zoom;
		//float* row = 255.0f + r * w;
		//float* row255 = image.pixels() + r * image.w();
        for(int c = 1; c < w - 1; ++c) {
			float x=(float(c)-w/2) /w*zoom;
			//std::cout << pix_nb(float(r),float(c)) << "\n";
			temp=pix_nb(x,y);
			//std::cout << temp << "\n";
            image.row = temp;
			//std::cout << temp*255.0f << "\n";
			//filtered_row255[c]= temp*255.0f;
        }
        //std::copy(filtered_row, filtered_row + image.w(), row);
        //std::copy(filtered_row255, filtered_row255 + image.w(), row255);
		
    }
	return image;
}

void creat_f (GSImage& image, std::vector<float> vec){
	int size=image.h()*image.w();
	for(int i = 0;i<size;i++){
		int j=i*4;
		if (j > size)
			continue;
		vec[j]=255.0f;
		vec[j+1]=vec[j+2]=vec[j+3]=image.pixels()[i]*255.0f;
	}

}


