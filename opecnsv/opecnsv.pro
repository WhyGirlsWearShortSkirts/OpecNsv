QT       += core gui

QT      += concurrent

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

RC_ICONS = titg.ico

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    custom/lvideoshowqlables.cpp \
    custom/nsv_points.cpp \
    custom/nsv_pushbutton.cpp \
    custom/nsv_scene.cpp \
    custom/nsv_view.cpp \
    main.cpp \
    mainwindow.cpp \
    param/nsv_image_analy.cpp \
    param/nsv_image_tree.cpp \
    param/nsv_json_analy.cpp \
    param/nsv_readimagefordir.cpp \
    param/soft_encryption.cpp \
    widget/labels_ui.cpp \
    custom_tree/lattree_newdata.cpp \
    custom_tree/lattree_newitem.cpp \
    custom_tree/lattree_newnode.cpp \
    custom_tree/lattree_pushbutton.cpp \
    custom_tree/lattree_tree.cpp \
    widget/nsv_tree.cpp \
    widget/ocr_more_view.cpp \
    widget/setting_ui.cpp \
    widget/softencrypdialog.cpp

HEADERS += \
    custom/lvideoshowqlables.h \
    custom/nsv_points.h \
    custom/nsv_pushbutton.h \
    custom/nsv_scene.h \
    custom/nsv_view.h \
    mainwindow.h \
    param/nsv_common.h \
    param/nsv_global_param.h \
    param/nsv_image_analy.h \
    param/nsv_image_tree.h \
    param/nsv_json_analy.h \
    param/nsv_readimagefordir.h \
    param/nsv_include.h \
    param/soft_encryption.h \
    widget/labels_ui.h \
    custom_tree/lattree_newnode.h \
    param/lattree_param.h \
    custom_tree/lattree_newdata.h \
    custom_tree/lattree_newitem.h \
    custom_tree/lattree_pushbutton.h \
    custom_tree/lattree_tree.h \
    widget/nsv_tree.h \
    widget/ocr_more_view.h \
    widget/setting_ui.h \
    widget/softencrypdialog.h

FORMS += \
    custom_tree/lattree_newdata.ui \
    custom_tree/lattree_newitem.ui \
    custom_tree/lattree_newnode.ui \
    mainwindow.ui \
    widget/labels_ui.ui \
    widget/nsv_tree.ui \
    widget/ocr_more_view.ui \
    widget/setting_ui.ui \
    widget/softencrypdialog.ui

RESOURCES += \
    mmp.qrc

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

INCLUDEPATH += D:\opencv455\opencv\mingw\install\include
INCLUDEPATH += D:\opencv455\opencv\mingw\install\include\opencv2

INCLUDEPATH += rapidjson/error
INCLUDEPATH += rapidjson/internal
INCLUDEPATH += rapidjson/msinttypes
INCLUDEPATH += rapidjson

LIBS += D:\opencv455\opencv\mingw\install\x64\mingw\lib\libopencv_*.a

DISTFILES += \
    未完成部分

