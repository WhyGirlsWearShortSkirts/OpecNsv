#include "nsv_image_tree.h"

//构造函数
nsv_image_tree::nsv_image_tree()
{

}

//=============================== 图像处理流程树专有算法 ===============================================================================================

//初始化变量类型
QList<QString> nsv_image_tree::init_Type()
{
    QList<QString> type;

    type.append("bool");
    type.append("int");
    type.append("float");
    type.append("double");

    type.append("image");
    type.append("color");
    type.append("size");
    type.append("rect");

    return type;
}

//初始化算子
QList<param_cross> nsv_image_tree::init_Param()
{
    QList<param_cross> param_list;

    param_cross param;

    param.name="图像二值化";

    param.intype.append("image");
    param.intype.append("bool");
    param.intype.append("int");
    param.intype.append("int");

    param.intype_info.append("待处理图");
    param.intype_info.append("启用双边限制");
    param.intype_info.append("低阈值");
    param.intype_info.append("高阈值");

    param.outtype.append("image");

    param.outtype_info.append("二值化图");

    param.info="对图像进行二值化操作，将图像有灰度图转换为二值化图。";
    param.param="输入：待处理图，启用双边限制，低阈值，高阈值。输出：二值化图。";

    param.tig=param_list.size();

    param_list.append(param);

    param_cross param1;

    param1.name="图像灰度化";

    param1.intype.append("image");
    param1.intype.append("int");

    param1.intype_info.append("待处理图");
    param1.intype_info.append("灰度化类型");

    param1.outtype.append("image");

    param1.outtype_info.append("灰度图");

    param1.info="转换彩色图像为灰度图，类型至为0时，直接转化为灰度图，为123时，分别对应rgb三通道图像。";
    param1.param="输入：待处理图，类型。输出：灰度图。";

    param1.tig=param_list.size();

    param_list.append(param1);

    param_cross param7;

    param7.name="图像反色";

    param7.intype.append("image");

    param7.intype_info.append("待处理图");

    param7.outtype.append("image");

    param7.outtype_info.append("反色图");

    param7.info="对图像执行反色操作。";
    param7.param="输入：待处理图。输出：反色图。";

    param7.tig=param_list.size();

    param_list.append(param7);

    param_cross param2;

    param2.name="开操作";

    param2.intype.append("image");
    param2.intype.append("int");

    param2.intype_info.append("待处理图");
    param2.intype_info.append("开操作强度");

    param2.outtype.append("image");

    param2.outtype_info.append("结果图");

    param2.info="对图像执行开操作，去除离散点和毛边。";
    param2.param="输入：待处理图，开操作强度。输出：结果图。";

    param2.tig=param_list.size();

    param_list.append(param2);

    param_cross param3;

    param3.name="闭操作";

    param3.intype.append("image");
    param3.intype.append("int");

    param3.intype_info.append("待处理图");
    param3.intype_info.append("闭操作强度");

    param3.outtype.append("image");

    param3.outtype_info.append("结果图");

    param3.info="对图像执行闭操作，消弭孔洞，连接间隙。";
    param3.param="输入：待处理图，闭操作强度。输出：结果图。";

    param3.tig=param_list.size();

    param_list.append(param3);

    param_cross param4;

    param4.name="感兴趣区域提取";

    param4.intype.append("image");
    param4.intype.append("rect");

    param4.intype_info.append("待处理图");
    param4.intype_info.append("感兴趣区域");

    param4.outtype.append("image");

    param4.outtype_info.append("结果图");

    param4.info="截取图像感兴趣区域，非感兴趣区域置白色。";
    param4.param="输入：待处理图，感兴趣区域。输出：结果图。";

    param4.tig=param_list.size();

    param_list.append(param4);

    param_cross param19;

    param19.name="对比度亮度调节";

    param19.intype.append("image");
    param19.intype.append("float");
    param19.intype.append("int");

    param19.intype_info.append("待处理图");
    param19.intype_info.append("对比度");
    param19.intype_info.append("亮度");

    param19.outtype.append("image");

    param19.outtype_info.append("调整图");

    param19.info="调整图像对比度，亮度。";
    param19.param="输入：待处理图，对比度，亮度。输出：调整图。";

    param19.tig=param_list.size();

    param_list.append(param19);

    param_cross param5;

    param5.name="颜色分布";

    param5.intype.append("image");
    param5.intype.append("color");

    param5.intype_info.append("待处理图");
    param5.intype_info.append("基色");

    param5.outtype.append("image");

    param5.outtype_info.append("分布图");

    param5.info="以基色为零值，重新计算图像中颜色情况，处理后图像颜色越接近黑色，即越接近基色，越接近白色，则越远离基色。";
    param5.param="输入：待处理图，基色。输出：分布图。";

    param5.tig=param_list.size();

    param_list.append(param5);

    param_cross param6;

    param6.name="灰度分布";

    param6.intype.append("image");
    param6.intype.append("int");

    param6.intype_info.append("待处理图");
    param6.intype_info.append("设定灰度");

    param6.outtype.append("image");

    param6.outtype_info.append("分布图");

    param6.info="以设定灰度为零值，重新计算图像中灰度情况，处理后图像颜色越接近黑色，即越接近设置灰度，越接近白色，则越远离设置灰度。";
    param6.param="输入：待处理图，设定灰度。输出：分布图。";

    param6.tig=param_list.size();

    param_list.append(param6);

    param_cross param8;

    param8.name="色差提取";

    param8.intype.append("image");
    param8.intype.append("color");
    param8.intype.append("int");

    param8.intype_info.append("待处理图");
    param8.intype_info.append("基色");
    param8.intype_info.append("让渡阈值");

    param8.outtype.append("image");

    param8.outtype_info.append("色差图");

    param8.info="先计算图像中颜色与基色的三通道差值，再计算基色和图像色颜色趋势差值，最后做权值计算。";
    param8.param="输入：待处理图，基色，让渡阈值。输出：色差图。";

    param8.tig=param_list.size();

    param_list.append(param8);

    param_cross param9;

    param9.name="因子调制";

    param9.intype.append("image");
    param9.intype.append("int");
    param9.intype.append("int");
    param9.intype.append("int");
    param9.intype.append("int");

    param9.intype_info.append("待处理图");
    param9.intype_info.append("因子长");
    param9.intype_info.append("因子宽");
    param9.intype_info.append("因子类型");
    param9.intype_info.append("操作类型");

    param9.outtype.append("image");

    param9.outtype_info.append("结果图");

    param9.info="使用特殊形状因子进行的图像形态学操作，可设定因子的长宽类型，可选择执行的形态学操作类型。";
    param9.param="输入：待处理图，因子长，因子宽，因子类型，操作类型。输出：结果图。";

    param9.tig=param_list.size();

    param_list.append(param9);

    param_cross param10;

    param10.name="直方图均衡化";

    param10.intype.append("image");
    param10.intype.append("int");
    param10.intype.append("double");
    param10.intype.append("size");

    param10.intype_info.append("待处理图");
    param10.intype_info.append("均衡化类型");
    param10.intype_info.append("均衡化尺度");
    param10.intype_info.append("因子大小");

    param10.outtype.append("image");

    param10.outtype_info.append("结果图");

    param10.info="对图像执行均衡化操作，提取优势灰度值并拉伸至全灰度域，已达到提高对比度的效果。";
    param10.param="输入：待处理图，均衡化类型，均衡化尺度，因子大小。输出：结果图。";

    param10.tig=param_list.size();

    param_list.append(param10);

    param_cross param11;

    param11.name="直方图均衡化(彩色)";

    param11.intype.append("image");
    param11.intype.append("int");
    param11.intype.append("double");
    param11.intype.append("size");

    param11.intype_info.append("待处理图");
    param11.intype_info.append("均衡化类型");
    param11.intype_info.append("均衡化尺度");
    param11.intype_info.append("因子大小");

    param11.outtype.append("image");

    param11.outtype_info.append("结果图");

    param11.info="对图像各通道执行均衡化操作，再将分离的通道合成在一起。";
    param11.param="输入：待处理图，均衡化类型，均衡化尺度，因子大小。输出：结果图。";

    param11.tig=param_list.size();

    param_list.append(param11);

    param_cross param12;

    param12.name="图像梯度化";

    param12.intype.append("image");
    param12.intype.append("int");
    param12.intype.append("int");

    param12.intype_info.append("待处理图");
    param12.intype_info.append("因子类型");
    param12.intype_info.append("梯度化尺度");

    param12.outtype.append("image");

    param12.outtype_info.append("梯度图");

    param12.info="对图像进行梯度提取，并输出梯度图。";
    param12.param="输入：待处理图，因子类型，梯度化尺度。输出：梯度图。";

    param12.tig=param_list.size();

    param_list.append(param12);

    param_cross param13;

    param13.name="图像梯度化(彩色)";

    param13.intype.append("image");
    param13.intype.append("int");
    param13.intype.append("int");
    param13.intype.append("bool");
    param13.intype.append("int");
    param13.intype.append("int");
    param13.intype.append("bool");

    param13.intype_info.append("待处理图");
    param13.intype_info.append("因子类型");
    param13.intype_info.append("梯度化尺度");
    param13.intype_info.append("启用幅值限制");
    param13.intype_info.append("最小幅值");
    param13.intype_info.append("最大幅值");
    param13.intype_info.append("启用加算");

    param13.outtype.append("image");

    param13.outtype_info.append("梯度图");

    param13.info="对图像各通道执行梯度化操作，再将分离的通道合成在一起，可选择对梯度化图像进行幅值限制及选择梯度图合成方式，包括三通道合成和图像加算。";
    param13.param="输入：待处理图，因子类型，梯度化尺度，启用幅值限制，最小幅值，最大幅值，启用加算。输出：梯度图。";

    param13.tig=param_list.size();

    param_list.append(param13);

    param_cross param14;

    param14.name="散点清理";

    param14.intype.append("image");
    param14.intype.append("int");

    param14.intype_info.append("待处理图");
    param14.intype_info.append("离散点直径");

    param14.outtype.append("image");

    param14.outtype_info.append("结果图");

    param14.info="清理图像前景离散点。";
    param14.param="输入：待处理图，离散点直径。输出：结果图。";

    param14.tig=param_list.size();

    param_list.append(param14);

    param_cross param15;

    param15.name="散点清理(彩色)";

    param15.intype.append("image");
    param15.intype.append("int");

    param15.intype_info.append("待处理图");
    param15.intype_info.append("离散点直径");

    param15.outtype.append("image");

    param15.outtype_info.append("结果图");

    param15.info="清理图像前景离散点。";
    param15.param="输入：待处理图，离散点直径。输出：结果图。";

    param15.tig=param_list.size();

    param_list.append(param15);

    param_cross param16;

    param16.name="通道合成";

    param16.intype.append("image");
    param16.intype.append("image");
    param16.intype.append("image");

    param16.intype_info.append("B通道图");
    param16.intype_info.append("G通道图");
    param16.intype_info.append("R通道图");

    param16.outtype.append("image");

    param16.outtype_info.append("彩色图");

    param16.info="将三幅灰度图按bgr顺序合成为一张彩色图。";
    param16.param="输入：B通道图，G通道图，R通道图。输出：彩色图。";

    param16.tig=param_list.size();

    param_list.append(param16);

    param_cross param17;

    param17.name="图像与或非";

    param17.intype.append("image");
    param17.intype.append("image");
    param17.intype.append("int");

    param17.intype_info.append("计算图1");
    param17.intype_info.append("计算图2");
    param17.intype_info.append("操作类型");

    param17.outtype.append("image");

    param17.outtype_info.append("结果图");

    param17.info="对两幅相同大小图像各像素执行与，或，异或操作。";
    param17.param="输入：计算图1，计算图2，操作类型。输出：结果图。";

    param17.tig=param_list.size();

    param_list.append(param17);

    param_cross param18;

    param18.name="图像K聚类";

    param18.intype.append("image");
    param18.intype.append("int");

    param18.intype_info.append("待处理图");
    param18.intype_info.append("组别n");

    param18.outtype.append("image");

    param18.outtype_info.append("结果图");

    param18.info="对图像执行K聚类操作，将图像中颜色按相近程度划分为2的n次方组。";
    param18.param="输入：待处理图，组别n。输出：结果图。";

    param18.tig=param_list.size();

    param_list.append(param18);

    return param_list;
}

