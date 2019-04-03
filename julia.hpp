#ifndef JULIA_HPP
	#define JULIA_HPP
	#include <opencv2/core/core.hpp>
	#include <opencv2/highgui/highgui.hpp>

	float pix_nb(float x, float y);
	cv::Mat filtre(cv::Mat image,int w, int h, float zoom);
	void creat_f (GSImage& image, std::vector<float> vec);
#endif
