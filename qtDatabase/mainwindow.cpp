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
    QString username,password;
    username = ui->lineEdit->text();
    password = ui->lineEdit_2->text();

    QSqlQuery query;
    if(query.exec("select * from Data where Type = '"+username+"' and name = '"+password+"'"))
    {
        ui->label->setText("Correct.");

    }else{
         ui->label->setText("inCorrect.");
    }
}
