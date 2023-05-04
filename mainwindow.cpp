#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "widgets/custowidget.h"
#include "widgets/console.h"
#include <QHBoxLayout>
#include <QDebug>
#include <QTime>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    mpv=new MpvWidget(this);
    QHBoxLayout *mpv_layout=new QHBoxLayout();
    mpv_layout->setMargin(0);
    mpv_layout->addWidget(mpv);


    QHBoxLayout *mpv_center_layout=new QHBoxLayout();
    Console *mpv_center_widget=new Console(mpv,this);
    mpv_center_layout->addWidget(mpv_center_widget);


    mpv->setLayout(mpv_center_layout);

    ui->Base->setLayout(mpv_layout);

//    connect(ui->Base,&CustoWidget::mouseMove,this,[=]{
//        QTime  now_time = QTime::currentTime();

//        qDebug()<<"鼠标在主页面移动了"<<now_time.second();
//    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

