class Solution {
  public:
    int maxDiffSubArrays(vector<int>& arr) {
        int ans=0;
        int n=arr.size();
        vector<int> temp(n);
        temp[n-1]=arr[n-1];
        for(int i=n-2;i>=0;i--){
            temp[i]=max(arr[i],temp[i+1]+arr[i]);
        }
        int minSum=0;
        int sum=0;
        for(int i=0;i<n-1;i++){
            sum+=arr[i];
            ans=max(ans,abs(sum-temp[i+1]));
            if(sum>0){
                sum=0;
            }
        }
        temp[n-1]=arr[n-1];
        for(int i=n-2;i>=0;i--){
            temp[i]=min(arr[i],temp[i+1]+arr[i]);
        }
        int maxSum=0;
        for(int i=0;i<n-1;i++){
            maxSum+=arr[i];
            ans=max(ans,abs(maxSum-temp[i+1]));
            if(maxSum<0){
                maxSum=0;
            }
        }
        return ans;
    }
};