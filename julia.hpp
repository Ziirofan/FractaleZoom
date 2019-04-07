#ifndef JULIA_HPP
#define JULIA_HPP

#include <thread>
#include <iostream>

#define W 700
#define H 700

class Julia2 : public std::thread{
	public:
		Julia2(){}
	public:
		static void julia(cv::Mat mi,float resize, float d, int w, int h){
			float x1 = -1.5-resize, x2 = 1.5+resize, y1 = -1.2-resize, y2 = 1.2+resize;
			int ite_max = 100;
			if(d<0.2)
				ite_max = 200;
			if(d<0.1)
				ite_max = 300;
			if(d<0.05)
				ite_max = 500;
			if(d<0.03)
				ite_max = 700;
			int imageX = /*(x2-x1)*zoom;*/w;
			int imageY = /*(y2-y1)*zoom;*/h;

			float zoomX = imageX /(x2 - x1);
			float zoomY = imageY /(y2 - y1);
			//std::cout << imageX <<"\n"<< imageY <<"\n"<<zoomX<<"\n"<<zoomY<<"\n";
			//zoomX*=d;
			//zoomY*=d;
			
			#pragma omp parallel for
			for(int x = 0; x < imageX; x++){
				for(int y= 0;y<imageY;y++){
					bool is_julia=false;
					
					double jx = (x / /*zoom*/(double)zoomX + x1)*d;
					double jy = (y / /*zoom*/(double)zoomY + y1)*d;
					std::complex<float> c(-0.4f, 0.59f);
					std::complex<float> a(jx,jy);
					int ite = 0;
					for (ite = 0; ite < ite_max; ite++) {
						a = a*a + c;
						//mut.lock();

						if (std::abs(a) > 500) {
							is_julia= false;
							break;
						}
						else
							is_julia = true;
						}
						//std::cout << abs(a) << "\n";
						if(is_julia){
						//*(mi.data + offset) = cv::Scalar(255,2,255);
						mi.at<cv::Vec3b>(y,x)[0] = 0;
						mi.at<cv::Vec3b>(y,x)[1] = 0;
						mi.at<cv::Vec3b>(y,x)[2] = ite*255/ite_max;
						//std::cout << ite*255/ite_max << "\n" << ite*(255/ite_max)<<"\n";
						}
						else{
						mi.at<cv::Vec3b>(y,x)[0] = 0;
						mi.at<cv::Vec3b>(y,x)[1] = 0;
						mi.at<cv::Vec3b>(y,x)[2] = 0;

						}
							
						//mut.unlock();
				}
			}
		}
};

void run_julia(cv::Mat image, float zoom_Max, float pas);


#endif
