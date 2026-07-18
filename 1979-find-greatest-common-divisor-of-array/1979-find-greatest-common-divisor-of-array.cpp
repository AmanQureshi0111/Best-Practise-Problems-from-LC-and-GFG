class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mini=1000;
        int maxi=2;
        for(auto &num:nums){
            mini=min(mini,num);
            maxi=max(maxi,num);
        }
        return __gcd(mini,maxi);
    }
};