//执行算子
QList<QVariant> nsv_image_tree::item_an(QList<QVariant> input,param_cross param)
{
    QList<QVariant> data_out;

    switch(param.tig)
    {
    case 0:
        if(input.size()==4)
        {
            cv::Mat image=image_Thresold(input[0].value<cv::Mat>(),input[1].toBool(),input[2].toInt(),input[3].toInt());
            QVariant data;

            data.setValue<cv::Mat>(image);

            data_out.append(data);
        }
        break;
    case 1:
        if(input.size()==2)
        {
            cv::Mat image=image_Gray(input[0].value<cv::Mat>(),input[1].toInt());

            QVariant data;

            data.setValue<cv::Mat>(image);

            data_out.append(data);
        }
        break;
    case 2:
        if(input.size()==1)
        {
            cv::Mat image;

            cv::bitwise_not(input[0].value<cv::Mat>(),image);

            QVariant data;

            data.setValue<cv::Mat>(image);

            data_out.append(data);
        }
        break;
    case 3:
        if(input.size()==2)
        {
            cv::Mat image=image_ErDi(input[0].value<cv::Mat>(),abs(input[1].toInt()));

            QVariant data;

            data.setValue<cv::Mat>(image);

            data_out.append(data);
        }
        break;
    case 4:
        if(input.size()==2)
        {
            cv::Mat image=image_ErDi(input[0].value<cv::Mat>(),-1*abs(input[1].toInt()));

            QVariant data;

            data.setValue<cv::Mat>(image);

            data_out.append(data);
        }
        break;
    case 5:
        if(input.size()==2)
        {
            cv::Mat image=image_Rect(input[0].value<cv::Mat>(),input[1].value<cv::Rect>());

            QVariant data;

            data.setValue<cv::Mat>(image);

            data_out.append(data);
        }
        break;
    case 6:
        if(input.size()==3)
        {
            cv::Mat image=image_AlphaBeta(input[0].value<cv::Mat>(),input[1].toFloat(),input[2].toInt());

            QVariant data;

            data.setValue<cv::Mat>(image);

            data_out.append(data);
        }
        break;
    case 7:
        if(input.size()==2)
        {
            cv::Mat image=image_diff_color(input[0].value<cv::Mat>(),input[1].value<cv::Scalar>());

            QVariant data;

            data.setValue<cv::Mat>(image);

            data_out.append(data);
        }
        break;
    case 8:
        if(input.size()==2)
        {
            cv::Mat image=image_diff_gray(input[0].value<cv::Mat>(),input[1].toInt());

            QVariant data;

            data.setValue<cv::Mat>(image);

            data_out.append(data);
        }
        break;
    case 9:
        if(input.size()==3)
        {
            cv::Mat image=image_diff_color_gray(input[0].value<cv::Mat>(),input[1].value<cv::Scalar>(),input[2].toInt());

            QVariant data;

            data.setValue<cv::Mat>(image);

            data_out.append(data);
        }
        break;
    case 10:
        if(input.size()==5)
        {
            QList<cv::Mat> image=image_ErDi_more(input[0].value<cv::Mat>(),input[1].toInt(),input[2].toInt(),input[3].toInt(),input[4].toInt());

            QVariant data;

            data.setValue<cv::Mat>(image[0]);

            data_out.append(data);
        }
        break;
    case 11:
        if(input.size()==4)
        {
            cv::Mat image=image_Clane(input[0].value<cv::Mat>(),input[1].toInt(),input[2].toDouble(),input[3].value<cv::Size>());

            QVariant data;

            data.setValue<cv::Mat>(image);

            data_out.append(data);
        }
        break;
    case 12:
        if(input.size()==4)
        {
            cv::Mat image=image_Clane_colour(input[0].value<cv::Mat>(),input[1].toInt(),input[2].toDouble(),input[3].value<cv::Size>());

            QVariant data;

            data.setValue<cv::Mat>(image);

            data_out.append(data);
        }
        break;
    case 13:
        if(input.size()==3)
        {
            cv::Mat image=image_Gradient(input[0].value<cv::Mat>(),input[1].toInt(),input[2].toInt());

            QVariant data;

            data.setValue<cv::Mat>(image);

            data_out.append(data);
        }
        break;
    case 14:
        if(input.size()==7)
        {
            cv::Mat image=image_Gradient_colour(input[0].value<cv::Mat>(),input[1].toInt(),input[2].toInt(),input[3].toBool(),input[4].toInt(),input[5].toInt(),input[2].toBool());

            QVariant data;

            data.setValue<cv::Mat>(image);

            data_out.append(data);
        }
        break;
    case 15:
        if(input.size()==2)
        {
            cv::Mat image=image_Stats_clear(input[0].value<cv::Mat>(),input[1].toInt());

            QVariant data;

            data.setValue<cv::Mat>(image);

            data_out.append(data);
        }
        break;
    case 16:
        if(input.size()==2)
        {
            cv::Mat image=image_Stats_clear_colour(input[0].value<cv::Mat>(),input[1].toInt());

            QVariant data;

            data.setValue<cv::Mat>(image);

            data_out.append(data);
        }
        break;
    case 17:
        if(input.size()==3)
        {
            std::vector<cv::Mat> matlist;

            matlist.push_back(input[0].value<cv::Mat>());
            matlist.push_back(input[1].value<cv::Mat>());
            matlist.push_back(input[2].value<cv::Mat>());

            cv::Mat image=image_Grlour(matlist);

            QVariant data;

            data.setValue<cv::Mat>(image);

            data_out.append(data);
        }
        break;
    case 18:
        if(input.size()==3)
        {
            cv::Mat image=image_Arithmetic(input[0].value<cv::Mat>(),input[1].value<cv::Mat>(),input[2].toInt());

            QVariant data;

            data.setValue<cv::Mat>(image);

            data_out.append(data);
        }
        break;
    case 19:
        if(input.size()==2)
        {
            cv::Mat image=image_Cluster(input[0].value<cv::Mat>(),input[1].toInt());

            QVariant data;

            data.setValue<cv::Mat>(image);

            data_out.append(data);
        }
        break;
    }

    return data_out;
}

