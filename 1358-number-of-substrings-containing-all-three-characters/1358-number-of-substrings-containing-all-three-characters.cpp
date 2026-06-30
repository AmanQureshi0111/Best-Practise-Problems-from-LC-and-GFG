class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char,int> mp;
        int i=0;
        int j=0;
        int n=s.length();
        int cnt=0;
        while(j<n){
            mp[s[j]]++;
            while(mp.size()==3){
                cnt+=n-j;
                if(--mp[s[i]]==0){
                    mp.erase(s[i]);
                }
                i++;
            }
            j++;
        }
        return cnt;
    }
};
/*
4+3+2+1

*/