#include <iostream>
#include <vector>
#include <queue> 
using namespace std;

class StoneGame{
    public:
        int lastStoneWeight(vector<int>& stones){
            //create a max heap
            priority_queue<int> maxHeap(stones.begin(), stones.end());

            //continue until only one or no stones are left
            while(maxHeap.size() > 1){
                int first = maxHeap.top();
                maxHeap.pop();
                int second = maxHeap.top();
                maxHeap.pop();

                //if the stones have different weights, push the difference back
                if(first != second){
                    maxHeap.push(first - second);
                }
            }

            //if there's a stone left, return its weight; otherwise, return 0
            return maxHeap.empty() ? 0 : maxHeap.top();
        }


};

int main(){
    StoneGame game;
    vector<int> stones1 = {2, 7, 4, 1, 8, 1};
    cout << "Last stone weight (case 1): " << game.lastStoneWeight(stones1) << endl;

    vector<int> stones2 = {1,1};
    cout << "Last stone weight (case 2): " << game.lastStoneWeight(stones2) << endl;

    return 0;
}