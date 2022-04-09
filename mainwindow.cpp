#include "mainwindow.h"
#include "ui_mainwindow.h"


#include <QDebug>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->graphicsView->installEventFilter(this);
    ui->graphicsView->setMouseTracking(true);


    Mat image01=imread("C:/Users/thisi/Documents/opencvdemo/images/vir_cam_1_2022_03_28_13_04_18_821_1_3360.bmp");//一定要使用绝对路径，其他可以回报错
    Mat image02=imread("C:/Users/thisi/Documents/opencvdemo/images/vir_cam_1_2022_03_28_13_04_19_322_2_5280.bmp",1);
    Mat image03=imread("C:/Users/thisi/Documents/opencvdemo/images/vir_cam_1_2022_03_28_13_04_19_823_3_7200.bmp",1);
    Mat image04=imread("C:/Users/thisi/Documents/opencvdemo/images/vir_cam_1_2022_03_28_13_04_20_323_4_8880.bmp",1);
    Mat image05=imread("C:/Users/thisi/Documents/opencvdemo/images/vir_cam_1_2022_03_28_13_04_20_825_5_10800.bmp",1);

    Mat image06=imread("C:/Users/thisi/Documents/opencvdemo/images/vir_cam_2_2022_03_28_13_04_18_651_1_2640.bmp",1);
    Mat image07=imread("C:/Users/thisi/Documents/opencvdemo/images/vir_cam_2_2022_03_28_13_04_19_151_2_4560.bmp",1);
    Mat image08=imread("C:/Users/thisi/Documents/opencvdemo/images/vir_cam_2_2022_03_28_13_04_19_649_3_6480.bmp",1);
    Mat image09=imread("C:/Users/thisi/Documents/opencvdemo/images/vir_cam_2_2022_03_28_13_04_20_150_4_8160.bmp",1);

    Mat image010=imread("C:/Users/thisi/Documents/opencvdemo/images/vir_cam_3_2022_03_28_13_04_18_820_1_3360.bmp",1);
    Mat image011=imread("C:/Users/thisi/Documents/opencvdemo/images/vir_cam_3_2022_03_28_13_04_19_322_2_5280.bmp",1);
    Mat image012=imread("C:/Users/thisi/Documents/opencvdemo/images/vir_cam_3_2022_03_28_13_04_19_823_3_7200.bmp",1);
    Mat image013=imread("C:/Users/thisi/Documents/opencvdemo/images/vir_cam_3_2022_03_28_13_04_20_323_4_8880.bmp",1);
    Mat image014=imread("C:/Users/thisi/Documents/opencvdemo/images/vir_cam_3_2022_03_28_13_04_20_824_5_10800.bmp",1);



    if (image01.empty())
    {
        qDebug()<< "加载图片失败，请检查对应路径图片是否存在！" << endl;
        //  return 1;
    }

    /*
vir_cam_1_2022_03_28_13_04_18_821_1_3360
vir_cam_1_2022_03_28_13_04_19_322_2_5280
vir_cam_1_2022_03_28_13_04_19_823_3_7200
vir_cam_1_2022_03_28_13_04_20_323_4_8880
vir_cam_1_2022_03_28_13_04_20_825_5_10800


vir_cam_2_2022_03_28_13_04_18_651_1_2640
vir_cam_2_2022_03_28_13_04_19_151_2_4560
vir_cam_2_2022_03_28_13_04_19_151_2_4560
vir_cam_2_2022_03_28_13_04_19_649_3_6480
vir_cam_2_2022_03_28_13_04_20_150_4_8160


vir_cam_3_2022_03_28_13_04_18_820_1_3360
vir_cam_3_2022_03_28_13_04_19_322_2_5280
vir_cam_3_2022_03_28_13_04_19_823_3_7200
vir_cam_3_2022_03_28_13_04_20_323_4_8880
vir_cam_3_2022_03_28_13_04_20_824_5_10800
*/
    // int w1 = (image01.cols)/2; int h1 = (image01.rows)/2;//缩放大小无效
    int w1 = (image01.cols); int h1 = (image01.rows);
    int width = w1*3 ; int height =h1*5; //设置拼接后的图片尺寸

    Mat  resultImg = Mat(height,width, CV_8UC3, Scalar::all(0));
    Mat ROI_1 = resultImg(Rect(0, 0, w1, h1));
    Mat ROI_2 = resultImg(Rect(0,h1,w1, h1));
    Mat ROI_3 = resultImg(Rect(0,h1*2,w1, h1));
    Mat ROI_4 = resultImg(Rect(0,h1*3,w1, h1));
    Mat ROI_5 = resultImg(Rect(0,h1*4,w1, h1));

    Mat ROI_6 = resultImg(Rect(w1,0,w1, h1));
    Mat ROI_7 = resultImg(Rect(w1,h1,w1, h1));
    Mat ROI_8 = resultImg(Rect(w1,h1*2,w1, h1));
    Mat ROI_9 = resultImg(Rect(w1,h1*3,w1, h1));

    Mat ROI_10 = resultImg(Rect(w1*2,0,w1, h1));
    Mat ROI_11 = resultImg(Rect(w1*2,h1,w1, h1));
    Mat ROI_12 = resultImg(Rect(w1*2,h1*2,w1, h1));
    Mat ROI_13 = resultImg(Rect(w1*2,h1*3,w1, h1));
    Mat ROI_14 = resultImg(Rect(w1*2,h1*4,w1, h1));



    image01.copyTo(ROI_1);
    image02.copyTo(ROI_2);
    image03.copyTo(ROI_3);
    image04.copyTo(ROI_4);
    image05.copyTo(ROI_5);
    image06.copyTo(ROI_6);
    image07.copyTo(ROI_7);
    image08.copyTo(ROI_8);
    image09.copyTo(ROI_9);
    image010.copyTo(ROI_10);
    image011.copyTo(ROI_11);
    image012.copyTo(ROI_12);
    image013.copyTo(ROI_13);
    image014.copyTo(ROI_14);


    cvtColor(resultImg,resultImg, cv::COLOR_BGR2RGB); //threshold 是单通道图像（mat格式） ，把单通道转换为三通道
    img = QImage(resultImg.data, resultImg.cols, resultImg.rows, resultImg.step, QImage::Format_RGB888);//转换成QImage格式


    scene = new QGraphicsScene;//图像显示
    scene->addPixmap(QPixmap::fromImage(img));
    ui->graphicsView->setScene(scene);
    ui->graphicsView->show();
    ui->graphicsView->scale(0.2, 0.2);
    waitKey(0);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::wheelEvent(QWheelEvent *event)
{
    ui->graphicsView->scale(1/m_scale, 1/m_scale);
    if(event->delta() > 0){
        if(m_scale < 10){
            m_scale += 0.2;
        }else{
            m_scale = 10;
        }
    }else{
        if(m_scale > 0.2){
            m_scale -= 0.2;
        }else{
            m_scale = 0.2;
        }
    }
    ui->graphicsView->scale(m_scale, m_scale);
    qDebug()<<m_scale;
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    m_lastPointF = event->pos();
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    QPointF disPointF = event->pos() - m_lastPointF;
    m_lastPointF = event->pos();
    ui->graphicsView->scene()->setSceneRect(ui->graphicsView->scene()->sceneRect().x()+disPointF.x(),ui->graphicsView->scene()->sceneRect().y()+disPointF.y(),
                                            ui->graphicsView->scene()->sceneRect().width(),ui->graphicsView->scene()->sceneRect().height());
    ui->graphicsView->scene()->update();
}

void MainWindow::mouseDoubleClickEvent(QMouseEvent *event)
{

    //这里是鼠标双击事件

}


