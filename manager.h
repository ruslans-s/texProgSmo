#ifndef MANAGER_H
#define MANAGER_H
#include "queue.h"
#include "block.h"
#include "QVector"
#include "shop.h"
#include "valve.h"
#include "statisticmanager.h"


class Manager
{
private:
    int timeToCreateBlock; // Время появления блока в цехах
    int timeWorkShop; // Время работы сборщика
    int timeWorkChecks; //Время проверки и исправления
    int timeWork; // Время моделирования
    QVector<QString> logTextVec; /*
    Массив с логами после разработки удалить
    */
    QVector<Queue> queueList;
    QVector<Valve> valveList;
    QVector<Shop> shopList;
public:
    Manager(int newTimeToCreateBlock,int newTimeWorkShop,int newTimeWorkChecks,int newTimeWork);
    void startModeling();
    QVector<QString> getLog(); /*
                                 ЛОГ
    */

};

#endif // MANAGER_H