//执行流程树
QList<QVariant> nsv_image_tree::item_run(tree_param tree,QList<QVariant> exec_data)
{
    QList<QList<param_cross>> pc = nsv_image_tree::ListAsTree(tree.tree,tree.d_l,tree.p_l,tree.n_l);
    for(int i=0;i<pc.size();i++)
    {
        if(pc[i].size()>0)
        {
            if(pc[i][0].tig==300001)
            {
                if(pc[i].size()>=3)
                {
                    if(pc[i][0].inList.size()>=3)
                    {
                        data_cross d1;
                        if(pc[i][0].inList[1]-100000<tree.d_l.size() && pc[i][0].inList[1]-100000<exec_data.size())
                        {
                            d1=tree.d_l[pc[i][0].inList[1]-100000];
                            d1.data=exec_data[pc[i][0].inList[1]-100000];
                        }
                        else
                        {
                            qDebug()<<"判断：比较值变量编号超出变量表，请重新构建判断结构。";
                            emit error_back("判断：比较值变量编号超出变量表，请重新构建判断结构。");
                            exec_data.clear();
                            return exec_data;
                        }

                        data_cross d2;
                        if(pc[i][0].inList[2]-100000<tree.d_l.size() && pc[i][0].inList[2]-100000<exec_data.size())
                        {
                            d2=tree.d_l[pc[i][0].inList[2]-100000];
                            d2.data=exec_data[pc[i][0].inList[2]-100000];
                        }
                        else
                        {
                            qDebug()<<"判断：待比值变量编号超出变量表，请重新构建判断结构。";
                            emit error_back("判断：待比值变量编号超出变量表，请重新构建判断结构。");
                            exec_data.clear();
                            return exec_data;
                        }

                        int judge=item_run_judge(pc[i][0].inList[0],d1,d2);

                        if(judge==0)
                        {
                            QList<QVariant> exec_data_an=item_run_an(pc[i][1],tree,exec_data);
                            if(exec_data_an.size()==0)
                            {
                                qDebug()<<"流程树执行异常,流程执行失败";
                                exec_data.clear();
                                return exec_data;
                            }
                            else
                            {
                                exec_data=exec_data_an;
                            }
                        }
                        else if(judge==1)
                        {
                            QList<QVariant> exec_data_an=item_run_an(pc[i][2],tree,exec_data);
                            if(exec_data_an.size()==0)
                            {
                                qDebug()<<"流程树执行异常,流程执行失败";
                                exec_data.clear();
                                return exec_data;
                            }
                            else
                            {
                                exec_data=exec_data_an;
                            }
                        }
                        else
                        {
                            qDebug()<<"判断：变量判断结构执行异常。";
                            emit error_back("判断：变量判断结构执行异常。");
                            exec_data.clear();
                            return exec_data;
                        }
                    }
                    else
                    {
                        qDebug()<<"流程树执行异常,判断结构变量不完整";
                        exec_data.clear();
                        return exec_data;
                    }
                }
                else
                {
                    qDebug()<<"流程树执行异常,判断结构流程不完整";
                    exec_data.clear();
                    return exec_data;
                }
            }
            else
            {
                QList<QVariant> exec_data_an=item_run_an(pc[i][0],tree,exec_data);
                if(exec_data_an.size()==0)
                {
                    qDebug()<<"流程树执行异常,流程执行失败";
                    exec_data.clear();
                    return exec_data;
                }
                else
                {
                    exec_data=exec_data_an;
                }
            }
        }
        else
        {
            qDebug()<<"流程树执行异常，步骤中没有待执行的流程";
            exec_data.clear();
            return exec_data;
        }
    }
    return exec_data;
}

//执行流程
QList<QVariant> nsv_image_tree::item_run_an(param_cross p,tree_param tree,QList<QVariant> exec_data)
{
    if(p.tig>=200000)
    {
        if(p.tig-200000>tree.n_l.size())
        {
            qDebug()<<"流程编号："+QString::number(p.tig-200000)+" 不存在对应节点。";
            emit error_back("流程编号："+QString::number(p.tig-200000)+" 不存在对应节点。");
            exec_data.clear();
            return exec_data;
        }

        node_cross nd=tree.n_l[p.tig-200000];

        nd.inList=p.inList;
        nd.outList=p.outList;

        tree_param tree_nd;
        tree_nd.d_l=nd.dataList;
        tree_nd.n_l=tree.n_l;
        tree_nd.tree=nd.tree;
        tree_nd.data=nd.data;
        tree_nd.p_l=tree.p_l;

        QList<QVariant> ndl=nsv_image_tree::GetDataList(nd.dataList);

        if(nd.inList_inside.size()!=nd.inList.size())
        {
            qDebug()<<"节点："+p.name+" 内部输入与外部输入数量不匹配，请重新构建节点。";
            emit error_back("节点："+p.name+" 内部输入与外部输入数量不匹配，请重新构建节点。");
            exec_data.clear();
            return exec_data;
        }

        bool OneIsNull=false;
        for(int j=0;j<p.inList.size();j++)
        {
            if(nd.intype[j]=="")
            {
                ndl[nd.inList_inside[j]-100000]=nd.dataList[nd.inList_inside[j]-100000].data;

                if(isNull(nd.dataList[nd.inList_inside[j]-100000].data))
                {
                    qDebug()<<"data is NUll";
                    OneIsNull=true;
                    break;
                }
                continue;
            }
            if(p.inList[j]-100000<exec_data.size())
            {
                if(nd.inList_inside[j]-100000<ndl.size())
                {
                    ndl[nd.inList_inside[j]-100000]=exec_data[nd.inList[j]-100000];
                    if(isNull(exec_data[nd.inList[j]-100000]))
                    {
                        OneIsNull=true;
                        break;
                    }
                }
                else
                {
                    qDebug()<<"节点："+nd.name+" 内部输入变量编号超出内部变量表，请重新构建节点。";
                    emit error_back("节点："+nd.name+" 内部输入变量编号超出内部变量表，请重新构建节点。");
                    exec_data.clear();
                    return exec_data;
                }
            }
            else
            {
                ndl[nd.inList_inside[j]-100000]=QVariant();
                OneIsNull=true;
                break;
            }
        }
        if(!OneIsNull)
        {
            ndl=item_run(tree_nd,ndl);

            if(nd.outList.size() !=nd.outList_inside.size())
            {
                qDebug()<<"节点："+p.name+" 内部输出与外部输出数量不匹配，请重新构建节点。";
                emit error_back("节点："+p.name+" 内部输出与外部输出数量不匹配，请重新构建节点。");
                exec_data.clear();
                return exec_data;
            }

            for(int j=0;j<nd.outList.size();j++)
            {
                if(nd.outList[j]-100000<exec_data.size())
                {
                    if(nd.outList_inside[j]-100000<ndl.size())
                    {
                        exec_data[nd.outList[j]-100000]=ndl[nd.outList_inside[j]-100000];
                    }
                    else
                    {
                        qDebug()<<"节点："+nd.name+" 内部输出变量编号超出内部变量表，请重新构建节点。";
                        emit error_back("节点："+nd.name+" 内部输出变量编号超出内部变量表，请重新构建节点。");
                        exec_data.clear();
                        return exec_data;
                    }
                }
            }
        }
        else
        {
            qDebug()<<"节点："+p.name+" 存在未定义或空值输入，请检查流程树后再执行操作。";
            emit error_back("节点："+p.name+" 存在未定义或空值输入，请检查流程树后再执行操作。");
            exec_data.clear();
            return exec_data;
        }
    }
    else
    {
        if(p.tig>tree.p_l.size())
        {
            qDebug()<<"流程编号："+QString::number(p.tig)+" 不存在对应算子。";
            emit error_back("流程编号："+QString::number(p.tig)+" 不存在对应算子。");
            exec_data.clear();
            return exec_data;
        }

        QList<QVariant> inlist;
        bool OneIsNull=false;
        for(int j=0;j<p.inList.size();j++)
        {
            if(p.inList[j]-100000<exec_data.size())
            {
                inlist.append(exec_data[p.inList[j]-100000]);
                if(isNull(exec_data[p.inList[j]-100000]))
                {
                    OneIsNull=true;
                    break;
                }
            }
            else
            {
                inlist.append(QVariant());
                OneIsNull=true;
                break;
            }
        }
        if(!OneIsNull)
        {
            QList<QVariant> outlist=nsv_image_tree::item_an(inlist,p);
            for(int j=0;j<p.outList.size();j++)
            {
                if(p.outList[j]-100000<exec_data.size())
                {
                    exec_data[p.outList[j]-100000]=outlist[j];
                }
            }
        }
        else
        {
            qDebug()<<"算子："+p.name+" 存在未定义或空值输入，请检查流程树后再执行操作。";
            emit error_back("算子："+p.name+" 存在未定义或空值输入，请检查流程树后再执行操作。");
            exec_data.clear();
            return exec_data;
        }
    }

    return exec_data;
}

