#ifndef VALIDATING_H
#define VALIDATING_H
#include "block.h"

class Validating
{
private:
    //Block Blocks;
    int timeWork; //Время обработки текушей заявки
    int timeWorkOneBlock; //Время работы с 1 заявкой
    bool busy;
    Block microEVM; //Готовая микроЭВМ

public:
    Validating(int newTimeWorkOneBlock);
    void addBlock(Block newMicroEVM);
    bool getBusy();
    bool tic();

};

#endif // VALIDATING_H
