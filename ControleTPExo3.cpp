#include <iostream>
#include <string> 
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <ctime>
#include <bitset>

using namespace cv;
using namespace std;



int main()
{
	string g;
	string secret;
	char hxchar = '0x';

	cout << "Entrez votre code secret" << endl;
	getline(cin, secret);

	Mat img = imread("E:\\z autre\\test.png");

	char* char_array = new char[secret.length() + 1];
	char_array[secret.length()] = '\0';

	for (int i = 0; i < secret.length(); i++)
	{
		char_array[i] = secret[i];
	}

	int imgRows = img.rows;
	int imgCols = img.cols;

	for (int r = 0; r < imgRows; r++)
	{
		for (int c = 0; c < imgCols; c++)
		{
			
			Vec3b EncodePrep = img.at<Vec3b>(r, c);

			if (EncodePrep[0] == 255 && EncodePrep[1] == 255 && EncodePrep[2] == 255)
			{
				EncodePrep[0] = 254;
				EncodePrep[1] = 254;
				EncodePrep[2] = 254;

					img.at<Vec3b>(r, c) = EncodePrep;

			}




		}
	}


	int i, j;
	for (j = 10; j <= secret.length() * 10; j = j + 10)
	{
		const unsigned char m = char_array[j / 10 - 1];
		bitset<8> binaryValue2(m);

		for (i = 10; i < 100; i = i + 10)
		{

			Vec3b& EncodingFilter = img.at<Vec3b>(i, j);

			if (binaryValue2[(i / 10) - 1] == 1)
			{
				EncodingFilter[0] = 255;
				EncodingFilter[1] = 255;
				EncodingFilter[2] = 255;
			}
		}



	}

	imwrite("blackimage_encoded.png", img);
	imshow("image", img);
	waitKey(0);

	return 0;

}
