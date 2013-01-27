#include<QApplication>
#include"ghari.h"

int main(int argc,char* argv[])
{
QApplication app(argc,argv);
ghari *gh=new ghari();
return app.exec();
}
