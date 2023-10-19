#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

#define WIN_WIDTH 1074
#define WIN_HEIGHT 1080

int main()
{
	char character = 0;
	char currentBit = 1;

	Mat img = imread("blackimage_encoded.png", IMREAD_COLOR);


	for (unsigned int y = 10; y <= img.cols; y += 10) {
		currentBit = 1;
		for (unsigned int x = 10; x <= 70; x += 10) {
			Vec3b& pixel = img.at<Vec3b>(x, y);
			if (pixel.val[0] == 255 && pixel.val[1] == 255 && pixel.val[2] == 255) {

				character += currentBit;
			}
			currentBit = currentBit << 1;
		}
		if (character != 1) { cout << character; }
		character = 0;
	}

	imshow("image", img);
	waitKey(0);

	return 0;
}
