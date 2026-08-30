class Solution {
  public:
    vector<int> getMarks(vector<int> &l, vector<int> &r, vector<int> &rank) {
        // code here
        int n=l.size();
        vector<int> marks;
        unordered_map<int,int> mp;
        int t=1;
        for(int i=0;i<n;i++){
            for(int j=l[i];j<=r[i];j++){
                mp[t++]=j;
            }
        }
        for(int &i:rank){
            marks.push_back(mp[i]);
        }
        return marks;
    }
};