//变量判断
int nsv_image_tree::item_run_judge(int type,data_cross d1,data_cross d2)
{
    if(d1.type != d2.type)
    {
        qDebug()<<"用于判断的变量类型不同";
        return 3;
    }

    if(d1.type=="bool")
    {
        bool u1=d1.data.toBool();
        bool u2=d2.data.toBool();

        switch (type)
        {
        case 300006:
            return u1==u2 ? 0:1;
            break;
        case 300007:
            return u1!=u2 ? 0:1;
            break;
        default:
            qDebug()<<d1.type<<"无法执行该判断方式";
            return 3;
        }
    }
    else if(d1.type=="int")
    {
        int u1=d1.data.toInt();
        int u2=d2.data.toInt();

        switch(type)
        {
        case 300002:
            return u1>u2 ? 0:1;
            break;
        case 300003:
            return u1>=u2 ? 0:1;
            break;
        case 300004:
            return u1<u2 ? 0:1;
            break;
        case 300005:
            return u1<=u2 ? 0:1;
            break;
        case 300006:
            return u1==u2 ? 0:1;
            break;
        case 300007:
            return u1!=u2 ? 0:1;
            break;
        default:
            qDebug()<<d1.type<<"无法执行该判断方式";
            return 3;
        }
    }
    else if(d1.type=="float")
    {
        float u1=d1.data.toFloat();
        float u2=d2.data.toFloat();

        switch(type)
        {
        case 300002:
            return u1>u2 ? 0:1;
            break;
        case 300003:
            return u1>=u2 ? 0:1;
            break;
        case 300004:
            return u1<u2 ? 0:1;
            break;
        case 300005:
            return u1<=u2 ? 0:1;
            break;
        case 300006:
            return u1==u2 ? 0:1;
            break;
        case 300007:
            return u1!=u2 ? 0:1;
            break;
        default:
            qDebug()<<d1.type<<"无法执行该判断方式";
            return 3;
        }
    }
    else if(d1.type=="double")
    {
        double u1=d1.data.toDouble();
        double u2=d2.data.toDouble();

        switch(type)
        {
        case 300002:
            return u1>u2 ? 0:1;
            break;
        case 300003:
            return u1>=u2 ? 0:1;
            break;
        case 300004:
            return u1<u2 ? 0:1;
            break;
        case 300005:
            return u1<=u2 ? 0:1;
            break;
        case 300006:
            return u1==u2 ? 0:1;
            break;
        case 300007:
            return u1!=u2 ? 0:1;
            break;
        default:
            qDebug()<<d1.type<<"无法执行该判断方式";
            return 3;
        }
    }
    else if(d1.type=="color")
    {
        cv::Scalar u1=d1.data.value<cv::Scalar>();
        cv::Scalar u2=d2.data.value<cv::Scalar>();

        switch(type)
        {
        case 300006:
            return u1==u2 ? 0:1;
            break;
        case 300007:
            return u1!=u2 ? 0:1;
            break;
        default:
            qDebug()<<d1.type<<"无法执行该判断方式";
            return 3;
        }
    }
    else if(d1.type=="size")
    {
        cv::Size u1=d1.data.value<cv::Size>();
        cv::Size u2=d2.data.value<cv::Size>();

        switch(type)
        {
        case 300006:
            return u1==u2 ? 0:1;
            break;
        case 300007:
            return u1!=u2 ? 0:1;
            break;
        default:
            qDebug()<<d1.type<<"无法执行该判断方式";
            return 3;
        }
    }
    else if(d1.type=="rect")
    {
        cv::Rect u1=d1.data.value<cv::Rect>();
        cv::Rect u2=d2.data.value<cv::Rect>();

        switch(type)
        {
        case 300006:
            return u1==u2 ? 0:1;
            break;
        case 300007:
            return u1!=u2 ? 0:1;
            break;
        default:
            qDebug()<<d1.type<<"无法执行该判断方式";
            return 3;
        }
    }
    else
    {
        qDebug()<<d1.type<<"该变量类型尚未定义判断方式";
        return 3;
    }

    qDebug()<<"error but don't know why";
    return 3;
}

//运行流程树
void nsv_image_tree::item_th()
{
    QList<QVariant> result=item_run(now_tree,now_exec_data);

    if(result.size()>0)
    {
        emit run_back(result);
    }
}

//特殊类型变量保存
QString nsv_image_tree::special_data_save(QString type,QVariant da)
{
    QString data="";
    if(type=="size")
    {
        cv::Size size=da.value<cv::Size>();

        data="{"+QString::number(size.width)+"_"+QString::number(size.width)+"},";
    }
    else if(type=="color")
    {
        cv::Scalar color=da.value<cv::Scalar>();

        data="{"+QString::number(color[0])+"_"+QString::number(color[1])+"_"+QString::number(color[2])+"},";
    }
    else if(type=="rect")
    {
        cv::Rect rect=da.value<cv::Rect>();

        data="{"+QString::number(rect.x)+"_"+QString::number(rect.y)+"_"+QString::number(rect.width)+"_"+QString::number(rect.height)+"},";
    }
    else
    {
        data=da.toString()+",";
    }
    return data;
}

//特殊类型变量读取
QVariant nsv_image_tree::special_data_read(QString type,QString da)
{
    QVariant data;
    if(type=="size")
    {
        da.replace("{","");
        da.replace("}","");

        QStringList list=da.split("_");

        if(list.size()>1)
        {
            cv::Size size=cv::Size(list[0].toInt(),list[1].toInt());
            data.setValue<cv::Size>(size);
        }
        else
        {
            data=QVariant();
        }
    }
    else if(type=="color")
    {
        da.replace("{","");
        da.replace("}","");

        QStringList list=da.split("_");

        if(list.size()>2)
        {
            cv::Scalar color=cv::Scalar(list[0].toInt(),list[1].toInt(),list[2].toInt());
            data.setValue<cv::Scalar>(color);
        }
        else
        {
            data=QVariant();
        }
    }
    else if(type=="rect")
    {
        da.replace("{","");
        da.replace("}","");

        QStringList list=da.split("_");

        if(list.size()>3)
        {
            cv::Rect rect=cv::Rect(list[0].toInt(),list[1].toInt(),list[2].toInt(),list[3].toInt());
            data.setValue<cv::Rect>(rect);
        }
        else
        {
            data=QVariant();
        }
    }
    else
    {
        data=QVariant(da);
    }
    return data;
}

//判断变量是否可执行该判断
bool nsv_image_tree::judge_type_enable(int tip,QString type)
{
    bool isOK=true;

    switch(tip)
    {
    case 300002:
        isOK = type=="int" || type=="float" || type=="double" ? true:false;
        break;
    case 300003:
        isOK = type=="int" || type=="float" || type=="double" ? true:false;
        break;
    case 300004:
        isOK = type=="int" || type=="float" || type=="double" ? true:false;
        break;
    case 300005:
        isOK = type=="int" || type=="float" || type=="double" ? true:false;
        break;
    case 300006:
        isOK = type!="image" ? true:false;
        break;
    case 300007:
        isOK = type!="image" ? true:false;
        break;
    default:
        qDebug()<<"未定义该判断方式";
        isOK = false;
    }

    return isOK;
}

//=============================== 流程树基础算法 ===============================================================================================

//流程显示
void nsv_image_tree::LDebug(param_cross p)
{
    qDebug()<<"_____________________________________________________";

    qDebug()<<"tig: "<<p.tig;
    qDebug()<<"name: "<<p.name;
    qDebug()<<"info: "<<p.info;
    qDebug()<<"param: "<<p.param;

    qDebug()<<"_____________________________________________________";

    for(int i=0;i<p.intype.size();i++)
    {
        if(i<p.inList.size())
        {
            qDebug()<<"intype: "<<p.intype[i]<<"inList: "<<p.inList[i];
        }
        else
        {
            qDebug()<<"intype: "<<p.intype[i]<<"inList: "<<"---------";
        }
    }

    qDebug()<<"_____________________________________________________";

    for(int i=0;i<p.outtype.size();i++)
    {
        if(i<p.outList.size())
        {
            qDebug()<<"outtype: "<<p.outtype[i]<<"outList: "<<p.outList[i];
        }
        else
        {
            qDebug()<<"outtype: "<<p.outtype[i]<<"outList: "<<"---------";
        }
    }

    qDebug()<<"_____________________________________________________";
}

//获取空变量集
QList<QVariant> nsv_image_tree::GetDataList(QList<data_cross> data_list)
{
    QList<QVariant> exec_data;

    for(int i=0;i<data_list.size();i++)
    {
        QVariant data;
        exec_data.append(data);
    }

    return exec_data;
}

//流程树拆分
QList<QList<param_cross>> nsv_image_tree::ListAsTree(QString tree,QList<data_cross> &data_list,QList<param_cross> param_list,QList<node_cross> node_list)
{
    QList<QList<param_cross>> p_l;

    QList<QVariant> exec_data=nsv_image_tree::GetDataList(data_list);

    QStringList treelist=tree.split("||");

    for(int i=0;i<treelist.size();i++)
    {
        QString item=treelist[i];

        int tig=TigForTree(item);

        QList<param_cross> pl;

        if(tig<param_list.size())
        {
            param_cross p=ParamAsTree(item,param_list,data_list);
            pl.append(p);
        }
        else if(tig>=200000 && tig-200000<node_list.size())
        {
            param_cross p=NodeAsTree(item,node_list,data_list);
            pl.append(p);
        }
        else if(tig==300001)
        {
            QList<param_cross> npl=JudgeAsTree(item,param_list,node_list,data_list);
            pl=npl;
        }

        if(pl.size()!=0)
        {
            if(pl[0].tig!=2000000 && pl[0].tig!=1000000)
            {
                p_l.append(pl);
            }
        }
    }

    return p_l;
}

