#include "nsv_image_analy.h"

//获取点集质心
cv::Point2f point_center(std::vector<cv::KeyPoint> list)
{
    float x=0;
    float y=0;

    try
    {
        float allx=0;
        float ally=0;
        int num=list.size();

        for(int i=0;i<num;i++)
        {
            allx+=list[i].pt.x;
            ally+=list[i].pt.y;
        }

        x=allx/num;
        y=ally/num;
    }
    catch (...)
    {
        std::cout<<"point_center error!"<<std::endl;
    }

    return cv::Point2f(x,y);
}

//获取点集质心
cv::Point2f point_center(std::vector<cv::Point> list)
{

    float x=0;
    float y=0;

    try
    {
        float allx=0;
        float ally=0;

        int num=list.size();

        for(int i=0;i<num;i++)
        {
            allx+=list[i].x;
            ally+=list[i].y;
        }

        x=allx/num;
        y=ally/num;
    }
    catch (...)
    {
        std::cout<<"point_center error!"<<std::endl;
    }

    return cv::Point2f(x,y);
}

//获取点集质心
cv::Point2f point_center(std::vector<cv::Point2f> list)
{
    float x=0;
    float y=0;
    try
    {
        float allx=0;
        float ally=0;

        int num=list.size();

        for(int i=0;i<num;i++)
        {
            allx+=list[i].x;
            ally+=list[i].y;
        }

        x=allx/num;
        y=ally/num;
    }
    catch (...)
    {
        std::cout<<"point_center error!"<<std::endl;
    }
    return cv::Point2f(x,y);
}

//色差提取
cv::Mat image_diff_color(cv::Mat image_input,cv::Scalar color)
{
    cv::Mat image_out=image_input.clone();

    try
    {
        cv::Mat image=image_input.clone();
        for(int i=0;i<image.rows;i++)
        {
            for(int j=0;j<image.cols;j++)
            {
                cv::Vec3b last=image.at<cv::Vec3b>(i,j);
                image_out.at<cv::Vec3b>(i,j)=cv::Vec3b(abs(last[0]-color[0]),abs(last[1]-color[1]),abs(last[2]-color[2]));
            }
        }
    }
    catch(...)
    {
        std::cout<<"diff_color error!"<<std::endl;
    }
    return image_out;
}

//颜色分布方向分析
int color_ori(cv::Scalar color1,int neb)
{
    int b1=color1[0];
    int g1=color1[1];
    int r1=color1[2];

    int b1g1=b1-g1;
    int g1r1=g1-r1;
    int rib1=r1-b1;

    int t1=1;
    int t2=1;
    int t3=1;

    if(abs(b1g1)>neb)
    {
        if(b1g1>0)
        {
            t1=2;
        }
        else
        {
            t1=0;
        }
    }
    else
    {
        t1=1;
    }

    if(abs(g1r1)>neb)
    {
        if(g1r1>0)
        {
            t2=2;
        }
        else
        {
            t2=0;
        }
    }
    else
    {
        t2=1;
    }

    if(abs(rib1)>neb)
    {
        if(rib1>0)
        {
            t3=2;
        }
        else
        {
            t3=0;
        }
    }
    else
    {
        t3=1;
    }

    int t4=t1*100+t2*10+t3;
    return t4;
}

//方向认同
int ori_like(int t1,int t2)
{
    int tc1=t1/100;
    int tc2=t1%100/10;
    int tc3=int(t1%10);

    int tt1=t2/100;
    int tt2=t2%100/10;
    int tt3=int(t2%10);

    float size=float(abs(tc1-tt1))*127.5+float(abs(tc3-tt3))*127.5+float(abs(tc2-tt2))*127.5;

    float sizet=size/3;
    return int(sizet);
}

//色差分布
cv::Mat image_diff_color_gray(cv::Mat image_input,cv::Scalar color,int neb)
{
    int tc=color_ori(color,neb);
    cv::Mat image=image_input.clone();
    cv::Mat image_out=cv::Mat(image_input.size(),CV_8U);
    for(int i=0;i<image.rows;i++)
    {
        for(int j=0;j<image.cols;j++)
        {
            cv::Vec3b last=image.at<cv::Vec3b>(i,j);
            int tc2=color_ori(cv::Scalar(last[0],last[1],last[2]),neb);
            int size=ori_like(tc,tc2);
            image_out.at<uchar>(i,j)=uchar(int((abs(last[0]-color[0])+abs(last[1]-color[1])+abs(last[2]-color[2])+3*size)/6));
        }
    }
    return image_out;
}

//灰度差
cv::Mat image_diff_gray(cv::Mat image_input,int gray)
{
    cv::Mat image_out=image_input.clone();
    try
    {
        cv::Mat image=image_input.clone();
        for(int i=0;i<image.rows;i++)
        {
            for(int j=0;j<image.cols;j++)
            {
                uchar last=image.at<uchar>(i,j);
                image_out.at<uchar>(i,j)=uchar(abs(last-gray));
            }
        }
    }
    catch(...)
    {
        std::cout<<"diff_gray error!"<<std::endl;
    }
    return image_out;
}

//彩色转换为灰度图，包括单通道提取
cv::Mat image_Gray(cv::Mat image_input,int type)
{
    cv::Mat image_gray=cv::Mat::zeros(image_input.size(),CV_8U);
    try
    {
        cv::Mat image=image_input.clone();
        std::vector<cv::Mat> image_list;
        cv::split(image,image_list);
        if(type == 1)
        {
            image_gray=image_list.at(2);
        }
        else if(type == 2)
        {
            image_gray=image_list.at(1);
        }
        else if(type == 3)
        {
            image_gray=image_list.at(0);
        }
        else
        {
            cv::cvtColor(image,image_gray,cv::COLOR_BGR2GRAY);
        }

    }
    catch (...)
    {
        std::cout<<"image_gray error!"<<std::endl;
    }
    return image_gray;
}

//灰度图转二值化图
cv::Mat image_Thresold(cv::Mat image_input,bool type,int thresold_size,int thresold_size_inv)
{
    cv::Mat image_thresold=cv::Mat::zeros(image_input.size(),CV_8U);
    try
    {
        cv::Mat image=image_input.clone();
        if(type==true)
        {
            cv::Mat image_thresold_inv;
            cv::threshold(image,image_thresold_inv,thresold_size_inv,0,cv::THRESH_TOZERO_INV);
            cv::threshold(image_thresold_inv,image_thresold,thresold_size,255,cv::THRESH_BINARY);
        }
        else
        {
            cv::threshold(image,image_thresold,thresold_size,255,cv::THRESH_BINARY);
        }

    }
    catch (...)
    {
        std::cout<<"thresold error!"<<std::endl;
    }
    return image_thresold;
}

//感兴趣区域截取
cv::Mat image_Rect(cv::Mat image_input, cv::Rect rect)
{
    cv::Mat image_work=cv::Mat(image_input.size(),image_input.type(),cv::Scalar(255,255,255));

    try
    {
        cv::Mat image=image_input.clone();

        if (rect.x<=0)
        {
            rect.width=rect.width+rect.x;
            rect.x=0;
        }

        if (rect.y<=0)
        {
            rect.height=rect.height+rect.y;
            rect.y=0;
        }

        if (rect.x+rect.width>=image.cols)
        {
            rect.width=image.cols-rect.x;
        }

        if (rect.y+rect.height>=image.rows)
        {
            rect.height=image.rows-rect.y;
        }

        cv::Mat image_cut,imageROI;
        image_cut=image(rect);
        imageROI = image_work(cv::Range(rect.y, rect.y + image_cut.rows),cv::Range(rect.x, rect.x + image_cut.cols));
        image_cut.copyTo(imageROI);
    }
    catch(...)
    {
        std::cout<<"rect error!"<<std::endl;
    }

    return image_work;
}

