#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/world.hpp>
#include <opencv2/imgproc.hpp>
#include <chrono>
#include <ctime>
#include <string> 
#include <cstring> 
#include <cmath>

using namespace std;
using namespace cv;
using namespace std::chrono;
using chrono::system_clock;


int main()
{
	Mat vid;
	VideoCapture video;
	video.open(0);


	high_resolution_clock::time_point start = high_resolution_clock::now();

	for (;;)
	{
		video.read(vid);
		int imgRows = vid.rows;
		int imgCols = vid.cols;
		ostringstream taq;

		if (!video.read(vid))
		{


			cout << "No video capture device found.";

		}

		time_t now = time(NULL);
		tm now_tm;
		char str[26];
		localtime_s(&now_tm, &now);
		asctime_s(str, 26, &now_tm);
		str[strlen(str) - 1] = ' ';
		auto mtn = high_resolution_clock::now();
		const auto temp = duration_cast<seconds>(mtn - start).count();
		taq << "Temps : " << temp << "s";
		string temps = taq.str();
		

		Point text_position(350, 30);
		Point text_position2(0, 100);
		Point text_position3(vid.cols - 140, 60);
		double font_size = 0.65;
		double font_weight = 1.9;
		Scalar font_Color(100, 222, 100);
		putText(vid, str, text_position, FONT_HERSHEY_SIMPLEX, font_size, font_Color, font_weight);
		putText(vid, temps, text_position3, FONT_HERSHEY_DUPLEX, font_size, font_Color, font_weight);
		




		imshow("Augmented Reality", vid);
		waitKey(30);

	}
	auto end = std::chrono::steady_clock::now();

	return 0;


}
