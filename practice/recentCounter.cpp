#include <queue>
#include <iostream>
using namespace std;

class RecentCounter{
    private:
        queue<int> calls;

    public:
        RecentCounter(){}

        //adds a new call at time t, and returns the number of recent calls
        int ping(int t){
            //add the new call timestamp to the queue
            calls.push(t);

            //remove calls that are outside the 3000 ms window
            while(!calls.empty() && calls.front() < (t - 3000)){
                //the range is 1-3001 inclusive on both ends
                calls.pop();
            }

            //the size of the queue is the number of recent calls
            return calls.size();
        }
};

int main(){
    RecentCounter counter;
    cout << "Number of calls after call of timestamp 1: " << counter.ping(1) << endl;
    cout << "Number of calls after call of timestamp 100: " << counter.ping(100) << endl;
    cout << "Number of calls after call of timestamp 3001: " << counter.ping(3001) << endl;
    cout << "Number of calls after call of timestamp 200: " << counter.ping(200) << endl;
    cout << "Number of calls after call of timestamp 3002: " << counter.ping(3002) << endl;
    cout << "Number of calls after call of timestamp 500: " << counter.ping(500) << endl;

    return 0;
}