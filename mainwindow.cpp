#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->connect(dlg,SIGNAL(conn(QString)),this,SLOT(get(QString)));
    //this->connect(t,SIGNAL(timeout()),this,SLOT(moveChange()));
    t->start(1);
    setWindowFlags(Qt::FramelessWindowHint);
    ui->label->installEventFilter(this);



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    qDebug()<<this->pos();
    QPoint a=this->pos();
    a.setX(a.x()-420);
    //a.setY(a.y()-300);
    dlg->move(a);
    dlg->show();
    //dlg->exec();
    //dlg->ui;
}

void MainWindow::get(QString a)
{
    ui->textEdit->setText(a);
}

void MainWindow::moveChange()
{
    //qDebug()<<this->pos();
    b=this->pos();
    b.setX(b.x()-420);
    //qDebug()<<b;
    dlg->move(b);

}

void MainWindow::mouseMoveEvent(QMouseEvent *e)
{
    if(e->buttons()&Qt::LeftButton)
    {
        move(cursor().pos()-dragPosition);//鼠标位置减去按下点的坐标
        //qDebug()<<e->globalPos();
        //e->accept();
    }
}

void MainWindow::mousePressEvent(QMouseEvent *e)
{
    if(e->button()==Qt::LeftButton)
    {
        dragPosition=e->globalPos()-frameGeometry().topLeft();//鼠标位置减去左上角的左边
        //qDebug()<<QCursor::pos();
        //e->accept();
    }
}

bool MainWindow::eventFilter(QObject *obj, QEvent *e)
{
    if(obj==this->ui->label)
    {
        //qDebug() << "123123123" ;
        if(e->type()==QEvent::MouseButtonPress)
        {
            QMouseEvent *mouse=dynamic_cast<QMouseEvent*>(e);

            if(mouse->button()==Qt::RightButton){
                ui->label->setText("7654321");
                ui->label->setStyleSheet("background-color:red");
                //qDebug() << "123123123" ;
                return true;
            }

            else if(mouse->button()==Qt::LeftButton){
                ui->label->setText("7654321");
                ui->label->setStyleSheet("background-color:green");
                //qDebug() << "123123123" ;
                return true;
            }

        }
        else{
            return false;
        }

    }
    else{
        return QMainWindow::eventFilter(obj,e);
    }
}

void MainWindow::moveEvent(QMoveEvent *)
{
    //qDebug()<<this->pos();
    b=this->pos();
    b.setX(b.x()-420);
    //qDebug()<<e->pos();
    dlg->move(b);

}




