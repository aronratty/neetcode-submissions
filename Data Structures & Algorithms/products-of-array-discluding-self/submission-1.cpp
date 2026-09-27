class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> f(nums.size(), 1); 
        vector<int> b(nums.size(), 1);
        vector<int> res(nums.size()); 

        //1 1 2 8
        //1 6 24 48


        //0 1

        for(int i = 1; i < nums.size(); i++) {
            f[i] = f[i - 1] * nums[i - 1]; 
            b[i] = b[i - 1] * nums[nums.size() - i]; 
        }

        for(int i = 0; i < nums.size(); i++) {
            res[i] = f[i] * b[nums.size() - 1 - i]; 
        }

        return res; 
    }
};
