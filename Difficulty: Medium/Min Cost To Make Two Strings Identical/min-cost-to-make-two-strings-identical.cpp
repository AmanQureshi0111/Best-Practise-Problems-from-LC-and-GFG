class Solution {
  public:
    vector<vector<int>> dp;
    int findLCS(int i,int j,string &s1,string &s2){
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s2[j]){
            return dp[i][j]=1+findLCS(i-1,j-1,s1,s2);
        }
        return dp[i][j]=max(findLCS(i-1,j,s1,s2),findLCS(i,j-1,s1,s2));
    }
    int findMinCost(string &s1, string &s2, int costS1, int costS2) {
        int n1=s1.length();
        int n2=s2.length();
        dp.resize(n1,vector<int>(n2,-1));
        int len=findLCS(s1.length()-1,s2.length()-1,s1,s2);
       
        return (n1-len)*costS1+(n2-len)*costS2;
    }
};