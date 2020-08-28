#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAction>
#include <QTextEdit>
#include <QMenuBar>
#include <QToolBar>
#include <QFileDialog>
#include <QTextStream>
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void createMenus();
    void createAction();
    void createToolBars();
    void loadFile(QString fileName);


public slots:
    void slotNewFile();
    void slotOpenFile();
    void slotSaveFile();
    void slotAbout();
private:
    QMenu *fileMenu;
    QMenu *editMenu;
    QMenu  *aboutMenu;
    QToolBar *fileToolBar;
    QToolBar *editToolBar;
    QAction *fileOpenAction;
    QAction *fileNewAction;
    QAction *fileSaveAction;
    QAction *exitAction;
    QAction *copyAction;
    QAction *cutAction;
    QAction *pasteAction;
    QAction *aboutAction;

    QTextEdit *text;



};
#endif // MAINWINDOW_H
