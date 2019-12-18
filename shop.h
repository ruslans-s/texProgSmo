#ifndef SHOP_H
#define SHOP_H
#include "block.h"

class Shop
{
private:
    int interval;
public:
    Shop();
    void addBlock(Block );
    Block deleteBlock();

};

#endif // SHOP_H
