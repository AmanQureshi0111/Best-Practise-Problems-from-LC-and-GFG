class Solution {
  public:
    vector<vector<int>> dp;
    int solve(int i,int prev,vector<vector<int>> &mat){
        if(i<0){
            return 0;
        }
        if(dp[i][prev]!=-1) return dp[i][prev];
        int ans=INT_MAX;
        for(int j=0;j<3;j++){
            if(j==prev) continue;
            ans=min(ans,mat[i][j]+solve(i-1,j,mat));
        }
        return dp[i][prev]= ans;
    }
    int minCost(vector<vector<int>>& mat) {
        // code here
        int n=mat.size();
        int ans=INT_MAX;
        dp.resize(n,vector<int>(3,-1));
        for(int j=0;j<3;j++){
            ans=min(ans,mat[n-1][j]+solve(n-2,j,mat));
        }
        return ans;
    }
};