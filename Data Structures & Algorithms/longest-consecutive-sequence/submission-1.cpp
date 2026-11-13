class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());

        int ans = 0; 

        for(int x : s) {
            if(x == INT_MIN || !s.count(x - 1)) {
                int curr = x; 
                int length = 1; 

                while(curr != INT_MAX && s.count(curr + 1)) {
                    length++; 
                    curr = curr + 1; 
                }; 

                ans = max(ans, length);
            }
        } 


        return ans;
    }
};
