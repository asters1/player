#ifndef CUSTOWIDGET_H
#define CUSTOWIDGET_H

#include <QWidget>
#include <QTimer>
#include <QTime>
class CustoWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CustoWidget(QWidget *parent = nullptr);
    //单击
    void mousePressEvent(QMouseEvent *event);
    //双击
    void mouseMoveEvent(QMouseEvent *event);
    //移动
    void mouseDoubleClickEvent(QMouseEvent *event);

private:
    QTimer *t;
    QTime now_time;
signals:

  void clicked();
  void doubleClicked();
  void mouseMove();
private slots:
};

#endif // CUSTOWIDGET_H
