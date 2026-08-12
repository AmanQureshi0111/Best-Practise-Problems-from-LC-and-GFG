class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return nums[0]+1;
        }
        unordered_set<int> st(nums.begin(),nums.end());
        int x=nums[0];
        for(int j=1;j<n && nums[j]==nums[j-1]+1;j++){
            x+=nums[j];
        }
        while(st.find(x)!=st.end()){
            x++;
        }
        return x;
    }
};