#include "manager.h"

Manager::Manager(int newTimeToCreateBlock,int newTimeWorkShop,int newTimeWorkChecks,int newTimeWork)
{
    timeToCreateBlock=newTimeToCreateBlock;
    timeWorkShop=newTimeWorkShop;
    timeWorkChecks=newTimeWorkChecks;
    timeWork=newTimeWork;
    valveList.resize(4);
    queueList.resize(4);
    shopList.resize(3);
}
void Manager::startModeling(){
    Validating.setTime(timeWorkChecks); //Передача времени работы в цех проверки
    shopList[0].getSetting(timeToCreateBlock); //Установка врмени между появлениеми заявок
    shopList[1].getSetting(timeToCreateBlock);
    shopList[2].getSetting(timeToCreateBlock);

    Collector.setSetting(timeWorkShop); //Устанвока времени сборки ЭВМ
    QVector<int> tactInfo{0,0,0,0,0,0};
    bool tempBool=false,tempBool2=false;
    //Начало моделирования
    for(int i=1;i<=timeWork;i++){
    if(tempBool==true){ //Если цех сборки закончил сборку то собранная эвм передается в очередь в цех проверки
        queueList[3].addNewBlock();
        tactInfo[4]++;
    }
    if(tempBool2==true){ //Если цех проверки закончил проверку то собранная эвм передается в менеджер статистики
        StatisticManager.getNewBlock();
        tactInfo[5]++;
    }
    for(int j=0;j<shopList.size();j++){ //Проверка цехов на поступление новых блоков
        if (shopList[j].tic()==true){
           queueList[j].addNewBlock();
        }
    }
    if(Collector.getBusy()==false){ //Если сборшик свободен то клапаны открываются
        valveList[0].open();
        valveList[1].open();
        valveList[2].open();
    } else {
        valveList[0].close();
        valveList[1].close();
        valveList[2].close();
    }
    //Если все клапанны открыты и в каждой очереди есть по 1 блоку то они передаются в сборщик эвм
    if(valveList[0].chekopened()==true && valveList[1].chekopened()==true && valveList[2].chekopened()==true && queueList[0].getNumberBlock()!=0 && queueList[1].getNumberBlock()!=0 && queueList[2].getNumberBlock()!=0){
        Collector.addBlock(queueList[0].getFirstBlock(),queueList[1].getFirstBlock(),queueList[2].getFirstBlock());
        queueList[0].deleteFirst();
        queueList[1].deleteFirst();
        queueList[2].deleteFirst();
    }
    //Если цех проверки свободен и в очереди есть хотябы 1 эвм то цех приступает к проверке
    if(valveList[3].chekopened()==true && queueList[3].getNumberBlock()!=0){
        Validating.addBlock(queueList[3].getFirstBlock());
    }

    if(Validating.getBusy()==false){
        valveList[3].open();
    } else {
        valveList[3].close();
    }

    tempBool=Collector.tic();
    tempBool2=Validating.tic();
    tactInfo[0]=queueList[0].getNumberBlock();
    tactInfo[1]=queueList[1].getNumberBlock();
    tactInfo[2]=queueList[2].getNumberBlock();
    tactInfo[3]=queueList[3].getNumberBlock();
    StatisticManager.tic(tactInfo); //Передача в менеджер статистики информаций о текушем такте
    }

}
QVector<QVector<int>> Manager::getInfoModelling(){
    return StatisticManager.getInfoModelling();
}
