class Solution {
public:
    string smallestPalindrome(string s) {
        unordered_map<int,int> freq;
        for(auto &ch:s){
            freq[ch-'a']++;
        }
        string a="";
        char mid='1';
        for(int i=0;i<26;i++){
            char ch='a'+i;
            while(freq[i]>=2){
                a+=ch;
                freq[i]-=2;
            }
            if(freq[i]==1){
                mid=ch;
            }
        }
        string b=a;
        reverse(b.begin(),b.end());
        if(mid=='1'){
            return a+b;
        }
        return a+mid+b;
    }
};