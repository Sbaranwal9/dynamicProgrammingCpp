#include <iostream>
#include <vector>
using namespace std;

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
       int sumAll = 0;
        int prev, x = 0;
        int sum = 0;
        for(int i = 0; i < gas.size(); i++){
            int diff = gas[i]-cost[i];
            sumAll += diff;
            sum += diff;
            if(sum < 0){
                sum = 0;
                x = i+1;
            }
        } 
        return sumAll < 0 ? -1 : x;
    }

int main(){
  vector<int> gas({3,1,1});
  vector<int> cost({1,2,2});
  cout << canCompleteCircuit(gas, cost) << endl;
}
