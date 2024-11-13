#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

class GiftCollector {
    public:
        int remainingGifts(vector<int>& gifts, int k){
            //create a max heap (priority queue)
            priority_queue<int> giftsHeap;

            //build the max heap from the gifts array
            for(int gift : gifts){
                giftsHeap.push(gift);
            }

            //process for k seconds
            for(int i = 0; i < k; i++){
                if(!giftsHeap.empty()){
                    int maxGifts = giftsHeap.top();
                    giftsHeap.pop();

                    //leave behind the floor of the square root of maxGifts
                    int remainingGifts = floor(sqrt(maxGifts));
                    giftsHeap.push(remainingGifts);
                }
            }

            int totalRemaining = 0;
            while(!giftsHeap.empty()){
                totalRemaining += giftsHeap.top();
                giftsHeap.pop();
            }

            return totalRemaining;
        }
};

int main(){
    GiftCollector collector;
    vector<int> gifts = {25, 64, 9, 4, 100};
    int k = 4;
    int result = collector.remainingGifts(gifts, k);
    cout << "Total remaining gifts: " << result << endl;
}