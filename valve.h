#ifndef VALVE_H
#define VALVE_H


class Valve
{
private:
    bool opened;
   public:
    Valve();
    bool chekopened();
    void open() ;
    void close();
};

#endif // VALVE_H
