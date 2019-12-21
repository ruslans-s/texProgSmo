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
   // collectorList.resize(2);

}
void Manager::startModeling(){

    Validating Validating(timeWorkChecks);
    shopList[0].getSetting(7);
    shopList[1].getSetting(7);
    shopList[2].getSetting(7);
    Collector.setSetting(timeWorkShop);
    QVector<int> tactInfo{0,0,0,0,0,0};
    bool tempBool=false,tempBool2=false;
    for(int i=1;i<=timeWork;i++){

    if(tempBool==true){
        queueList[3].addNewBlock();
        tactInfo[4]++;
    }

    if(tempBool2==true){
        StatisticManager.getNewBlock();
        tactInfo[5]++;
    }
    for(int j=0;j<shopList.size();j++){
        if (shopList[j].tic()==true){
           queueList[j].addNewBlock();
        }
    }
    if(Collector.getBusy()==false){
        valveList[0].open();
        valveList[1].open();
        valveList[2].open();
    } else {
        valveList[0].close();
        valveList[1].close();
        valveList[2].close();
    }
    if(valveList[0].chekopened()==true && valveList[1].chekopened()==true && valveList[2].chekopened()==true && queueList[0].getNumberBlock()!=0 && queueList[1].getNumberBlock()!=0 && queueList[2].getNumberBlock()!=0){
        Collector.addBlock(queueList[0].getFirstBlock(),queueList[1].getFirstBlock(),queueList[2].getFirstBlock());
        queueList[0].deleteFirst();
        queueList[1].deleteFirst();
        queueList[2].deleteFirst();
    }
    if(valveList[3].chekopened()==true && queueList[3].getNumberBlock()!=0){
        Validating.addBlock(queueList[3].getFirstBlock());
    }
   // valveList[3].
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
    StatisticManager.tic(tactInfo);
    }

}
QVector<QVector<int>> Manager::getInfoModelling(){
    return StatisticManager.getInfoModelling();
}
