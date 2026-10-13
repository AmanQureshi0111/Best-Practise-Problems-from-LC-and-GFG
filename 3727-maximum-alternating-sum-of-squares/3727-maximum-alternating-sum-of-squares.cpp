class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
       long long ans=0;
       int n=nums.size();
       for(int i=0;i<n;i++){
            nums[i]=abs(nums[i]);
       }
       sort(nums.begin(),nums.end());
       int idx=0;
       while(idx<n/2){
        ans-=nums[idx]*nums[idx];
        idx++;
       }
       while(idx<n){
        ans+=nums[idx]*nums[idx];
        idx++;
       }
       return ans; 
    }
};