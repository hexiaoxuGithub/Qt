#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("QMainWindow");
    text=new QTextEdit(this);
    setCentralWidget(text);

    createAction();
    createMenus();
    createToolBars();
}

MainWindow::~MainWindow()
{

}

void MainWindow::slotNewFile()
{
    MainWindow *newWindow=new MainWindow;
    newWindow->show();

}

void MainWindow::slotSaveFile()
{

}

void MainWindow::slotOpenFile()
{
    QString fileName;
    fileName=QFileDialog::getOpenFileName(this);
    if(!fileName.isEmpty())
    {
        if(text->document()->isEmpty())
        {
            loadFile(fileName);
        }
        else
        {
            MainWindow *newWin=new MainWindow;
            newWin->show();
            newWin->loadFile(fileName);
        }

    }
}


void MainWindow::slotAbout()
{

}
void MainWindow::loadFile(QString fileName)
{
    printf("file name:%s\n",fileName.data());
    QFile file(fileName);
    if(file.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        QTextStream  textStream(&file);
        while(!textStream.atEnd())
        {
            text->append(textStream.readLine());
            printf("readline \n");
        }
          printf("end \n");
    }

}


void MainWindow::createMenus()
{
    //文件菜单
    fileMenu=menuBar()->addMenu("文件");
    fileMenu->addAction(fileNewAction);
    fileMenu->addAction(fileOpenAction);
    fileMenu->addAction(fileSaveAction);
    fileMenu->addAction(exitAction);


    //编辑菜单
    editMenu=menuBar()->addMenu("编辑");
    editMenu->addAction(copyAction);
    editMenu->addAction(cutAction);
    editMenu->addAction(pasteAction);

    //帮助菜单
    aboutMenu=menuBar()->addMenu("帮助");
    aboutMenu->addAction(aboutAction);

}


void MainWindow::createAction()

{
    //创建“打开”动作
    fileOpenAction=new QAction(QIcon(":/Icon/icon/dir.gif"),"Open",this);
    fileOpenAction->setShortcut(tr("Ctrl+O"));
    fileOpenAction->setStatusTip(tr("open a file"));
    connect(fileOpenAction,SIGNAL(triggered()),this,SLOT(slotOpenFile()));

    //创建“新建”动作
    fileNewAction=new QAction(QIcon(":/images/open.png"),"New",this);
    fileNewAction->setShortcut(tr("Ctrl+N"));
    fileNewAction->setStatusTip(tr("build a file"));
    connect(fileNewAction,SIGNAL(triggered()),this,SLOT(slotNewFile()));

    //创建“保存”动作
    fileSaveAction=new QAction(QIcon(":/images/open.png"),"Save",this);
    fileSaveAction->setShortcut(tr("Ctrl+S"));
    fileSaveAction->setStatusTip(tr("save a file"));
    connect(fileOpenAction,SIGNAL(triggered()),this,SLOT(slotSaveFile()));

    //创建“退出”动作
    exitAction=new QAction(QIcon(":/images/open.png"),"Exit",this);
    exitAction->setShortcut(tr("Ctrl+Q"));
    exitAction->setStatusTip(tr("exit"));
    connect(exitAction,SIGNAL(triggered()),this,SLOT(close()));

    //创建“剪切”动作
    cutAction=new QAction(QIcon(":/images/open.png"),"Cut",this);
    cutAction->setShortcut(tr("Ctrl+X"));
    cutAction->setStatusTip(tr("cut to clipboard"));
    connect(fileOpenAction,SIGNAL(triggered()),text,SLOT(cut()));

    //创建“复制”动作
    copyAction=new QAction(QIcon(":/images/open.png"),"Copy",this);
    copyAction->setShortcut(tr("Ctrl+C"));
    copyAction->setStatusTip(tr("paste clipboard to selection"));
    connect(copyAction,SIGNAL(triggered()),text,SLOT(copy()));

    //创建“粘贴”动作
    pasteAction=new QAction(QIcon(":/images/open.png"),"Paste",this);
    pasteAction->setShortcut(tr("Ctrl+V"));
    pasteAction->setStatusTip(tr("exit"));
    connect(fileOpenAction,SIGNAL(triggered()),text,SLOT(paste()));

    //创建“关于”动作
    aboutAction=new QAction(QIcon(":/images/open.png"),"About",this);
    aboutAction->setShortcut(tr("Ctrl+Q"));
    aboutAction->setStatusTip(tr("About"));
    connect(fileOpenAction,SIGNAL(triggered()),this,SLOT(slotAbout()));

}


void MainWindow::createToolBars()
{
    //文件工具栏
    fileToolBar=addToolBar("文件");
    fileToolBar->addAction(fileNewAction);
    fileToolBar->addAction(fileOpenAction);
    fileToolBar->addAction(fileSaveAction);


    //编辑工具栏
     editToolBar=addToolBar("编辑");
     editToolBar->addAction(copyAction);
     editToolBar->addAction(cutAction);
     editToolBar->addAction(pasteAction);
}