//图像旋转
cv::Mat image_rotate(cv::Mat image_input,cv::Point center,double angle,double scale)
{
    cv::Mat image_out=image_input.clone();
    try
    {
        cv::Mat image=image_input.clone();
        cv::Mat mapp_rota=cv::getRotationMatrix2D(center, angle, scale);
        cv::warpAffine(image,image_out,mapp_rota,image.size());
    }
    catch(...)
    {
        std::cout<<"image_rotate error!"<<std::endl;
    }
    return image_out;
}

//图像降采样
cv::Mat image_Pydown(cv::Mat image_input,int nft)
{
    cv::Mat image_cp=image_input.clone();
    try
    {
        if(nft>=0)
        {
            for(int i=0; i<nft; i++)
            {
                cv::pyrDown(image_cp,image_cp);
            }
        }
        else
        {
            for(int i=0; i<abs(nft); i++)
            {
                cv::pyrUp(image_cp,image_cp);
            }
        }

    }
    catch (...)
    {
        std::cout<<"image_pydown error!"<<std::endl;
    }
    return image_cp;
}

//图像比例缩放
cv::Mat image_Scale(cv::Mat image_input,float k)
{
    cv::Mat image=image_input.clone();
    try
    {
        if(!image.empty())
        {
            float width=image.cols;
            float height=image.rows;
            cv::Size size=cv::Size(int(width*k),int(height*k));
            if(k<1)
            {
                cv::resize(image,image,size,cv::INTER_AREA);
            }
            else if(k>1)
            {
                cv::resize(image,image,size,cv::INTER_CUBIC);
            }
        }
    }
    catch (...)
    {
        std::cout<<"image_scale error!"<<std::endl;
    }
    return image;
}

//蒙版转ROI
cv::Rect Rect_FromMask(cv::Mat mask)
{
    int x1=0;
    int y1=mask.rows;
    int x2=mask.cols;
    int y2=0;

    bool isfound=true;
    for(int i=0;i<mask.rows;i++)
    {
        bool t=false;
        for(int j=0;j<mask.cols;j++)
        {
            if(mask.at<uchar>(i,j)>200)
            {
                t=true;
                if(j<y1)
                {
                    y1=j;
                }
                if(j>y2)
                {
                    y2=j;
                }
            }
        }
        if(t && isfound)
        {
            x1=i;
            isfound=false;
        }
        if(t)
        {
            x2=i;
        }
    }

    cv::Rect rect;
    if(x1==0 && y1==mask.rows && x2==mask.cols && y2==0)
    {
        rect=cv::Rect(int(0),int(0),int(mask.cols),int(mask.rows));
    }
    else
    {
        rect=cv::Rect(int(y1),int(x1),int(abs(y2-y1)),int(abs(x2-x1)));
    }

    if (rect.x<=0)
    {
        rect.width=rect.width+rect.x;
        rect.x=0;
    }

    if (rect.y<=0)
    {
        rect.height=rect.height+rect.y;
        rect.y=0;
    }

    if (rect.x+rect.width>=mask.cols)
    {
        rect.width=mask.cols-rect.x;
    }

    if (rect.y+rect.height>=mask.rows)
    {
        rect.height=mask.rows-rect.y;
    }

    return rect;
}

//轮廓转ROI
cv::Rect Rect_FromClur(std::vector<cv::Point> clur)
{
    cv::Rect rect=cv::boundingRect(clur);
    return rect;
}

//蒙版
std::vector<cv::Mat> image_Mask(cv::Mat image_input,cv::Mat mask,int baise)
{
    std::vector<cv::Mat> image_list;
    try
    {
        cv::Mat image=image_input.clone();
        if(image.size()==mask.size())
        {
            if(baise==255)
            {
                cv::bitwise_not(image,image);
            }

            cv::Mat image_out;
            image.copyTo(image_out, mask);//通过蒙版将背景图片复制到resultimg
            if(baise==255)
            {
                cv::bitwise_not(image_out,image_out);
            }

            cv::Rect rect=Rect_FromMask(mask);

            cv::Mat image_cut=image_out(rect);
            image_list.push_back(image_out);
            image_list.push_back(image_cut);
        }
    }
    catch (...)
    {
        std::cout<<"image_Mask error!"<<std::endl;
    }
    return image_list;
}

//圆形蒙版
std::vector<cv::Mat> image_Cut_cir(cv::Mat image_input,cv::Point center,int r,int baise)
{
    std::vector<cv::Mat> image_list;
    try
    {
        cv::Mat image=image_input.clone();
        if(baise==255)
        {
            cv::bitwise_not(image,image);
        }
        cv::Mat mask=cv::Mat::zeros(image.size(), CV_8U);

        cv::Mat image_out;
        cv::circle(mask, center, r, cv::Scalar::all(255), -1);//在蒙版上绘制一个半径为100的圆
        image.copyTo(image_out, mask);//通过蒙版将背景图片复制到resultimg
        if(baise==255)
        {
            cv::bitwise_not(image_out,image_out);
        }

        cv::Rect rect=cv::Rect(int(center.x-r),int(center.y-r),int(2*r),int(2*r));

        if (rect.x<=0)
        {
            rect.width=rect.width+rect.x;
            rect.x=0;
        }

        if (rect.y<=0)
        {
            rect.height=rect.height+rect.y;
            rect.y=0;
        }

        if (rect.x+rect.width>=image.cols)
        {
            rect.width=image.cols-rect.x;
        }

        if (rect.y+rect.height>=image.rows)
        {
            rect.height=image.rows-rect.y;
        }

        cv::Mat image_cut=image_out(rect);
        image_list.push_back(image_out);
        image_list.push_back(image_cut);
    }
    catch (...)
    {
        std::cout<<"image_center error!"<<std::endl;
    }
    return image_list;
}

//图像开闭操作
cv::Mat image_ErDi(cv::Mat image_input,int size)
{
    cv::Mat image=image_input.clone();
    try
    {
        if(size>0)
        {
            size=abs(size);
            cv::Mat kernel = cv::getStructuringElement(cv::MORPH_RECT,cv::Size(2*size+1,2*size+1),cv::Point(-1,-1));
            cv::erode(image,image,kernel);
            cv::dilate(image,image,kernel);
        }
        else if(size<0)
        {
            size=abs(size);
            cv::Mat kernel = cv::getStructuringElement(cv::MORPH_RECT,cv::Size(2*size+1,2*size+1),cv::Point(-1,-1));
            cv::dilate(image,image,kernel);
            cv::erode(image,image,kernel);
        }
    }
    catch (...)
    {
        std::cout<<"erdi error!"<<std::endl;
    }
    return image;
}

//高级图像开闭操作（因子调制）
QList<cv::Mat> image_ErDi_more(cv::Mat image_input,int legth,int width,int type,int dowhat)
{
    QList<cv::Mat> image_list;
    try
    {
        cv::Mat image=image_input.clone();
        cv::Mat image20_w=cv::Mat(cv::Size(61,61),CV_8UC1,cv::Scalar(255,255,255));
        image20_w.at<uchar>(31,31)=0;
        cv::Mat image20_b=cv::Mat(cv::Size(61,61),CV_8UC1,cv::Scalar(0,0,0));
        image20_b.at<uchar>(31,31)=255;
        cv::Mat kernel = cv::getStructuringElement(type,cv::Size(2*legth+1,2*width+1),cv::Point(-1,-1));
        cv::erode(image20_w,image20_w,kernel);
        cv::dilate(image20_b,image20_b,kernel);

        switch (dowhat)
        {
        case 0:
            cv::erode(image,image,kernel);
            break;
        case 1:
            cv::dilate(image,image,kernel);
            break;
        case 2:
            cv::erode(image,image,kernel);
            cv::dilate(image,image,kernel);
            break;
        case 3:
            cv::dilate(image,image,kernel);
            cv::erode(image,image,kernel);
            break;
        default:break;
        }

        image_list.append(image);
        image_list.append(image20_w);
        image_list.append(image20_b);

    }
    catch (...)
    {
        std::cout<<"Erdi_more error!"<<std::endl;
    }
    return image_list;
}