//获取树编号
int nsv_image_tree::TigForTree(QString tree)
{
    QString item_tig=tree.replace("[","(");

    QStringList tigl=item_tig.split("(");

    int tig=2000000;

    if(tigl.size()>0)
    {
        tig=tigl[0].toInt();
    }

    return tig;
}

//流程树转流程
param_cross nsv_image_tree::ParamAsTree(QString tree,QList<param_cross> p_l,QList<data_cross> &d_l)
{
    param_cross p;

    p.canrun=true;

    QStringList tigl=tree.split("(");

    p.tig=tigl[0].toInt();

    QStringList actlist=tree.split("){");

    if(p.tig<p_l.size() && actlist.size()==2)
    {
        p.name=p_l[p.tig].name;
        p.ico=p_l[p.tig].ico;
        p.intype=p_l[p.tig].intype;
        p.outtype=p_l[p.tig].outtype;
        p.intype_info=p_l[p.tig].intype_info;
        p.outtype_info=p_l[p.tig].outtype_info;

        QString input=actlist[0].replace("(",",");

        QStringList inputlist=input.split(",");

        if(inputlist.size()>1)
        {
            for(int j=1;j<inputlist.size();j++)
            {
                if(inputlist[j]!="")
                {
                    if(inputlist[j].toInt()-100000<d_l.size())
                    {
                        if(d_l[inputlist[j].toInt()-100000].type==p.intype[j-1])
                        {
                            p.inList.append(inputlist[j].toInt());

                            d_l[inputlist[j].toInt()-100000].isUseLast=true;
                            d_l[inputlist[j].toInt()-100000].WhoUseMe.push_back(QString::number(p.tig)+"-"+QString::number(j-1));
                            if(d_l[inputlist[j].toInt()-100000].isGiveBefore)
                            {
                                if(d_l[inputlist[j].toInt()-100000].attr==1)
                                {
                                    d_l[inputlist[j].toInt()-100000].attr=1;
                                }
                                else
                                {
                                    d_l[inputlist[j].toInt()-100000].attr=3;
                                }
                            }
                            else
                            {
                                d_l[inputlist[j].toInt()-100000].attr=1;
                            }
                        }
                        else
                        {
                            p.inList.append(2000000);
                            p.canrun=false;
                        }
                    }
                    else
                    {
                        p.inList.append(1000000);
                        p.canrun=false;
                    }
                }
            }
        }

        QString output=actlist[1].replace("}","");

        QStringList outputlist=output.split(",");

        if(outputlist.size()>0)
        {
            for(int j=0;j<outputlist.size();j++)
            {
                if(outputlist[j]!="")
                {
                    if(outputlist[j].toInt()-100000<d_l.size())
                    {
                        if(d_l[outputlist[j].toInt()-100000].type==p.outtype[j])
                        {
                            p.outList.append(outputlist[j].toInt());
                            d_l[outputlist[j].toInt()-100000].isGiveBefore=true;
                            d_l[outputlist[j].toInt()-100000].WhoGiveMe.push_back(QString::number(p.tig)+"-"+QString::number(j));
                            if(d_l[outputlist[j].toInt()-100000].attr!=1)
                            {
                                d_l[outputlist[j].toInt()-100000].attr=2;
                            }
                        }
                        else
                        {
                            p.outList.append(2000000);
                        }
                    }
                    else
                    {
                        p.outList.append(1000000);
                    }
                }
            }
        }
    }
    else
    {
        p.tig=2000000;
        p.canrun=false;
    }

    return p;
}

//流程树转节点
param_cross nsv_image_tree::NodeAsTree(QString tree,QList<node_cross> n_l,QList<data_cross> &d_l)
{
    param_cross p;

    p.canrun=true;

    QStringList tigl=tree.split("(");

    p.tig=tigl[0].toInt();

    QStringList actlist=tree.split("){");

    if(p.tig>=200000 && p.tig-200000<n_l.size() && actlist.size()==2)
    {
        p.name=n_l[p.tig-200000].name;
        p.ico=n_l[p.tig-200000].ico;
        p.intype=n_l[p.tig-200000].intype;
        p.outtype=n_l[p.tig-200000].outtype;
        p.intype_info=n_l[p.tig-200000].intype_info;
        p.outtype_info=n_l[p.tig-200000].outtype_info;

        QString input=actlist[0].replace("(",",");

        QStringList inputlist=input.split(",");

        if(inputlist.size()>1)
        {
            for(int j=1;j<inputlist.size();j++)
            {
                if(inputlist[j]!="" && p.intype[j-1]!="")
                {
                    if(inputlist[j].toInt()-100000<d_l.size())
                    {
                        if(d_l[inputlist[j].toInt()-100000].type==p.intype[j-1])
                        {
                            p.inList.append(inputlist[j].toInt());
                            d_l[inputlist[j].toInt()-100000].isUseLast=true;
                            d_l[inputlist[j].toInt()-100000].WhoUseMe.push_back(QString::number(p.tig)+"-"+QString::number(j-1));
                            if(d_l[inputlist[j].toInt()-100000].isGiveBefore)
                            {
                                if(d_l[inputlist[j].toInt()-100000].attr==1)
                                {
                                    d_l[inputlist[j].toInt()-100000].attr=1;
                                }
                                else
                                {
                                    d_l[inputlist[j].toInt()-100000].attr=3;
                                }
                            }
                            else if(!d_l[inputlist[j].toInt()-100000].isGiveBefore)
                            {
                                d_l[inputlist[j].toInt()-100000].attr=1;
                            }
                        }
                        else
                        {
                            p.inList.append(2000000);
                            p.canrun=false;
                        }
                    }
                    else
                    {
                        p.inList.append(1000000);
                        p.canrun=false;
                    }
                }
                else
                {
                    p.inList.append(1000000);
                }
            }
        }

        QString output=actlist[1].replace("}","");

        QStringList outputlist=output.split(",");

        if(outputlist.size()>0)
        {
            for(int j=0;j<outputlist.size();j++)
            {
                if(outputlist[j]!="" && p.outtype[j]!="")
                {
                    if(outputlist[j].toInt()-100000<d_l.size())
                    {
                        if(d_l[outputlist[j].toInt()-100000].type==p.outtype[j])
                        {
                            p.outList.append(outputlist[j].toInt());
                            d_l[outputlist[j].toInt()-100000].isGiveBefore=true;
                            d_l[outputlist[j].toInt()-100000].WhoGiveMe.push_back(QString::number(p.tig)+"-"+QString::number(j));
                            if(d_l[outputlist[j].toInt()-100000].attr!=1)
                            {
                                d_l[outputlist[j].toInt()-100000].attr=2;
                            }
                        }
                        else
                        {
                            p.outList.append(2000000);
                        }
                    }
                    else
                    {
                        p.outList.append(1000000);
                    }
                }
                else
                {
                    p.outList.append(2000000);
                }
            }
        }
    }
    else
    {
        p.tig=2000000;
        p.canrun=false;
    }

    return p;
}

