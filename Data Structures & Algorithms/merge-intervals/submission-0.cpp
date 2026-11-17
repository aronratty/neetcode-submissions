
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> res;

        for (int i = 0; i < intervals.size(); i++) {
            if (res.empty()) {
                res.push_back(intervals[i]);
                continue;
            } else {
                if (intervals[i][0] <= res.back()[1]) {
                    res.back()[1] = std::max(
                        intervals[i][1],
                        res.back()[1]
                    );
                } else {
                    res.push_back(intervals[i]);
                }
            }
        }

        return res;
    }
};
