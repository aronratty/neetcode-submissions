class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res; 
        string curr = ""; 
        int open = 0;
        int closed = 0; 
        gen(res, curr, open, closed, n); 
        return res; 
    }
private: 
    void gen(vector<string>& res, string& curr, int open, int closed, int n) {
    
        if(curr.size() == 2 * n) {
            res.push_back(curr); 
            return;
        } 

        if(open < n) { 
            curr.push_back('('); 
            gen(res, curr, open + 1, closed, n); 
            curr.pop_back(); 
        }

        if(closed < open) { 
            curr.push_back(')'); 
            gen(res, curr, open, closed + 1, n); 
            curr.pop_back(); // Backtrack
        }
    }
};