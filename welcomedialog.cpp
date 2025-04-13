#include "welcomedialog.h"
#include "ui_welcomedialog.h"
#include "mainwindow.h"
#include <QScreen>
#include <QPushButton>

WelcomeDialog::WelcomeDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::WelcomeDialog)
{
    MainWindow w;
    ui->setupUi(this);
}

WelcomeDialog::~WelcomeDialog()
{
    delete ui;
}
