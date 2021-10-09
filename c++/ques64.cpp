class Solution {
public:
    vector<vector<int>> dp;
    int dfs(vector<vector<int>>& grid,int sr,int sc,int dr,int dc){
        if(sr<0 || sc<0 || sr>=grid.size() || sc>=grid[0].size()){
            return INT_MAX;
        }
        
        if(sr==dr && sc==dc){
            return dp[sr][sc]=grid[sr][sc];
        }
        
        if(dp[sr][sc]!=-1){
            return dp[sr][sc];
        }
        
        int ans1 = dfs(grid,sr,sc+1,dr,dc);
        int ans2 = dfs(grid,sr+1,sc,dr,dc);
        
        return dp[sr][sc]=min(ans1,ans2) + grid[sr][sc];
        
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(); 
        int m = grid[0].size();
        dp.resize(n,vector<int>(m,-1));
        return dfs(grid,0,0,grid.size()-1,grid[0].size()-1);
    }
};