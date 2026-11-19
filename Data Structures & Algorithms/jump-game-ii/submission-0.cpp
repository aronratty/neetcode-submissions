class Solution {
public:
    int jump(vector<int>& nums) {

        int l = 0; 
        int r = 0;
        int jumps = 0; 
        
        while(r < nums.size() - 1) {
            int distance = 0; 
            for(int i = l; i <= r; i++) {
                distance = max(distance, nums[i] + i);
            };
            l = r + 1; 
            r = distance;
            jumps++; 
        }; 

        return jumps; 
        
    }
};
