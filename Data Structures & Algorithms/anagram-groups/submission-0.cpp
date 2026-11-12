class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res; 
        unordered_map<string, vector<string>> mp; 

        for(auto& str : strs) {
            std::string c = str; 
            sort(c.begin(), c.end()); 
            mp[c].push_back(str); 
        };

        for(const auto& [key, vals] : mp) {
            res.push_back(vals); 
        }; 

        return res; 
        
    }
};