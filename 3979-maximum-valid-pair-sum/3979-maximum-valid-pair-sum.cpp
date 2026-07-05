class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> prefix(n+1);
        for(int i=0;i<n;i++){
            prefix[i+1]=max(prefix[i],nums[i]);
        }
        vector<int> suffix(n+1);
        for(int i=n-1;i>=0;i--){
            suffix[i]=max(suffix[i+1],nums[i]);
        }
        int ans=0;
        for(int i=0;i<n-k;i++){
            ans=max(ans,prefix[i+1]+suffix[i+k]);
        }
        return ans;
    }
};