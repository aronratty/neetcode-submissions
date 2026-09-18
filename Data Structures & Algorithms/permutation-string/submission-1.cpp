class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) return false;

        int l = 0, r = 0; 
        unordered_map<char, int> m; 
        unordered_map<char, int> check; 

        for (char c : s1) {
            m[c]++; 
        }

        while (r < s2.size()) {
            check[s2[r]]++; 

            while ((r - l + 1) > s1.size()) {
                check[s2[l]]--;
                if (check[s2[l]] == 0) {
                    check.erase(s2[l]); 
                }
                l++; 
            }

    
            if ((r - l + 1) == s1.size() && m == check) {
                return true; 
            }

            r++; 
        }
        
        return false; 
    }
};