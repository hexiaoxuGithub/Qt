#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QLabel>
#include <QGridLayout>
class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();
     void updateLabel();
     QLabel *label1;
     QLabel *label2;
     QLabel *label3;
     QLabel *label4;
     QLabel *label5;
     QLabel *label6;
     QLabel *label7;
     QLabel *label8;
     QLabel *label9;
     QLabel *label11;
     QLabel *label12;
     QLabel *label13;
     QLabel *label14;
     QLabel *label15;
     QLabel *label16;
     QLabel *label17;
     QLabel *label18;
     QLabel *label19;

     QGridLayout *layout;


protected:
     void moveEvent(QMoveEvent *);
     void resizeEvent(QResizeEvent *);

};
#endif // DIALOG_H
