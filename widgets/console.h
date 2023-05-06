#ifndef CONSOLE_H
#define CONSOLE_H

#include <QWidget>
#include "mpv/mpvwidget.h"
#include "custowidget.h"
#include <QTimer>
#include <QTime>
#include <QString>

namespace Ui {
class Console;
}

class Console : public QWidget
{
    Q_OBJECT

public:
    explicit Console(MpvWidget *mpv,QWidget *parent = nullptr);
    ~Console();
    QString getTime();

public slots:
    void seek(int pos);
    void setResolution(QString r);
signals:
    void change();
private:
    Ui::Console *ui;
    MpvWidget *mpv;
    QTimer *t;
    int tm;
    QTime now_time;

};

#endif // CONSOLE_H
