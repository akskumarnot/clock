#ifndef ALARMDIALOG_H
#define ALARMDIALOG_H
#include<QWidget>

class alarmdialog:public QWidget
{Q_OBJECT
public:
alarmdialog(QWidget* parent=0);
protected:
void mouseReleaseEvent(QMouseEvent* e);
void mouseMoveEvent(QMouseEvent* e);
void mousePressEvent(QMouseEvent* e);
};


#endif
