#ifndef MANAGER_H
#define MANAGER_H
#include "queue.h"
#include "block.h"
#include "QVector"
#include "shop.h"
#include "valve.h"
#include "statisticmanager.h"
#include "collector.h"
#include "validating.h"
class Manager
{
private:
    int timeToCreateBlock; // Время появления блока в цехах
    int timeWorkShop; // Время работы сборщика
    int timeWorkChecks; //Время проверки и исправления
    int timeWork; // Время моделирования
    QVector<Queue> queueList;
    QVector<Valve> valveList;
    QVector<Shop> shopList;
    Collector Collector;
   StatisticManager StatisticManager;
public:
    Manager(int newTimeToCreateBlock,int newTimeWorkShop,int newTimeWorkChecks,int newTimeWork);
    void startModeling();
    QVector<QVector<int>> getInfoModelling();
};

#endif // MANAGER_H
