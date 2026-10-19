class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        auto copy = nums; 
        sort(copy.begin(), copy.end()); 
        if(copy[copy.size() - 1] < 0) {
            return -1; 
        }

        int total = 0; 
        int sum = 0; 
        for(int i = 0; i < nums.size(); i++) {
            if(sum + nums[i] < 0) {
                sum = 0; 
            } else {
                sum += nums[i]; 
                total = std::max(total, sum); 
            }
        }

        return total; 

    }
};
