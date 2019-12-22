#ifndef STATISTICMANAGER_H
#define STATISTICMANAGER_H
#include <QVector>
#include <QString>
#include "block.h"
class StatisticManager
{
private:

    QVector<Block> blockModelInfo; //Информация о собранных и проверенных ЭВМ
    QVector<QVector<int>> infoModelling; //Информация о моделирований
    int numberTact;
public:
    StatisticManager();
    void getNewBlock();
    void tic(QVector<int> info);
    QVector<QVector<int>> getInfoModelling();
};

#endif // STATISTICMANAGER_H
