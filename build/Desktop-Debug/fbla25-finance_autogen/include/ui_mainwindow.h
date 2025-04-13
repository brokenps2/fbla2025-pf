/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionLoad;
    QAction *actionSave;
    QAction *actionExit;
    QAction *actionNew;
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *addRowButton;
    QTableWidget *tableWidget;
    QPushButton *calcButton;
    QSpacerItem *horizontalSpacer_2;
    QCheckBox *checkBox;
    QPushButton *rmRowButton;
    QLabel *endBalLabel;
    QLineEdit *curBalBox;
    QLabel *curBalLabel;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer;
    QLabel *label;
    QWidget *tab_2;
    QMenuBar *menubar;
    QMenu *menuFile;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1024, 600);
        actionLoad = new QAction(MainWindow);
        actionLoad->setObjectName("actionLoad");
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName("actionSave");
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName("actionExit");
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName("actionNew");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName("gridLayout_2");
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tab = new QWidget();
        tab->setObjectName("tab");
        gridLayout = new QGridLayout(tab);
        gridLayout->setObjectName("gridLayout");
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 0, 5, 1, 1);

        addRowButton = new QPushButton(tab);
        addRowButton->setObjectName("addRowButton");

        gridLayout->addWidget(addRowButton, 0, 1, 1, 1);

        tableWidget = new QTableWidget(tab);
        if (tableWidget->columnCount() < 4)
            tableWidget->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        if (tableWidget->rowCount() < 20)
            tableWidget->setRowCount(20);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setRowCount(20);
        tableWidget->setColumnCount(4);

        gridLayout->addWidget(tableWidget, 1, 0, 9, 7);

        calcButton = new QPushButton(tab);
        calcButton->setObjectName("calcButton");
        QFont font;
        font.setBold(true);
        calcButton->setFont(font);

        gridLayout->addWidget(calcButton, 2, 7, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 6, 1, 1);

        checkBox = new QCheckBox(tab);
        checkBox->setObjectName("checkBox");

        gridLayout->addWidget(checkBox, 0, 3, 1, 1);

        rmRowButton = new QPushButton(tab);
        rmRowButton->setObjectName("rmRowButton");

        gridLayout->addWidget(rmRowButton, 0, 2, 1, 1);

        endBalLabel = new QLabel(tab);
        endBalLabel->setObjectName("endBalLabel");
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Terminus")});
        font1.setPointSize(10);
        endBalLabel->setFont(font1);

        gridLayout->addWidget(endBalLabel, 6, 7, 1, 1);

        curBalBox = new QLineEdit(tab);
        curBalBox->setObjectName("curBalBox");
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Terminus")});
        font2.setPointSize(20);
        font2.setBold(true);
        curBalBox->setFont(font2);

        gridLayout->addWidget(curBalBox, 1, 7, 1, 1);

        curBalLabel = new QLabel(tab);
        curBalLabel->setObjectName("curBalLabel");
        curBalLabel->setFont(font1);

        gridLayout->addWidget(curBalLabel, 0, 7, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 4, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer, 3, 7, 1, 1);

        label = new QLabel(tab);
        label->setObjectName("label");
        label->setFont(font2);

        gridLayout->addWidget(label, 9, 7, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        tabWidget->addTab(tab_2, QString());

        gridLayout_2->addWidget(tabWidget, 0, 1, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1024, 22));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName("menuFile");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menuFile->addAction(actionNew);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionLoad);
        menuFile->addSeparator();
        menuFile->addSeparator();
        menuFile->addAction(actionExit);

        retranslateUi(MainWindow);
        QObject::connect(actionExit, &QAction::triggered, MainWindow, qOverload<>(&QMainWindow::close));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionLoad->setText(QCoreApplication::translate("MainWindow", "Load", nullptr));
#if QT_CONFIG(tooltip)
        actionLoad->setToolTip(QCoreApplication::translate("MainWindow", "Load...", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionLoad->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+L", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSave->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
#if QT_CONFIG(tooltip)
        actionSave->setToolTip(QCoreApplication::translate("MainWindow", "Save...", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionSave->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionExit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
#if QT_CONFIG(tooltip)
        actionExit->setToolTip(QCoreApplication::translate("MainWindow", "Exit Program...", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionExit->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+E", nullptr));
#endif // QT_CONFIG(shortcut)
        actionNew->setText(QCoreApplication::translate("MainWindow", "New", nullptr));
        addRowButton->setText(QCoreApplication::translate("MainWindow", "Add Row", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Amount", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Date", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "Type", nullptr));
        calcButton->setText(QCoreApplication::translate("MainWindow", "Calculate Balance", nullptr));
        checkBox->setText(QCoreApplication::translate("MainWindow", "Reccuring only", nullptr));
        rmRowButton->setText(QCoreApplication::translate("MainWindow", "Remove Row", nullptr));
        endBalLabel->setText(QCoreApplication::translate("MainWindow", "Remaining Balance ($)", nullptr));
        curBalBox->setText(QCoreApplication::translate("MainWindow", "0.00", nullptr));
        curBalLabel->setText(QCoreApplication::translate("MainWindow", "Monthly Income ($)", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "0.00", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "Budgeter", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "Insights", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