//高级图像对比度（直方图均衡化）
cv::Mat image_Clane(cv::Mat image_input,int type,double clsize,cv::Size size)
{
    cv::Mat image_out=image_input.clone();
    try
    {
        cv::Mat image=image_input.clone();
        if(type==0)
        {
            cv::Ptr<cv::CLAHE> clane=cv::createCLAHE(clsize,size);
            clane->apply(image,image_out);
        }
        else if(type==1)
        {
            cv::equalizeHist(image,image_out);
        }

    }
    catch (...)
    {
        std::cout<<"clane error!"<<std::endl;
    }
    return image_out;
}

//高级图像对比度（直方图均衡化）(彩色)
cv::Mat image_Clane_colour(cv::Mat image_input,int type,double clsize,cv::Size size)
{
    cv::Mat image_out=image_input.clone();
    try
    {
        cv::Mat image=image_input.clone();

        if(image.channels()>1)
        {
            std::vector<cv::Mat> imagelist;
            cv::split(image,imagelist);

            if(imagelist.size()==3)
            {
                std::vector<cv::Mat> imageoutlist;

                for(unsigned long long int i=0;i<imagelist.size();i++)
                {
                    cv::Mat image_single=imagelist[i];
                    cv::Mat image_single_out=image_single.clone();

                    if(type==0)
                    {
                        cv::Ptr<cv::CLAHE> clane=cv::createCLAHE(clsize,size);
                        clane->apply(image_single,image_single_out);
                    }
                    else if(type==1)
                    {
                        cv::equalizeHist(image_single,image_single_out);
                    }

                    imageoutlist.push_back(image_single_out);
                }

                image_out=image_Grlour(imageoutlist);
            }
        }
    }
    catch (...)
    {
        std::cout<<"clane_colour error!"<<std::endl;
    }
    return image_out;
}

//梯度化图像
cv::Mat image_Gradient(cv::Mat image_input,int type, int initsize)
{
    cv::Mat image_output=image_input.clone();

    try
    {
        cv::Mat image=image_input.clone();
        cv::Mat dstx,dsty;
        if(type == 0)
        {
            cv::Sobel(image,dstx,CV_16S,1,0,initsize);
            cv::Sobel(image,dsty,CV_16S,0,1,initsize);
            cv::convertScaleAbs(dstx,dstx);
            cv::convertScaleAbs(dsty,dsty);
            cv::addWeighted(dstx,1,dsty,1,0,image_output);
        }
        else if(type == 1)
        {
            cv::Scharr(image,dstx,CV_16S,1,0);
            cv::Scharr(image,dsty,CV_16S,0,1);
            cv::convertScaleAbs(dstx,dstx);
            cv::convertScaleAbs(dsty,dsty);
            cv::addWeighted(dstx,1,dsty,1,0,image_output);
        }
        else if(type == 2)
        {
            cv::Laplacian(image,image_output,CV_16S,initsize);
            cv::convertScaleAbs(image_output,image_output);
        }
    }
    catch (...)
    {
        qDebug()<<"image_Gradient error!";
    }

    return image_output;
}

//梯度化图像（彩色）
cv::Mat image_Gradient_colour(cv::Mat image_input,int type, int initsize,bool inv,int min_thres,int max_thres,bool Grl)
{
    cv::Mat image_out=image_input.clone();
    try
    {
        cv::Mat image=image_input.clone();

        if(image.channels()>1)
        {
            std::vector<cv::Mat> imagelist;
            cv::split(image,imagelist);

            if(imagelist.size()==3)
            {
                std::vector<cv::Mat> imageoutlist;

                for(unsigned long long int i=0;i<imagelist.size();i++)
                {
                    cv::Mat image_single=imagelist[i];
                    cv::Mat image_single_out=image_single.clone();

                    image_single_out=image_Gradient(image_single,type,initsize);

                    if(inv)
                    {
                        image_single_out=image_Thresold(image_single_out,true,min_thres,max_thres);
                    }

                    imageoutlist.push_back(image_single_out);
                }

                if(Grl)
                {
                    image_out=image_Grlour(imageoutlist);
                }
                else
                {
                    cv::Mat image_Ari=cv::Mat::zeros(imageoutlist[0].rows,imageoutlist[0].cols,CV_8U);

                    for(unsigned long long int i=0;i<imageoutlist.size();i++)
                    {
                        image_Ari=image_Arithmetic(image_Ari,imageoutlist[i],1);
                    }

                    cv::cvtColor(image_Ari,image_out,cv::COLOR_GRAY2BGR);
                }
            }
        }
    }
    catch (...)
    {
        std::cout<<"image_Gradient_colour error!"<<std::endl;
    }
    return image_out;
}

//清理散点
cv::Mat image_Stats_clear(cv::Mat image_input,int clear)
{
    cv::Mat src=image_input.clone();
    cv::Mat image_out=cv::Mat::zeros(src.size(),CV_8U);

    if(!src.empty() && src.channels()==1)
    {
        try
        {
            cv::Mat labels, stats, centroids;
            int nccomps =cv::connectedComponentsWithStats(src,labels,stats,centroids);

            std::vector<uchar> colors(abs(nccomps)+1);
            colors[0]=0;
            std::cout<<nccomps<<std::endl;
            for(int i=1;i<abs(nccomps);i++)
            {
                int width  = stats.at<int>(i,cv::CC_STAT_WIDTH);
                int height = stats.at<int>(i,cv::CC_STAT_HEIGHT);
                if(clear>=0)
                {
                    if(width>abs(clear) && height>abs(clear))
                    {
                        colors[i] = 255;
                    }
                    else
                    {
                        colors[i] = 0;
                    }
                }
                else
                {
                    if(width<abs(clear) && height<abs(clear))
                    {
                        colors[i] = 255;
                    }
                    else
                    {
                        colors[i] = 0;
                    }
                }

            }

            for(int i=0;i<labels.rows;i++)
            {
                for(int j=0;j<labels.cols;j++)
                {
                    try
                    {
                        int label = labels.at<int>(i,j);
                        image_out.at<uchar>(i,j) = colors[label];
                    }
                    catch (...)
                    {
                        std::cout<<"point error!"<<std::endl;
                    }
                }
            }
        }
        catch (...)
        {
            std::cout<<"image_Stats_clear error!"<<std::endl;
        }
    }

    return image_out;
}

//清理散点（彩色）
cv::Mat image_Stats_clear_colour(cv::Mat image_input, int clear)
{
    cv::Mat src=image_input.clone();
    cv::Mat image_out=cv::Mat::zeros(image_input.size(),CV_8U);

    try
    {
        if(!src.empty() && src.channels()>1)
        {
            std::vector<cv::Mat> imagelist;
            std::vector<cv::Mat> imagelist_out;
            cv::split(src,imagelist);
            if(imagelist.size()==3)
            {
                for(unsigned long long int i=0;i<imagelist.size();i++)
                {
                    cv::Mat image=imagelist[i];

                    cv::Mat image_out=image_Stats_clear(image,clear);

                    imagelist_out.push_back(image_out);
                }
            }

            if(imagelist_out.size()==3)
            {
                image_out=image_Grlour(imagelist_out);
            }
        }
    }
    catch (...)
    {
        qDebug()<<"image_Stats_clear_colour error!";
    }

    return image_out;
}

//通道合成
cv::Mat image_Grlour(std::vector<cv::Mat> imagelist)
{
    cv::Mat image=cv::Mat::zeros(cv::Size(1920,1080),CV_8UC3);

    try
    {
        if(imagelist.size()==3)
        {
            if(imagelist[0].size==imagelist[1].size && imagelist[1].size==imagelist[2].size)
            {
                cv::Mat image_Blue=imagelist[0];
                cv::Mat image_Gree=imagelist[1];
                cv::Mat image_Redd=imagelist[2];

                cv::resize(image,image,cv::Size(image_Blue.cols,image_Blue.rows));

                for(int i=0;i<image.rows;i++)
                {
                    for(int j=0;j<image.cols;j++)
                    {
                        image.at<cv::Vec3b>(i,j)=cv::Vec3b(image_Blue.at<uchar>(i,j),image_Gree.at<uchar>(i,j),image_Redd.at<uchar>(i,j));
                    }
                }
            }
        }
    }
    catch (...)
    {
        qDebug()<<"image_Grlour error!";
    }

    cv::Mat image_out=image.clone();

    return image_out;
}

