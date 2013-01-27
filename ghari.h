#ifndef GHARI_H
#define GHARI_H
#include<QWidget>

class ghari :public QWidget
{Q_OBJECT
public:
ghari(QWidget* parent=0);
protected:
void mousePressEvent(QMouseEvent *e);
void mouseReleaseEvent(QMouseEvent *e);
void mouseMoveEvent(QMouseEvent *e);
public slots:
void onclickedglowingbut();
};
#endif
