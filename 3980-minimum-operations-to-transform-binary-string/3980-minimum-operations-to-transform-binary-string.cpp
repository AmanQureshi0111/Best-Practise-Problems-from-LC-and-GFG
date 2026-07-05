class Solution {
public:
    int minOperations(string s1, string s2) {
        int n=s1.length();
        int cnt=0;
        for(int i=0;i<n-1;i++){
            if(s1[i]==s2[i]) continue;
            if(s1[i]=='0'){
                cnt++;
                continue;
            } 
            if(s1[i+1]=='1'){
                cnt++;
            }else{
                cnt+=2;
            }
            s1[i+1]='0';
        }
        //last char
        if(s1[n-1]==s2[n-1]) return cnt;
        if(s1[n-1]=='0') return cnt+1;
        if(n==1) return -1;
        return cnt+2;
    }
};