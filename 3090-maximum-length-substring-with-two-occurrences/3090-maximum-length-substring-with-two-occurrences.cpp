class Solution {
public:
    int maximumLengthSubstring(string s) {
        int ans=0;
        int n=s.length();
        for(int i=0;i<n;i++){
            int j=i;
            vector<int> freq(26);
            while(j<n){
                freq[s[j]-'a']++;
                if(freq[s[j]-'a']>2){
                    break;
                }
                j++;
            }
            ans=max(ans,j-i);
        }
        return ans;
    }
};