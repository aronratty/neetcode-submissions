class Solution {
public:
    int trap(vector<int>& height) {

        if(height.size() < 3) {
            return 0; 
        }
        
        int l = 0; 
        int r = height.size() - 1;
        int total = 0; 

        stack<int> s; 

        while(l < r && height[l] < height[l + 1]) {
            l++; 
        }

        while(r > l && height[r] < height[r - 1]) {
            r--; 
        }

        for(int i = l; i <= r; i++) {
            while(!s.empty() && height[i] > height[s.top()]) {
                int prevHeightIndex = s.top();
                s.pop(); 

                if(s.empty()) {
                    break;
                }

                int boundHeightIndex = s.top(); 
                int w = i - boundHeightIndex - 1; 
                int boundHeight = min(height[boundHeightIndex], height[i]) - height[prevHeightIndex]; 
                total += w * boundHeight;
            }

            s.push(i);
        }

        return total; 
    }
};
