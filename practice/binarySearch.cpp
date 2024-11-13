#include <iostream>
#include <vector>
using namespace std;

//recursive function to perform binary search
int findNumber(const vector<int> &orderedList, int target, int left, int right){
    //base case: if the range is invalid
    if(left > right){
        return -1; // target not found
    }

    int mid = left + (right - left) / 2; //find the middle index

    //check if the middle index is the target
    if(orderedList[mid] == target){
        return mid; //target found at index mid
    }

    //if target is less than the middle element, search in the left half
    if(target < orderedList[mid]){
        return findNumber(orderedList, target, left, mid - 1);
    }

    //if target is greater than the middle element, search in the right half
    if(target > orderedList[mid]){
        return findNumber(orderedList, target, mid + 1, right);
    }
}

int main(){
    vector<int> orderedList = {1, 3, 5, 7, 9, 11, 13, 15, 17};
    int target = 7;
    
    cout << "Ordered list: ";
    for(int num : orderedList){
        cout << num << " ";
    }
    cout << endl;

    int result = findNumber(orderedList, target, 0, orderedList.size() - 1);

    if(result != -1){
        cout << "Number " << target << " found at index " << result << endl;
    } else {
        cout << "Number " << target << " not found in the list" << endl;
    }

    return 0;
}