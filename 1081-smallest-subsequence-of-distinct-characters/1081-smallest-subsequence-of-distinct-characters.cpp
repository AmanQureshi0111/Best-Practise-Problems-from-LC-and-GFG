class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> last(26,0);
        int n=s.length();
        for(int i=0;i<n;i++){
            int idx=s[i]-'a';
            last[idx]=i;
        }
        string st;
        vector<bool> inStack(26,false);
        for(int i=0;i<n;i++){
            int idx=s[i]-'a';
            if(inStack[idx]){
                continue;
            }
            while(!st.empty() && st.back()>s[i] && last[st.back()-'a']>i){
                
                inStack[st.back()-'a']=false;
                st.pop_back();
            }
            st.push_back(s[i]);
            inStack[idx]=true;
        }
        return st;
    }
};