//图像与或非
cv::Mat image_Arithmetic(cv::Mat image_1,cv::Mat image_2,int type)
{
    cv::Mat image=cv::Mat::zeros(cv::Size(1920,1080),CV_8U);

    try
    {
        if(image_1.channels()==1 && image_2.channels()==1)
        {
            if(image_1.size==image_2.size)
            {
                cv::resize(image,image,cv::Size(image_1.cols,image_1.rows));

                for(int i=0;i<image.rows;i++)
                {
                    for(int j=0;j<image.cols;j++)
                    {
                        if(type==1)
                        {
                            image.at<uchar>(i,j)=image_1.at<uchar>(i,j) | image_2.at<uchar>(i,j);
                        }
                        else if(type==2)
                        {
                            image.at<uchar>(i,j)=image_1.at<uchar>(i,j) ^ image_2.at<uchar>(i,j);
                        }
                        else
                        {
                            image.at<uchar>(i,j)=image_1.at<uchar>(i,j) & image_2.at<uchar>(i,j);
                        }
                    }
                }
            }
        }
    }
    catch (...)
    {
        qDebug()<<"image_Arithmetic error!";
    }

    cv::Mat image_out=image.clone();

    return image_out;
}

//颜色量化（图像K均值聚类）
cv::Mat image_Cluster(cv::Mat image_input,int cluster_num)
{
    cv::Mat image_out = image_input.clone();
    try
    {

        cluster_num=pow(2,cluster_num);

        if(!image_input.empty())
        {
            cv::Mat image=image_input.clone();

            cv::GaussianBlur(image,image,cv::Size(3,3),0);//对图像进行高斯滤波
            image.convertTo(image,CV_32FC3);//更改图像格式

            image=image_Pydown(image,1);

            unsigned long int size = image.rows*image.cols;

            cv::Mat image_work = cv::Mat(size, 1, CV_32FC3);
            cv::Vec3f* image_work_i   = (cv::Vec3f*)image_work.data;
            cv::Vec3f* image_i        = (cv::Vec3f*)image.data;
            for(unsigned long int i = 0;i < size; i++)
            {
                *image_work_i = *image_i;
                image_work_i++;
                image_i++;
            }

            cv::Mat clusters = cv::Mat(size, 1, CV_32SC1);
            cv::Mat center = cv::Mat(cluster_num,1,CV_32FC3);
            cv::TermCriteria termcriteria = cv::TermCriteria(cv::TermCriteria::EPS+cv::TermCriteria::COUNT, 10, 0.1);
            cv::kmeans(image_work,cluster_num,clusters,termcriteria,int(cluster_num/4+1),cv::KMEANS_PP_CENTERS,center);

            //将原本单行的分类结果按图像顺序重新赋值
            cv::Mat results_work = cv::Mat(image.size(), CV_32SC1);
            int* clusters_i = (int*)clusters.data;
            int* results_work_i = (int*)results_work.data;
            for(unsigned long int i = 0;i < size; i++)
            {
                *results_work_i = *clusters_i;
                results_work_i++;
                clusters_i++;
            }

            //显示聚类结果
            cv::Mat image_last = cv::Mat(image.size(),CV_32FC3);
            for (int y = 0; y < image.rows; y++)
            {
                for (int x = 0; x < image.cols; x++)
                {
                    int id = results_work.at<int>(y,x);
                    image_last.at<cv::Vec3f>(y,x)=center.at<cv::Vec3f>(id,0);
                }
            }
            cv::normalize(image_last,image_last,1,0,cv::NORM_MINMAX);

            image_last.convertTo(image,CV_8UC3,255);//更改图像格式

            image=image_Pydown(image,-1);

            image_out=image;
        }

    }
    catch(...)
    {
        std::cout<<"cluster error!"<<std::endl;
    }
    return image_out;
}

//调整对比度及亮度
cv::Mat image_AlphaBeta(cv::Mat image_input,float alpha,int beta)
{
    cv::Mat image_out=image_input.clone();
    try
    {
        cv::Mat image=image_input.clone();
        image.convertTo(image_out,image.type(),abs(alpha),beta);
    }
    catch (...)
    {
        std::cout<<"alpha_beta error!"<<std::endl;
    }
    return image_out;
}

//获取固定灰度图像分布
cv::Mat image_GetGray(cv::Mat image_input,int gray,QRect rect)
{
    cv::Mat image_out = cv::Mat::zeros(image_input.size(),CV_8U);
    if(!image_input.empty())
    {
        for(long int i=rect.y();i<rect.y()+rect.height();i++)
        {
            for(long int j=rect.x();j<rect.x()+rect.width();j++)
            {
                try
                {
                    int label = image_input.at<int>(i,j);
                    if(label >0 && label == gray)
                    {
                        image_out.at<uchar>(i,j)=255;
                    }
                }
                catch (...)
                {
                    qDebug()<<"point error!";
                }
            }
        }
    }
    return image_out;
}

//获取固定灰度图像分布
cv::Mat image_GetGray(cv::Mat image_input,int gray)
{
    cv::Mat image_out=image_input.clone();
    if(!image_input.empty())
    {
        try
        {
            cv::threshold(image_out,image_out,gray,0,cv::THRESH_TOZERO_INV);
            cv::threshold(image_out,image_out,gray-1,255,cv::THRESH_BINARY);
        }
        catch(...)
        {
            std::cout<<"GetGray error!"<<std::endl;
        }
    }
    return image_out;
}

//蒙版图割
cv::Mat image_GrabCut(cv::Mat mask_input,cv::Mat image_last,int fast)
{
    cv::Mat mask_out=cv::Mat::zeros(mask_input.size(),CV_8U);

    if(mask_input.size()==image_last.size())
    {
        cv::Mat img=image_last.clone();
        cv::Mat mask=mask_input.clone();

        for(int i=0;i<fast;i++)
        {
            cv::pyrDown(img,img);
            cv::pyrDown(mask,mask);
        }

        if(img.channels()!=3)
        {
            cv::cvtColor(image_last,img,cv::COLOR_GRAY2BGR);
        }

        if(mask.channels()!=1)
        {
            cv::cvtColor(mask,mask,cv::COLOR_BGR2GRAY);
        }

        cv::Mat bgd = cv::Mat::zeros(1,65,CV_64FC1);
        cv::Mat fgd = cv::Mat::zeros(1,65,CV_64FC1);

        cv::Mat mask_res = cv::Mat::zeros(mask.size(),CV_8U);
        cv::Mat mask_small = cv::Mat::zeros(mask.size(),CV_8U);

        cv::Rect rect=Rect_FromMask(mask);

        cv::grabCut(img,mask_res,rect,bgd,fgd,5,cv::GC_INIT_WITH_RECT);
        cv::Mat result;

        for(long int i=rect.y;i<rect.y+rect.height;i++)
        {
            for(long int j=rect.x;j<rect.x+rect.width;j++)
            {
                int n=mask_res.at<uchar>(i,j);
                if(n==1 || n==3)
                {
                    mask_small.at<uchar>(i,j)=255;
                }
            }
        }

        cv::bitwise_and(img,img,result,mask_small);

        for(int i=0;i<fast;i++)
        {
            cv::pyrUp(result,result);
            cv::pyrUp(mask_small,mask_small);
        }

        mask_out=mask_small;
    }

    return mask_out;
}

