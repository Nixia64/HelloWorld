#include <iostream>
#include <iomanip>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
using namespace cv;
using namespace std;


int main()
{
	//Mat img;
	//VideoCapture video;
	//video.open(1);

	//for (;;)
	//{
		//video.read(img);
		//int imgRows = img.rows;
		//int imgCols = img.cols;

		//for (int r = 0; r < imgRows; r++)
		//{
			//for (int c = 0; c < imgCols; c++)
			//{
				//Vec3b unPixel = img.at<Vec3b>(r, c);

				//if (unPixel[0] <= 120 && unPixel[1] >= 120 && unPixel[2] <= 120)
				//{
					//unPixel[0] = 0;
					//unPixel[1] = 0;
					//unPixel[2] = 0;

					//img.at<Vec3b>(r, c) = unPixel;

				//}

			//}
		//}
	//}

	//imshow("image", img);
	//waitKey(30);

	Mat img = imread("D:\\cours\\1. c++\\tp2\\NoiseImage1.png", IMREAD_COLOR);
	Mat LinearFilter(3,3,CV_8UC3);
	int imgRows = img.rows - 2;
	int imgCols = img.cols - 2;
	
	for (int r = 0 ; r < imgRows; r++)
	{
			for (int c = 0 ; c < imgCols; c++)
			{
				Vec3b unPixel = img.at<Vec3b>(r, c);

				for (int x = 0; x < 3; x++)
				{
					for (int y = 0; y < 3; y++)
					{

						LinearFilter.at<Vec3b>(x, y) = img.at<Vec3b>(r + x, c + y);

					};
				};
				
				Vec3b PixelCent = LinearFilter.at<Vec3b>(1, 1);
				Vec3b Pixel1 = LinearFilter.at<Vec3b>(0, 0);
				Vec3b Pixel2 = LinearFilter.at<Vec3b>(0, 1);
				Vec3b Pixel3 = LinearFilter.at<Vec3b>(0, 2);
				Vec3b Pixel4 = LinearFilter.at<Vec3b>(1, 0);
				Vec3b Pixel5 = LinearFilter.at<Vec3b>(1, 2);
				Vec3b Pixel6 = LinearFilter.at<Vec3b>(2, 0);
				Vec3b Pixel7 = LinearFilter.at<Vec3b>(2, 1);
				Vec3b Pixel8 = LinearFilter.at<Vec3b>(2, 2);

				for (int x = 0; x < 3 ; x++) //3 composantes RVB
				{

					PixelCent[x] = (Pixel1[x] + Pixel2[x] + Pixel3[x] + Pixel4[x] + Pixel5[x] + Pixel6[x] + Pixel7[x] + Pixel8[x]) / 8;

					//cout << "teinte" << x << " = " << dec << static_cast<int>(PixelCent[x]) << endl;;

					unPixel[x] = PixelCent[x];
					img.at<Vec3b>(r + 1, c + 1)[x] = unPixel[x];
				}

				

			}
	}

		imshow("image", img);
		waitKey(0);

	


	return 0;
}
