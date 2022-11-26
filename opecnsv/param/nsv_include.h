#ifndef NSV_INCLUDE_H
#define NSV_INCLUDE_H

#include <highgui/highgui.hpp>
#include <opencv.hpp>
#include <core/core.hpp>
#include <features2d.hpp>
#include <flann.hpp>
#include <highgui.hpp>
#include <imgcodecs.hpp>
#include <windows.h>

#include <cstdlib>
#include <iostream>

#include <QPair>
#include <QDir>
#include <QFile>
#include <QString>
#include <QtDebug>
#include <QFileDialog>
#include <QMessageBox>

#include <QImage>
#include <QBuffer>

#include <QKeyEvent>

#include <QCoreApplication>
#include <QThread>
#include <QThreadPool>
#include <QtConcurrent/QtConcurrent>
#include <QFuture>
#include <QColorDialog>

#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/prettywriter.h"
#include "rapidjson/stringbuffer.h"

#include <iostream>
#include <fstream>
#include <string>

#include "param/nsv_common.h"
#include "param/nsv_global_param.h"
#include "param/nsv_readimagefordir.h"
#include "param/nsv_image_analy.h"
#include "param/nsv_json_analy.h"

#include "widget/labels_ui.h"

Q_DECLARE_METATYPE(cv::Mat)
Q_DECLARE_METATYPE(cv::Rect)
Q_DECLARE_METATYPE(cv::Size)
Q_DECLARE_METATYPE(cv::Point)
Q_DECLARE_METATYPE(cv::Scalar)

using namespace std;

#endif // NSV_INCLUDE_H