//获取缺陷
result_for_hull image_GetHull(std::vector<cv::Point> contours,int min_size)
{
    result_for_hull hull_out;

    try
    {
        if(contours.size()>3)
        {
            //获取轮廓范围
            cv::Rect roi=Rect_FromClur(contours);

            //获取凸形图像
            cv::Mat img_hull=cv::Mat::zeros(roi.y+roi.height+20,roi.x+roi.width+20,CV_8U);
            std::vector<cv::Point> hull;
            cv::convexHull(cv::Mat(contours),hull);
            cv::drawContours(img_hull,std::vector<std::vector<cv::Point>>{hull},0,cv::Scalar(255, 255, 255), -1);
            cv::drawContours(img_hull,std::vector<std::vector<cv::Point>>{contours},0,cv::Scalar(0, 0, 0), -1);


            //图像差分
            cv::Mat kernel = getStructuringElement(cv::MORPH_RECT,cv::Size(7,7),cv::Point(-1,-1));
            cv::erode(img_hull,img_hull,kernel);
            cv::dilate(img_hull,img_hull,kernel);

            //分析凸缺陷
            int max_s=0;
            cv::Mat labels_, stats_, centroids_;
            cv::connectedComponentsWithStats(img_hull,labels_,stats_,centroids_);
            for (int i = 1; i < centroids_.rows; i++)
            {
                object_for_stats object;
                object.cx       = centroids_.at<double>(i, 0);
                object.cy       = centroids_.at<double>(i, 1);
                object.x        = stats_.at<int>(i,cv::CC_STAT_LEFT);
                object.y        = stats_.at<int>(i,cv::CC_STAT_TOP);
                object.width    = stats_.at<int>(i,cv::CC_STAT_WIDTH);
                object.height   = stats_.at<int>(i,cv::CC_STAT_HEIGHT);
                object.size     = stats_.at<int>(i,cv::CC_STAT_AREA);

                if(object.size>min_size)
                {
                    cv::Mat image=image_GetGray(labels_,i,QRect(object.x,object.y,object.width,object.height));
                    object.Img_point=image.clone();
                    hull_out.hull_list.append(object);
                }

                if(object.size>max_s)
                {
                    max_s=object.size;
                    hull_out.max_hull=object;
                }
            }
        }
    }
    catch (...)
    {
        std::cout<<"image_GetHull error !"<<std::endl;
    }

    return hull_out;
}

//Fast特征点
result_for_fast image_Fast(cv::Mat image_input)
{
    result_for_fast fast_out;

    try
    {
        cv::Mat image=image_input.clone();

        cv::Mat image_show=image.clone();

        if(image.channels()==1)
        {
            cv::cvtColor(image_show,image_show,cv::COLOR_GRAY2BGR);
        }

        std::vector<cv::KeyPoint> fast_list;

        cv::Ptr<cv::FastFeatureDetector> Fast=cv::FastFeatureDetector::create(10,true);

        Fast->detect(image,fast_list);

        cv::drawKeypoints(image_show, fast_list, image_show, cv::Scalar::all(-1), cv::DrawMatchesFlags::DRAW_OVER_OUTIMG);

        fast_out.image_out=image_show.clone();

        fast_out.keypointlist=fast_list;

    }
    catch (...)
    {
        std::cout<<"image_fast error!"<<std::endl;
    }

    return fast_out;
}

//Stats识别结果分层设色
cv::Mat image_Stats_out(cv::Mat image_input,int nccomps,cv::Mat stats,int min,int max)
{
    cv::Mat image_out=cv::Mat::zeros(image_input.size(),CV_8UC3);
    try
    {
        vector<cv::Vec3b> colors(abs(nccomps)+1);
        colors[0] = cv::Vec3b(0,0,0);
        for(int i = 1; i < abs(nccomps); i++ )
        {
            int x        = stats.at<int>(i,cv::CC_STAT_LEFT);
            int y        = stats.at<int>(i,cv::CC_STAT_TOP);
            int width    = stats.at<int>(i,cv::CC_STAT_WIDTH);
            int height   = stats.at<int>(i,cv::CC_STAT_HEIGHT);
            int size     = stats.at<int>(i,cv::CC_STAT_AREA);
            if(size>=min && size<=max && x!=0 && y!=0 && x+width!=image_input.cols && y+height!=image_input.rows)
            {
                colors[i] = cv::Vec3b(255, rand()%256, rand()%256);
            }
            else
            {
                colors[i] = cv::Vec3b(40,40,40);
            }
        }

        for( int i = 0; i < image_input.rows; i++ )
        {
            for( int j = 0; j < image_input.cols; j++ )
            {
                try
                {
                    int label = image_input.at<int>(i,j);
                    image_out.at<cv::Vec3b>(i,j) = colors[label];
                }
                catch (...)
                {
                    qDebug()<<"point error!";
                }
             }
        }

    }
    catch (...)
    {
        std::cout<<"stats_out error!"<<std::endl;
    }
    return image_out;
}

//Stats识别
result_for_stats image_Stats(cv::Mat src,cv::Mat image_input,nsv Nsv)
{
    result_for_stats listI;

    listI.image_out=image_input.clone();

    try
    {
        if(!src.empty())
        {
            cv::Mat labels, stats, centroids;
            int nccomps =cv::connectedComponentsWithStats(src,labels,stats,centroids);
            cv::Mat labels_c;
            labels.convertTo(labels_c,CV_8U);

            for (int i = 1; i < centroids.rows; i++)
            {
                object_for_stats object;
                object.cx       = centroids.at<double>(i, 0);
                object.cy       = centroids.at<double>(i, 1);
                object.x        = stats.at<int>(i,cv::CC_STAT_LEFT);
                object.y        = stats.at<int>(i,cv::CC_STAT_TOP);
                object.width    = stats.at<int>(i,cv::CC_STAT_WIDTH);
                object.height   = stats.at<int>(i,cv::CC_STAT_HEIGHT);
                object.size     = stats.at<int>(i,cv::CC_STAT_AREA);
                if(object.size>=Nsv.min_size && object.size<=Nsv.max_size && object.x!=0 && object.y!=0 && object.x+object.width!=src.cols && object.y+object.height!=src.rows)
                {
                    try
                    {
                        cv::Mat image=image_GetGray(labels,i,QRect(object.x,object.y,object.width,object.height));
                        object.image_last=image_input;
                        object.Img_point=image.clone();
                        std::vector<cv::Mat> image_list=image_Mask(image_input,image,0);
                        if(image_list.size()>0)
                        {
                            object.image_cut_all=image_list[0];
                            object.image_cut=image_list[1];
                            object=image_Angle(object,Nsv.angle_type,Nsv.angle_com,Nsv.angle_left);
                        }
                        listI.object_stats.append(object);
                    }
                    catch (...)
                    {
                        qDebug()<<"stats error！";
                    }
                }
            }
            cv::Mat image_out=image_Stats_out(labels,nccomps,stats,Nsv.min_size,Nsv.max_size);
            listI.image_out=image_out.clone();
        }
    }
    catch (...)
    {
        std::cout<<"image_stats error!"<<std::endl;
    }
    return listI;
}

