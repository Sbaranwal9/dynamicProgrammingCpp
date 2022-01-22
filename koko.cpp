#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minEatingSpeed(vector<int>& piles, int h) {
    int s = 1;
    int e = *max_element(piles.begin(), piles.end());
    int m = s + (e - s) / 2;
    while (s < e)
    {
        m = s + (e - s) / 2;
       
        int sum = 0;
        for (int i = 0; i < piles.size(); i++)
        {
            sum += (piles[i] / m) + (piles[i] % m == 0 ? 0 : 1);
        }
       
     if (sum > h)
        {
            s = m + 1;
        }
        else
        {
            e = m;
        }
    }
    return s;
    }
    // m+1 for s and not m-1 for e because / 2 will always ignore the decimal values

int main () {
  vector<int> pile = {30, 11, 23, 4, 20};
  cout << minEatingSpeed(pile, 5) << endl ;
}