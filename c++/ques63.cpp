class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size(),n=obstacleGrid[0].size();
        if(m==1 && n==1 && obstacleGrid[0][0]==0)return 1;
        if(obstacleGrid[0][0]==1)return 0;
        int dp[m][n];
        for(int i=0;i<m;i++){
            n=obstacleGrid[0].size();
            for(int j=0;j<n;j++){
                if(i==0 && j==0)dp[i][j]=0;
                else if(i==0){
                    if(obstacleGrid[i][j]==1) dp[i][j]=0;
                    else if(j==1)dp[i][j]=1;
                    else dp[i][j]=dp[i][j-1];
                }else if(j==0){
                    if(obstacleGrid[i][j]==1) dp[i][j]=0;
                    else if(i==1) dp[i][j]=1;
                    else dp[i][j]=dp[i-1][j];
                }
                else if(obstacleGrid[i][j]==1) dp[i][j]=0;
                else dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};