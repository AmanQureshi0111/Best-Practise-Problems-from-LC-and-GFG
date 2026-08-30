class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int min_idx=0;
        int max_idx=0;
        int n = nums.size();
        for(int i=1;i<n;i++){
            if(nums[min_idx]>nums[i]){
                min_idx=i;
            }
            if(nums[max_idx]<nums[i]){
                max_idx=i;
            }
        }
        int ans=INT_MAX;
        // left side
        int j=max(min_idx,max_idx);
        ans=j+1;
        // right side
        j=min(min_idx,max_idx);
        ans=min(ans,n-j);
        //opposite side
        ans=min(ans,min(min_idx+1,n-min_idx)+min(max_idx+1,n-max_idx));
        return ans;

    }
};