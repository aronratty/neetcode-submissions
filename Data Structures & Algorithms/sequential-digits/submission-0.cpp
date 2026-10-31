class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> res;
        string digits = "123456789";
        
        int minLen = to_string(low).size();
        int maxLen = to_string(high).size();

        for (int len = minLen; len <= maxLen; ++len) {
            for (int i = 0; i + len <= 9; ++i) {
                int x = stoi(digits.substr(i, len));
                if (x >= low && x <= high) {
                    res.push_back(x);
                }
            }
        }
        return res;
    }
};