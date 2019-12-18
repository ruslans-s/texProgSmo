#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    Manager Managers (ui->spinBox->text().toInt(),ui->spinBox_2->text().toInt(),ui->spinBox_3->text().toInt(),ui->spinBox_4->text().toInt());
    Managers.startModeling();
    QVector<QString> logs = Managers.getLog();
    for(int i=0;i<logs.size();i++){
        ui->listWidget->addItem(logs[i]);
    }
}
