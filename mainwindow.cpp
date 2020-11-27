#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "Interpreter/interpreter.h"

#include <QFileDialog>
#include <QTextStream>

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

void MainWindow::on_btnRun_clicked()
{
    Interpreter interpreter;
    std::string commands = ui->scriptEdit->document()->toPlainText().toStdString();
    ui->resultEdit->setText(QString(interpreter.interprete(commands).c_str()));
}

void MainWindow::on_btnSave_clicked()
{
    QFile file(QFileDialog::getSaveFileName(this, "Save script", "", "*.atp; *.txt"));

    if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;

    QTextStream stream(&file);
    stream << ui->scriptEdit->document()->toPlainText();

    file.close();
}

void MainWindow::on_btnLoad_clicked()
{
    QFile file(QFileDialog::getOpenFileName(this, "Load script", "", "*.atp; *.txt"));

    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QTextStream stream(&file);
    ui->scriptEdit->setText(stream.readAll());

    file.close();
}
