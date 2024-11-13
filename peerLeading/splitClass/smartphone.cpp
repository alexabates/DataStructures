#include "smartphone.h"
#include "device.h"
#include <iostream>

//default constructor for Smartphone
Smartphone:: Smartphone() : Device("", -1), brand(""), storage(-1){}
//constructor for smartphone
Smartphone:: Smartphone(string ownr, int y_old, string brnd, double storage) 
    : Device(ownr, y_old), brand(brnd), storage(storage){}

//print function for smartphone
void Smartphone:: display_info(){
    Device:: display_info();
    cout << "Brand: " << brand << endl;
    cout << "Storage: " << storage << " GB" << endl;
}

virtual double calculateUsageCost() const override{
            return Device::calculateUsageCost() + (storage * 20);
        }