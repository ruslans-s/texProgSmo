#include "shop.h"

void Shop::getSetting(int newInterval)
{
    interval=newInterval;
   // numberCycles=0;
    elapsedTime=0;
}
bool Shop::tic(){
    //numberCycles++;
    elapsedTime++;
    if(elapsedTime==interval){
        elapsedTime=0;
        return true;
    } else return false;
}
