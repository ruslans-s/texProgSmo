#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QStandardItem"

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
    //ui->listWidget->clear();
    Manager Managers (ui->spinBox->text().toInt(),ui->spinBox_2->text().toInt(),ui->spinBox_3->text().toInt(),ui->spinBox_4->text().toInt()*60);
    Managers.startModeling();

    QVector<QVector<int>> infoModelling=Managers.getInfoModelling();
    QStandardItemModel *model = new QStandardItemModel;
    QStandardItem *item;
    QModelIndex index;
    model = new QStandardItemModel(infoModelling.size(),6,this);
    ui->tableView->setModel(model);
        model->setHeaderData(0,Qt::Horizontal,"Кол-во Блоков в 1 очереди");
        model->setHeaderData(1,Qt::Horizontal,"Кол-во Блоков в 2 очереди");
        model->setHeaderData(2,Qt::Horizontal,"Кол-во Блоков в 3 очереди");
        model->setHeaderData(3,Qt::Horizontal,"Кол-во МикроЭВМ в очереди");
        model->setHeaderData(4,Qt::Horizontal,"Собранно МикроЭВМ");
        model->setHeaderData(5,Qt::Horizontal,"Проверенно МикроЭВМ");

    for(int row=0;row<model->rowCount();row++){
         for(int col=0;col<model->columnCount();col++) {
           index=model->index(row,col);
           model->setData(index, QString::number(infoModelling[row][col]));
        }
    }
    double tempInt1=0,tempInt2=0,tempInt3=0,tempInt4=0,tempInt5=0,tempInt6=ui->spinBox_4->text().toDouble(),tempInt7=0;
    for(int i=0;i<infoModelling.size()-1;i=i+60){
        tempInt1+=infoModelling[i][0];
        tempInt2+=infoModelling[i][1];
        tempInt3+=infoModelling[i][2];
        tempInt5+=infoModelling[i][3];
    }
    tempInt4=infoModelling[infoModelling.size()-1][3];
    tempInt7=infoModelling[infoModelling.size()-1][4];
    ui->lineEdit->setText(QString::number(tempInt1/tempInt6));
    ui->lineEdit_2->setText(QString::number(tempInt2/tempInt6));
    ui->lineEdit_3->setText(QString::number(tempInt3/tempInt6));
    ui->lineEdit_4->setText(QString::number(tempInt5/tempInt6));
    ui->lineEdit_5->setText(QString::number((tempInt4*ui->spinBox_2->text().toDouble())/(tempInt6*60)));
    ui->lineEdit_6->setText(QString::number((tempInt7*ui->spinBox_2->text().toDouble())/(tempInt6*60)));

}
