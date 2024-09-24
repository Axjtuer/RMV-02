#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;
int main() {
    Mat img = imread("/home/zph/OpenCV_Project/resources/test_image.png");
    if (img.empty()) {
        cerr << "Error" << endl;
        return -1;
    }
    //转换为灰度图像
    Mat grayimg;
    cvtColor(img,grayimg,COLOR_BGR2GRAY);
    imwrite("../resources/grayimg.png",grayimg);
    //转换为HSV图像
    Mat hsvimg;
    cvtColor(img, hsvimg, COLOR_BGR2HSV);
    imwrite("../resources/hsvimg.png", hsvimg);
    //均值滤波
    Mat averageblur;
    blur(img, averageblur, Size(5, 5));
    imwrite("../resources/average_blur_img.png", averageblur);
    //高斯滤波
    Mat gaussblur;
    GaussianBlur(img, gaussblur, Size(5, 5), 0, 0);
    imwrite("../resources/gauss_blur_img.png", gaussblur);
    //提取红色区域
    Mat mask1, mask2, mask;
    Scalar lowerred1(0,100,100),upperred1(10,255,255),lowerred2(160,100,100),upperred2(180,255,255);
    inRange(hsvimg,lowerred1,upperred1, mask1);  // 红色区间1
    inRange(hsvimg,lowerred2,upperred2, mask2);  // 红色区间2
    add(mask1,mask2,mask);
    Mat redregion;
    bitwise_and(img,img,redregion,mask);
    imwrite("../resources/redregion.png",redregion);
    //寻找图像中红色的外轮廓
    vector<vector<Point>> contours;
    vector<Vec4i> hierarchy;
    findContours(mask,contours,hierarchy,RETR_TREE, CHAIN_APPROX_SIMPLE);
    Mat contourimg = img.clone();
    // 绘制轮廓
    drawContours(contourimg, contours, -1, Scalar(0, 255, 0), 2, LINE_8, hierarchy, 0);
    imwrite("../resources/contourimg.png",contourimg);
    //bounding_box和面积.
    double red_area = 0.0;
    Mat bounding_boximg=img.clone();
    for (size_t i = 0; i < contours.size(); i++) {
        // 累加每个轮廓的面积
        red_area += contourArea(contours[i]);
        // 绘制bounding box
        Rect bounding_box = boundingRect(contours[i]);
        rectangle(bounding_boximg, bounding_box, Scalar(255, 0, 0), 2);
    }
    cout << "红色区域总面积: " << red_area << endl;
    imwrite("../resources/contours_bounding_box.png", bounding_boximg);
    //高亮区域处理
    //二值化
    Mat binary;
    threshold(grayimg, binary, 120, 255, THRESH_BINARY); //灰度化
    imwrite("../resources/binary_img.png", binary);
    //膨胀
    Mat dilated;
    dilate(binary, dilated, Mat(), Point(-1, -1), 2);
    imwrite("../resources/dilated_img.png", dilated);
    //腐蚀
    Mat eroded;
    erode(dilated, eroded, Mat(), Point(-1, -1), 2);
    imwrite("../resources/eroded_img.png", eroded);
    //漫水白色区域
    Mat floodfilled = eroded.clone();
    floodFill(floodfilled, Point(0, 0), Scalar(255));
    imwrite("../resources/floodfilled_img.png", floodfilled);
    //绘制任意圆形、方形和文字
    Mat drawing = img.clone();
    rectangle(drawing, Point(100, 100), Point(200,200), Scalar(255, 0, 0), 3);  //绘制蓝色正方形
    circle(drawing, Point(150, 275), 50, Scalar(0, 255, 0), 3); //绘制绿色圆    
    putText(drawing, "This is rm", Point(50, 50), FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 0, 255), 2);   //红色字
    imwrite("../resources/drawing_shapes.png", drawing);
    //图像旋转
    Point2f center(img.cols / 2.0, img.rows / 2.0);  //绕几何中心旋转
    Mat rotationMat = getRotationMatrix2D(center, 35, 1.0); //构造旋转矩阵
    Mat rotated;
    warpAffine(img, rotated, rotationMat, img.size());  //旋转并保持旋转后图片大小与原图片相同
    imwrite("../resources/rotated_img.png", rotated);
    //图像裁剪
    Rect roi(0, 0, img.cols / 2, img.rows / 2); //定义矩形裁减区域
    Mat cropped = img(roi); //进行裁剪
    imwrite("../resources/cropped_img.png", cropped);
    return 0;
}