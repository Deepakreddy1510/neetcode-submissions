class Solution {
public:
    void dfs(int r,int c,vector<vector<int>>& vis,vector<vector<char>>& grid){
        int n = grid.size();
        int m = grid[0].size();
        if(r < 0 || r >= n || c < 0 || c >= m || grid[r][c] == '0' || vis[r][c] == 1){
            return;
        }
        vis[r][c] = 1;
        dfs(r-1,c,vis,grid);
        dfs(r,c+1,vis,grid);
        dfs(r+1,c,vis,grid);
        dfs(r,c-1,vis,grid);
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int islands = 0;
        vector<vector<int>> vis(n,vector<int>(m,0));

        for(int i=0; i < n; i++){
            for(int j=0; j < m; j++){
                if(grid[i][j] == '1' && vis[i][j] == 0){
                    dfs(i,j,vis,grid);
                    islands++;
                }
            }
        }
        return islands;
    }
};