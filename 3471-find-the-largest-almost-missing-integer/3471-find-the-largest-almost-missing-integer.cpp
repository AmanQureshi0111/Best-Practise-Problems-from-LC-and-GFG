class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n-k+1;i++){
            unordered_set<int> st;
            for(int j=i;j<i+k;j++){
                if(st.find(nums[j])==st.end()){
                    mp[nums[j]]++;
                    st.insert(nums[j]);
                }
            }
        }
        int ans=-1;
        for(int &num:nums){
            if(mp[num]==1){
                ans=max(ans,num);
            }
        }
        return ans;
    }
};