#ifndef DIGICLOCK_H
#define DIGICLOCK_H
#include<QWidget>
#include<QTimer>
class digiclock:public QWidget
{Q_OBJECT
private:
QTimer *clockcore;
public:
digiclock(QWidget *parent=0);
void gothrough(QPainter *painter,int now,int,int);
void drawthis(QPainter *painter,int seg,int,int);
void addColon(QPainter*,int,int);
public slots:
protected:
void paintEvent(QPaintEvent* event);
};

#endif
