#include <iostream>
#include <opencv.hpp>
using namespace cv;
using namespace std;
int main()
{
	cv::Mat dstMat;
	cv::Mat	srcMat = cv::imread("C:/Users/HS/Desktop/06.jpg", 1);
	if (srcMat.empty())	return -1;

	int height = srcMat.rows; //行数
	int width = srcMat.cols;//每行元素数量
							//变换前的四点坐标
	cv::Point2f pts1[4];
	//左上角
	for (int j = 0; j < width; j++)
	{
		int i = 0;
		if ((srcMat.at<Vec3b>(i, j)[0] > 250) && (srcMat.at<Vec3b>(i, j)[1] > 250) && (srcMat.at<Vec3b>(i, j)[2] > 250))
		{

		}
		else

		{
			pts1[0] = cv::Point2f(j, i);
			break;
		}
	}

	//右上角
	for (int i = 0; i < height; i++)
	{
		int j = width - 1;
		if ((srcMat.at<Vec3b>(i, j)[0] > 250) && (srcMat.at<Vec3b>(i, j)[1] > 250) && (srcMat.at<Vec3b>(i, j)[2] > 250))
		{

		}
		else

		{
			pts1[1] = cv::Point2f(j, i);
			break;
		}
	}
	//右下角
	for (int j = width - 1; j >= 0; j--)
	{
		int i = height - 1;
		if ((srcMat.at<Vec3b>(i, j)[0] > 250) && (srcMat.at<Vec3b>(i, j)[1] > 250) && (srcMat.at<Vec3b>(i, j)[2] > 250))
		{

		}
		else

		{
			pts1[2] = cv::Point2f(j, i);
			break;
		}
	}
	//左下角
	for (int i = height - 1; i >= 0; i--)
	{
		int j = 0;
		if ((srcMat.at<Vec3b>(i, j)[0] > 250) && (srcMat.at<Vec3b>(i, j)[1] > 250) && (srcMat.at<Vec3b>(i, j)[2] > 250))
		{

		}
		else

		{
			pts1[3] = cv::Point2f(j, i);
			break;
		}
	}

	//变换后的四点坐标
	cv::Point2f pts2[] = {
		cv::Point2f(0,0),
		cv::Point2f(width-1,0),
		cv::Point2f(width-1,height-1),
		cv::Point2f(0,height-1) };
	//透视变换行列式计算
	cv::Mat perspective_matrix = cv::getPerspectiveTransform(pts1, pts2);
	//变换
	cv::warpPerspective(srcMat, dstMat, perspective_matrix, srcMat.size());

	cv::imshow("src", srcMat);
	cv::imshow("dst", dstMat);
	cv::waitKey(0);

}