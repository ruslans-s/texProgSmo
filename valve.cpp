#include "valve.h"

Valve::Valve()
{

}
bool Valve::chekopened(){
    return opened;
}
void Valve::open(){
    opened=true;
}
void Valve::close(){
    opened=false;
}
