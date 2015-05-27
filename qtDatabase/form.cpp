#include "form.h"
#include "ui_form.h"

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
    Connection();
}

Form::~Form()
{
    delete ui;
}
void Form::Connection(){
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/home/sahakornb/qt_project/qtDB/qtDatabase/DB/qtProject.db");
    if (!db.open()) {
        ui->label->setText("Cannot open database");
    }else
      ui->label->setText("Database Connected.");
}
