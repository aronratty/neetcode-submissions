#include <vector>

class Solution {
private:
    void bs(const std::vector<int>& nums, int l, int r, int target, int& pos) {
        if (l > r) {
            return; // Base case: not found
        }

        int m = l + (r - l) / 2;

        if (nums[m] == target) {
            pos = m; 
            return;  
        }  

        if (nums[l] <= nums[m]) {
            if (nums[l] <= target && target < nums[m]) {
                bs(nums, l, m - 1, target, pos);
            } else {
                bs(nums, m + 1, r, target, pos); 
            }
        } 
     
        else {
            if (nums[m] < target && target <= nums[r]) {
                bs(nums, m + 1, r, target, pos);
            } else {
                bs(nums, l, m - 1, target, pos); 
            }
        }
    }

public:
    int search(std::vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;  
        int pos = -1; 
        
        bs(nums, l, r, target, pos); 

        return pos; 
    }
};