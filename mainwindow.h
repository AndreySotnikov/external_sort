#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "file.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private:
    Ui::MainWindow *ui;
    void configureUi();
    File* fl;
    int sz;
private slots:
    void process();
    void on_pbGenerate_clicked();
    void on_pbSort_clicked();
};

#endif // MAINWINDOW_H
