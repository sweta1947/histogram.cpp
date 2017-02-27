#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
using namespace cv;
using namespace std;
int main()
{
	Mat var1(200, 400, CV_8UC3, Scalar(24, 25, 245));
	for (int i = 0; i < var1.rows; i++){
		for (int j = 0; j < var1.cols; j++)
		{
			var1.at<Vec3b>(i, j)[0] = rand() % 255 + 1;
			var1.at<Vec3b>(i, j)[1] = rand() % 255 + 1;
			var1.at<Vec3b>(i, j)[2] = rand() % 255 + 1;
		}
	}
	int B[256] = {0};
	int G[256] = { 0 };
	int R[256] = {0};
	int b, g, r;
	for (int i = 0; i < var1.rows; i++){
		for (int j = 0; j < var1.cols; j++)
		{
			b = var1.at<Vec3b>(i, j)[0];
			g = var1.at<Vec3b>(i, j)[1];
			r = var1.at<Vec3b>(i, j)[2];
			B[b]++;
			G[g]++;
			R[r]++;
		}
	}
	int maxB = B[0];
	int maxG = G[0];
	int maxR = R[0];
	for (int i = 1; i <= 255; i++)
	{
		if (B[i] > maxB)
			maxB = B[i];
		if (G[i] > maxG)
			maxG = G[i];
		if (R[i] > maxR)
			maxR = R[i];
	}

	Mat var2(1500, 256, CV_8UC3, Scalar(0, 0, 0));
	Mat var3(1500, 256, CV_8UC3, Scalar(0, 0, 0));
	Mat var4(1500, 256, CV_8UC3, Scalar(0, 0, 0));
	for (int i = 0; i < 256; i++)
	{
		var2.at<Vec3b>(B[i] / 4, i)[0] = 255;
		var2.at<Vec3b>(G[i] / 4, i)[1] = 255;
		var2.at<Vec3b>(R[i] / 4, i)[2] = 255;
	}

	namedWindow("windows2", 1);
	imshow("windows2", var2);
	//namedWindow("windows2", 1);
	//imshow("windows3", var3);
	//namedWindow("windows2", 1);
	//imshow("windows3", var4);
	waitKey(0);
	return(0);
}