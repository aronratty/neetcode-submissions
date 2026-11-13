class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0; 
        int right = heights.size() - 1; 
        int water = 0;
        int maxWater = 0; 

        while(left < right) {
            water = std::min(heights[left], heights[right]) * (right - left);
            maxWater =  std::max(water, maxWater); 
            if(heights[left] < heights[right]) {
                left++; 
            } else if (heights[right] < heights[left]) {
                right--; 
            } else {
                left++; 
            }
        }

        return maxWater; 
        
    }
};
