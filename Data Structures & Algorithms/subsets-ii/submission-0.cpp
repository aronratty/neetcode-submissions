class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res; 
        vector<int> curr;
        sort(nums.begin(), nums.end()); 
        bt(0, res, curr, nums); 
        return res; 
    }
private:
    void bt(int start, auto& res, auto& curr, auto& nums) {
        res.push_back(curr); 

        for(int i = start; i < nums.size(); i++) {
            if(i > start && nums[i] == nums[i - 1]) {
                continue; 
            }

            curr.push_back(nums[i]); 

            bt(i + 1, res, curr, nums); 

            curr.pop_back(); 
        }; 
    }
};
