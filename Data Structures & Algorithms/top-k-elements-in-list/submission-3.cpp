class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::priority_queue<pair<int, int>, vector<pair<int, int>>, std::greater<pair<int, int>>> pq; 
        std::unordered_map<int, int> mp; 
        vector<int> res; 

        for(int n : nums) {
            mp[n]++; 
        };

        for(const auto& [num, freq] : mp) {
            pq.push({freq, num}); 
            if(pq.size() > k) {
                pq.pop();
            }
        }; 

        while(!pq.empty()) {
            auto [freq, num] = pq.top(); 
            res.push_back(num);
            pq.pop(); 
        }


        return res;
        
    }
};
