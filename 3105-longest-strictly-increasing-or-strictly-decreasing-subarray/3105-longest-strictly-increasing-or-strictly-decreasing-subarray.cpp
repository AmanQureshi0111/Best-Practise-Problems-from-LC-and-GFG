class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int i=0,d=0;
        int ans=1;
        for(int k=1;k<nums.size();k++){
            if(nums[k]>nums[k-1]){
                d=k;
            }else if(nums[k]<nums[k-1]){
                i=k;
            }else{
                i=k;
                d=k;
            }
            ans=max({ans,k-i+1,k-d+1});
        }
        return ans;
    }
};