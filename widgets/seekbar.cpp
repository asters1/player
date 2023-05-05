#include "seekbar.h"
#include "ui_seekbar.h"
#include <QDebug>

seekBar::seekBar(QWidget *parent) : QWidget(parent), ui(new Ui::seekBar) {
  ui->setupUi(this);
  t1 = 0;
  t2 = 0;
  value = 0;
  this->maxValue = 99;
  connect(this, &seekBar::changeT1, this, &seekBar::setT1);
  connect(this,&seekBar::clicked,this,&seekBar::clickSetValue);
}

seekBar::~seekBar() { delete ui; }

void seekBar::mousePressEvent(QMouseEvent *) { emit clicked(); }

void seekBar::setH(int h) {
  this->setGeometry(this->geometry().x(), this->geometry().y(),
                    this->geometry().width(), h);
}

// void seekBar::setSeek(int x)
//{
//    ui->jd->setGeometry(ui->jd->geometry().x(),ui->jd->geometry().y(),ui->jd->width()+x,ui->jd->geometry().height());

//}

void seekBar::setMaxValue(int max) {
  this->maxValue = max;
  setT2();
}

int seekBar::getMaxValue() { return this->maxValue; }

int seekBar::getValue() { return this->value; }

void seekBar::clickSetValue() {
  //    //获取：窗口基于屏幕的位置，左上角位置
  //    QPoint pt = this->pos();
  //获取当前点位于屏幕坐标的点
  QPoint pt0 = this->cursor().pos();
  //屏幕坐标点 --> 成当前窗口坐标点
  QPoint pt1 = this->mapFromGlobal(pt0);
  //    //窗口上坐标点 -- >屏幕坐标
  //    QPoint pt2 = this->mapToGlobal(pt1);
  //    //当前窗口坐标 -- > 成屏幕坐标
  //    QPoint pt3 = this->mapToParent(pt1);
  //    //屏幕坐标 -- >窗口坐标
  //    QPoint pt4 = this->mapFromParent(pt0);
  if (pt1.x() > ui->t1->geometry().width() &&
      pt1.x() < ui->t2->geometry().x()) {
    int x = pt1.x() - ui->t1->geometry().width();
    int t = ((x * 1.0) / ui->bottom->geometry().width()) * getMaxValue();

    qDebug() << "x:" << x << "width:" << ui->bottom->geometry().width()
             << "max:" << getMaxValue() << "t:" << t;
//    setValue(t);
    emit Moved(t);
//    return t;
  } else {
    qDebug() << "不再范围内:" << getValue();
//    return getValue();
  }
}

void seekBar::setT1(int v) {
  if (v > getMaxValue()) {
    v = getMaxValue();
  }
  QString SH = "";
  QString SM = "";
  QString SS = "";
  QString ST1 = "";
  if (v > 3600) {
    int H = v / 3600;
    int HY = v % 3600;
    int M = HY / 60;
    int S = HY % 60;

    SH = timeToQstr(H);
    SM = timeToQstr(M);
    SS = timeToQstr(S);

    ST1 = SH + ":" + SM + ":" + SS;

  } else {
    int M = v / 60;
    int S = v % 60;
    SM = timeToQstr(M);
    SS = timeToQstr(S);
    ST1 = SM + ":" + SS;
  }
  ui->t1->setText(ST1);
}

void seekBar::setT2() {
  int v = this->getMaxValue();
  QString SH = "";
  QString SM = "";
  QString SS = "";
  QString ST2 = "";
  if (v > 3600) {
    int H = v / 3600;
    int HY = v % 3600;
    int M = HY / 60;
    int S = HY % 60;
    SH = timeToQstr(H);
    SM = timeToQstr(M);
    SS = timeToQstr(S);
    ST2 = SH + ":" + SM + ":" + SS;

  } else {
    int M = v / 60;
    int S = v % 60;
    SM = timeToQstr(M);
    SS = timeToQstr(S);
    ST2 = SM + ":" + SS;
  }
  ui->t2->setText(ST2);
}

QString seekBar::timeToQstr(int t) {
  QString ST = "";
  if (t >= 0 && t < 10) {
    ST = "0" + QString::number(t);
  } else {
    ST = QString::number(t);
  }
  return ST;
}

void seekBar::setValue(int value) {
  setT1(value);
  this->value = value;
  float fv = value * 1.0;
  int bottom_width = ui->bottom->geometry().width();
  float bl = fv / this->maxValue;
  int v = bl * bottom_width;

  // qDebug()<<"v:"<<v<<" width:"<<bottom_width;

  ui->jd->setGeometry(ui->jd->geometry().x(), ui->jd->y(), v, ui->jd->height());
}