//物体角度获取
object_for_stats image_Angle(object_for_stats stats,int type,float dep,bool left)
{
    object_for_stats stats_out;
    stats_out=stats;
    stats_out.angle=0;
    try
    {
        std::vector<std::vector<cv::Point> > contours;
        std::vector<cv::Vec4i> hireachy;
        cv::Rect rect=cv::Rect(stats.x,stats.y,stats.width,stats.height);
        cv::Mat image=stats.Img_point(rect).clone();
        cv::findContours(image, contours, hireachy, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_NONE);

        cv::Point2f center;
        float ridus;
        if(contours.size()>0)
        {
            unsigned long long int max_size=0;
            unsigned long long int max_tip=0;
            for(unsigned long long int i=0;i<contours.size();i++)
            {
                if(contours[i].size()>max_size)
                {
                    max_size=contours[i].size();
                    max_tip=i;
                }
            }

            cv::minEnclosingCircle(contours[max_tip],center,ridus);
            cv::Point center_point=cv::Point(int(stats.x+center.x),int(stats.y+center.y));

            //以外接矩长边计角度
            if(type==0)
            {
                std::vector<cv::Point> rect;
                cv::RotatedRect poly=cv::minAreaRect(contours[max_tip]);
                if(poly.size.height<poly.size.width)
                {
                    stats_out.angle=poly.angle+dep;
                }
                else
                {
                    stats_out.angle=poly.angle+dep+90;
                }
            }
            else
            {
                cv::Point mean_point=cv::Point(0,0);

                //以最大凸缺陷计角度
                if(type==1)
                {
                    result_for_hull hull = image_GetHull(contours[max_tip],0);
                    if(hull.hull_list.size()>0)
                    {
                        mean_point=cv::Point(int(hull.max_hull.cx+stats.x),int(hull.max_hull.cy+stats.y));
                    }
                }
                //以fast特征点质心计角度
                else if(type==2)
                {
                    result_for_fast fast_list=image_Fast(stats.image_cut_all(rect));
                    cv::Point2f center=point_center(fast_list.keypointlist);
                    mean_point=cv::Point(int(center.x+stats.x),int(center.y+stats.y));
                }
                //以图像质心计角度
                else if(type==3)
                {
                    mean_point=cv::Point(stats.cx,stats.cy);
                }
                //以轮廓复杂度计角度
                else if(type==4)
                {
                    std::vector<cv::Point> hull;
                    cv::approxPolyDP(contours[max_tip], hull, 5, true);

                    cv::Point2f center=point_center(hull);
                    mean_point=cv::Point(int(center.x+stats.x),int(center.y+stats.y));
                }

                if(left)
                {
                    QPointF point_pol=DesToPolar(QPointF(mean_point.x - center_point.x,center_point.y - mean_point.y));
                    stats_out.angle=point_pol.x()+dep;
                }
                else
                {
                    QPointF point_pol=DesToPolar(QPointF(mean_point.x - center_point.x,mean_point.y - center_point.y));
                    stats_out.angle=point_pol.x()+dep;
                }

                stats_out.point_list.push_back(cv::Point(center_point.x,center_point.y));
                stats_out.point_list.push_back(mean_point);
            }
        }
    }
    catch(...)
    {
        std::cout<<"Angle error!"<<std::endl;
    }
    return stats_out;
}

//最小外接矩转Vector
std::vector<cv::Point> RotatedRect_to_Vector(cv::RotatedRect poly)
{
    std::vector<cv::Point> dst;
    try
    {
        cv::Point2f vertices[4];
        poly.points(vertices);
        for(int i=0;i<4;i++)
        {
            cv::Point p;
            p.x=int(vertices[i].x);
            p.y=int(vertices[i].y);
            dst.push_back(p);
        }

    }
    catch (...)
    {
        std::cout<<"RotatedRect_to_Rect error!"<<std::endl;
    }
    return dst;
}

//排序
void sortA2(float a[], int length)
{
    float temp;
    for(int i = 0; i < length; ++i)
    {
        for(int j = length - 1; j > i; --j)
        {

            if(a[j] > a[j - 1])
            {

                temp = a[j];

                a[j] = a[j - 1];

                a[j - 1] = temp;

            }
        }
    }
}

//获取最大面积轮廓
int MaxTip_Clur(std::vector<std::vector<cv::Point>> contours)
{
    unsigned long long int max_tip=999999;

    try
    {
        unsigned long long int max_area=0;
        for(unsigned long long int j=0;j<contours.size();j++)
        {
            double csize=cv::contourArea(contours[j],false);
            if(csize>max_area)
            {
                max_area=csize;
                max_tip=j;
            }
        }
    }
    catch (...)
    {
        std::cout<<"MaxTip_Clur error!"<<std::endl;
    }

    return max_tip;
}

//矩形框面积计算
QList<float> rect_Size(std::vector<cv::Point> box)
{
    QList<float> out;
    try
    {
        cv::Point A=box[0];
        cv::Point B=box[1];
        cv::Point C=box[2];
        float AB = sqrt(pow(A.x - B.x, 2) + pow(A.y - B.y, 2));
        float AC = sqrt(pow(A.x - C.x, 2) + pow(A.y - C.y, 2));
        float CB = sqrt(pow(C.x - B.x, 2) + pow(C.y - B.y, 2));

        float all[3];
        all[0]=AB;
        all[1]=AC;
        all[2]=CB;

        sortA2(all,3);

        out.push_back(all[2]);
        out.push_back(all[1]);
        out.push_back(all[1]*all[2]);
    }
    catch(...)
    {
        std::cout<<"rect_size error!"<<std::endl;
    }
    return out;
}

//夹角计算
float angle_Findforpoints(cv::Point A,cv::Point B,cv::Point C)
{
    double pi=3.14159265358979323846;
    double theta = atan2(C.x - A.x, C.y - A.y) - atan2(B.x - A.x, B.y - A.y);
    if (theta > pi)
    {
        theta -= 2 * pi;
    }
    if (theta < -pi)
    {
        theta += 2 * pi;
    }
    theta = abs(theta * 180.0 / pi);

    return theta;
}

//逐角计算
std::vector<cv::Rect2f> angles_points(std::vector<cv::Point> hull)
{
    std::vector<cv::Rect2f> angles;

    if(hull.size()>2)
    {
        angles.push_back(cv::Rect2f(hull[0].x,hull[0].y,angle_Findforpoints(hull[0],hull[1],hull[hull.size()-1]),0));

        for(int i=1;i<hull.size()-1;i++)
        {
            angles.push_back(cv::Rect2f(hull[i].x,hull[i].y,angle_Findforpoints(hull[i],hull[i-1],hull[i+1]),0));
        }

        angles.push_back(cv::Rect2f(hull[hull.size()-1].x,hull[hull.size()-1].y,angle_Findforpoints(hull[hull.size()-1],hull[0],hull[hull.size()-2]),0));
    }

    return angles;
}

//绘制识别框
cv::Mat image_out_list(cv::Mat image_input,result_for_findC constur,bool info_show)
{
    cv::Mat image_out=image_input.clone();
    try
    {
        for(int i=0;i<constur.point_list.size();i++)
        {
            std::vector<cv::Point> hull=QlistToCvlist(constur.point_list[i]);

            for(unsigned long long int j=0;j<hull.size()-1;j++)
            {
                cv::line(image_out, hull[j], hull[j+1], cv::Scalar(255,0,255), 2);
                cv::circle(image_out,hull[j],5,cv::Scalar(255,255,255),-1);
            }

            if(constur.list_type!=3)
            {
                cv::line(image_out, hull[hull.size()-1],hull[0], cv::Scalar(255,0,255), 2);
            }
            cv::circle(image_out,hull[hull.size()-1],5,cv::Scalar(255,255,255),-1);

            if(i<constur.angle_list.size())
            {
                std::vector<cv::Rect2f> al=constur.angle_list[i];

                for(int j=0;j<al.size();j++)
                {
                    cv::putText(image_out,std::to_string(int(al[j].width)),cv::Point(al[j].x,al[j].y)+cv::Point(70,30),cv::FONT_HERSHEY_COMPLEX,0.75,cv::Scalar(255,255,255));

                    cv::putText(image_out,std::to_string(j),cv::Point(al[j].x,al[j].y)+cv::Point(30,30),cv::FONT_HERSHEY_COMPLEX,0.75,cv::Scalar(255,255,255));

                    cv::circle(image_out,cv::Point(al[j].x,al[j].y),10,cv::Scalar(255,255,255),2);
                }
            }

            for(unsigned long long int t=0;t<constur.object_stats[i].point_list.size();t++)
            {
                cv::circle(image_out,constur.object_stats[i].point_list[t],5,cv::Scalar(255,255,0),-1);
            }

            if(info_show)
            {
                QString print1= " width:"+QString::number(int(constur.width_list[i]))+
                                " legth:"+QString::number(int(constur.legth_list[i]));

                QString print4= " per:"+QString::number(constur.Per_list[i])+
                                " hullnum:"+QString::number(int(constur.hull_size[i]));

                QString print2= " pyl:"+QString::number(int(constur.pyl_list[i]))+
                                " cir:"+QString::number(int(constur.cir_list[i]))+
                                " angle:"+QString::number(int(constur.object_stats[i].angle));

                QString print3= " rectsize:"+QString::number(int(constur.rectsize_list[i]))+
                                " size:"+QString::number(int(constur.object_stats[i].size));

                cv::Point textpoint=cv::Point(int(constur.object_stats[i].cx+0.5*constur.object_stats[i].width),int(constur.object_stats[i].cy+0.3*constur.object_stats[i].height));

                cv::putText(image_out,print4.toStdString(),cv::Point(textpoint.x+5,textpoint.y-45),cv::FONT_HERSHEY_COMPLEX,1,cv::Scalar(0,255,255));
                cv::putText(image_out,print2.toStdString(),cv::Point(textpoint.x+5,textpoint.y-15),cv::FONT_HERSHEY_COMPLEX,1,cv::Scalar(0,255,255));
                cv::putText(image_out,print3.toStdString(),cv::Point(textpoint.x+5,textpoint.y+15),cv::FONT_HERSHEY_COMPLEX,1,cv::Scalar(0,255,255));
                cv::putText(image_out,print1.toStdString(),cv::Point(textpoint.x+5,textpoint.y+45),cv::FONT_HERSHEY_COMPLEX,1,cv::Scalar(0,255,255));
            }
        }
    }
    catch (...)
    {
        std::cout<<"image_show error!"<<std::endl;
    }
    return image_out;
}

