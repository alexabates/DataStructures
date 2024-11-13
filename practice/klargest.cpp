#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> findKLargest(const vector<int>& nums, int k){
    priority_queue<int, vector<int>, greater<int>> minHeap;

    //insert the first k elements
    for(int i = 0; i < k; i++){
        minHeap.push(nums[i]);
    }

    //process the remaining elements
    for(int i = k; i < nums.size(); i++){
        if(nums[i] > minHeap.top()){
            minHeap.pop();
            minHeap.push(nums[i]);
        }
    }

    //extract elements from the heap
    vector<int> kLargest;
    while(!minHeap.empty()){
        kLargest.push_back(minHeap.top());
        minHeap.pop();
    }

    sort(kLargest.rbegin(), kLargest.rend());
    return kLargest;
}

int main(){
    vector<int> nums = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
    int k = 3;

    vector<int> kLargest = findKLargest(nums, k);

    cout << "The " << k << " largest elements are: ";
    for(int num : kLargest){
        cout << num << " ";
    }
    cout << endl;

    return 0;
}