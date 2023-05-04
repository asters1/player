#include "custowidget.h"
#include <QDebug>
#include <QTimer>
#include <QTime>

CustoWidget::CustoWidget(QWidget *parent) : QWidget(parent)
{
    //初始化定时器
    t=new QTimer(this);
    //当前时间
    now_time = QTime::currentTime();
    //设置鼠标跟踪
   setMouseTracking(true);

   connect(t,&QTimer::timeout,this,[=]{
       t->stop();
       emit clicked();});
}

void CustoWidget::mousePressEvent(QMouseEvent *)
{

   t->start(350);

}

void CustoWidget::mouseMoveEvent(QMouseEvent *)

{
    now_time = QTime::currentTime();
    emit mouseMove();
}

void CustoWidget::mouseDoubleClickEvent(QMouseEvent *)
{
    t->stop();
    emit doubleClicked();
}
