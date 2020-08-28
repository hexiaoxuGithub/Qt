#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QFont f("ZYSong18030",12);
    setFont(f);

    setWindowTitle(tr("Image Processor"));

    imageLabel=new QLabel(this);
    imageLabel->setSizePolicy(QSizePolicy::Ignored,QSizePolicy::Ignored);
    imageLabel->setScaledContents(true);

    setCentralWidget(imageLabel);

    createActions();
    createMenus();
    createToolBars();
}

MainWindow::~MainWindow()
{
}


void MainWindow::slotOpenFile()
{
    QString fileName;
    fileName=QFileDialog::getOpenFileName(this);
    if(!fileName.isEmpty())
    {

          img.load(fileName);
          imageLabel->setPixmap(QPixmap::fromImage(img));
          resize(img.width(),img.height());
    }
}
void MainWindow::slotZoomIn()
{
    if(img.isNull())
        return;

    QMatrix matrix;
    matrix.scale(2,2);
    img=img.transformed(matrix);
    imageLabel->setPixmap(QPixmap::fromImage(img));
    imageLabel->resize(img.width(),img.height());
}
void MainWindow::slotZoomOut()
{
    if(img.isNull())
        return;

    QMatrix matrix;
    matrix.scale(0.5,0.5);
    img=img.transformed(matrix);
    imageLabel->setPixmap(QPixmap::fromImage(img));
    imageLabel->resize(img.width(),img.height());
}


void MainWindow::slotRotate90()
{
    if(img.isNull())
        return;

    QMatrix matrix;
    matrix.rotate(90);
    img=img.transformed(matrix);
    imageLabel->setPixmap(QPixmap::fromImage(img));
    resize(img.width(),img.height());
}

void MainWindow::slotRotate180()
{
    if(img.isNull())
        return;

    QMatrix matrix;
    matrix.rotate(180);
    img=img.transformed(matrix);
    imageLabel->setPixmap(QPixmap::fromImage(img));
    resize(img.width(),img.height());
}

void MainWindow::slotRotate270()
{
    if(img.isNull())
        return;

    QMatrix matrix;
    matrix.rotate(270);
    img=img.transformed(matrix);
    imageLabel->setPixmap(QPixmap::fromImage(img));
    resize(img.width(),img.height());
}

void MainWindow::slotMirrorVertical()
{
    if(img.isNull())
        return;

    img=img.mirrored(false,true);
    imageLabel->setPixmap(QPixmap::fromImage(img));
    resize(img.width(),img.height());
}

void MainWindow::slotMirrorHorizontal()
{
    if(img.isNull())
        return;

    img=img.mirrored(true,false);
    imageLabel->setPixmap(QPixmap::fromImage(img));
    resize(img.width(),img.height());
}


void MainWindow::createActions()
{

    //创建“打开”动作
    openFileAction=new QAction(QIcon(":/Icon/icon/dir.gif"),"Open",this);
    openFileAction->setShortcut(tr("Ctrl+O"));
    openFileAction->setStatusTip(tr("open a file"));
    connect(openFileAction,SIGNAL(triggered()),this,SLOT(slotOpenFile()));

    //创建“缩小”动作
    zoomInAction=new QAction(QIcon(":/images/open.png"),"New",this);
    zoomInAction->setShortcut(tr("Ctrl+S"));
    zoomInAction->setStatusTip(tr("ZoomIn"));
    connect(zoomInAction,SIGNAL(triggered()),this,SLOT(slotZoomIn()));

    //创建“放大”动作
    zoomOutAction=new QAction(QIcon(":/images/open.png"),"Save",this);
    zoomOutAction->setShortcut(tr("Ctrl+B"));
    zoomOutAction->setStatusTip(tr("ZoomOut"));
    connect(zoomOutAction,SIGNAL(triggered()),this,SLOT(slotZoomOut()));

    //创建“旋转90”动作
    rotate90Action=new QAction(QIcon(":/images/open.png"),"Save",this);
    rotate90Action->setShortcut(tr("Ctrl+Q"));
    rotate90Action->setStatusTip(tr("Rotate90"));
    connect(rotate90Action,SIGNAL(triggered()),this,SLOT(slotRotate90()));

    //创建“旋转180”动作
    rotate180Action=new QAction(QIcon(":/images/open.png"),"Save",this);
    rotate180Action->setShortcut(tr("Ctrl+W"));
    rotate180Action->setStatusTip(tr("Rotate180"));
    connect(rotate180Action,SIGNAL(triggered()),this,SLOT(slotRotate180()));

    //创建“旋转270”动作
    rotate270Action=new QAction(QIcon(":/images/open.png"),"Save",this);
    rotate270Action->setShortcut(tr("Ctrl+E"));
    rotate270Action->setStatusTip(tr("Rotate270"));
    connect(rotate270Action,SIGNAL(triggered()),this,SLOT(slotRotate270()));

    //创建“水平镜像”动作
    mirrorVerticalAction=new QAction(QIcon(":/images/open.png"),"Save",this);
    mirrorVerticalAction->setShortcut(tr("Ctrl+V"));
    mirrorVerticalAction->setStatusTip(tr("MirrorVeitical"));
    connect(mirrorVerticalAction,SIGNAL(triggered()),this,SLOT(slotMirrorVertical()));

    //创建“垂直镜像”动作
    mirrorHorizontalAction=new QAction(QIcon(":/images/open.png"),"Save",this);
    mirrorHorizontalAction->setShortcut(tr("Ctrl+H"));
    mirrorHorizontalAction->setStatusTip(tr("MirrorHorizontal"));
    connect(mirrorHorizontalAction,SIGNAL(triggered()),this,SLOT(slotMirrorHorizontal()));

}
void MainWindow::createMenus()
{
    //文件菜单
    fileMenu=menuBar()->addMenu("文件");
    fileMenu->addAction(openFileAction);

    //缩放菜单
    fileMenu=menuBar()->addMenu("缩放");
    fileMenu->addAction(zoomInAction);
    fileMenu->addAction(zoomOutAction);


    //旋转菜单
    fileMenu=menuBar()->addMenu("旋转");
    fileMenu->addAction(rotate90Action);
    fileMenu->addAction(rotate180Action);
    fileMenu->addAction(rotate270Action);


    //镜像菜单
    fileMenu=menuBar()->addMenu("镜像");
    fileMenu->addAction(mirrorVerticalAction);
    fileMenu->addAction(mirrorHorizontalAction);


}
void MainWindow::createToolBars()
{

}




