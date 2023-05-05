#include "console.h"
#include "ui_console.h"
#include "custowidget.h"
#include <QDebug>

Console::Console(MpvWidget *mpv,QWidget *parent) :
  QWidget(parent),
    ui(new Ui::Console)
{
    ui->setupUi(this);
    ui->seek->setH(100);
    ui->time->setText(getTime());
    this->mpv=mpv;
    t=new QTimer(this);
//    tm=new QTimer(this);
    tm=0;
    connect(mpv,&MpvWidget::durationChanged,ui->seek,&seekBar::setMaxValue);
    connect(mpv,&MpvWidget::positionChanged,ui->seek,&seekBar::setValue);
    connect(ui->seek,&seekBar::Moved,this,&Console::seek);
    connect(t,&QTimer::timeout,this,[=]{

    ui->time->setText(getTime());
    tm=tm+1;
    //ui->seek->setValue(tm);
    emit change();
//    qDebug()<<tm<<"s";
//        ui->seek->setMaxValue(mpv->getTimeLength());
    });
    t->start(1000);
    connect(this,&Console::change,this,[=]{
        if(tm>5){
      ui->widget->hide();
        }
    });
    connect(ui->widget,&CustoWidget::mouseMove,this,[=]{
        ui->widget->showNormal();
    });
    connect(ui->btn_play_play,&QPushButton::clicked,mpv,[=]{
         mpv->command(QStringList() << "loadfile" << "/home/asters/download/localsend/斗罗大陆01.ts");
         qDebug()<<"时长："<<mpv->getTimeLength();

    });
    connect(ui->widget,&CustoWidget::clicked,this,[=]{

    QTime now_time = QTime::currentTime();
        qDebug()<<"单击了"<<now_time.second();
    });
    connect(ui->widget,&CustoWidget::mouseMove,this,[=]{
        tm=0;
        ui->widget->showNormal();
    });
     connect(ui->bottom,&CustoWidget::clicked,this,[=]{

    QTime now_time = QTime::currentTime();
        qDebug()<<"b单击了"<<now_time.second();
    });
    connect(ui->bottom,&CustoWidget::mouseMove,this,[=]{
        tm=0;
        ui->widget->showNormal();
    });


}

Console::~Console()
{
    delete ui;
}

QString Console::getTime()
{

    now_time=QTime::currentTime();
    int H=now_time.hour();
    int M=now_time.minute();
    int S=now_time.second();
    QString SH="";
    QString SM="";
    QString SS="";
    if(H>=0&&H<10){
        SH="0"+QString::number(H);
    }else{
        SH=QString::number(H);
    }
    if(M>=0&&M<10){
        SM="0"+QString::number(M);
    }else{
        SM=QString::number(M);
    }
    if(S>=0&&S<10){
        SS="0"+QString::number(S);
    }else{
        SS=QString::number(S);
    }
    return SH+":"+SM+":"+SS;
}

void Console::seek(int pos)
{

  mpv->command(QVariantList() << "seek" << pos << "absolute");
}
