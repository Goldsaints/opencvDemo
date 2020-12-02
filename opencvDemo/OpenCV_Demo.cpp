#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;

//图片腐蚀
void fushi() {
	Mat srcImage = imread("1.jpg");
	imshow("腐蚀操作：", srcImage);
	waitKey(0);
	//进行腐蚀操作
	Mat element = getStructuringElement(MORPH_RECT, Size(15, 15));
	Mat dstImage;
	erode(srcImage, dstImage, element);

	imshow("腐蚀操作：", dstImage);
	waitKey(0);
}

//图片模糊
void imageMoHu() {
	Mat srcImage = imread("1.jpg");
	imshow("均值滤波：", srcImage);
	waitKey(0);
	//均值滤波操作
	Mat dstImage;
	blur(srcImage, dstImage, Size(7, 7));

	imshow("均值滤波：", dstImage);
	waitKey(0);
}

//边缘检测
void byprotect() {
	Mat srcImage = imread("1.jpg");
	imshow("Canny边缘检测：", srcImage);
	Mat dstImage,edge,grayImage;

	//1、创建与src同类型和大小的矩阵(dst)
	dstImage.create(srcImage.size(), srcImage.type());

	//2、原图像转灰度图像
	cvtColor(srcImage, grayImage, COLOR_BGR2GRAY);

	//3、使用3X3内核来降噪
	blur(grayImage, edge, Size(3, 3));

	//4、运行Canny算子
	Canny(edge, edge, 3, 9, 3);

	imshow("Canny边缘检测：", edge);

	waitKey(0);
}
//获取本地视频并播放
void getAndPlayVideo() {
	VideoCapture capture("1.MP4");

	//2、循环每一帧
	while(1){
		Mat frame;
		//读取当前帧数据
		capture >> frame;
		//显示当前帧
		imshow("读取视频",frame);
		//延时30ms
		waitKey(30);
	}
}

//摄像头获取信息并做Canny边缘处理
void getCameraAndCannyHandle() {
	VideoCapture capture(0);
	Mat edges;

	//2、循环每一帧
	while (1) {
		Mat frame;
		//读取当前帧数据
		capture >> frame;

		//将原图像转换为灰度图像
		cvtColor(frame, edges, CV_BGR2GRAY);
		
		//使用3x3内核来降噪(2x3+1=7)
		blur(edges, edges, Size(7, 7));

		//运行Canny算子
		Canny(edges, edges, 0, 30, 3);

		//显示当前帧
		imshow("被canny后的视频", edges);
		//延时30ms
		if (waitKey(30) >= 0) break;
	}
}

int main()
{
	//imageMoHu();
	//byprotect();
	//getAndPlayVideo();
	getCameraAndCannyHandle();
	return 0;
}
