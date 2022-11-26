#ifndef FBC_MESSY_TEST_COMMON_HPP_
#define FBC_MESSY_TEST_COMMON_HPP_

#include "param/nsv_include.h"
#include <QByteArray>
#include <QString>
#include <QBuffer>
#include <QImage>

namespace
{

inline QString converRGB16HexStr(QColor _color)
{
    //r的rgb转化为16进制
    QString redStr = QString("%1").arg(_color.red(),2,16,QChar('0'));
    //g的rgb转化为16进制
    QString greenStr = QString("%1").arg(_color.green(),2,16,QChar('0'));
    //b的rgb转化为16进制
    QString blueStr = QString("%1").arg(_color.blue(),2,16,QChar('0'));
    //将各rgb的拼接在一起形成#000000
    QString hexStr = "#"+redStr+greenStr+blueStr;
    //返回hexStr
    return hexStr;
}

inline QImage cvMat2QImage(const cv::Mat& mat)
{
    // 8-bits unsigned, NO. OF CHANNELS = 1
    if(mat.type() == CV_8UC1)
    {
        QImage image(mat.cols, mat.rows, QImage::Format_Indexed8);
        // Set the color table (used to translate colour indexes to qRgb values)
        image.setColorCount(256);
        for(int i = 0; i < 256; i++)
        {
            image.setColor(i, qRgb(i, i, i));
        }
        // Copy input Mat
        uchar *pSrc = mat.data;
        for(int row = 0; row < mat.rows; row ++)
        {
            uchar *pDest = image.scanLine(row);
            memcpy(pDest, pSrc, mat.cols);
            pSrc += mat.step;
        }
        return image;
    }
    // 8-bits unsigned, NO. OF CHANNELS = 3
    else if(mat.type() == CV_8UC3)
    {
        // Copy input Mat
        const uchar *pSrc = (const uchar*)mat.data;
        // Create QImage with same dimensions as input Mat
        QImage image(pSrc, mat.cols, mat.rows, mat.step, QImage::Format_RGB888);
        return image.rgbSwapped();
    }
    else if(mat.type() == CV_8UC4)
    {
//        qDebug() << "CV_8UC4";
        // Copy input Mat
        const uchar *pSrc = (const uchar*)mat.data;
        // Create QImage with same dimensions as input Mat
        QImage image(pSrc, mat.cols, mat.rows, mat.step, QImage::Format_ARGB32);
        return image.copy();
    }
    else
    {
        qDebug() << "ERROR: Mat could not be converted to QImage.";
        return QImage();
    }
}

inline cv::Mat QImage2cvMat(QImage image)
{
    cv::Mat mat;
    switch(image.format())
    {
    case QImage::Format_ARGB32:
    case QImage::Format_RGB32:
    case QImage::Format_ARGB32_Premultiplied:
        mat = cv::Mat(image.height(), image.width(), CV_8UC4, (void*)image.constBits(), image.bytesPerLine());
        break;
    case QImage::Format_RGB888:
        mat = cv::Mat(image.height(), image.width(), CV_8UC3, (void*)image.constBits(), image.bytesPerLine());
        cv::cvtColor(mat, mat, cv::COLOR_BGR2RGB);
        break;
    case QImage::Format_Indexed8:
        mat = cv::Mat(image.height(), image.width(), CV_8UC1, (void*)image.constBits(), image.bytesPerLine());
        break;
    default: break;
    }
    return mat;
}

//笛卡尔转极坐标
inline QPointF DesToPolar(QPointF point)
{
    float x_=point.x();
    float y_=point.y();
    float pi=3.1415926;
    float distance=sqrt(pow(x_,2)+pow(y_,2));

    float angle_temp;
    if (x_ == 0.0)
    {
        angle_temp = pi / 2.0;
    }
    else
    {
        angle_temp = atan(fabs(y_/x_));
    }

    if ((x_<0.0) && (y_>=0.0))
    {
        angle_temp = pi - angle_temp;
    }
    else if ((x_<0.0) && (y_<0.0))
    {
        angle_temp = pi + angle_temp;
    }
    else if ((x_>=0.0) && (y_<0.0))
    {
        angle_temp = pi * 2.0 - angle_temp;
    }

    float angle_last=angle_temp*360/2/pi;
    QPointF pointP=QPointF(angle_last,distance);
    return pointP;
}

inline QPointF PolarToDes(QPointF pointP)
{
    float _x=cosf(pointP.x()*2*3.1415926/360)*pointP.y();
    float _y=sinf(pointP.x()*2*3.1415926/360)*pointP.y();

    QPointF point=QPointF(_x,_y);
    return point;
}

inline QString base64Toutf8(const char* base64)
{
    //base64编码
    QByteArray abc = QByteArray::fromBase64(base64);
    //qt自带的utf8编解码器
    QTextCodec* utf8Codec= QTextCodec::codecForName("utf-8");
    //qt自带的gb2312编解码器
    QTextCodec* gb2312Codec = QTextCodec::codecForName("gb2312");
    //将gb2312的base64编码转成unicode编码，也就是统一编码
    QString strUnicode= gb2312Codec->toUnicode(abc);
    //把统一编码转为utf8编码，统一编码在此做了中间媒介的作用。
    QByteArray ByteUtf8= utf8Codec->fromUnicode(strUnicode);
    //QByteArray转为QString
    QString result = QString(ByteUtf8);

    return result;
}

inline const char* utf8Togbk(const char* utf8)
{
    return const_cast<char*>(utf8);
}

inline std::string base64Decode(const char* Data, int DataByte)
{
    //解码表
    const char DecodeTable[] =
    {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        62, // '+'
        0, 0, 0,
        63, // '/'
        52, 53, 54, 55, 56, 57, 58, 59, 60, 61, // '0'-'9'
        0, 0, 0, 0, 0, 0, 0,
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12,
        13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, // 'A'-'Z'
        0, 0, 0, 0, 0, 0,
        26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38,
        39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, // 'a'-'z'
    };
    std::string strDecode;
    int nValue;
    int i = 0;
    while (i < DataByte) {
        if (*Data != '\r' && *Data != '\n')
        {
            nValue = DecodeTable[*Data++] << 18;
            nValue += DecodeTable[*Data++] << 12;
            strDecode += (nValue & 0x00FF0000) >> 16;
            if (*Data != '=')
            {
                nValue += DecodeTable[*Data++] << 6;
                strDecode += (nValue & 0x0000FF00) >> 8;
                if (*Data != '=') {
                    nValue += DecodeTable[*Data++];
                    strDecode += nValue & 0x000000FF;
                }
            }
            i += 4;
        }
        else {
            Data++;
            i++;
        }
    }
    return strDecode;
}

inline std::string base64Encode(const unsigned char* Data, int DataByte)
{
    //编码表
    const char EncodeTable[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    //返回值
    std::string strEncode;
    unsigned char Tmp[4] = { 0 };
    int LineLength = 0;
    for (int i = 0; i < (int)(DataByte / 3); i++) {
        Tmp[1] = *Data++;
        Tmp[2] = *Data++;
        Tmp[3] = *Data++;
        strEncode += EncodeTable[Tmp[1] >> 2];
        strEncode += EncodeTable[((Tmp[1] << 4) | (Tmp[2] >> 4)) & 0x3F];
        strEncode += EncodeTable[((Tmp[2] << 2) | (Tmp[3] >> 6)) & 0x3F];
        strEncode += EncodeTable[Tmp[3] & 0x3F];
        if (LineLength += 4, LineLength == 76) { strEncode += "\r\n"; LineLength = 0; }
    }
    //对剩余数据进行编码
    int Mod = DataByte % 3;
    if (Mod == 1) {
        Tmp[1] = *Data++;
        strEncode += EncodeTable[(Tmp[1] & 0xFC) >> 2];
        strEncode += EncodeTable[((Tmp[1] & 0x03) << 4)];
        strEncode += "==";
    }
    else if (Mod == 2) {
        Tmp[1] = *Data++;
        Tmp[2] = *Data++;
        strEncode += EncodeTable[(Tmp[1] & 0xFC) >> 2];
        strEncode += EncodeTable[((Tmp[1] & 0x03) << 4) | ((Tmp[2] & 0xF0) >> 4)];
        strEncode += EncodeTable[((Tmp[2] & 0x0F) << 2)];
        strEncode += "=";
    }


    return strEncode;
}

//imgType 包括png bmp jpg jpeg等opencv能够进行编码解码的文件
inline std::string Mat2Base64(const cv::Mat &img, std::string imgType)
{
    //Mat转base64
    std::string img_data;
    std::vector<uchar> vecImg;
    std::vector<int> vecCompression_params;
    vecCompression_params.push_back(cv::IMWRITE_JPEG_QUALITY);
    vecCompression_params.push_back(90);
    imgType = "." + imgType;
    cv::imencode(imgType, img, vecImg, vecCompression_params);
    img_data = base64Encode(vecImg.data(), vecImg.size());
    return img_data;
}

inline cv::Mat Base2Mat(std::string &base64_data)
{
    cv::Mat img;
    std::string s_mat;
    s_mat = base64Decode(base64_data.data(), base64_data.size());
    std::vector<char> base64_img(s_mat.begin(), s_mat.end());
    img = cv::imdecode(base64_img, cv::IMREAD_COLOR);
    return img;
}

inline QByteArray imageToBase64(QString image)
{
    QImage Image(image);
    QByteArray ba;
    QBuffer buf(&ba);
    Image.save(&buf, "png");
    return ba.toBase64();
}

inline QList<QPointF> CvlistToQlist(std::vector<cv::Point> pointlist)
{
    QList<QPointF> QPointlist;
    for(unsigned int i=0;i<pointlist.size();i++)
    {
        QPointF point=QPointF(pointlist[i].x,pointlist[i].y);
        QPointlist.append(point);
    }
    return QPointlist;
}

inline std::vector<cv::Point> QlistToCvlist(QList<QPointF> pointlist)
{
    std::vector<cv::Point> CVPointlist;
    for(int i=0;i<pointlist.size();i++)
    {
        cv::Point point=cv::Point(pointlist[i].x(),pointlist[i].y());
        CVPointlist.push_back(point);
    }
    return CVPointlist;
}

inline std::vector<cv::Point> MatToVector(cv::Mat &mat)
{
    return (std::vector<cv::Point>)(mat.reshape(1, 1));
}

inline bool StrinList(QString str,QList<QString> labels)
{
    bool flag=false;
    for(int i=0;i<labels.size();i++)
    {
        if(labels[i]==str)
        {
            flag=true;
            break;
        }
    }
    return flag;
}

inline bool intinList(int str,QList<int> labels)
{
    bool flag=false;
    for(int i=0;i<labels.size();i++)
    {
        if(labels[i]==str)
        {
            flag=true;
            break;
        }
    }
    return flag;
}

inline bool intinVector(int str,std::vector<int> labels)
{
    bool flag=false;
    for(int i=0;i<labels.size();i++)
    {
        if(labels[i]==str)
        {
            flag=true;
            break;
        }
    }
    return flag;
}

inline bool RectInRectList(std::vector<cv::Point> r,std::vector<std::vector<cv::Point>> rl,bool igor)
{
    bool flag=false;
    for(int i=0;i<rl.size();i++)
    {
        if(igor)
        {
            if(rl[i].size()==r.size())
            {
                bool isdiff=false;

                for(int j=0;j<r.size();j++)
                {
                    bool ishave=false;

                    for(int s=0;s<rl[i].size();s++)
                    {
                        if(r[j]==rl[i][s])
                        {
                            ishave=true;
                            break;
                        }
                    }

                    if(!ishave)
                    {
                        isdiff=true;
                        break;
                    }
                }

                if(!isdiff)
                {
                    flag=true;
                    break;
                }
            }
        }
        else
        {
            if(rl[i]==r)
            {
                flag=true;
                break;
            }
        }
    }
    return flag;
}

inline int TipinList(QString str,QList<QString> labels)
{
    int tip=9999;
    for(int i=0;i<labels.size();i++)
    {
        if(labels[i]==str)
        {
            tip=i;
            break;
        }
    }
    return tip;
}

inline int PointinList(cv::Point str,std::vector<cv::Point> labels)
{
    bool flag=false;
    for(int i=0;i<labels.size();i++)
    {
        if(labels[i]==str)
        {
            flag=true;
            break;
        }
    }
    return flag;
}

inline QList<QPoint> PointFToPoint(QList<QPointF> pointlist)
{
    QList<QPoint> listpoint;
    for(int i=0;i<pointlist.size();i++)
    {
        listpoint.append(QPoint(pointlist[i].x(),pointlist[i].y()));
    }
    return listpoint;
}

inline QString GBK2UTF8(const QString &inStr)
{
    QTextCodec *gbk = QTextCodec::codecForName("GB18030");

    QString g2u = gbk->toUnicode(gbk->fromUnicode(inStr));
    return g2u;
}

inline QString UTF82GBK(const QString &inStr)
{
    QTextCodec *gbk = QTextCodec::codecForName("GB18030");

    QString utf2gbk = gbk->toUnicode(inStr.toLocal8Bit());
    return utf2gbk;
}

inline std::string gbk2utf8(const QString &inStr)
{
    return GBK2UTF8(inStr).toStdString();
}

inline QString utf82gbk(const std::string &inStr)
{
    QString str = QString::fromStdString(inStr);

    return UTF82GBK(str);
}

inline QList<QPointF> pointlist2k(QList<QPointF> list,float k)
{
    QList<QPointF> listI;
    for(int i=0;i<list.size();i++)
    {
        QPointF point=list[i];
        QPointF pointk=QPointF(point.x()*k,point.y()*k);
        listI.append(pointk);
    }
    return listI;
}

} // namespace

#endif // FBC_MESSY_TEST_COMMON_HPP_
