class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> freq(26);
        for(auto &ch:text){
            freq[ch-'a']++;
        }
        int ans=INT_MAX;
        string str="balloon";
        for(auto &ch:str){
            ans=min(ans,freq[ch-'a']);
            freq[ch-'a']/=2;
        }
        return ans;
    }
};