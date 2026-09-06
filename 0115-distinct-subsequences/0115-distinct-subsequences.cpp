class Solution {
public:
    int numDistinct(string s, string t) {
        int n=s.length();
        int m=t.length();
        vector<long> dp(m+1,0);
        dp[0]=1;
        for(int i=1;i<=n;i++){
            for(int j=m;j>=1;j--){
                long not_match=dp[j];
                long match=0;
                if(s[i-1]==t[j-1]){
                    match=dp[j-1];
                }
                dp[j]=int(match+not_match);
            }
        }
        return dp[m];
    }
};