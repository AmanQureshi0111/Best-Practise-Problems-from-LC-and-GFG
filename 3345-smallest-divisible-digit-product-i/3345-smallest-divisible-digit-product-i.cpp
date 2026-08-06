class Solution {
public:
    int prod(int n,int t){
        int prod=1;
        while(n){
            prod*=(n%10);
            n/=10;
        }
        return prod == 0 ? true :( prod%t == 0 ? true : false );
    }
    int smallestNumber(int n, int t) {
        while(prod(n,t)==false){
            n++;
        }
        return n;
    }
};