class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res; 

        if(nums.size() < 3) {
            return res;
        }; 

        sort(nums.begin(), nums.end());

        for(int first = 0; first < nums.size(); first++) {

            if(first > 0 && nums[first] == nums[first - 1]) {
                continue; 
            }

            int left = first + 1; 
            int right = nums.size() - 1; 

            while(left < right) {

                int sum = nums[first] + nums[left] + nums[right]; 

                if(sum == 0) {
                    res.push_back({nums[first],nums[left],nums[right]}); 

                    while(left < right && nums[left] == nums[left + 1]) {
                        left++; 
                    }; 
                    left++; 

                    while(right > left && nums[right] == nums[right - 1]) {
                        right--; 
                    };
                    right--; 
                } else if (sum > 0) {
                    right--;
                } else if (sum < 0) {
                    left++; 
                }
            }
        }
        return res;
    }
};
