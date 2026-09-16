class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int total = 0;                                   
        int count = 1; 
        unordered_set<int> s(nums.begin(), nums.end()); 
        for(int i = 0; i < nums.size(); i++) {
            if(!s.contains(nums[i] - 1)) {
                int curr = nums[i];
                while(s.contains(curr + 1)) {
                    count++; 
                    curr++; 
                } 
                total = max(count, total);
                count = 1; 
            }
        }
        return total; 
    }
};
