class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> temp=arr;
        sort(temp.begin(),temp.end());
        unordered_set<int> st;
        unordered_map<int,int> rank;
        for(int &x:temp){
            st.insert(x);
            rank[x]=st.size();
        }
        int n=arr.size();
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            ans[i]=rank[arr[i]];
        }
        return ans;
    }
};