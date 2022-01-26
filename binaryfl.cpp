#include <vector>
#include <iostream>
using namespace std;

vector<int> searchRange1(vector<int>& nums, int target) {
        int l = 0, h = nums.size() - 1;
        while(l <= h){
            int mid = l + (h - l) / 2; 
            if(nums[mid] < target) l = mid + 1;
            else if(nums[mid] > target) h = mid - 1;
            else{
                if(nums[l] == target && nums[h] == target) return {l, h};
                if(nums[l] < target) l++;
                if(nums[h] > target) h--;
            }
        }
        return {-1, -1};
    }

vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> r{-1, -1};
        // finding first occurance
        int l = 0, h = nums.size() - 1;
        while(l <= h){
            int m = l + (h - l) / 2;
            if(nums[m] > target) h = m - 1;
            else if(nums[m] < target) l = m + 1;
            else{
                r[0] = m;
                h = m - 1;
            }
        }
        // finding second occurance
        l = 0, h = nums.size() - 1;
        while(l <= h){
            int m = l + (h - l) / 2;
            if(nums[m] > target) h = m - 1;
            else if(nums[m] < target) l = m + 1;
            else{
                r[1] = m;
                l = m + 1;
            }
        }
        return r;
    }

int main(){
  vector<int> nums{5,7,7,8,8,10}
  int target = 8;
  vector<int> res = searchRange(nums, target);
  cout << res[0] << " " << res[1] << endl;
}