//识别结果描述（最小外接矩，最少点，凸包）
result_for_findC image_FindContours(result_for_stats object,int type,int approx_size)
{
    result_for_findC Contours;

    Contours.image_out=object.image_out.clone();

    try
    {
        cv::Mat image_out=object.image_out.clone();
        for(int i=0;i<object.object_stats.size();i++)
        {
            std::vector<std::vector<cv::Point> > contours;
            std::vector<cv::Vec4i> hireachy;
            cv::Mat image=object.object_stats[i].Img_point.clone();
            cv::findContours(image, contours, hireachy, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_NONE);
            if(contours.size()>0)
            {
                int max_tip=MaxTip_Clur(contours);

                if(max_tip!=999999)
                {
                    std::vector<cv::Point> rect;
                    cv::RotatedRect poly=cv::minAreaRect(contours[max_tip]);

                    rect=RotatedRect_to_Vector(poly);

                    if(rect.size()>3)
                    {
                        QList<float> rect_size=rect_Size(rect);
                        if(rect_size.size()>2)
                        {
                            int per=cv::arcLength(contours[max_tip],true);
                            double csize=cv::contourArea(contours[max_tip],false);
                            float cir_=((4*CV_PI*csize)/std::pow(per,2))*100;
                            float rectsize_=(object.object_stats[i].size/rect_size[2])*100;
                            float pyl_=std::min(rect_size[1]/rect_size[0],rect_size[0]/rect_size[1])*100;

                            int num_hull=0;
                            try
                            {
                                result_for_hull hull_list = image_GetHull(contours[max_tip],100);
                                num_hull=hull_list.hull_list.size();
                            }
                            catch (...)
                            {
                                qDebug()<<"hull error!";
                            }

                            Contours.Per_list       .push_back(per);
                            Contours.object_stats   .push_back(object.object_stats[i]);
                            Contours.legth_list     .push_back(rect_size[1]);
                            Contours.width_list     .push_back(rect_size[0]);
                            Contours.size_list      .push_back(rect_size[2]);
                            Contours.cir_list       .push_back(cir_);
                            Contours.rectsize_list  .push_back(rectsize_);
                            Contours.pyl_list       .push_back(pyl_);
                            Contours.hull_size      .push_back(num_hull);

                            if(type==0)
                            {
                                std::vector<cv::Point> hull=rect;
                                QList<QPointF> points=CvlistToQlist(hull);

                                std::vector<cv::Rect2f> angles=angles_points(hull);
                                Contours.angle_list.append(angles);

                                Contours.point_list.append(points);
                            }
                            else if(type==1)
                            {
                                std::vector<cv::Point> hull;
                                cv::approxPolyDP(contours[max_tip], hull, approx_size, true);
                                QList<QPointF> points=CvlistToQlist(hull);

                                std::vector<cv::Rect2f> angles=angles_points(hull);
                                Contours.angle_list.append(angles);

                                Contours.point_list.append(points);
                            }
                            else if(type==2)
                            {
                                std::vector<cv::Point> poly;
                                std::vector<cv::Point> hull;
                                cv::convexHull(contours[max_tip],poly);
                                cv::approxPolyDP(cv::Mat(poly), hull, approx_size, true);
                                QList<QPointF> points=CvlistToQlist(hull);

                                std::vector<cv::Rect2f> angles=angles_points(hull);
                                Contours.angle_list.append(angles);

                                Contours.point_list.append(points);
                            }
                            else if(type==3)
                            {
                                QList<QPointF> points;
                                points.append(QPointF(object.object_stats[i].x,object.object_stats[i].y));
                                points.append(QPointF(object.object_stats[i].x+object.object_stats[i].width,object.object_stats[i].y+object.object_stats[i].height));
                                Contours.point_list.append(points);
                            }
                        }
                    }
                }
            }
        }
        Contours.list_type=type;
        Contours.image_out=image_out.clone();
    }
    catch(...)
    {
        std::cout<<"FindContours error!"<<std::endl;
    }
    return Contours;
}

