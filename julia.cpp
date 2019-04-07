#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include "julia.hpp"

void run_julia(cv::Mat image, float zoom_Max, float pas){
	Julia2 rendu;
	cv::VideoWriter video("outcpp.avi",CV_FOURCC('M','J','P','G'),5, cv::Size(W,H));
	for(float i = zoom_Max; i > 0; i=i-pas){
		rendu.julia(image,i,i,W,H);
		//imshow("FRACTALE",image);
		video.write(image);

		char key = (char)cv::waitKey(10);
		if(key == 'q' || key == 'Q' || key == 27)
			break;
	}
	video.release();
	cv::destroyAllWindows();
}
