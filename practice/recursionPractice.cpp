#include <iostream>
#include <vector>
#include <string>
using namespace std;

int factorial(int num){
    if(num <= 1){
        return 1;
    }

    return num * factorial(num - 1);
}

int fibonacci(int num){
    if(num <= 1){
        return num;
    }

    return fibonacci(num - 1) + fibonacci(num - 2);
}

int arraySum(const vector<int>& arr, int index){
    if(index == arr.size()){
        return 0;
    }

    return arr[index] + arraySum(arr, index + 1);
}

int binarySearch(const vector<int> &arr, int target, int left, int right){
    if(left > right){
        return -1;
    }

    mid = left + (right - left) / 2;

    if(arr[mid] == target){
        return arr[mid];
    } else if(arr[mid] > target){
        return binarySearch(arr, target, left, mid - 1);
    } else{
        return binarySearch(arr, target, mid + 1, right);
    }
}

string reverseString(const string &str){
    if(str.length() <= 1){
        return str;
    }

    return reverseString(str.substr(1)) + str[0];
}