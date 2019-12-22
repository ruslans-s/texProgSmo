#ifndef COLLECTOR_H
#define COLLECTOR_H
#include "block.h"

class Collector
{
private:
    int timeWork; //Время обработки текушей заявки
    int timeWorkOneBlock; //Время работы с 1 заявкой
    bool busy;
    Block blockCPU; //Блок ЦПУ
    Block contorl;  //Блок контроля
    Block power;    //Блок с питанием
public:
    void setSetting(int newTimeWorkOneBlock);
    void addBlock(Block newBlockCPU,Block newContorl,Block newPower);
    bool getBusy();
    bool tic();
};

#endif // COLLECTOR_H
