class Solution {
private:
    void dfs(int node, auto& edges, auto& visited) {
        visited.insert(node);

        for(auto edge : edges) {
            int u = edge[0];
            int v = edge[1]; 

            if (u != node && v != node) {
                continue;
            }

            int neighbor = (u == node) ? v : u; 


            if(!visited.contains(neighbor)) {
                dfs(neighbor, edges, visited); 
            }; 
        }; 
    };
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        if(n <= 1) {
            return n; 
        }; 

        int count = 0; 
        unordered_set<int> visited; 

        for(int i = 0; i < n; i++) {
            if(visited.contains(i)) {
                continue; 
            } else {
                count++; 
                dfs(i, edges, visited); 
            }
        }; 

        return count;
    }
};