//流程树转判断结构
QList<param_cross> nsv_image_tree::JudgeAsTree(QString tree,QList<param_cross> p_l,QList<node_cross> n_l,QList<data_cross> &d_l)
{
    QString str=tree.replace("[",";");

    str=str.replace("]","");

    QStringList tigl=str.split(";");

    param_cross p;

    param_cross ptp;

    param_cross pfp;

    p.canrun=true;

    QList<param_cross> pl;

    if(tigl.size()>=4)
    {
        p.tig=tigl[0].toInt();

        QString pj=tigl[1];

        pj=pj.replace("(",",");

        pj=pj.replace(")","");

        QStringList pjl=pj.split(",");

        if(pjl.size()>=3)
        {
            p.intype_info.append("判断方式");
            p.intype_info.append("比较值");
            p.intype_info.append("待比值");

            p.inList.append(pjl[0].toInt());

            if(p.inList[0]!=1000000)
            {
                if(p.inList[0]<300002 || p.inList[0]>=300010)
                {
                    p.inList[0]=1000000;
                    p.tig=2000000;
                    p.canrun=false;
                }
            }

            if(pjl[1].toInt()-100000<d_l.size())
            {
                p.inList.append(pjl[1].toInt());
                d_l[pjl[1].toInt()-100000].isUseLast=true;
                d_l[pjl[1].toInt()-100000].WhoUseMe.push_back(QString::number(p.tig)+"-"+QString::number(1));
                if(d_l[pjl[1].toInt()-100000].isGiveBefore)
                {
                    if(d_l[pjl[1].toInt()-100000].attr==1)
                    {
                        d_l[pjl[1].toInt()-100000].attr=1;
                    }
                    else
                    {
                        d_l[pjl[1].toInt()-100000].attr=3;
                    }
                }
                else if(!d_l[pjl[1].toInt()-100000].isGiveBefore)
                {
                    d_l[pjl[1].toInt()-100000].attr=1;
                }
            }
            else
            {
                p.inList.append(1000000);
                p.canrun=false;
            }

            if(pjl[2].toInt()-100000<d_l.size())
            {
                p.inList.append(pjl[2].toInt());
                d_l[pjl[2].toInt()-100000].isUseLast=true;
                d_l[pjl[2].toInt()-100000].WhoUseMe.push_back(QString::number(p.tig)+"-"+QString::number(2));
                if(d_l[pjl[2].toInt()-100000].isGiveBefore)
                {
                    if(d_l[pjl[2].toInt()-100000].attr==1)
                    {
                        d_l[pjl[2].toInt()-100000].attr=1;
                    }
                    else
                    {
                        d_l[pjl[2].toInt()-100000].attr=3;
                    }
                }
                else if(!d_l[pjl[2].toInt()-100000].isGiveBefore)
                {
                    d_l[pjl[2].toInt()-100000].attr=1;
                }
            }
            else
            {
                p.inList.append(1000000);
                p.canrun=false;
            }

        }
        else
        {
            p.tig=2000000;
            p.canrun=false;
        }

        QString pt=tigl[2];

        int tigt=TigForTree(pt);

        if(tigt<p_l.size())
        {
            ptp=ParamAsTree(pt,p_l,d_l);
        }
        else if(tigt>=200000 && tigt-200000<n_l.size())
        {
            ptp=NodeAsTree(pt,n_l,d_l);
        }

        QString pf=tigl[3];

        int tigf=TigForTree(pf);

        if(tigf<p_l.size())
        {
            pfp=ParamAsTree(pf,p_l,d_l);
        }
        else if(tigf>=200000 && tigf-200000<n_l.size())
        {
            pfp=NodeAsTree(pf,n_l,d_l);
        }

        if(ptp.tig==2000000 || ptp.tig==1000000 || pfp.tig==2000000 || pfp.tig==1000000)
        {
            p.tig=2000000;
            p.canrun=false;
        }

        if(!ptp.canrun || !pfp.canrun)
        {
            p.canrun=false;
        }

        pl.append(p);
        pl.append(ptp);
        pl.append(pfp);
    }
    else
    {
        p.tig=2000000;
        p.canrun=false;
        pl.append(p);
        pl.append(ptp);
        pl.append(pfp);
    }

    return pl;
}

//转换变量表为列表
QList<data_cross> nsv_image_tree::ListAsData(QString data)
{
    QList<data_cross> dl;
    QStringList strlist=data.split("||");

    for(int i=0;i<strlist.size();i++)
    {
        QString single=strlist[i];

        QStringList singlelist=single.split("(");
        if(singlelist.size()==2)
        {
            data_cross d;
            d.tig=singlelist[0].toInt();
            QString param=singlelist[1];
            param.replace(")","");
            QStringList paramlist=param.split(",");
            if(paramlist.size()>=9)
            {
                d.name=paramlist[0];
                d.type=paramlist[1];
                d.attr=paramlist[2].toInt();
                d.isGiveBefore=QVariant(paramlist[3]).toBool();
                d.isUseLast=QVariant(paramlist[4]).toBool();
                if(paramlist[5]=="")
                {
                    d.data=QVariant();
                }
                else
                {
                    d.data=nsv_image_tree::special_data_read(d.type,paramlist[5]);
                }
                paramlist[6].replace("{","");
                paramlist[6].replace("}","");

                QStringList givelist=paramlist[6].split("_");

                for(int j=0;j<givelist.size();j++)
                {
                    d.WhoGiveMe.push_back(givelist[j]);
                }

                paramlist[7].replace("{","");
                paramlist[7].replace("}","");

                QStringList uselist=paramlist[7].split("_");

                for(int j=0;j<uselist.size();j++)
                {
                    d.WhoUseMe.push_back(uselist[j]);
                }

                d.isFixed=QVariant(paramlist[8]).toBool();

                dl.append(d);
            }
        }
    }
    return dl;
}

//转换变量表为字符串
QString nsv_image_tree::DataAsList(QList<data_cross> dl)
{
    QString data="";

    for(int i=0;i<dl.size();i++)
    {
        data+=QString::number(dl[i].tig);
        data+="("+dl[i].name+",";
        data+=dl[i].type+",";
        data+=QString::number(dl[i].attr)+",";
        data+=QVariant(dl[i].isGiveBefore).toString()+",";
        data+=QVariant(dl[i].isUseLast).toString()+",";

        if(nsv_image_tree::isNull(dl[i].data))
        {
            data+=",";
        }
        else
        {
            data+=nsv_image_tree::special_data_save(dl[i].type,dl[i].data);
        }
        data+="{";
        for(int j=0;j<dl[i].WhoGiveMe.size();j++)
        {
            data+=dl[i].WhoGiveMe[j];
            if(j!=dl[i].WhoGiveMe.size()-1)
            {
                data+="_";
            }
        }
        data+="},";

        data+="{";
        for(int j=0;j<dl[i].WhoUseMe.size();j++)
        {
            data+=dl[i].WhoUseMe[j];
            if(j!=dl[i].WhoUseMe.size()-1)
            {
                data+="_";
            }
        }
        data+="},";
        data+=QVariant(dl[i].isFixed).toString();

        data+=")";

        if(i!=dl.size()-1)
        {
            data+="||";
        }
    }

    return data;
}

//节点保存
QString nsv_image_tree::SaveNode(node_cross n,QString where)
{
    QDir dir;
    QString path=where+"/"+n.name;

    if (!dir.exists(path))
    {
        dir.mkpath(path);
    }

    if(n.tig>=200000 && n.tig<300000)
    {
        nsv_json_analy::json_create_node(n,path);

        if(!n.tree_img.isNull())
        {
            n.tree_img.save(path+"/"+"tree.png","PNG",100);
        }

        if(!n.data_img.isNull())
        {
            n.data_img.save(path+"/"+"data_inside.png","PNG",100);
        }

        if(!n.ico.isNull())
        {
            n.ico.pixmap(QSize(500,500)).save(path+"/"+"ico.ico","PNG",100);
        }
    }
    else
    {
        qDebug()<<"节点："+n.name+",tig:"+QString::number(n.tig)+"为非法节点!";
    }

    return path;
}

//节点读取
node_cross nsv_image_tree::ReadNode(QString path)
{
    node_cross n;
    QDir dir;
    if (!dir.exists(path))
    {
        qDebug()<<path<<"Is No Found!";
        return n;
    }

    n=nsv_json_analy::json_read_node(path);

    n.dataList=nsv_image_tree::ListAsData(n.data);

    if(n.tig>=200000 && n.tig<300000)
    {
        QImage tree;
        tree.load(path+"/"+"tree.png");

        if(!tree.isNull())
        {
            n.tree_img=tree;
        }

        QImage data_inside;
        data_inside.load(path+"/"+"data_inside.png");

        if(!data_inside.isNull())
        {
            n.data_img=data_inside;
        }

        QImage ico;
        ico.load(path+"/"+"ico.ico");

        if(!ico.isNull())
        {
            QPixmap pix=QPixmap::fromImage(ico);
            n.ico.addPixmap(pix);
        }
    }
    else
    {
        qDebug()<<"节点："+n.name+",tig:"+QString::number(n.tig)+"为非法节点!";
    }

    return n;
}

