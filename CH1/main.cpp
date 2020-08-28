#include "widget.h"

#include <QApplication>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QPushButton b("HEllo World");
    b.show();
    QObject::connect(&b,SIGNAL(clicked()),&app,SLOT(quit()));
    return app.exec();
}
