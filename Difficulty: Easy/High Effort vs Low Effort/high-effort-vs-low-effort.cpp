class Solution {
  public:
    int maxTask(vector<int>& h, vector<int>& l) {
        // code here
        int n=l.size();
        if(n==1){
            return max(h[0],l[0]);
        }
        int a=max(h[0],l[0]);
        int b=max(max(h[1],h[0]+l[1]),l[0]+l[1]);
        for(int i=2;i<n;i++){
            int c=max(h[i]+a,l[i]+b);
            a=b;
            b=c;
        }
        return b;
    }
};
/*
[2,8,1]
[1,2,1]
[2,8,]
*/