//转换流程树为节点
node_cross nsv_image_tree::TreeToNode(node_cross info,QList<param_cross> p_l,QList<node_cross> n_l)
{
    node_cross node;
    node.name=info.name;
    node.info=info.info;
    node.param=info.param;
    node.ico=info.ico;
    node.tree=info.tree;
    node.data=info.data;
    node.tree_img=info.tree_img;
    node.data_img=info.data_img;
    QList<data_cross> d_l = nsv_image_tree::ListAsData(info.data);
    node.tig=n_l.size()+200000;
    node.dataList=d_l;
    for(int i=0;i<d_l.size();i++)
    {
        data_cross d=d_l[i];
        if(d.attr==1 && !d.isFixed)
        {
            node.inList_inside.append(d.tig);
            node.intype.append(d.type);
            QString show="";
            for(int j=0;j<d.WhoUseMe.size();j++)
            {
                QStringList stl=d.WhoUseMe[j].split("-");
                if(stl.size()>1)
                {
                    if(stl[0].toInt()>=200000)
                    {
                        if(stl[0].toInt()-200000<n_l.size())
                        {
                            show+=n_l[stl[0].toInt()-200000].name;
                            show+=":";
                            show+=n_l[stl[0].toInt()-200000].intype_info[stl[1].toInt()];
                        }

                        if(stl[0].toInt()==300001)
                        {
                            if(stl[1].toInt()==1)
                            {
                                show+="比较值";
                            }
                            else if(stl[1].toInt()==2)
                            {
                                show+="待比值";
                            }
                        }

                        if(j!=d.WhoUseMe.size()-1)
                        {
                            show+=" ";
                        }
                    }
                    else
                    {
                        if(stl[0].toInt()<p_l.size())
                        {
                            show+=p_l[stl[0].toInt()].name;
                            show+=":";
                            show+=p_l[stl[0].toInt()].intype_info[stl[1].toInt()];
                        }
                        if(j!=d.WhoUseMe.size()-1)
                        {
                            show+=" ";
                        }
                    }
                }
                if(j>3)
                {
                    break;
                }
            }
            node.intype_info.push_back(show);
        }
        else if(d.attr==1 && d.isFixed)
        {
            if(nsv_image_tree::isNull(d.data))
            {
                node.name="要保存的流程树存在常量输入没有赋值，请尝试运行后并赋值后再保存。";
                node.tig=2000000;
                return node;
            }
            else
            {
                node.inList_inside.append(d.tig);
                node.intype.append("");
                QString show="常量 ";
                for(int j=0;j<d.WhoUseMe.size();j++)
                {
                    QStringList stl=d.WhoUseMe[j].split("-");
                    if(stl.size()>1)
                    {
                        if(stl[0].toInt()>=200000)
                        {
                            if(stl[0].toInt()-200000<n_l.size())
                            {
                                show+=n_l[stl[0].toInt()-200000].name;
                                show+=":";
                                show+=n_l[stl[0].toInt()-200000].intype_info[stl[1].toInt()];
                            }

                            if(stl[0].toInt()==300001)
                            {
                                if(stl[1].toInt()==1)
                                {
                                    show+="比较值";
                                }
                                else if(stl[1].toInt()==2)
                                {
                                    show+="待比值";
                                }
                            }

                            if(j!=d.WhoUseMe.size()-1)
                            {
                                show+=" ";
                            }
                        }
                        else
                        {
                            if(stl[0].toInt()<p_l.size())
                            {
                                show+=p_l[stl[0].toInt()].name;
                                show+=":";
                                show+=p_l[stl[0].toInt()].intype_info[stl[1].toInt()];
                            }
                            if(j!=d.WhoUseMe.size()-1)
                            {
                                show+=" ";
                            }
                        }
                    }
                    if(j>3)
                    {
                        break;
                    }
                }

                node.intype_info.push_back(show);
            }
        }
        else if(d.attr==2 && !d.isFixed)
        {
            node.outList_inside.append(d.tig);
            node.outtype.append(d.type);
            QString show="";
            for(int j=0;j<d.WhoGiveMe.size();j++)
            {
                QStringList stl=d.WhoGiveMe[j].split("-");
                if(stl.size()>1)
                {
                    if(stl[0].toInt()>=200000)
                    {
                        if(stl[0].toInt()-200000<n_l.size())
                        {
                            show+=n_l[stl[0].toInt()-200000].name;
                            show+=":";
                            show+=n_l[stl[0].toInt()-200000].outtype_info[stl[1].toInt()];
                        }

                        if(stl[0].toInt()==300001)
                        {
                            if(stl[1].toInt()==1)
                            {
                                show+="比较值";
                            }
                            else if(stl[1].toInt()==2)
                            {
                                show+="待比值";
                            }
                        }

                        if(j!=d.WhoGiveMe.size()-1)
                        {
                            show+=" ";
                        }
                    }
                    else
                    {
                        if(stl[0].toInt()<p_l.size())
                        {
                            show+=p_l[stl[0].toInt()].name;
                            show+=":";
                            show+=p_l[stl[0].toInt()].outtype_info[stl[1].toInt()];
                        }
                        if(j!=d.WhoGiveMe.size()-1)
                        {
                            show+=" ";
                        }
                    }
                }
                if(j>3)
                {
                    break;
                }
            }
            node.outtype_info.push_back(show);
        }
        else if(d.attr==2 && d.isFixed)
        {
            node.outList_inside.append(d.tig);
            node.outtype.append("");
            QString show="隐藏 ";
            for(int j=0;j<d.WhoGiveMe.size();j++)
            {
                QStringList stl=d.WhoGiveMe[j].split("-");
                if(stl.size()>1)
                {
                    if(stl[0].toInt()>=200000)
                    {
                        if(stl[0].toInt()-200000<n_l.size())
                        {
                            show+=n_l[stl[0].toInt()-200000].name;
                            show+=":";
                            show+=n_l[stl[0].toInt()-200000].outtype_info[stl[1].toInt()];
                        }

                        if(stl[0].toInt()==300001)
                        {
                            if(stl[1].toInt()==1)
                            {
                                show+="比较值";
                            }
                            else if(stl[1].toInt()==2)
                            {
                                show+="待比值";
                            }
                        }

                        if(j!=d.WhoGiveMe.size()-1)
                        {
                            show+=" ";
                        }
                    }
                    else
                    {
                        if(stl[0].toInt()<p_l.size())
                        {
                            show+=p_l[stl[0].toInt()].name;
                            show+=":";
                            show+=p_l[stl[0].toInt()].outtype_info[stl[1].toInt()];
                        }
                        if(j!=d.WhoGiveMe.size()-1)
                        {
                            show+=" ";
                        }
                    }
                }
                if(j>3)
                {
                    break;
                }
            }
            node.outtype_info.push_back(show);
        }
    }

    return node;
}

//添加流程至流程树末尾
QString nsv_image_tree::AddParamToTree(int tip,QList<param_cross> p_l,QList<node_cross> n_l,QString tree)
{
    if(tip<p_l.size())
    {
        param_cross p=p_l[tip];
        if(tree=="")
        {
            tree+=QString::number(tip)+"(";

            for(int i=0;i<p.intype.size()-1;i++)
            {
                tree+="1000000,";
            }

            tree+="1000000){";

            for(int i=0;i<p.outtype.size()-1;i++)
            {
                tree+="1000000,";
            }

            tree+="1000000}";
        }
        else
        {
            tree+="||";

            tree+=QString::number(tip)+"(";

            for(int i=0;i<p.intype.size()-1;i++)
            {
                tree+="1000000,";
            }

            tree+="1000000){";

            for(int i=0;i<p.outtype.size()-1;i++)
            {
                tree+="1000000,";
            }

            tree+="1000000}";
        }
    }

    if(tip>=200000 && tip-200000<n_l.size())
    {
        node_cross p=n_l[tip-200000];
        if(tree=="")
        {
            tree+=QString::number(tip)+"(";

            for(int i=0;i<p.intype.size()-1;i++)
            {
                tree+="1000000,";
            }

            tree+="1000000){";

            for(int i=0;i<p.outtype.size()-1;i++)
            {
                tree+="1000000,";
            }

            tree+="1000000}";
        }
        else
        {
            tree+="||";

            tree+=QString::number(tip)+"(";

            for(int i=0;i<p.intype.size()-1;i++)
            {
                tree+="1000000,";
            }

            tree+="1000000){";

            for(int i=0;i<p.outtype.size()-1;i++)
            {
                tree+="1000000,";
            }

            tree+="1000000}";
        }
    }

    return tree;
}

//添加判断组至树的末尾
QString nsv_image_tree::AddJudgeToTree(int tipt,int tipf, QList<param_cross> p_l, QList<node_cross> n_l, QString tree)
{
    if(tree=="")
    {
        tree+="300001[1000000(1000000,1000000);";

        tree+=nsv_image_tree::AddParamToTree(tipt,p_l,n_l,"")+";";

        tree+=nsv_image_tree::AddParamToTree(tipf,p_l,n_l,"")+"]";
    }
    else
    {
        tree+="||300001[1000000(1000000,1000000);";

        tree+=nsv_image_tree::AddParamToTree(tipt,p_l,n_l,"")+";";

        tree+=nsv_image_tree::AddParamToTree(tipf,p_l,n_l,"")+"]";
    }

    return tree;
}

//删除流程树末尾流程
QString nsv_image_tree::DelParamAsTree(QString last_tree)
{
    QString tree="";

    QStringList treelist=last_tree.split("||");

    for(int i=0;i<treelist.size()-1;i++)
    {
        QString action=treelist[i];

        if(i!=treelist.size()-2)
        {
            tree+=action+"||";
        }
        else
        {
            tree+=action;
        }

    }

    return tree;
}

