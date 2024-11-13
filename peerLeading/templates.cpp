// templates
// you don't have to declare the type of variable, so the function template can be used for multiple data types

#include <iostream>
#include <string>
using namespace std;

// void swap(int &a, int &b){
//     int temp = a;
//     a = b;
//     b = temp;
// }

// void swap(char &a, char &b){
//     char temp = a;
//     a = b;
//     b = temp;
// }

template <typename T>
void Swap(T &a, T &b){
    T temp = a;
    a = b;
    b = temp;
}


int main(){

    int o = 1, p = 2;
    cout << o << " " << p << endl;
    swap(o, p);
    cout << o << " " << p << endl;

    char a = 'a', b = 'b';
    cout << a << " " << b << endl;
    Swap(a,b);
    cout << a << " " << b << endl;

    int x = 1, y = 7;
    cout << x << ' ' << y << endl;
    Swap(x, y);
    cout << x << ' ' << y << endl;


    return 0;
}