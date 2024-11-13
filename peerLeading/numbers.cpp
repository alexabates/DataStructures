// 3 main ways to protect data
// public, private, protected

#include <iostream>
#include <string>
using namespace std;

// class Numbers{

//     protected:
//         /// cannot be accessed publicly, but can be accessed from a subclass
//         int v43;

//     public:
//         int getV1(){
//             return v1;
//         }
//         void setV1(int v1){
//             this->v1 = v1;
//             // this: when you are trying to access something within its own class
//         }
// /* same function as above, without using "this" keyword
//     void setV1(int vec1){
//         v1 = vec1
//         }
//     we only used "this" because there were two "v1"s being used and we had to specify
// */

//     private:
//         int v1;
//         int v2;
//         int v3;
// };

class Numbers{
    public:
        //default constructor
        Numbers(){};
        //another default constructor
        Numbers(int v1, int v2, int v3){
            this->v1 = v1;
            this->v2 = v2;
            this->v3 = v3;
        }
        
        int v1;
        void print(){
            cout << v1 << " " << v2 << " " << v3 << endl;
        }
        void setVar3(int var3){v3 = var3;}
        int getVar3(){return v3;}
    
    protected:
        int v2;

    private:
        int v3;
};

//how you would define the constructor out of the class:
// Numbers :: Numbers(int v1, int v2, int v3){
//     this->v1 = v1;
//     this->v2 = v2;
//     this->v3 = v3;
// }

//how you would define the print function out of the class:
// void Numbers :: print(){
//     cout << v1 << " " << v2 << " " << v3 << endl;
// }

class B: public Numbers{
    public:
        B(int v1, int v2, int v3){
            this->v1 = v2;
            this->v2 = v2; //v2 is protected, but can still be accessed because this class is inherited from Numbers
            setVar3(v3); //since v3 is private, we create a setvar3 function in private of numbers class
        }
        void printV2V3(); //function is declared in the class, but the implementation is done out of class
    
    private:
};

void B :: printV2V3(){
    cout << v2 << " " << getVar3() << endl;
}

int main(){
    Numbers num1(1, 2, 3);
    num1.print();
    B nums2(4, 5, 6);
    nums2.printV2V3();

    return 0;
}
