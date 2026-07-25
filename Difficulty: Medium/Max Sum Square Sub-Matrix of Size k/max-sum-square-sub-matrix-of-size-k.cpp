class Solution {
  public:
    int maximumSum(vector<vector<int>>& mat, int k) {
        // code here
        int n=mat.size();
        vector<vector<int>> prefSum(n,vector<int>(n));
        prefSum[0][0]=mat[0][0];
        for(int i=1;i<n;i++){
            prefSum[i][0]=prefSum[i-1][0]+mat[i][0];
            prefSum[0][i]=prefSum[0][i-1]+mat[0][i];
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<n;j++){
                prefSum[i][j]=prefSum[i-1][j]+prefSum[i][j-1]+mat[i][j]-prefSum[i-1][j-1];
            }
        }
        int ans=INT_MIN;
        for(int i=k-1;i<n;i++){
            for(int j=k-1;j<n;j++){
                int currSum=prefSum[i][j];
                if(i-k>=0){
                    currSum-=prefSum[i-k][j];
                }
                if(j-k>=0){
                    currSum-=prefSum[i][j-k];
                }
                if(i>=k && j>=k){
                    currSum+=prefSum[i-k][j-k];
                }
                ans=max(ans,currSum);
            }
        }
        return ans;
    }
};
/*
-1 -3 -6
-5 
*/
