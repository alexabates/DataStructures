#ifndef SMARTPHONE_H
#define SMARTPHONE_H
#include "device.h"
#include <string>
using namespace std;

class Smartphone : public Device{
    public:
        Smartphone();
        Smartphone(string ownr, int y_old, string brnd, double storage);

        virtual void display_info() override;

        virtual double calculateUsageCost() const;

        protected:
            string brand;
            double storage;
};

#endif