#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QGridLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QFrame>

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();
public:
    QGridLayout *layout;
    QPushButton *filePushButton;
    QPushButton *colorPushButton;
    QPushButton *fontPushButton;
    QLineEdit *fileLineEdit;
    QLineEdit *fontLineEdit;
    QFrame *colorFrame;
private slots:
    void slotOpenFileDlg();
    void slotOpenColorDlg();
    void slotOpenFontDlg();
};
#endif // DIALOG_H
