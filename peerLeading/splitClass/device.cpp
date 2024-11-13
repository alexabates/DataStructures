
#include "device.h"
#include <iostream>

//default constructor definition
Device:: Device() : owner(""), years_old(-1){}
//constructor definition
Device:: Device(string ownr, int y_old) : owner(ownr), years_old(y_old){}

//print function for device
void Device:: display_info(){
    cout << "Owner: " << owner << endl;
    cout << "Years old: " << years_old << endl;
}

void Device::setOwner(string owner) {}

string Device::getOwner() const {return owner;}

double Device::calculateUsageCost() const{
    return years_old * 500;
}