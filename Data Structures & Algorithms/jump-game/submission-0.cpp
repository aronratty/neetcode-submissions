class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = nums.size() - 1; 
        
        for(int i = nums.size() - 1; i >= 0; i--) {
            if(i + nums[i] >= maxReach) {
                maxReach = i; 
            }
        }

        return maxReach == 0; 
    }
};
