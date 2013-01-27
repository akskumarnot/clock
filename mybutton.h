#ifndef MYBUTTON_H
#define MYBUTTON_H
#include<QPushButton>
#include<QPaintEvent>
class mybutton:public QPushButton
{Q_OBJECT
public:
mybutton(QWidget *parent=0);
protected:
void paintEvent(QPaintEvent *e);
void enterEvent(QEvent *e);
void leaveEvent(QEvent *e);
};

#endif
