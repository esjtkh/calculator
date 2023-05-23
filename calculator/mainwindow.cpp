#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include<string>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}






void MainWindow::on_one_clicked()
{
    QString text=ui->display->text();
    text+= QString::fromStdString("1");
    ui->display->setText(text);
}

void MainWindow::on_two_clicked()
{
    QString text=ui->display->text();
    text+=QString::fromStdString("2");
    ui->display->setText(text);

}

void MainWindow::on_three_clicked()
{
    QString text=ui->display->text();
    text+=QString::fromStdString("3");
    ui->display->setText(text);


}

void MainWindow::on_four_clicked()
{
    QString text=ui->display->text();
    text+=QString::fromStdString("4");
    ui->display->setText(text);
}

void MainWindow::on_five_clicked()
{
    QString text=ui->display->text();
    text+=QString::fromStdString("5");
    ui->display->setText(text);

}

void MainWindow::on_six_clicked()
{
    QString text=ui->display->text();
    text+=QString::fromStdString("6");
    ui->display->setText(text);
}

void MainWindow::on_seven_clicked()
{
    QString text=ui->display->text();
    text+=QString::fromStdString("7");
    ui->display->setText(text);
}

void MainWindow::on_eight_clicked()
{
    QString text=ui->display->text();
    text+=QString::fromStdString("8");
    ui->display->setText(text);
}

void MainWindow::on_nine_clicked()
{
    QString text=ui->display->text();
    text+=QString::fromStdString("9");
    ui->display->setText(text);
}

void MainWindow::on_zero_clicked()
{
    QString text=ui->display->text();
    text+=QString::fromStdString("0");
    ui->display->setText(text);
}

void MainWindow::on_plus_clicked()
{
    QString text=ui->display->text();
    text+=QString::fromStdString("+");
    ui->display->setText(text);
}

void MainWindow::on_minus_clicked()
{
    QString text=ui->display->text();
    text+=QString::fromStdString("-");
    ui->display->setText(text);
}

void MainWindow::on_multiply_clicked()
{
    QString text=ui->display->text();
    text+=QString::fromStdString("*");
    ui->display->setText(text);
}

void MainWindow::on_divide_clicked()
{
    QString text=ui->display->text();
    text+=QString::fromStdString("/");
    ui->display->setText(text);
}

void MainWindow::on_equal_clicked()
{
    infixTOposfix itp;
     QString text=ui->display->text();
     string t=text.toStdString();
    if( itp.valid(t))
     {
        stack<string> exp = iTp.infixToPostfix(text,itp);//class instance
        string rslt = iTp.calculate_Postfix(exp);
        QString result = QString::fromStdString(rslt);
   //convert int to qstring
        ui->display->setText(result);
     }

    else
    {
        ui->display->setText("invalid input");
    }
}

void MainWindow::on_left_clicked()
{
    QString text=ui->display->text();
    text+=QString::fromStdString("(");
    ui->display->setText(text);
}

void MainWindow::on_right_clicked()
{
    QString text=ui->display->text();
    text+=QString::fromStdString(")");
    ui->display->setText(text);
}

void MainWindow::on_power_clicked()
{
    QString text=ui->display->text();
    text+=QString::fromStdString("^");
    ui->display->setText(text);
}
