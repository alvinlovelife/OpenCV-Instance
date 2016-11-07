#pragma execution_character_set("utf-8")

#include "opencv2/core.hpp"
#include "opencv2/face.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include "Main.h"
#include "opencv2/objdetect/objdetect.hpp"
using namespace cv;
using namespace cv::face;
using namespace std;

static char* FACES_MODEL = "C:\\facedata\\face.yaml";
static char* FACES_TXT_PATH = "C:\\facedata\\face.txt";
static char* HAARCASCADE_FRONTALFACE_ALT = "C:\\facedata\\haarcascade_frontalface_alt.xml";

/*
*	一、识别人脸并加框
*  url：传入图片路径；url2：储存到的路径
*/
void rectface(char* url, char* url2) {
	char *HARR_XML_PATH1 = HAARCASCADE_FRONTALFACE_ALT;//-配置文件 xml
	string fn_haar = string(HARR_XML_PATH1);
	//人脸识别算法
	CascadeClassifier haar_cascade; //级联分类器检测类
	haar_cascade.load(fn_haar);
	vector< Rect_<int> > faces;
	Mat picture = imread(url, CV_LOAD_IMAGE_COLOR);

	haar_cascade.detectMultiScale(picture, faces);
	for (int i = 0; i < faces.size(); i++) {
		rectangle(picture, faces[i], CV_RGB(0, 255, 0), 1);
		putText(picture, "", Point(faces[i].x, faces[i].y), FONT_HERSHEY_PLAIN, 1.0, CV_RGB(0, 255, 0), 2.0);
	}
	imwrite(url2, picture);
}

/*
*	二、图片中第一张人脸截取 转灰度图
*   url：传入图片路径；url2：储存到的路径
*/
int grayface(char* url, char* url2) {
	char *HARR_XML_PATH1 = HAARCASCADE_FRONTALFACE_ALT;
	string fn_haar = string(HARR_XML_PATH1);    //-配置文件 xml
												//人脸识别算法
	CascadeClassifier haar_cascade;
	haar_cascade.load(fn_haar);
	Mat gray;
	vector< Rect_<int> > faces;
	Mat picture = imread(url, CV_LOAD_IMAGE_COLOR);

	if (!picture.empty()) {
		cvtColor(picture, gray, CV_BGR2GRAY);
		equalizeHist(gray, gray);    //直方图均衡化
	}
	//将灰度化的图片用于识别出人脸faces
	haar_cascade.detectMultiScale(gray, faces);

	//识别多张人脸
	for (int i = 0; i < faces.size(); i++) {
		Rect face_i = faces[i];
		Mat face = gray(face_i);
		char urltext[256];
		sprintf(urltext, "%s%s%d%s", url2, "gray", i, ".png");
		imwrite(urltext, face);
	}
	return faces.size();
}

int main(int argc, const char *argv[]) {
	rectface("C:\\Users\\Administrator\\Desktop\\opencv\\1.png", "C:\\Users\\Administrator\\Desktop\\opencv\\rect1.png");
	grayface("C:\\Users\\Administrator\\Desktop\\opencv\\1.png", "C:\\Users\\Administrator\\Desktop\\opencv\\");
	return 0;
}