#ifndef NSV_IMAGE_ANALY_H
#define NSV_IMAGE_ANALY_H

#include "param/nsv_include.h"
#include "param/nsv_global_param.h"
#include "param/nsv_common.h"

//获取点集质心
cv::Point2f point_center(std::vector<cv::KeyPoint> list);

//获取点集质心
cv::Point2f point_center(std::vector<cv::Point> list);

//获取点集质心
cv::Point2f point_center(std::vector<cv::Point2f> list);

//图像降采样
cv::Mat image_Pydown(cv::Mat image_input,int nft);

//图像比例缩放
cv::Mat image_Scale(cv::Mat image_input,float k);

//色差提取
cv::Mat image_diff_color_gray(cv::Mat image_input,cv::Scalar color,int neb);

//颜色分布方向分析
int color_ori(cv::Scalar color1);

//方向认同
int ori_like(int t1,int t2);

//色差分布
cv::Mat image_diff_color(cv::Mat image_input,cv::Scalar color);

//灰度差
cv::Mat image_diff_gray(cv::Mat image_input,int gray);

//彩色转换为灰度图，包括单通道提取
cv::Mat image_Gray(cv::Mat image_input,int type);

//灰度图转二值化图，包括正反色
cv::Mat image_Thresold(cv::Mat image_input,bool type,int thresold_size,int thresold_size_inv);

//感兴趣区域截取
cv::Mat image_Rect(cv::Mat image_input, cv::Rect rect);

//图像旋转
cv::Mat image_rotate(cv::Mat image_input,cv::Point center,double angle,double scale);

//图像开闭操作
cv::Mat image_ErDi(cv::Mat image_input,int size);

//高级图像开闭操作（因子调制）
QList<cv::Mat> image_ErDi_more(cv::Mat image_input,int legth,int width,int type,int dowhat);

//蒙版转ROI
cv::Rect Rect_FromMask(cv::Mat mask);

//轮廓转ROI
cv::Rect Rect_FromClur(std::vector<cv::Point> clur);

//蒙版
std::vector<cv::Mat> image_Mask(cv::Mat image_input,cv::Mat mask,int baise);

//圆形蒙版
std::vector<cv::Mat> image_Cut_cir(cv::Mat image_input,cv::Point center,int r,int baise);

//获取缺陷
result_for_hull image_GetHull(std::vector<cv::Point> contours,cv::Mat last,int min_size);

//颜色量化（图像K均值聚类）
cv::Mat image_Cluster(cv::Mat image_input,int cluster_num);

//调整对比度及亮度
cv::Mat image_AlphaBeta(cv::Mat image_input,float alpha,int beta);

//高级图像对比度（直方图均衡化）
cv::Mat image_Clane(cv::Mat image_input,int type,double clsize,cv::Size size);

//高级图像对比度（直方图均衡化）(彩色)
cv::Mat image_Clane_colour(cv::Mat image_input,int type,double clsize,cv::Size size);

//梯度化图像
cv::Mat image_Gradient(cv::Mat image_input,int type, int initsize);

//梯度化图像（彩色）
cv::Mat image_Gradient_colour(cv::Mat image_input,int type, int initsize,bool inv,int min_thres,int max_thres,bool Grl);

//散点清理
cv::Mat image_Stats_clear(cv::Mat image_input,int clear);

//散点清理（彩色）
cv::Mat image_Stats_clear_colour(cv::Mat image_input,int clear);

//通道合成
cv::Mat image_Grlour(std::vector<cv::Mat> imagelist);

//图像加减法
cv::Mat image_Arithmetic(cv::Mat image_1,cv::Mat image_2,int type);

//获取固定灰度图像分布
cv::Mat image_GetGray(cv::Mat image_input,int gray,QRect rect=QRect(0,0,0,0));

//获取固定灰度图像分布
cv::Mat image_GetGray(cv::Mat image_input,int gray);

//Stats识别结果分层设色
result_for_stats image_Stats(cv::Mat src,cv::Mat image_input,nsv Nsv);

//Stats识别
result_for_stats image_Stats(cv::Mat src,cv::Mat image_input,int min_size,int max_size);

//Fast特征点
result_for_fast image_Fast(cv::Mat image_input);

//物体角度获取
object_for_stats image_Angle(object_for_stats stats,int type,float dep,bool left);

//排序
void sortA2(float a[], int length);

//矩形框面积计算
QList<float> rect_Size(std::vector<cv::Point> box);

//最小外接矩转Vector
std::vector<cv::Point> RotatedRect_to_Vector(cv::RotatedRect poly);

//识别结果描述（最小外接矩，最少点，凸包）
result_for_findC image_FindContours(result_for_stats object,int type=0,int approx_size=5);

//绘制识别框
cv::Mat image_out_list(cv::Mat image_input,result_for_findC constur,bool info_show);

//识别流程
result_for_findC image_FindPointstoStats(cv::Mat image_input,nsv Nsv,bool info_show);

//stats及结果解析
result_for_findC image_FindPointsOnlyStats(cv::Mat image_input,cv::Mat image_last,nsv Nsv,bool info_show);

//查找蒙版边缘
result_for_findC image_FindPointstoMask(cv::Mat image_input,cv::Mat last,bool usegradcut);

#endif // NSV_IMAGE_ANALY_H
