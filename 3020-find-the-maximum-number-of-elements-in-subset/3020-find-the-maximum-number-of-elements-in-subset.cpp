class Solution {
public:
    int maximumLength(vector<int>& nums) {
        
        map<int,int> mp;
        for(int &num:nums){
            mp[num]++;
        }
        int ans=1;
        if(mp.find(1)!=mp.end()){
            if(mp[1]%2==0){
                ans=max(ans,mp[1]-1);
            }else{
                ans=max(ans,mp[1]);
            }
            mp.erase(1);
        }
        for(auto &it:mp){
            int cnt=0;
            long long x=(long long)it.first;
            while(mp.find((int)x)!=mp.end()){
                cnt++;
                if(mp[(int)x]<2){
                    break;
                }
                if(x>LLONG_MAX/x) break;
                x*=x;
            }
            ans=max(ans,2*cnt-1);
        }
        return ans;
    }
};