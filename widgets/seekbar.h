#ifndef SEEKBAR_H
#define SEEKBAR_H

#include <QWidget>

namespace Ui {
class seekBar;
}

class seekBar : public QWidget
{
    Q_OBJECT

public:
    explicit seekBar(QWidget *parent = nullptr);
    ~seekBar();
    void mousePressEvent(QMouseEvent *e);
    QString timeToQstr(int t);
signals:
    void clicked();
    void changeT1(int v);
public slots:
    void setValue(int value);
    void setH(int h);
    void setMaxValue(int max);
    void setT1(int v);
    void setT2();
    int getMaxValue();
    int getValue();
    int clickSetValue();
private:
    Ui::seekBar *ui;
    int t1;
    int t2;
    int value;
    int maxValue;

};

#endif // SEEKBAR_H
