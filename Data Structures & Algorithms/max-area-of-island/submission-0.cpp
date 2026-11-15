class Solution {
private: 
    void dfs(vector<vector<int>>& grid, int x, int y, int& count, int& maxCount) {
        int dirs[4][2] = {
            {-1, 0}, 
            {1, 0}, 
            {0, 1}, 
            {0, -1}, 
        }; 


        if(x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] != 1) {
            return;  
        } 

        count++;
        grid[x][y] = 0; 

        maxCount = max(count, maxCount); 

        for(auto& dir : dirs) {
            dfs(grid, x + dir[0], y + dir[1], count, maxCount); 
        } 
    }
    
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxCount = 0; 
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[i].size(); j++) {
                if(grid[i][j] == 1) {
                    int count = 0;
                    dfs(grid, i, j, count, maxCount); 
                }
            }
        } 

        return maxCount;
    }
};