//识别流程
result_for_findC image_FindPointstoStats(cv::Mat image_input,nsv Nsv,bool info_show)
{
    result_for_findC contour_out;

    contour_out.image_out=image_input.clone();

    try
    {
        cv::Mat image=image_input.clone();

        if(Nsv.image_roi_enable)
        {
            image=image_Rect(image,Nsv.rect_cut);
        }

        if(Nsv.image_alpha_beta_enable)
        {
            if(Nsv.clane)
            {
                if(Nsv.clane_colour)
                {
                    image=image_Clane(image,Nsv.clane_type,Nsv.clane_clsize,Nsv.clane_size);
                }
                else
                {
                    cv::Mat image_gray_clane=cv::Mat::zeros(image.size(),CV_8U);

                    if(Nsv.color_extract)
                    {
                        image_gray_clane=image_diff_color_gray(image,Nsv.extract_color,30);
                    }
                    else
                    {
                        image_gray_clane=image_Gray(image,Nsv.image_split_type);
                    }

                    cv::Mat image_clane=image_Clane(image_gray_clane,Nsv.clane_type,Nsv.clane_clsize,Nsv.clane_size);

                    if(image_clane.channels()<3)
                    {
                        cv::cvtColor(image_clane,image,cv::COLOR_GRAY2BGR);
                    }
                }
            }
            else
            {
                image=image_AlphaBeta(image,Nsv.image_alpha,Nsv.image_beta);
            }
        }

        if(Nsv.image_clur_enable)
        {
            image=image_Cluster(image,Nsv.image_clur);
        }

        cv::Mat image_gray=cv::Mat(image.size(),CV_8U);

        if(true)
        {
            if(Nsv.color_extract)
            {
                image_gray=image_diff_color_gray(image,Nsv.extract_color,30);
            }
            else
            {
                image_gray=image_Gray(image,Nsv.image_split_type);
            }
        }

        cv::Mat image_thre=cv::Mat(image.size(),CV_8U);

        if(true)
        {
            image_thre=image_Thresold(image_gray,Nsv.image_thresold_inv_enable,Nsv.image_thresold,Nsv.image_thresold_inv);
        }

        if(Nsv.image_re_color)
        {
            cv::bitwise_not(image_thre,image_thre);
        }

        if(Nsv.image_roi_enable)
        {
            image_thre=image_Rect(image_thre,Nsv.rect_cut);
        }

        if(Nsv.image_erdi_enable)
        {
            if(Nsv.erdi_more)
            {
                QList<cv::Mat> image_list=image_ErDi_more(image_thre,Nsv.erdi_legth,Nsv.erdi_width,Nsv.erdi_type,Nsv.erdi_dowhat);

                if(image_list.size()>0)
                {
                    image_thre=image_list[0];
                }
            }
            else
            {
                image_thre=image_ErDi(image_thre,Nsv.image_erdi);
            }
        }

        if(image_thre.channels()>1)
        {
            cv::cvtColor(image_thre,image_thre,cv::COLOR_BGR2GRAY);
        }

        result_for_stats stats=image_Stats(image_thre,image_input,Nsv);

        if(stats.object_stats.size()>0)
        {
            result_for_findC contour = image_FindContours(stats,Nsv.contours_type,Nsv.contours_size);

            if(contour.object_stats.size()>0)
            {
                if(Nsv.other_enable)
                {
                    for(int i=0;i<contour.point_list.size();i++)
                    {
                        qDebug()<<"image_"+QString::number(i)+".bmp";
                        cv::imwrite("image_"+std::to_string(i)+".bmp",contour.object_stats[i].Img_point);

                        QString error="";

                        if(Nsv.legth_enable)
                        {
                            if(contour.legth_list[i]>Nsv.max_legth || contour.legth_list[i]<Nsv.min_legth)
                            {
                                error="legth";
                            }
                        }

                        if(Nsv.width_enable)
                        {
                            if(contour.width_list[i]>Nsv.max_width || contour.width_list[i]<Nsv.min_width)
                            {
                                error="width";
                            }
                        }

                        if(Nsv.rectsize_enable)
                        {
                            if(contour.rectsize_list[i]>Nsv.max_rectsize || contour.rectsize_list[i]<Nsv.min_rectsize)
                            {
                                error="rectsize";
                            }
                        }

                        if(Nsv.pyl_enable)
                        {
                            if(contour.pyl_list[i]>Nsv.max_pyl || contour.pyl_list[i]<Nsv.min_pyl)
                            {
                                error="pyl";
                            }
                        }

                        if(Nsv.cir_enable)
                        {
                            if(contour.cir_list[i]>Nsv.max_cir || contour.cir_list[i]<Nsv.min_cir)
                            {
                                error="cir";
                            }
                        }

                        if(Nsv.hullnum_enable)
                        {
                            if(contour.hull_size[i]>Nsv.max_hullnum || contour.hull_size[i]<Nsv.min_hullnum)
                            {
                                error="hullnum";
                            }
                        }

                        if(error=="")
                        {
                            contour_out.Per_list.append(contour.Per_list[i]);
                            contour_out.legth_list.append(contour.legth_list[i]);
                            contour_out.object_stats.append(contour.object_stats[i]);
                            contour_out.point_list.append(contour.point_list[i]);
                            contour_out.size_list.append(contour.size_list[i]);
                            contour_out.width_list.append(contour.width_list[i]);
                            contour_out.cir_list.append(contour.cir_list[i]);
                            contour_out.pyl_list.append(contour.pyl_list[i]);
                            contour_out.hull_size.append(contour.hull_size[i]);
                            contour_out.rectsize_list.append(contour.rectsize_list[i]);
                            contour_out.angle_list.append(contour.angle_list[i]);
                        }
                    }

                    contour_out.image_out=contour.image_out;
                    contour_out.list_type=contour.list_type;
                }
                else
                {
                    contour_out=contour;
                }

                contour_out.image_out=image_out_list(contour.image_out,contour_out,info_show);
            }
        }
    }
    catch (...)
    {
        qDebug()<<"FindPointstoStats error";
    }

    return contour_out;
}

//识别流程
result_for_findC image_FindPointsOnlyStats(cv::Mat image_input,cv::Mat image_last,nsv Nsv,bool info_show)
{
    result_for_findC contour_out;

    contour_out.image_out=image_input.clone();

    try
    {
        cv::Mat image=image_input.clone();

        if(image.channels()>1)
        {
            cv::cvtColor(image,image,cv::COLOR_BGR2GRAY);
        }

        result_for_stats stats=image_Stats(image,image_last,Nsv);

        if(stats.object_stats.size()>0)
        {
            result_for_findC contour = image_FindContours(stats,Nsv.contours_type,Nsv.contours_size);

            if(contour.object_stats.size()>0)
            {
                if(Nsv.other_enable)
                {
                    for(int i=0;i<contour.point_list.size();i++)
                    {
                        qDebug()<<"image_"+QString::number(i)+".bmp";
                        cv::imwrite("image_"+std::to_string(i)+".bmp",contour.object_stats[i].Img_point);

                        QString error="";

                        if(Nsv.legth_enable)
                        {
                            if(contour.legth_list[i]>Nsv.max_legth || contour.legth_list[i]<Nsv.min_legth)
                            {
                                error="legth";
                            }
                        }

                        if(Nsv.width_enable)
                        {
                            if(contour.width_list[i]>Nsv.max_width || contour.width_list[i]<Nsv.min_width)
                            {
                                error="width";
                            }
                        }

                        if(Nsv.rectsize_enable)
                        {
                            if(contour.rectsize_list[i]>Nsv.max_rectsize || contour.rectsize_list[i]<Nsv.min_rectsize)
                            {
                                error="rectsize";
                            }
                        }

                        if(Nsv.pyl_enable)
                        {
                            if(contour.pyl_list[i]>Nsv.max_pyl || contour.pyl_list[i]<Nsv.min_pyl)
                            {
                                error="pyl";
                            }
                        }

                        if(Nsv.cir_enable)
                        {
                            if(contour.cir_list[i]>Nsv.max_cir || contour.cir_list[i]<Nsv.min_cir)
                            {
                                error="cir";
                            }
                        }

                        if(Nsv.hullnum_enable)
                        {
                            if(contour.hull_size[i]>Nsv.max_hullnum || contour.hull_size[i]<Nsv.min_hullnum)
                            {
                                error="hullnum";
                            }
                        }

                        if(error=="")
                        {
                            contour_out.Per_list.append(contour.Per_list[i]);
                            contour_out.legth_list.append(contour.legth_list[i]);
                            contour_out.object_stats.append(contour.object_stats[i]);
                            contour_out.point_list.append(contour.point_list[i]);
                            contour_out.size_list.append(contour.size_list[i]);
                            contour_out.width_list.append(contour.width_list[i]);
                            contour_out.cir_list.append(contour.cir_list[i]);
                            contour_out.pyl_list.append(contour.pyl_list[i]);
                            contour_out.hull_size.append(contour.hull_size[i]);
                            contour_out.rectsize_list.append(contour.rectsize_list[i]);
                            contour_out.angle_list.append(contour.angle_list[i]);
                        }
                    }

                    contour_out.image_out=contour.image_out;
                    contour_out.list_type=contour.list_type;
                }
                else
                {
                    contour_out=contour;
                }

                contour_out.image_out=image_out_list(contour.image_out,contour_out,info_show);
            }
        }
    }
    catch (...)
    {
        qDebug()<<"FindPointstoStats error";
    }

    return contour_out;
}

//识别流程
result_for_findC image_FindPointstoMask(cv::Mat image_input,cv::Mat last,bool usegradcut)
{
    result_for_findC contour_out;

    contour_out.image_out=image_input.clone();

    try
    {
        cv::Mat image=image_input.clone();

        if(usegradcut)
        {
            image=image_GrabCut(image,last,2);
        }

        if(image.channels()>1)
        {
            cv::cvtColor(image,image,cv::COLOR_BGR2GRAY);
        }

        nsv Nsv;

        result_for_stats stats=image_Stats(image,last,Nsv);

        if(stats.object_stats.size()>0)
        {
            result_for_findC contour = image_FindContours(stats,1,10);

            if(contour.object_stats.size()>0)
            {
                contour_out=contour;

                contour_out.image_out=image_out_list(contour.image_out,contour_out,true);
            }
        }
    }
    catch (...)
    {
        qDebug()<<"FindPointstoMask error";
    }
    return contour_out;
}
