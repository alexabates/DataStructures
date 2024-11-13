#include "computer.h"
#include "device.h"
#include <iostream>


//default constructor for computer
Computer:: Computer() : Device("", -11), brand(""), processor_speed(-1) {}
//constructor for computer
Computer:: Computer(string ownr, int y_old, string brnd, double proc_speed) 
    : Device(owner, y_old), brand(brnd), processor_speed(proc_speed){}

//print function for computer
void Computer:: display_info(){
    Device:: display_info();
    cout << "Brand: " << brand << endl;
    cout << "Processor speed: " << processor_speed << endl;
}

virtual double calculateUsageCost() const override{
            return Device::calculateUsageCost() + processor_speed * 100;
        }
