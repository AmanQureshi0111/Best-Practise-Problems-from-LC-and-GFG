class Solution {
public:
    int minimumPushes(string word) {
        int len=word.length();
        int ans=0;
        while(len>=0){
            ans+=len;
            len-=8;
        }
        return ans;
    }
};
/*
8=1
26
*/