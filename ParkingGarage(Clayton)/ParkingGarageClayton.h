#ifndef PARKINGGARAGECLAYTON_H_INCLUDED
#define PARKINGGARAGECLAYTON_H_INCLUDED


#include <string>

using namespace std;

class Car{
    private:
        //All car variable declarations
        string color;
        string make;
        string model;
        string lpNum;
        int floorNum;
        int spaceNum;
        int timePeriod;
        int moneyOwed;
        bool isVIP;

        //declarations of setter methods for car variables
        void set_color(string c);
        void set_make(string m);
        void set_model(string m);
        void set_lpNum(string lpN);
        void set_floorNum(int fn);
        void set_spaceNum(int sn);
        void set_timePeriod(int tp);
        void set_moneyOwed(int m);
        void set_isVIP(bool v);

        //declarations of getter methods for car variables
        string get_color();
        string get_make();
        string get_model();
        string get_lpNum();
        int get_floorNum();
        int get_spaceNum();
        int get_timePeriod();
        int get_moneyOwed();
        bool get_isVIP();

};



//Setters
void Car::set_color(string c)
{
    color = c;
}

void Car::set_make(string m)
{
    make = m;
}

void Car::set_model(string m)
{
    model = m;
}

void Car::set_lpNum(string lp)
{
    lpNum = lp;
}

void Car::set_floorNum(int fn)
{
    floorNum = fn;
}

void Car::set_spaceNum(int sn)
{
    spaceNum = sn;
}

void Car::set_timePeriod(int tp)
{
    timePeriod = tp;
}

void Car::moneyOwed(int m)
{
    moneyOwed = m;
}

void Car::set_isVIP(bool v)
{
    isVIP = v;
}


//Getters
string Car::get_color()
{
    return color;
}

string Car::get_make()
{
    return make;
}

string Car::get_model()
{
    return model;
}

string Car::get_lpNum()
{
    return lpNum;
}

int Car::get_floorNum()
{
    return floorNum;
}

int Car::get_spaceNum()
{
    return spaceNum;
}

int Car::get_timePeriod()
{
    return timePeriod;
}

int Car::get_moneyOwed()
{
    return moneyOwed;
}

bool Car::get_isVIP()
{
    return isVIP;
}


#endif // PARKINGGARAGECLAYTON_H_INCLUDED
