#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "CNF/cnf.h"
#include "CNF/resolution.h"

#include "Expression/Operators/and.h"
#include "Expression/Operators/or.h"
#include "Expression/variable.h"

#include "Expression/variablesregister.h"
#include "Expression/const.h"

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
    CNF a, b, c, d;
    a.addVariable("A", 0);
    a.addVariable("B", 0);
    a.addVariable("C", 0);

    b.addVariable("A", 1);
    b.addVariable("B", 0);
    b.addVariable("C", 0);

    c.addVariable("C", 1);

    d.addVariable("B", 0);

    //CNF f = CNF::split(a, b);
    //f = CNF::split(f, c);
    //f.print();

    Resolution resolution;
    resolution.addCNF(a);
    resolution.addCNF(b);
    resolution.addCNF(c);
    resolution.addCNF(d);

    std::cout << resolution.proof() << std::endl;

    ui->textEdit->setText(QString("%1").arg(1));

    VariablesRegister reg;
    reg.addVariable(new Const("A"));
}
