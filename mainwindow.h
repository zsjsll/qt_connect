#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <dialog.h>
#include <QPoint>
#include <QDebug>
#include <QTimer>
#include <QMouseEvent>
#include <QMoveEvent>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void get(QString);
    void moveChange();

protected:
    void mouseMoveEvent(QMouseEvent*);
    void mousePressEvent(QMouseEvent*);
    bool eventFilter(QObject *, QEvent *);
    void moveEvent(QMoveEvent *);

private:
    Ui::MainWindow *ui;
    Dialog *dlg=new Dialog;
    QTimer *t=new QTimer;
    QPoint b;
    QPoint dragPosition;
};

#endif // MAINWINDOW_H
