#include "collector.h"

void Collector::setSetting(int newTimeWorkOneBlock)
{
    timeWork=0;
    timeWorkOneBlock=newTimeWorkOneBlock;
    busy=false;
}

void Collector::addBlock(Block newBlockCPU,Block newContorl,Block newPower){
    blockCPU=newBlockCPU;
    contorl=newContorl;
    power=newPower;
    busy=true;
}
bool Collector::getBusy(){
    return busy;
}
bool Collector::tic(){
    if(busy==true){
        timeWork++;
        if(timeWork==timeWorkOneBlock){
            timeWork=0;
            busy=false;
            return true;
        } else return false;
    } else return false;
}
