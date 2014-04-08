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
    ui->twCycle->clear();

    ui->twCompare->setHorizontalHeaderLabels(QStringList() << "File Size" << "Random File" << "Reverse File");
    ui->twRead->setHorizontalHeaderLabels(QStringList() << "File Size" << "Random File" << "Reverse File");
    ui->twTime->setHorizontalHeaderLabels(QStringList() << "File Size" << "Random File" << "Reverse File");
    ui->twCycle->setHorizontalHeaderLabels(QStringList() << "File Size" << "Random File" << "Reverse File");
}

void MainWindow::process() {
    const int SIZE = 8;
    const int sizes[SIZE] = {10, 100, 500, 1000, 10000, 50000, 100000, 1000000};
    configureUi();

    ui->twCompare->setRowCount(SIZE);
    ui->twRead->setRowCount(SIZE);
    ui->twTime->setRowCount(SIZE);
    ui->twCycle->setRowCount(SIZE);

//    ui->twCompare->setUpdatesEnabled(true);
//    ui->twRead->setUpdatesEnabled(true);
//    ui->twTime->setUpdatesEnabled(true);



    for (int i = 0;  i < SIZE - 1; i++) {

        ui->twCompare->setItem(i, 0, new QTableWidgetItem(QString::number(sizes[i])));
        ui->twRead->setItem(i, 0, new QTableWidgetItem(QString::number(sizes[i])));
        ui->twTime->setItem(i, 0, new QTableWidgetItem(QString::number(sizes[i])));
        ui->twCycle->setItem(i, 0, new QTableWidgetItem(QString::number(sizes[i])));
        qApp->processEvents();

        fl->generateRandom(sizes[i]);
        //fl->sort();

        ui->twCompare->setItem(i, 1, new QTableWidgetItem(QString::number(fl->getCompares())));
        ui->twRead->setItem(i, 1, new QTableWidgetItem(QString::number(fl->getReads())));
        ui->twTime->setItem(i, 1, new QTableWidgetItem(QString::number((fl->getTime()))));
        ui->twCycle->setItem(i, 1, new QTableWidgetItem(QString::number((fl->getCycleCount()))));
        qApp->processEvents();

        fl->generateReverse(sizes[i]);
        //fl->sort();
        ui->twCompare->setItem(i, 2, new QTableWidgetItem(QString::number(fl->getCompares())));
        ui->twRead->setItem(i, 2, new QTableWidgetItem(QString::number(fl->getReads())));
        ui->twTime->setItem(i, 2, new QTableWidgetItem(QString::number((fl->getTime()))));
        ui->twCycle->setItem(i, 2, new QTableWidgetItem(QString::number((fl->getCycleCount()))));
        qApp->processEvents();

    }


}

MainWindow::~MainWindow() {
    delete fl;
    delete ui;
}

void MainWindow::on_pbGenerate_clicked() {
    sz = ui->sbSize->value();
    ui->lwRandom->clear();
    ui->lwSorted->clear();
    fl->generateRandom(sz);
    //fl->generateReverse(sz);
    ifstream fin(fl->getFilename().c_str());
    int data;
    for (int i = 0; i < sz; i++) {
        fin >> data;
        ui->lwRandom->addItem(QString::number(data));
    }
    fin.close();

}

void MainWindow::on_pbSort_clicked() {
    ifstream fin(fl->getFilename().c_str());
    //fl->sort();
    fl->newSort();
    int data;
    for (int i = 0; i < sz; i++) {
        fin >> data;
        ui->lwSorted->addItem(QString::number(data));
    }
    fin.close();

}
