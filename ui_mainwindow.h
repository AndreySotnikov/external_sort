/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionProcess;
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tab_2;
    QTableWidget *twTime;
    QWidget *tab;
    QTableWidget *twCompare;
    QWidget *tab_3;
    QTableWidget *twRead;
    QWidget *tab_4;
    QTableWidget *twCycle;
    QWidget *tab_5;
    QListWidget *lwRandom;
    QListWidget *lwSorted;
    QSpinBox *sbSize;
    QPushButton *pbGenerate;
    QPushButton *pbSort;
    QMenuBar *menuBar;
    QMenu *menuAction;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(458, 376);
        actionProcess = new QAction(MainWindow);
        actionProcess->setObjectName(QStringLiteral("actionProcess"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setEnabled(true);
        tabWidget->setGeometry(QRect(20, 20, 421, 281));
        tabWidget->setTabPosition(QTabWidget::North);
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabWidget->setElideMode(Qt::ElideNone);
        tabWidget->setUsesScrollButtons(true);
        tabWidget->setDocumentMode(true);
        tabWidget->setMovable(false);
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        twTime = new QTableWidget(tab_2);
        if (twTime->columnCount() < 3)
            twTime->setColumnCount(3);
        twTime->setObjectName(QStringLiteral("twTime"));
        twTime->setGeometry(QRect(5, 1, 481, 251));
        twTime->setColumnCount(3);
        twTime->verticalHeader()->setVisible(false);
        tabWidget->addTab(tab_2, QString());
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        twCompare = new QTableWidget(tab);
        if (twCompare->columnCount() < 3)
            twCompare->setColumnCount(3);
        twCompare->setObjectName(QStringLiteral("twCompare"));
        twCompare->setGeometry(QRect(5, 1, 481, 251));
        twCompare->setColumnCount(3);
        twCompare->verticalHeader()->setVisible(false);
        tabWidget->addTab(tab, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        twRead = new QTableWidget(tab_3);
        if (twRead->columnCount() < 3)
            twRead->setColumnCount(3);
        twRead->setObjectName(QStringLiteral("twRead"));
        twRead->setGeometry(QRect(5, 1, 481, 251));
        twRead->setColumnCount(3);
        twRead->verticalHeader()->setVisible(false);
        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        twCycle = new QTableWidget(tab_4);
        if (twCycle->columnCount() < 3)
            twCycle->setColumnCount(3);
        twCycle->setObjectName(QStringLiteral("twCycle"));
        twCycle->setGeometry(QRect(5, 1, 411, 251));
        twCycle->setColumnCount(3);
        twCycle->verticalHeader()->setVisible(false);
        tabWidget->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        lwRandom = new QListWidget(tab_5);
        lwRandom->setObjectName(QStringLiteral("lwRandom"));
        lwRandom->setGeometry(QRect(20, 10, 71, 231));
        lwSorted = new QListWidget(tab_5);
        lwSorted->setObjectName(QStringLiteral("lwSorted"));
        lwSorted->setGeometry(QRect(110, 10, 71, 231));
        sbSize = new QSpinBox(tab_5);
        sbSize->setObjectName(QStringLiteral("sbSize"));
        sbSize->setGeometry(QRect(220, 40, 61, 27));
        sbSize->setMinimum(1);
        sbSize->setMaximum(9999);
        pbGenerate = new QPushButton(tab_5);
        pbGenerate->setObjectName(QStringLiteral("pbGenerate"));
        pbGenerate->setGeometry(QRect(190, 80, 141, 27));
        pbSort = new QPushButton(tab_5);
        pbSort->setObjectName(QStringLiteral("pbSort"));
        pbSort->setGeometry(QRect(198, 120, 131, 27));
        tabWidget->addTab(tab_5, QString());
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 458, 20));
        menuAction = new QMenu(menuBar);
        menuAction->setObjectName(QStringLiteral("menuAction"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuAction->menuAction());
        menuAction->addAction(actionProcess);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionProcess->setText(QApplication::translate("MainWindow", "Process", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Time", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Compare Count", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "Read Count", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("MainWindow", "Cycle Count", 0));
        pbGenerate->setText(QApplication::translate("MainWindow", "Generate", 0));
        pbSort->setText(QApplication::translate("MainWindow", "Sort", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QApplication::translate("MainWindow", "Page", 0));
        menuAction->setTitle(QApplication::translate("MainWindow", "Action", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
