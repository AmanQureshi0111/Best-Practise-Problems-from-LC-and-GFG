class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> last(26);
        int n=s.length();
        for(int i=0;i<n;i++){
            last[s[i]-'a']=i;
        }
        string st;
        vector<bool> inStack(26);
        for(int i=0;i<n;i++){
            if(inStack[s[i]-'a']) continue;
            while(!st.empty() && st.back()>s[i] && last[st.back()-'a']>i){
                inStack[st.back()-'a']=false;
                st.pop_back();
            }
            inStack[s[i]-'a']=true;
            st.push_back(s[i]);
        }
        return st;
    }
};