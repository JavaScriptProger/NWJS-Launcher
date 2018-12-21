#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"
#include <QFileDialog>
#include <QChar>
//Std lib
#include <stdlib.h>

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

void MainWindow::on_select_clicked()
{
    //For selecting building configuration
    cnfPath = QFileDialog::getOpenFileName(this,tr("Configuration"), "",tr("Configuration (*.nwconfig);;All Files (*)"));

    QFile cnf(cnfPath);

    if (!cnf.open(QIODevice::ReadOnly | QIODevice::Text)) {
       qDebug() << "Error reading file";
       return;
    }

    QTextStream in(&cnf);
    int len = 0;
    int mode = 0;//0-nwjs 1-project

    while(!in.atEnd()) {
        QString line = in.readLine();
        if(mode == 0){
            len = line.length() - 5;
            nw = line.mid(5,len);
            mode = 1;
        } else {
            len = line.length() - 8;
            prj = line.mid(8,len);
        }
    }

    ui->nw->setText(nw);
    ui->path->setText(prj);

    //this->cmd = QString::fromUtf8(nw + " U+0022" + prj + "U+0022");
    QString s = QChar(0x22);
    this->cmd = nw + " " + s + prj + s;
    qDebug() << cmd;
}

void MainWindow::on_run_clicked()
{
    //For running project
    system(qPrintable(cmd));
}
