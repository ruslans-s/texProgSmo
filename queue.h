#ifndef QUEUE_H
#define QUEUE_H
#include "block.h"
#include "QVector"
class Queue
{
private:
    QVector<Block> blockVec;
public:
    Queue();
    int getNumberBlock();
    Block getFirstBlock();
    void addNewBlock();
    void deleteFirst();
};

#endif // QUEUE_H
