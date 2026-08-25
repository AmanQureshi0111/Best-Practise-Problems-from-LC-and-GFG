class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> st(nums.begin(),nums.end());
        int mul=1;
        while(st.find(k*mul)!=st.end()){
            mul++;
        }
        return k*mul;
    }
};