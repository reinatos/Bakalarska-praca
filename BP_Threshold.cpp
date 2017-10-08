#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"

#include <iostream>
#include <stdlib.h>

cv::Mat src;
cv::Mat dst;

int threshold_value=200;
int threshold_type=0;
int const max_value = 255;

int main() {
	src = cv::imread("ID.jpg",0);	//Input image

	//exception
	if (src.empty()) {                                  
		std::cout << "error: image not read from file\n\n";       
		system("pause");
		return(0);                                              
	}

	//show original image
	cv::namedWindow("ID_original", CV_WINDOW_AUTOSIZE);
	cv::imshow("ID_original", src);

	//Threshold
	cv::threshold(src, dst, threshold_value, max_value, threshold_type);

	//show finished image
	cv::namedWindow("ID_Finished", CV_WINDOW_AUTOSIZE);
	cv::imshow("ID_Finished", dst);

	//saved finished image
	cv::imwrite("ID_finished.jpg", dst);
	return 0;
}