//流程赋值
QString nsv_image_tree::ChoParamData(QRect where,int tig,QString last_tree,QList<param_cross> p_l,QList<node_cross> n_l,QList<data_cross> d_l)
{
    QString tree="";

    if(where.width()>0)
    {
        QList<QList<param_cross>> pl=nsv_image_tree::ListAsTree(last_tree,d_l,p_l,n_l);

        int tip=1;

        for(int i=0;i<pl.size();i++)
        {
            for(int j=0;j<pl[i].size();j++)
            {
                if(tip==where.width())
                {
                    param_cross p=pl[i][j];
                    if(p.tig==300001)
                    {
                        if(p.inList.size()>=3)
                        {
                            if(where.y()==0)
                            {
                                if(tig-100000>d_l.size())
                                {
                                    return "ERROR";
                                }

                                if(d_l[tig-100000].type=="image")
                                {
                                    return "CANTTYPE";
                                }

                                if(where.x()==1)
                                {
                                    if(p.inList[2]!=1000000)
                                    {
                                        if(p.inList[2]-100000<d_l.size())
                                        {
                                            if(d_l[tig-100000].type==d_l[p.inList[2]-100000].type)
                                            {
                                                p.inList[1]=tig;
                                            }
                                            else
                                            {
                                                return "DIFFERENT";
                                            }
                                        }
                                        else
                                        {
                                            return "ERROR";
                                        }
                                    }
                                    else
                                    {
                                        p.inList[1]=tig;
                                    }
                                }
                                else if(where.x()==2)
                                {
                                    if(p.inList[1]!=1000000)
                                    {
                                        if(p.inList[1]-100000<d_l.size())
                                        {
                                            if(d_l[tig-100000].type==d_l[p.inList[1]-100000].type)
                                            {
                                                p.inList[2]=tig;
                                            }
                                            else
                                            {
                                                return "DIFFERENT";
                                            }
                                        }
                                        else
                                        {
                                            return "ERROR";
                                        }
                                    }
                                    else
                                    {
                                        p.inList[2]=tig;
                                    }
                                }
                                else
                                {
                                    return "ERROR";
                                }
                            }
                            else if(where.y()==3)
                            {
                                if(where.x()==0)
                                {
                                    if(tig<300002 || tig>=300010 )
                                    {
                                        return "ERROR";
                                    }

                                    if(p.inList[2]==1000000 && p.inList[1]==1000000)
                                    {
                                        return "NULL";
                                    }
                                    else
                                    {
                                        if(p.inList[1]!=1000000)
                                        {
                                            if(p.inList[1]-100000>=d_l.size())
                                            {
                                                return "ERROR";
                                            }

                                            if(judge_type_enable(tig,d_l[p.inList[1]-100000].type))
                                            {
                                                p.inList[0]=tig;
                                            }
                                            else
                                            {
                                                return "CANT";
                                            }
                                        }

                                        if(p.inList[2]!=1000000)
                                        {
                                            if(p.inList[2]-100000>=d_l.size())
                                            {
                                                return "ERROR";
                                            }

                                            if(judge_type_enable(tig,d_l[p.inList[2]-100000].type))
                                            {
                                                p.inList[0]=tig;
                                            }
                                            else
                                            {
                                                return "CANT";
                                            }
                                        }
                                    }
                                }
                                else
                                {
                                    return "ERROR";
                                }
                            }
                            else
                            {
                                return "ERROR";
                            }
                        }
                        else
                        {
                            return "ERROR";
                        }
                    }
                    else
                    {
                        if(tig-100000>d_l.size())
                        {
                            return "ERROR";
                        }
                        if(where.y()==0)
                        {
                            //还没验证类型
                            for(int i=0;i<p.intype.size();i++)
                            {
                                if(i==where.x() && p.inList.size()>i)
                                {
                                    if(d_l[tig-100000].type==p.intype[i])
                                    {
                                        p.inList[i]=tig;
                                    }
                                    else
                                    {
                                        return "";
                                    }
                                }
                            }
                        }
                        else if(where.y()==2)
                        {
                            for(int i=0;i<p.outtype.size();i++)
                            {
                                if(i==where.x() && p.outList.size()>i)
                                {
                                    if(d_l[tig-100000].type==p.outtype[i])
                                    {
                                        p.outList[i]=tig;
                                    }
                                    else
                                    {
                                        return "";
                                    }
                                }
                            }
                        }
                        else
                        {
                            return "ERROR";
                        }
                    }
                    pl[i][j]=p;
                }

                tip+=1;
            }
        }

        tree=nsv_image_tree::ListToTree(pl,p_l,n_l,d_l);

        return tree;
    }
    else
    {
        return "ERROR";
    }
}

//流程转流程树
QString nsv_image_tree::ListToTree(QList<QList<param_cross>> pl,QList<param_cross> p_l,QList<node_cross> n_l,QList<data_cross> d_l)
{
    QString tree="";

    for(int i=0;i<pl.size();i++)
    {
        if(pl[i].size()>0)
        {
            QString tree_item="";

            int tig=pl[i][0].tig;
            if(tig<p_l.size())
            {
                tree_item=nsv_image_tree::ParamToTree(pl[i][0],p_l,d_l);
            }
            else if(tig>=200000 && tig-200000<n_l.size())
            {
                tree_item=nsv_image_tree::NodeToTree(pl[i][0],n_l,d_l);
            }
            else if(tig==300001)
            {
                tree_item=nsv_image_tree::JudgeToTree(pl[i],p_l,n_l,d_l);
            }

            if(tree_item=="")
            {
                tree="";
                return tree;
            }
            else
            {
                tree+=tree_item;
                if(i!=pl.size()-1)
                {
                    tree+="||";
                }
            }
        }
        else
        {
            tree="";
            return tree;
        }
    }

    return tree;
}

//算子转流程树
QString nsv_image_tree::ParamToTree(param_cross p, QList<param_cross> p_l,QList<data_cross> d_l)
{
    QString tree="";

    int tig=p.tig;
    if(tig<p_l.size())
    {
        tree+=QString::number(tig)+"(";
        if(p.inList.size()==p_l[tig].intype.size() && p.outList.size()==p_l[tig].outtype.size())
        {
            for(int i=0;i<p_l[tig].intype.size();i++)
            {
                if(p.inList[i]-100000<d_l.size())
                {
                    tree+=QString::number(p.inList[i]);
                }
                else
                {
                    tree+="1000000";
                }

                if(i!=p_l[tig].intype.size()-1)
                {
                    tree+=",";
                }
            }

            tree+="){";

            for(int i=0;i<p_l[tig].outtype.size();i++)
            {
                if(p.outList[i]-100000<d_l.size())
                {
                    tree+=QString::number(p.outList[i]);
                }
                else
                {
                    tree+="1000000";
                }

                if(i!=p_l[tig].outtype.size()-1)
                {
                    tree+=",";
                }
            }

            tree+="}";
        }
        else
        {
            tree="";
        }
    }

    return tree;
}

//节点转流程树
QString nsv_image_tree::NodeToTree(param_cross p, QList<node_cross> n_l,QList<data_cross> d_l)
{
    QString tree="";

    int tig=p.tig;
    if(tig>=200000 && tig-200000<n_l.size())
    {
        tree+=QString::number(tig)+"(";
        if(p.inList.size()==n_l[tig-200000].intype.size() && p.outList.size()==n_l[tig-200000].outtype.size())
        {
            for(int i=0;i<n_l[tig-200000].intype.size();i++)
            {
                if(p.inList[i]-100000<d_l.size())
                {
                    tree+=QString::number(p.inList[i]);
                }
                else
                {
                    tree+="1000000";
                }

                if(i!=n_l[tig-200000].intype.size()-1)
                {
                    tree+=",";
                }
            }

            tree+="){";

            for(int i=0;i<n_l[tig-200000].outtype.size();i++)
            {
                if(p.outList[i]-100000<d_l.size())
                {
                    tree+=QString::number(p.outList[i]);
                }
                else
                {
                    tree+="1000000";
                }

                if(i!=n_l[tig-200000].outtype.size()-1)
                {
                    tree+=",";
                }
            }

            tree+="}";
        }
        else
        {
            tree="";
        }
    }

    return tree;
}

//判断结构转流程树
QString nsv_image_tree::JudgeToTree(QList<param_cross> pl,QList<param_cross> p_l,QList<node_cross> n_l,QList<data_cross> d_l)
{
    QString tree="";

    if(pl.size()>2)
    {
        param_cross pj=pl[0];

        if(pj.tig==300001)
        {
            tree+=QString::number(pj.tig)+"[";
        }
        else
        {
            tree="";
        }

        if(tree!="")
        {
            if(pj.inList.size()>2)
            {
                if(pj.inList[0]!=1000000)
                {
                    if(pj.inList[0]<300002 || pj.inList[0]>=300010)
                    {
                        tree+="1000000(";
                    }
                    else
                    {
                        tree+=QString::number(pj.inList[0])+"(";
                    }
                }
                else
                {
                    tree+=QString::number(pj.inList[0])+"(";
                }

                if(pj.inList[1]-100000<d_l.size())
                {
                    tree+=QString::number(pj.inList[1])+",";
                }
                else
                {
                    tree+="1000000,";
                }

                if(pj.inList[2]-100000<d_l.size())
                {
                    tree+=QString::number(pj.inList[2])+");";
                }
                else
                {
                    tree+="1000000);";
                }
            }
            else
            {
                tree="";
            }
        }

        param_cross pt=pl[1];

        if(tree!="")
        {
            QString tree_t="";

            if(pt.tig<p_l.size())
            {
                tree_t=nsv_image_tree::ParamToTree(pt,p_l,d_l);
            }
            else if(pt.tig>=200000 && pt.tig-200000<n_l.size())
            {
                tree_t=nsv_image_tree::NodeToTree(pt,n_l,d_l);
            }

            if(tree_t!="")
            {
                tree+=tree_t+";";
            }
            else
            {
                tree="";
            }
        }

        param_cross pf=pl[2];

        if(tree!="")
        {
            QString tree_f="";

            if(pf.tig<p_l.size())
            {
                tree_f=nsv_image_tree::ParamToTree(pf,p_l,d_l);
            }
            else if(pf.tig>=200000 && pf.tig-200000<n_l.size())
            {
                tree_f=nsv_image_tree::NodeToTree(pf,n_l,d_l);
            }

            if(tree_f!="")
            {
                tree+=tree_f+"]";
            }
            else
            {
                tree="";
            }
        }
    }

    return tree;
}

