#include <iostream>
#include <stack>
#include <string>
using namespace std;

string removeDigits(const string &s){
    stack<char> charStack; //stack to store non-digit characters
    string result = ""; //result string

    for(char ch : s){
        if(isdigit(ch)){
            //if a digit is encountered, pop the top non-digit character
            if(!charStack.empty()){
                charStack.pop();
            }
        } else {
            //for non-digit characters, push them to the stack and add to result
            charStack.push(ch);
        }
    }

    while(!charStack.empty()){
        result = charStack.top() + result; //add characters in reverse order
        charStack.pop();
    }

    //now the result string contains the remaining characters
    return result;
}

int main(){

    string s1 = "a1b2c3";
    string s2 = "x9yz5y";
    string s3 = "1234";
    string s4 = "a1b1c1def";

    cout << "Result for s1: " << removeDigits(s1) << endl;
    cout << "Result for s2: " << removeDigits(s2) << endl;
    cout << "Result for s3: " << removeDigits(s3) << endl;
    cout << "Result for s4: " << removeDigits(s4) << endl;

    return 0;
}