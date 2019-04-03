/**
 * MAIN.C
 *
 * */


#include <iostream>
#include <vector>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "GSImage.hpp"
#include "julia.hpp"


#define H 800
#define W 1500
using namespace cv;

void on_error(char const* executable) {
    std::cout << "usage: " << executable << " source_file.png target_file.png\n";
    exit(1);
}

int main(int argc, char const* argv[]) {



    GSImage image("image.png");
	
	std::cout << " image " << image.h() << " "<< image.w() <<"\n";
	int size = image.w()*image.h();
	std::vector<float> vpix;
	vpix.resize(size);

    /*
     * Application des filtres à l'image découper en 4 vues 
     * */

    /*filtre(image.view(0,0,image.w()/2,image.h()/2));
    filtre(image.view(image.w()/2,0,image.w()/2,image.h()/2));
    filtre(image.view(0,image.h()/2,image.w()/2,image.h()/2));
    filtre(image.view(image.w()/2,image.h()/2,image.w()/2,image.h()/2));
    */

    /*std::vector<std::future<void>> futResults;
    futResults.push_back(std::async(std::launch::async,filtre,image.view(0,0,image.w()/2,image.h()/2)));
    futResults.push_back(std::async(std::launch::async,filtre,image.view(image.w()/2-1,0,image.w()/2,image.h()/2)));
    futResults.push_back(std::async(std::launch::async,filtre,image.view(0,image.h()/2,image.w()/2,image.h()/2)));
    futResults.push_back(std::async(std::launch::async,filtre,image.view(image.w()/2,image.h()/2,image.w()/2,image.h()/2)));
    image.save_png(argv[2]);

    for_each(futResults.begin(), futResults.end(), [](auto& x) { return x.get(); });*/
	//float imap[size]={0};
	//std::cout << image.pixels()[1002]*255.0f << "\n";
	float i = 2.0f;
	int u = 1;
	Mat imag(W,H,CV_8UC3);
	Mat d(W,H,CV_8UC3);
	for(;i>0;i-=0.05f){
		d=filtre(imag,W,H,i);
		//std::cout << image.pixels()[u] << "\n";
		//u+=10;
		//creat_f(image,vpix);
		//for(int j = 0; j<size-1;j++){
		//	vpix[j]=image.pixels()[j]*255.0f;
		//}
		imshow("r",d);
      char key = (char)waitKey(1);
      if(key == 'q' || key == 'Q' || key == 27)
          break;

	}
    return 0;
}
