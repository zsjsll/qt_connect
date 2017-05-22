#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_textEdit_textChanged()
{
    QString txt;
    txt = ui->textEdit->toPlainText();
    emit conn(txt);
}
