class Solution {
private: 
    bool canFinish(vector<int>& piles, int k, int h) {
        long long hours = 0; 
        
        for(int p : piles) {
            hours += (p + k - 1) / k; 
        }
        
        return hours <= h;
    }
    
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1; 
        int r = *max_element(piles.begin(), piles.end()); 
        
        while(l < r) {
            int m = l + (r - l) / 2; 
            
            if(canFinish(piles, m, h)) {
                r = m; 
            } else {
                l = m + 1; 
            }
        }
        
        return l; 
    }
};
