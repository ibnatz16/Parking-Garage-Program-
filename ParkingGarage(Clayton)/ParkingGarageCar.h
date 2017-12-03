#ifndef PARKINGGARAGECAR_H_INCLUDED
#define PARKINGGARAGECAR_H_INCLUDED

#include <string>

using namespace std;

class Car{

        public:

        //Car Constructor
        Car();


        //Car Setters
        void set_color(string c);

        void set_make(string m);

        void set_model(string m);

        void set_lpNum(string lpN);

        void set_floorNum(int fn);

        void set_spaceNum(int sn);

        void set_timePeriod(int tp);

        void set_moneyOwed(double m);

        void set_isOccupied(bool o);

        void set_isVIP(bool v);

        void set_isTowed(bool t);


        //Car Getters
        string get_color();

        string get_make();

        string get_model();

        string get_lpNum();

        int get_floorNum();

        int get_spaceNum();

        int get_timePeriod();

        double get_moneyOwed();

        bool get_isOccupied();

        bool get_isVIP();

        bool get_isTowed();


        private:

        //Car variable declarations
        string color;

        string make;

        string model;

        string lpNum;

        int floorNum;

        int spaceNum;

        int timePeriod;

        double moneyOwed;

        bool isOccupied;

        bool isVIP;

        bool isTowed;

};


#endif // PARKINGGARAGECAR_H_INCLUDED
