#include"digiclock.h"
#include"mybutton.h"
#include<QTimer>
#include<QTime>
#include<QPainter>
#include<QPen>
#include<QBrush>
#include<QPalette>
#include<QMouseEvent>
#include<QPoint>
#include<QColor>
#include<QPalette>
#include<QVBoxLayout>

int segments[10][7]={
{1,1,1,1,1,1,0},
{1,1,0,0,0,0,0},  
{1,0,1,1,0,1,1},
{1,1,1,0,0,1,1},
{1,1,0,0,1,0,1},
{0,1,1,0,1,1,1},
{0,1,1,1,1,1,1},
{1,1,0,0,0,1,0},
{1,1,1,1,1,1,1},
{1,1,0,0,1,1,1}
 };
bool colonkeliye=true;

digiclock::digiclock(QWidget* parent):QWidget(parent)
{
clockcore=new QTimer();QTimer *colontimer=new QTimer();
colontimer->setInterval(500);colontimer->start();
clockcore->setInterval(1000);clockcore->start();
connect(colontimer,SIGNAL(timeout()),this,SLOT(update()));
connect(clockcore,SIGNAL(timeout()),this,SLOT(update()));
setFixedSize(280,60);setWindowFlags(Qt::SplashScreen);
setWindowOpacity(0.5);
QPalette pal=palette();
QColor color(0,0,0);
pal.setColor(QPalette::Window,color);
setPalette(pal);
}

void digiclock::paintEvent(QPaintEvent *e)
{
Q_UNUSED(e);
QPainter * painter=new QPainter();
painter->begin(this);

QTime time=QTime::currentTime();
//hour
int hr1=time.hour();
int hr2=hr1/10;
hr1=hr1%10;
gothrough(painter,hr2,3,10);
gothrough(painter,hr1,50,10);
addColon(painter,92,22);
//min
int min2=time.minute();
int min1=min2/10;
min2=min2%10;
gothrough(painter,min1,114,10);
gothrough(painter,min2,154,10);
if(colonkeliye==true)
{addColon(painter,190,22);colonkeliye=false;}
else{colonkeliye=true;}
//sec
int now=time.second();
int now1=now/10;
now=now%10;
gothrough(painter,now1,210,10);
gothrough(painter,now,250,10);
}


void digiclock::gothrough(QPainter *painter,int now,int x, int y)
{
for(int i=0;i<10;i++)
   {  
    if(segments[now][i]==1)
     drawthis(painter,i,x,y);
   }
}


void digiclock::drawthis(QPainter *painter,int seg,int x,int y)
{
QColor color(0,255,70);
QBrush brush(color);
QPen pen(color);
pen.setWidth(5);
painter->setPen(pen);painter->setBrush(color);

switch(seg)
  {
	case 0:painter->drawLine(20+x,0+y,20+x,20+y);
          break;
	case 1:painter->drawLine(20+x,20+y,20+x,40+y);
          break;
	case 2:painter->drawLine(0+x,40+y,20+x,40+y);
          break;
	case 3:painter->drawLine(0+x,20+y,0+x,40+y);
          break;
	case 4:painter->drawLine(0+x,0+y,0+x,20+y);
          break;
 	case 5:painter->drawLine(0+x,0+y,20+x,0+y);
          break;
        case 6:painter->drawLine(0+x,20+y,20+x,20+y);
          break;
  }

}


void digiclock::addColon(QPainter *painter,int offx,int offy)
{
 painter->drawEllipse(offx,offy,3,3);
 painter->drawEllipse(offx,offy+15,3,3);
}


