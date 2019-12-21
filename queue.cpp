#include "queue.h"

Queue::Queue()
{

}
void Queue::addNewBlock(){
    blockVec.resize(blockVec.size()+1);
}
int Queue::getNumberBlock(){
    return blockVec.size();
}
Block Queue::getFirstBlock(){
    //Block tempBlock = blockVec[0];
    return blockVec[0];
}
void Queue::deleteFirst(){
    blockVec.pop_front();
}
