#ifndef DEVICE.H
#define DEVICE.H
#include <string>
using namespace std;

class Device{
    public:
        Device(); //default constructor
        Device(string ownr, int y_old); //constructor
        virtual void display_info(); //virtual means it can be overridden

        //setter function for owner
        void setOwner(string owner);

        //getter function for owner
        string getOwner() const;

        //virtual function to calculate usage cost
        virtual double calculateUsageCost() const;

        protected:
            string owner;
            int years_old;
};

#endif