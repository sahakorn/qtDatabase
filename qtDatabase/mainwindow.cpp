#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Connection();
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::Connection(){
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/home/sahakornb/qt_project/qtDB/qtDatabase/DB/qtProject.db");
    if (!db.open()) {
        ui->label->setText("Cannot open database");
    }else
      ui->label->setText("Database Connected.");
}

void MainWindow::on_pushButton_clicked()
{
    QString username,password,Repass;
    username = ui->lineEdit->text();
    password = ui->lineEdit_2->text();
    Repass = ui->lineEdit_3->text();
    if(password != Repass)
    {
        ui->label->setText("Password don't same.");
    }
    else {
    QSqlQuery query;
    query.exec("INSERT INTO users (username,password) VALUES ('"+username+"', '"+password+"')");
    form.show();
    this->close();
    //    ui->label->setText("Success.");

//        while (query.next()) {
//                QString Type = query.value(0).toString();
//                QString name =  query.value(1).toString();
//                double weight =  query.value(2).toDouble();
//                qDebug() << Type<<name<<weight;
//            }

}
}
