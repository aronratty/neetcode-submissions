class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> mp; 

        std::priority_queue<
            std::pair<int, int>,
            std::vector<std::pair<int, int>>,
            std::greater<std::pair<int, int>>
        > pq;

        for(int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++; 
        }

        for(const auto& [num, freq] : mp) {
            if(pq.size() < k) {
                pq.push({freq, num}); 
            } else if (pq.top().first < freq) {
                pq.pop(); 
                pq.push({freq, num}); 
            }
        }

        vector<int> res; 

        while(!pq.empty()) {
            res.push_back(pq.top().second); 
            pq.pop(); 
        }

        return res;
    }
};