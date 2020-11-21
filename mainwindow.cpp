#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "CNF/cnf.h"
#include "CNF/resolution.h"

#include "Expression/Operators/and.h"
#include "Expression/Operators/or.h"
#include "Expression/Operators/not.h"
#include "Expression/variable.h"

#include "Expression/variablesregister.h"
#include "Expression/atom.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    AND a;
    OR b, c;
    NOT n;
    b.setTerms(new Atom("A"), new Atom("B"));
    n.setTerm(&b);
    c.setTerms(new Atom("C"), new Atom("D"));
    a.setTerms(&c, &n);
    ui->textEdit->setText(QString(a.toString().c_str()));
}
