class Solution {
  public:
    string compress(string &s) {
        stack<char> st;
        int n=s.length();
        for(int i=n-1;i>=0;i--){
            int length=i+1;
            if(length%2==1){
                st.push(s[i]);
                continue;
            }
            int half=length/2;
            bool similar=true;
            for(int j=0;j<half;j++){
                if(s[j]!=s[half+j]){
                    similar=false;
                    break;
                }
            }
            if(similar){
                st.push('*');
                i=half;
            }else{
                st.push(s[i]);
            }
        }
        string ans="";
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};
