#include <vector>
#include <iostream>
using namespace std;

// normal
int search(vector<int> nums, int target) {
  int l = 0, h = nums.size() - 1;
  while(l <= h){
    int mid = l + (h - l) / 2;
    if(nums[mid] == target) return mid;
    else if(nums[mid] > target) h = mid - 1;
    else l = mid + 1;
  }
  return -1;
}

// lower
int searchLower(vector<int> nums, int target) {
  int l = 0, h = nums.size() - 1;
  while(l < h){ 
    // upper mid
    int mid = l + (h - l + 1) / 2;
    cout << l << " " << mid << " " << h << endl;
    if(nums[mid] > target) h = mid - 1;
    else l = mid;
  }
  // if(nums[l] == target) return l;
  // return -1;
  return nums[l];
}

// higher
int searchHigher(vector<int> nums, int target) {
  int l = 0, h = nums.size() - 1;
  while(l < h){
    // lower mid
    int mid = l + (h - l) / 2;
    cout << l << " " << mid << " " << h << endl;
    if(nums[mid] < target) l = mid + 1;
    else h = mid;
  }
  // if(nums[l] == target) return l;
  // return -1;
  return nums[l];
}

int main(){
  // cout << search({-1,0,3,5,9,12}, 2) << endl;
  cout << searchLower({-1,0,3,5,9,12}, 2) << endl;
  // cout << searchHigher({-1,0,3,5,9,12}, 2) << endl;
  return 0;
}