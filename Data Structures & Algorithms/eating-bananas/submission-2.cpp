class Solution {
private:
    bool bs(auto& piles, int h, int k) {
        int time = 0; 

        for(int p : piles) {
            time += (p + k - 1) / k; 
        }; 

        return time <= h; 
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1; 
        int r = *max_element(piles.begin(),piles.end()); 

        while(l < r) {
            int m = l + (r - l) / 2; 
            if(bs(piles, h, m)) {
                r = m; 
            } else {
                l = m + 1; 
            }; 
        }

        return l; 
    }
};