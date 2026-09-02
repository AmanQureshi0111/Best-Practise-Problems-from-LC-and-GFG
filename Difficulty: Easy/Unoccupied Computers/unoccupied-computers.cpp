class Solution {
  public:
    int solve(int n, string s) {
        // code here
        int cnt=0;
        int freePC=n;
        vector<bool> visited(26,false);
        vector<bool> alloted(26,false);
        for(auto ch:s){
            if(visited[ch-'A']==false){
                if(freePC>0){
                    alloted[ch-'A']=true;
                    freePC--;
                }else{
                    cnt++;
                }
                visited[ch-'A']=true;
            }else{
                if(alloted[ch-'A']){
                    freePC++;
                }
            }
        }
        return cnt;
    }
};
