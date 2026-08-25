class Solution {
  public:
    int minMoves(vector<int>& arr) {
        int n=arr.size();
        vector<int> count(n+1,0);
        for(auto &x:arr){
            if(count[x-1]!=0){
                count[x]=count[x-1]+1;
            }else{
                count[x]=1;
            }
        }
        int longest=0;
        for(int i=1;i<=n;i++){
            longest=max(longest,count[i]);
        }
        return n-longest;
    }
};