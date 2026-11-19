class Solution {
private: 
    void bt(auto& letters, auto& v, string& s, int& n) {    
        if(s.size() == n) {
            v.push_back(s); 
            return; 
        }; 

        for(char l : letters) {
            if(!s.empty() && s.back() == l) {
                continue; 
            } else {
                s += l; 
                bt(letters, v, s, n); 
                s.pop_back(); 
            }
        }; 
    }
public:
    string getHappyString(int n, int k) {  
        char letters[3] = {
            'a', 
            'b',
            'c', 
        }; 
        vector<string> v; 
        string s = ""; 
        bt(letters, v, s, n);
        sort(v.begin(), v.end()); 

        return v.size() >= k ? v[k - 1] : ""; 
    }
};
