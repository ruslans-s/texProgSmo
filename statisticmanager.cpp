#include "statisticmanager.h"

StatisticManager::StatisticManager()
{
    numberTact=0;
}
void StatisticManager::getNewBlock(){
    blockModelInfo.resize(blockModelInfo.size()+1);

}
void StatisticManager::tic(QVector<int> info){
    infoModelling.resize(infoModelling.size()+1);
    infoModelling[infoModelling.size()-1].resize(info.size());
    for(int i=0;i<info.size();i++){
        infoModelling[infoModelling.size()-1][i]=info[i];
    }
}
QVector<QVector<int>> StatisticManager::getInfoModelling(){
    return  infoModelling;
}
