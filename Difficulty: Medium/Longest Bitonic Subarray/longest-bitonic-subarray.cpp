class Solution {
  public:
    int bitonic(vector<int> &arr) {
        int n=arr.size();
        vector<int> inc(n);
        inc[0]=1;
        for(int i=1;i<n;i++){
            inc[i]=(arr[i]>=arr[i-1]) ? inc[i-1]+1 : 1;
        }
        vector<int> dec(n);
        dec[n-1]=1;
        for(int i=n-2;i>=0;i--){
            dec[i]=(arr[i]>=arr[i+1]) ? dec[i+1]+1 : 1;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,inc[i]+dec[i]-1);
        }
        return ans;
    }
};
