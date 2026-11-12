class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ps(n, 1); 
        vector<int> s(n, 1); 
        vector<int> res(n, 1);


        for(int i = 1; i < n; i++) {
            ps[i] = ps[i - 1] * nums[i - 1];
        }

        for(int i = n - 2; i >= 0; i--) {
            s[i] = s[i + 1] * nums[i + 1]; 
        }

        for(int i = 0; i < n; i++) {
            res[i] = ps[i] * s[i]; 
        }

        return res;
    }
};