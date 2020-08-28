#include "dialog.h"
#include <QFrame>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle("Geometry");
    label1=new QLabel("x():");
    label2=new QLabel("y():");
    label3=new QLabel("frameGeometry():");
    label4=new QLabel("pos():");
    label5=new QLabel("geometry():");
    label6=new QLabel("width():");
    label7=new QLabel("height():");
    label8=new QLabel("rect():");
    label9=new QLabel("size():");

    label11=new QLabel;
    label12=new QLabel;
    label13=new QLabel;
    label14=new QLabel;
    label15=new QLabel;
    label16=new QLabel;
    label17=new QLabel;
    label18=new QLabel;
    label19=new QLabel;

    layout=new QGridLayout(this);
    layout->addWidget(label1,0,0);
    layout->addWidget(label2,1,0);
    layout->addWidget(label3,2,0);
    layout->addWidget(label4,3,0);
    layout->addWidget(label5,4,0);
    layout->addWidget(label6,5,0);
    layout->addWidget(label7,6,0);
    layout->addWidget(label8,7,0);
    layout->addWidget(label9,8,0);

    layout->addWidget(label11,0,1);
    layout->addWidget(label12,1,1);
    layout->addWidget(label13,2,1);
    layout->addWidget(label14,3,1);
    layout->addWidget(label15,4,1);
    layout->addWidget(label16,5,1);
    layout->addWidget(label17,6,1);
    layout->addWidget(label18,7,1);
    layout->addWidget(label19,8,1);

    updateLabel();
}

Dialog::~Dialog()
{
}
void Dialog::moveEvent(QMoveEvent *)
{
    updateLabel();
}
void Dialog::resizeEvent(QResizeEvent *)
{
    updateLabel();
}

void Dialog::updateLabel()
{
     QString temp1,temp2,temp3,temp4;

    QString str_x;
    label11->setText(str_x.setNum(x()));

    QString str_y;
    label12->setText(str_y.setNum(y()));

    QString frameGeo;

    frameGeo=temp1.setNum(frameGeometry().x())+","+
            temp2.setNum(frameGeometry().y())+","+
            temp3.setNum(frameGeometry().width())+","+
            temp4.setNum(frameGeometry().height());
    label13->setText(frameGeo);

    QString position;
    position =temp1.setNum(pos().x())+","+temp2.setNum(pos().y());
    label14->setText(position);

    QString geo;
    geo=temp1.setNum(geometry().x())+","+
            temp2.setNum(geometry().y())+","+
            temp3.setNum(geometry().width())+","+
            temp4.setNum(geometry().height());
    label15->setText(geo);

    QString w;
    label16->setText(w.setNum(width()));

    QString h;
    label17->setText(h.setNum(height()));

    QString r;
    r=temp1.setNum(rect().x())+","+
            temp2.setNum(rect().y())+","+
            temp3.setNum(rect().width())+","+
            temp4.setNum(rect().height());
     label18->setText(r);


     QString s;
     s=temp1.setNum(size().width())+","+
             temp2.setNum(size().height());
      label19->setText(s);

}
