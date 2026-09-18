class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1; 
        int r = *std::max_element(piles.begin(), piles.end());
        int ans = r; 

        while(l <= r) {
            int k = l + (r - l) / 2; 

            int total = 0; 
            for(const auto& pile : piles) {
                total += std::ceil((double) pile / k); 
            }; 

            if(total <= h) {
                ans = k; 
                r = k - 1; 
            } else {
                l = k + 1; 
            }
        }

        return ans; 
    }
};
