#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    fl = new File();
    configureUi();
    connect(ui->actionProcess, SIGNAL(triggered()), this, SLOT(process()));
}

void MainWindow::configureUi() {
    ui->twCompare->clear();
    ui->twRead->clear();
    ui->twTime->clear();

    ui->twCompare->setHorizontalHeaderLabels(QStringList() << "File Size" << "Random File" << "Reverse File");
    ui->twRead->setHorizontalHeaderLabels(QStringList() << "File Size" << "Random File" << "Reverse File");
    ui->twTime->setHorizontalHeaderLabels(QStringList() << "File Size" << "Random File" << "Reverse File");
}

void MainWindow::process() {
    const int SIZE = 7;
    const int sizes[SIZE] = {10, 100, 500, 1000, 10000, 50000, 100000};
    configureUi();

    ui->twCompare->setRowCount(SIZE);
    ui->twRead->setRowCount(SIZE);
    ui->twTime->setRowCount(SIZE);

//    ui->twCompare->setUpdatesEnabled(true);
//    ui->twRead->setUpdatesEnabled(true);
//    ui->twTime->setUpdatesEnabled(true);



    for (int i = 0;  i < SIZE; i++) {

        ui->twCompare->setItem(i, 0, new QTableWidgetItem(QString::number(sizes[i])));
        ui->twRead->setItem(i, 0, new QTableWidgetItem(QString::number(sizes[i])));
        ui->twTime->setItem(i, 0, new QTableWidgetItem(QString::number(sizes[i])));
        qApp->processEvents();

        fl->generateRandom(sizes[i]);
        fl->sort();

        ui->twCompare->setItem(i, 1, new QTableWidgetItem(QString::number(fl->getCompares())));
        ui->twRead->setItem(i, 1, new QTableWidgetItem(QString::number(fl->getReads())));
        ui->twTime->setItem(i, 1, new QTableWidgetItem(QString::number((fl->getTime()))));
        qApp->processEvents();

        fl->generateReverse(sizes[i]);
        fl->sort();
        ui->twCompare->setItem(i, 2, new QTableWidgetItem(QString::number(fl->getCompares())));
        ui->twRead->setItem(i, 2, new QTableWidgetItem(QString::number(fl->getReads())));
        ui->twTime->setItem(i, 2, new QTableWidgetItem(QString::number((fl->getTime()))));
        qApp->processEvents();

    }


}

MainWindow::~MainWindow() {
    delete fl;
    delete ui;
}
