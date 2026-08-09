class Solution {
  public:
    int n;
    vector<vector<int>> dp;
    int solve(int i,int last,vector<vector<int>> &mat){
        if(i==n) return 0;
        if(dp[i][last]!=-1) return dp[i][last];
        int ans=0;
        for(int j=0;j<n;j++){
            if(last==j) continue;
            ans=max(ans,mat[i][j]+solve(i+1,j,mat));
        }
        return dp[i][last] = ans;
    }
    int zigzagSequence(vector<vector<int>>& mat) {
        n=mat.size();
        dp.resize(n,vector<int>(n+1,-1));
        return solve(0,n,mat);
    }
};