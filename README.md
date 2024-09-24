# 环境配置

camke和opencv按教程安装，均没有出现问题

# 任务实现

1. CMakeLists编写：按照教程中编写，没有出现问题

2. 图像操作:

   + 图像颜色空间转换:

     * 灰度图

       ![灰度图](/OpenCV_Project/resources/grayimg.png)

     * HSV图片

       ![HSV图片](/OpenCV_Project/resources/hsvimg.png)

   + 应用各种滤波操作：

     + 均值滤波

       ![均值滤波](/OpenCV_Project/resources/average_blur_img)

     + 高斯滤波

       ![高斯滤波](/OpenCV_Project/resources/gauss_blur_img)

   + 特征提取

     + HSV方法提取红色颜色区域

       ![红色区域](/OpenCV_Project/resources/redregion.png)

     + 寻找红色外轮廓

       ![外轮廓](/OpenCV_Project/resources/contourimg.png)

     + 寻找红色bounding_box

       ![bounding_box](/OpenCV_Project/resources/contours_bounding_box.png)

     + 计算轮廓面积

     + 提取高亮颜色区域并进行图形学处理

       + 二值化

         ![二值化](/OpenCV_Project/resources/binary_img)

       + 膨胀

         ![膨胀](/OpenCV_Project/resources/dilated_img.png)

       + 腐蚀

         ![腐蚀](/OpenCV_Project/resources/eroded_img.png)

       + 漫水处理

         ![漫水](/OpenCV_Project/resources/floodfilled_img.png)

     + 图像绘制

       + 绘制圆形方形和文字

         ![图像](/OpenCV_Project/resources/drawing_shapes.png)

       + 外轮廓和bounding_box均在前面

     + 图像处理

       + 旋转35度

         ![旋转](/OpenCV_Project/resources/retated_img.png)

       + 裁剪为左上角1/4

         ![裁剪](/OpenCV_Project/resources/cropped_img.png)

         
