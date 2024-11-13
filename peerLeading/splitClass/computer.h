#ifndef COMPUTER_H
#define COMPUTER_H
#include "device.h"
#include <string>
using namespace std;

class Computer : public Device{
    public:
        Computer();
        Computer(string ownr, int y_old, string brnd, double proc_speed);

        virtual void display_info() override; //virtual means it can be overridden

        //override usage cost function for computers
        virtual double calculateUsageCost() const;

        protected:
            string brand;
            double processor_speed;
};

#endif