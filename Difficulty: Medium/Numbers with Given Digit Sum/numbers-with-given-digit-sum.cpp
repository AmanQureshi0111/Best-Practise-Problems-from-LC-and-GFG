class Solution {
  public:
    vector<vector<int>> dp;
    int cntWays(int n,int sum){
        if(n==0){
            return sum==0;
        }
        if(dp[n][sum]!=-1) return dp[n][sum];
        int cnt=0;
        for(int i=0;i<=9;i++){
            if(sum<i){
                break;
            }
            cnt+=cntWays(n-1,sum-i);
        }
        return dp[n][sum]= cnt;
    }
    int countWays(int n, int sum) {
        // code here
        dp.resize(n,vector<int>(sum,-1));
        int cnt=0;
        for(int i=1;i<=9;i++){
            if(sum<i){
                break;
            }
            cnt+=cntWays(n-1,sum-i);
        }
        return cnt==0 ? -1 : cnt;
    }
};