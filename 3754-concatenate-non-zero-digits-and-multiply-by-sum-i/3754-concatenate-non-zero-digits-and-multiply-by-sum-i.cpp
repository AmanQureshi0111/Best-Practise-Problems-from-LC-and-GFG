class Solution {
public:
    typedef long long ll;
    long long sumAndMultiply(int n) {
        ll x=0;
        ll sum=0;
        ll mul=1LL;
        while(n){
            int d=n%10;
            if(d!=0){
                x+=d*mul;
                mul*=10LL;
            } 
            sum+=(ll)d;
            n/=10;
        }
        return x*sum;
    }
};