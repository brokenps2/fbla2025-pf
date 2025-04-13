#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void setFinalBalance();
    void addRowToBudgetTable();
    void delRowFromBudgetTable();
    void saveTableToCSV(const QString& filePath);
    void loadTableFromCSV(const QString& filePath);
    void loadTableFromBlankCSV();
    void saveTableWithDialog();
    void loadTableWithDialog();
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
