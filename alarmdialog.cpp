#include"mybutton.h"
#include<QLabel>
#include<QVBoxLayout>
#include"alarmdialog.h"
#include<QPalette>

int startx1,starty1;bool press1=false;
alarmdialog::alarmdialog(QWidget*parent):QWidget(parent)
{
QLabel *lab=new QLabel("*SET Alarm*");
QPalette pal=palette();
QColor color(0,255,70);
pal.setColor(QPalette::WindowText,color);
setPalette(color);
color.setRgb(0,0,0);
pal.setColor(QPalette::Window,color);
setPalette(pal);
setWindowFlags(Qt::SplashScreen);
QVBoxLayout *lay=new QVBoxLayout();
lay->addStretch(1);
lay->addWidget(lab);
setLayout(lay);
setFixedSize(300,50);
setWindowOpacity(0.5);
}

void alarmdialog::mouseMoveEvent(QMouseEvent *e)
{
if(press1==true)
 {
int dx=e->globalX()-startx1;
int dy=e->globalY()-starty1;

startx1=e->globalX();
starty1=e->globalY();
move(x()+dx,y()+dy);
 }

}

void alarmdialog::mouseReleaseEvent(QMouseEvent* e)
{
Q_UNUSED(e);
press1=false;
}

void alarmdialog::mousePressEvent(QMouseEvent *e)
{
press1=true;
startx1=e->globalX();
starty1=e->globalY();
}




