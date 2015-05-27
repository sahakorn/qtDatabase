#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include <QtSql/QSql>
#include <QMainWindow>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>


namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = 0);
    ~Form();
     void Connection();

private:
    Ui::Form *ui;
};

#endif // FORM_H
