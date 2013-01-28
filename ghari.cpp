#include<QVBoxLayout>
#include<QWidget>
#include<QPalette>
#include"digiclock.h"
#include"mybutton.h"
#include"ghari.h"
#include"alarmdialog.h"
#include<QLabel>
#include<QApplication>
#include<QDebug>

int startx,starty;bool press=false;int triple=0;
QTimer * waiter;
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

//tripple click functionality
switch(triple)
  {
   case 0:waiter=new QTimer();
         waiter->setInterval(800);
         waiter->setSingleShot(true);
         waiter->start();
         ++triple;
         break;
   case 1:
         if(waiter->isActive())++triple;
          else{triple=0;delete waiter;}
         break;
        
   case 2:if(waiter->isActive())
          {triple=0; 
          waiter->stop();
          delete waiter;
          this->close();
          }
          else{triple=0;
              waiter->stop();
              delete waiter;}  
          break;
  }
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

void ghari::closeEvent(QCloseEvent *e)
{ Q_UNUSED(e);
           QTimer *tame=new QTimer();
            tame->setInterval(1500);
            QColor color1(0,0,0);
            QColor color2(0,255,70);
            QLabel *lab=new QLabel("!Bye!");
            lab->setFixedSize(60,30);
            lab->setAlignment(Qt::AlignHCenter);
            QPalette pal=lab->palette();
            pal.setColor(QPalette::Window,color1);
            pal.setColor(QPalette::WindowText,color2);
            lab->setWindowOpacity(0.5);
            lab->setPalette(pal);
            lab->setWindowFlags(Qt::SplashScreen);
            lab->show();
       tame->start();
       connect(tame,SIGNAL(timeout()),QApplication::instance(),SLOT(quit()));
}


