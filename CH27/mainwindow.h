#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QMenu>
#include <QAction>
#include <QToolBar>
#include <QFont>
#include <QFileDialog>
#include <QMenuBar>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void createMenus();
    void  createActions();
    void  createToolBars();
private:
    QImage img;
    QLabel *imageLabel;

    QMenu *fileMenu;
    QMenu *zoomMenu;
    QMenu *rotateMenu;
    QMenu *mirrorMenu;

    QAction *openFileAction;
    QAction *zoomInAction;
    QAction *zoomOutAction;
    QAction *rotate90Action;
    QAction *rotate180Action;
    QAction *rotate270Action;
    QAction *mirrorVerticalAction;
    QAction *mirrorHorizontalAction;

    QToolBar *fileTool;
    QToolBar *zoomTool;
    QToolBar *rotateTool;
    QToolBar *mirrorTool;

protected slots:
    void  slotOpenFile();
    void  slotZoomIn();
    void  slotZoomOut();
    void  slotRotate90();
    void  slotRotate180();
    void  slotRotate270();
    void  slotMirrorVertical();
    void  slotMirrorHorizontal();


};
#endif // MAINWINDOW_H
