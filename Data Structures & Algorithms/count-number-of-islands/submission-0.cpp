class Solution {
private:
    void dfs(vector<vector<char>>& grid, int i, int j) {

        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] != '1') {
            return; 
        }

        grid[i][j] = '.'; 

        vector<vector<int>> dirs = {
            {-1, 0}, 
            {1, 0},
            {0, 1}, 
            {0, -1}
        };

        for (auto dir : dirs) {
            dfs(grid, i + dir[0], j + dir[1]); 
        }
    }
    
public:
    int numIslands(vector<vector<char>>& grid) {
        int counter = 0; 
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[i].size(); j++) {
                if(grid[i][j] == '1') {
                    counter++; 
                    dfs(grid, i, j); 
                }
            }
        }
        return counter;         
    }
};