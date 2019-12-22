#include "validating.h"

void Validating::setTime(int newTimeWorkOneBlock)
{
    timeWorkOneBlock=newTimeWorkOneBlock;
    timeWork=0;
    busy=false;
}
void Validating::addBlock(Block newMicroEVM){
    microEVM=newMicroEVM;
    busy=true;
}
bool Validating::getBusy(){
    return busy;
}
bool Validating::tic(){
    if(busy==true){
        timeWork++;
        if(timeWork==timeWorkOneBlock){
            timeWork=0;
             busy=false;
            return true;
        } else return false;
    } else return false;
}
