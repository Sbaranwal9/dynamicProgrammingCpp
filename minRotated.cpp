#include <vector>
using namespace std;

int findMin(vector<int>& nums) {
    int l = 0, h = nums.size() - 1;
    while(l < h){
        int m = l + (h - l) / 2;
        if(nums[m] < nums[h]) h = m;
        else l = m + 1;
    }
    return nums[l];
}
int findMin2(vector<int>& nums) {
    int l = 0, h = nums.size() - 1, n = nums.size();
    while(l <= h){
        if(nums[l] <= nums[h]) return nums[l];
        int m = l + (h - l) / 2;
        int next = (m + 1) % n;
        int prev = (m - 1 + n) % n;
        if(nums[m] <= nums[next] && nums[m] <= nums[prev]) return nums[m];
        else if(nums[m] <= nums[h]) h = m - 1;
        else if(nums[m] >= nums[l]) l = m + 1;
    }
    return nums[l];
}
