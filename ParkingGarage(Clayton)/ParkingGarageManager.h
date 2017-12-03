#ifndef PARKINGGARAGEMANAGER_H_INCLUDED
#define PARKINGGARAGEMANAGER_H_INCLUDED

#include <string>

using namespace std;

class Manager{

    public:

        //manager constructor
        Manager(string user);


        // Manager Setters
        void set_username (string user);

        void set_password (string pass);


        //Manager Getters
        string get_password ();

        string get_username ();


    private:

        //Manager variables
        string username;

        string password;

};


#endif // PARKINGGARAGEMANAGER_H_INCLUDED
