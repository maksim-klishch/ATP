#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "CNF/cnf.h"
#include "CNF/resolution.h"

#include "Expression/Operators/and.h"
#include "Expression/Operators/or.h"
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
    b.setTerms(new Atom("A"), new Atom("B"));
    c.setTerms(new Atom("C"), new Atom("D"));
    a.setTerms(&b, &c);
    std::cout << a.toString() << std::endl;
}
