#ifndef SHOP_H
#define SHOP_H
#include "block.h"

class Shop
{
private:
    int interval; //Интервал поступления заявки
    int elapsedTime; // Времени прошло с поступления прошлой заявки
public:
    void getSetting(int newInterval);
    bool tic();
};

#endif // SHOP_H
