#include <iostream>
#include <opencv.hpp>
using namespace cv;
using namespace std;
int main()
{
	cv::Mat dstMat;
	cv::Mat	srcMat = cv::imread("C:/Users/HS/Desktop/06.jpg", 1);
	if (srcMat.empty())	return -1;

	int height = srcMat.rows; //����
	int width = srcMat.cols;//ÿ��Ԫ������
							//�任ǰ���ĵ�����
	cv::Point2f pts1[4];
	//���Ͻ�
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

	//���Ͻ�
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
	//���½�
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
	//���½�
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

	//�任����ĵ�����
	cv::Point2f pts2[] = {
		cv::Point2f(0,0),
		cv::Point2f(width-1,0),
		cv::Point2f(width-1,height-1),
		cv::Point2f(0,height-1) };
	//͸�ӱ任����ʽ����
	cv::Mat perspective_matrix = cv::getPerspectiveTransform(pts1, pts2);
	//�任
	cv::warpPerspective(srcMat, dstMat, perspective_matrix, srcMat.size());

	cv::imshow("src", srcMat);
	cv::imshow("dst", dstMat);
	cv::waitKey(0);

}