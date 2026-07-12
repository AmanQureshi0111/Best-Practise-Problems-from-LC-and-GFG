class Solution {
  public:
    int maxAmount(vector<int>& arr, int k) {
        priority_queue<int> pq;
        for(auto &a:arr) pq.push(a);
        int ans=0;
        int mod=1e9+7;
        while(k-- && !pq.empty()){
            int top=pq.top(); pq.pop();
            ans=(ans+top)%mod;
            if(top-1>0){
                pq.push(top-1);
            }
        }
        return ans;
    }
};