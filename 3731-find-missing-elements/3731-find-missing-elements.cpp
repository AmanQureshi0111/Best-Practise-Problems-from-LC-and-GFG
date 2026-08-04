class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> ans;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int missing=nums[0]+1;
        int i=1;
        while(i<n){
            if(missing<nums[i]){
                ans.push_back(missing);
                missing++;
            }else if(missing==nums[i]){
                missing++;
                i++;
            }
        }
        return ans;
    }
};