#include <iostream>
#include <string>
#include "Computer.h"
#include "Smartphone.h"
using namespace std;


int main(){
    Device d1("Alice", 2);
    d1.display_info();
    cout << "Usage Cost: $" << d1.calculateUsageCost() << endl;
    cout << endl;

    Computer c1("Bob", 3, "Dell", 3.6);
    c1.display_info();
    cout << "Usage Cost: $" << c1.calculateUsageCost() << endl;
    cout << endl;

    Smartphone s1("Charlie", 1, "Apple", 128);
    s1.display_info();
    cout << "Usage Cost: $" << s1.calculateUsageCost() << endl;
    cout << endl;

    Device *d2 = new Device;
    d2->display_info();
    cout << endl;

    d2->setOwner("David");
    d2->display_info();
    cout << endl;

    Computer *c2 = new Computer;
    c2->display_info();
    cout << endl;

    c2->setOwner("Eva");
    c2->display_info();
    cout << endl;

    Smartphone *s2 = new Smartphone("Fiona", 2, "Samsung", 64);
    s2->display_info();
    cout << "Usage Cost: $" << s2->calculateUsageCost() << endl;

    return 0;
}