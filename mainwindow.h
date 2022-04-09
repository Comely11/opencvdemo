#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPaintEvent>
#include <QScrollBar>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <QFileDialog>
#include <QString>
#include <QTextCodec>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui_c.h>
#include <QPainter>

#include <QGraphicsPixmapItem>
#include<Windows.h>
QT_BEGIN_NAMESPACE
using namespace cv;
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


    void wheelEvent(QWheelEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseDoubleClickEvent(QMouseEvent *event);
private:
    QWidget* sceneWidget;
 QImage img;
    QGraphicsPixmapItem *m_bkPixmapItem;
QGraphicsScene *scene;
    QPointF m_lastPointF;
    qreal m_scale = 1;
private slots:


private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
