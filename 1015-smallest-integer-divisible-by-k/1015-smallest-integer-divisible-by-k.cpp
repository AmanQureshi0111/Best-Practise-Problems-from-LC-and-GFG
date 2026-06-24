class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int rem=1%k;
        for(int length=1;length<=k;length++){
            if(rem==0) return length;
            rem=(rem*10+1)%k;
        }
        return -1;
    }
};