#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QScreen>
#include <QFile>
#include <QFileDialog>

void MainWindow::saveTableToCSV(const QString& filePath) {
    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qWarning("Couldn't open file for writing.");
        return;
    }

    QTextStream out(&file);

    // Write the balance as the first line
    QString balance = ui->curBalBox->text();
    out << "Balance," << balance << "\n";

    // Write the table data
    int rows = ui->tableWidget->rowCount();
    int cols = ui->tableWidget->columnCount();

    for (int row = 0; row < rows; ++row) {
        QStringList rowContents;
        for (int col = 0; col < cols; ++col) {
            QTableWidgetItem* item = ui->tableWidget->item(row, col);
            rowContents << (item ? item->text() : "");
        }
        out << rowContents.join(",") << "\n";
    }

    file.close();
}

void MainWindow::loadTableFromCSV(const QString& filePath) {
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning("Couldn't open file for reading.");
        return;
    }

    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(0);

    QTextStream in(&file);
    int row = 0;

    // First line: read the balance
    if (!in.atEnd()) {
        QString balanceLine = in.readLine();
        QStringList parts = balanceLine.split(',');
        if (parts.size() >= 2 && parts[0].trimmed().toLower() == "balance") {
            ui->curBalBox->setText(parts[1].trimmed());
        }
    }

    // Rest: table contents
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split(',');

        ui->tableWidget->insertRow(row);
        for (int col = 0; col < fields.size(); ++col) {
            QTableWidgetItem* item = new QTableWidgetItem(fields[col]);
            ui->tableWidget->setItem(row, col, item);
        }
        row++;
    }

    file.close();
}

void MainWindow::loadTableFromBlankCSV() {
    QFile file("blank.csv");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning("Couldn't open file for reading.");
        return;
    }

    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(0);

    QTextStream in(&file);
    int row = 0;

    // First line: read the balance
    if (!in.atEnd()) {
        QString balanceLine = in.readLine();
        QStringList parts = balanceLine.split(',');
        if (parts.size() >= 2 && parts[0].trimmed().toLower() == "balance") {
            ui->curBalBox->setText(parts[1].trimmed());
        }
    }

    // Rest: table contents
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split(',');

        ui->tableWidget->insertRow(row);
        for (int col = 0; col < fields.size(); ++col) {
            QTableWidgetItem* item = new QTableWidgetItem(fields[col]);
            ui->tableWidget->setItem(row, col, item);
        }
        row++;
    }

    file.close();
}

void MainWindow::saveTableWithDialog() {
    QString filePath = QFileDialog::getSaveFileName(this, "Save File", "", "CSV Files (*.csv);;All Files (*)");
    if (!filePath.isEmpty()) {
        saveTableToCSV(filePath);  // Call the save function we created earlier
    }
}

void MainWindow::loadTableWithDialog() {
    QString filePath = QFileDialog::getOpenFileName(this, "Open File", "", "CSV Files (*.csv);;All Files (*)");
    if (!filePath.isEmpty()) {
        loadTableFromCSV(filePath);  // Call the load function we created earlier
    }
}


void MainWindow::setFinalBalance() {
    double sum = 0.0;
    int column = 1;  // third column (index starts from 0)
    int rowCount = ui->tableWidget->rowCount();

    for (int row = 0; row < rowCount; ++row) {
        QTableWidgetItem* item = ui->tableWidget->item(row, column);

        if(!ui->checkBox->isChecked()) {
            if(item) {
                bool ok;
                double value = item->text().toDouble(&ok);
                if (ok) {
                    sum += value;
                }
            }
        } else {
            if(item) {
                if(ui->tableWidget->item(row, 3)->text() == "R") {
                    bool ok;
                    double value = item->text().toDouble(&ok);
                    if (ok) {
                        sum += value;
                    }
                }
            }
        }
    }

    double subtr = ui->curBalBox->text().toDouble() - sum;

    ui->label->setText(QString::number(subtr, 'f', 2));;
}

void MainWindow::addRowToBudgetTable() {
    int rowCount = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(rowCount);  // Adds a row at the bottom

    // Optionally, initialize some cells
    for (int col = 0; col < ui->tableWidget->columnCount(); ++col) {
        ui->tableWidget->setItem(rowCount, col, new QTableWidgetItem(""));
    }
}


void MainWindow::delRowFromBudgetTable() {
    int rowCount = ui->tableWidget->rowCount();
    ui->tableWidget->removeRow(rowCount - 1);  // Adds a row at the bottom
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect screenGeometry = screen->availableGeometry();

    int x = 600;
    int y = screenGeometry.y() + (screenGeometry.height() - this->height()) / 2;

    this->move(x, y);

    connect(ui->calcButton, &QPushButton::clicked, this, &MainWindow::setFinalBalance);
    connect(ui->addRowButton, &QPushButton::clicked, this, &MainWindow::addRowToBudgetTable);
    connect(ui->rmRowButton, &QPushButton::clicked, this, &MainWindow::delRowFromBudgetTable);
    connect(ui->actionLoad, &QAction::triggered, this, &MainWindow::loadTableWithDialog);
    connect(ui->actionSave, &QAction::triggered, this, &MainWindow::saveTableWithDialog);
    connect(ui->actionNew, &QAction::triggered, this, &MainWindow::loadTableFromBlankCSV);
}

MainWindow::~MainWindow()
{
    delete ui;
}
