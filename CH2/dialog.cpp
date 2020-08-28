#include "dialog.h"
#include <QFileDialog>
#include <QColorDialog>
#include <QFontDialog>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle(tr("Standard Dialog"));
    layout =new QGridLayout(this);

    filePushButton=new QPushButton;
    filePushButton->setText("FileDialog");

    colorPushButton=new QPushButton;
    colorPushButton->setText("ColorDialog");

    fontPushButton=new QPushButton;
    fontPushButton->setText("FontDialog");

    fileLineEdit=new QLineEdit;

    colorFrame=new QFrame;
    colorFrame->setFrameShape(QFrame::Box);
    colorFrame->setAutoFillBackground(true);

    fontLineEdit=new QLineEdit("Hello World");

    layout->addWidget(filePushButton,0,0);
    layout->addWidget(fileLineEdit,0,1);
    layout->addWidget(fontPushButton,1,0);
    layout->addWidget(fontLineEdit,1,1);
    layout->addWidget(colorPushButton,2,0);
    layout->addWidget(colorFrame,2,1);

    layout->setMargin(15);
    layout->setSpacing(10);

    connect(filePushButton,SIGNAL(clicked()),this,SLOT(slotOpenFileDlg()));
    connect(colorPushButton,SIGNAL(clicked()),this,SLOT(slotOpenColorDlg()));
    connect(fontPushButton,SIGNAL(clicked()),this,SLOT(slotOpenFontDlg()));


}

Dialog::~Dialog()
{

}

void Dialog::slotOpenFileDlg()
{
    QString s=QFileDialog::getOpenFileName(this,"OpenFileDlg","/","C++ Files(*.cpp);;C Fiel(*.c);;Head Files(*.h)");
    fileLineEdit->setText(s.toUtf8());
}

void Dialog::slotOpenColorDlg()
{
    QColor color=QColorDialog::getColor(Qt::blue);
    if(color.isValid())
    {
        colorFrame->setPalette(QPalette(color));
    }
}
void Dialog::slotOpenFontDlg()
{
   bool ok;
   QFont font=QFontDialog::getFont(&ok);
   if(ok)
   {
       fontLineEdit->setFont(font);
   }

}
