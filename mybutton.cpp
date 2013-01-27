#include"mybutton.h"
#include<QPushButton>
#include<QPainter>

bool enter=false;
mybutton::mybutton(QWidget *parent):QPushButton(parent)
{
setFixedSize(140,15);setWindowOpacity(0.5);
QColor color(0,0,0);
QPalette pal=palette();
setWindowFlags(Qt::SplashScreen);
pal.setColor(QPalette::Window,color);
setPalette(pal);
update();
}

void mybutton::paintEvent(QPaintEvent *e)
{
Q_UNUSED(e);
QPen pen;
QColor color1(0,255,70);QColor color2(0,0,0);
QPainter *painter=new QPainter();
painter->begin(this);
if(enter==true)
  {pen.setColor(color1);}
else{pen.setColor(color2);}
pen.setWidth(2);
painter->setPen(pen);
painter->drawRect(2,2,135,10);
}

void mybutton::enterEvent(QEvent *e)
{Q_UNUSED(e);
enter=true;update();
}

void mybutton::leaveEvent(QEvent *e)
{Q_UNUSED(e);
enter=false;update();
}
