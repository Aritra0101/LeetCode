class Solution {
private:
    void bfs(vector<vector<char>>& grid, int i, int j, int m, int n) {
        grid[i][j] = '0';

        if(i>0 && grid[i-1][j]=='1') {
            bfs(grid, i-1,j, m,n);
        }
        if(i<m-1 && grid[i+1][j]=='1') {
            bfs(grid, i+1,j, m,n);
        }

        if(j>0 && grid[i][j-1]=='1') {
            bfs(grid, i,j-1, m,n);
        }
        if(j<n-1 && grid[i][j+1]=='1') {
            bfs(grid, i,j+1, m,n);
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == '1') {
                    ans++;
                    bfs(grid, i,j, m,n);
                    // dfs(grid, i,j, m,n);
                }
            }
        }
        return ans;

        return 11;
    }
};