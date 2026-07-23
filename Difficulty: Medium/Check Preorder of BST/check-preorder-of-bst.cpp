class Solution {
  public:
    bool canRepresentBST(vector<int> &arr) {
        stack<int> st;
        int root=INT_MIN;
        for(auto &node:arr){
            if(node<root){
                return false;
            }
            while(!st.empty() && st.top()<node){
                root=st.top();
                st.pop();
            }
            st.push(node);
        }
        return true;
    }
};
/*

*/