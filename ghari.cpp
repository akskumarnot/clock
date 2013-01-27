#include<QVBoxLayout>
#include<QWidget>
#include<QPalette>
#include"digiclock.h"
#include"mybutton.h"
#include"ghari.h"
#include"alarmdialog.h"

int startx,starty;bool press=false;

ghari::ghari(QWidget*parent):QWidget(parent)
{
digiclock *clk=new digiclock();
mybutton *but=new mybutton();
QVBoxLayout *lay=new QVBoxLayout();
QHBoxLayout *l=new QHBoxLayout();
l->addSpacing(0.5);
l->addWidget(but);
lay->addWidget(clk);
lay->addLayout(l);
setLayout(lay);
setWindowOpacity(0.5);
QPalette pal=palette();
QColor color(0,0,0);
pal.setColor(QPalette::Window,color);
setPalette(pal);
setWindowFlags(Qt::SplashScreen);
setFixedSize(300,95);

connect(but,SIGNAL(clicked()),this,SLOT(onclickedglowingbut()));
show();
}

void ghari::mousePressEvent(QMouseEvent *e)
{
press=true;
startx=e->globalX();
starty=e->globalY();
}

void ghari::mouseMoveEvent(QMouseEvent *e)
{
if(press==true)
 {
int dx=e->globalX()-startx;
int dy=e->globalY()-starty;

startx=e->globalX();
starty=e->globalY();
move(x()+dx,y()+dy);
 }

}

void ghari::mouseReleaseEvent(QMouseEvent* e)
{
Q_UNUSED(e);
press=false;
}


void ghari::onclickedglowingbut()
{
alarmdialog *ad=new alarmdialog();
ad->show();
}


