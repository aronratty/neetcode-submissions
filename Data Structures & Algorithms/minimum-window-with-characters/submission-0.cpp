class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty() || t.size() > s.size()) {
            return "";
        }

        unordered_map<char, int> tmap;
        unordered_map<char, int> smap;

        int matched = 0;
        int minSize = INT_MAX;
        int bestStart = 0;

        for (char c : t) {
            tmap[c]++;
        }

        int l = 0;
        int r = 0;

        while (r < s.size()) {
            if (tmap.count(s[r]) > 0) {
                if (smap[s[r]] + 1 == tmap[s[r]]) {
                    matched++;
                }
                smap[s[r]]++;
            }

            r++;

            while (matched == tmap.size()) {
                if (r - l < minSize) {
                    minSize = r - l;
                    bestStart = l;
                }

                if (tmap.count(s[l]) > 0) {
                    smap[s[l]]--;

                    if (smap[s[l]] < tmap[s[l]]) {
                        matched--;
                    }
                }

                l++;
            }
        }

        if (minSize == INT_MAX) {
            return "";
        }

        return s.substr(bestStart, minSize);
    }
};
