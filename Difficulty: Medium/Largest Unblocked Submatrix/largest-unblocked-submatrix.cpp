class Solution {
  public:
    int largestArea(int n, int m, vector<vector<int>> &arr) {
        // code here
        int k=arr.size();
        vector<bool> rows(n,false);
        vector<bool> cols(m,false);
        for(auto &t:arr){
            int r=t[0]-1;
            int c=t[1]-1;
            rows[r]=true;
            cols[c]=true;
        }
        int row=0;
        int col=0;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(!rows[i]){
                cnt++;
            }else{
                cnt=0;
            }
            row=max(row,cnt);
        }
        cnt=0;
        for(int i=0;i<m;i++){
            if(!cols[i]){
                cnt++;
            }else{
                cnt=0;
            }
            col=max(col,cnt);
        }
        return row*col;
    }
};