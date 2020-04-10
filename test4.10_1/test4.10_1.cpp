// test4.10_1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<opencv.hpp>

using namespace cv;
using namespace std;

int main()
{
	Mat srcMat = imread("E:\\Picture\\lena.jpg");
	Mat dst;
	float angle = -10.0, scale = 1;
	Point2f center(srcMat.cols / 2.0, srcMat.rows / 2.0);
	Mat rot = getRotationMatrix2D(center, angle, scale);
	Rect bbox = RotatedRect(center, srcMat.size(), angle).boundingRect();
	rot.at<double>(0, 2) += bbox.width / 2.0 - center.x;
	rot.at<double>(1, 2) += bbox.height / 2.0 - center.y;
	warpAffine(srcMat, dst, rot, bbox.size());

	imshow("原图", srcMat);
	imshow("dst", dst);
	waitKey();
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
