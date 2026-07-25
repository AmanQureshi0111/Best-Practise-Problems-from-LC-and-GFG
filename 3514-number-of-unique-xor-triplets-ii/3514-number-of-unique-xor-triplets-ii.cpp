class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        vector<bool> pass(3001,false);
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                pass[nums[i]^nums[j]]=true;
            }
        }
        int cnt=0;
        for(int i=0;i<=3000;i++){
            for(int &num:nums){
                if((i^num)<=3000 && pass[i^num]){ 
                    cnt++;
                    break;
                }
            }
        }
        return cnt;
    }
};