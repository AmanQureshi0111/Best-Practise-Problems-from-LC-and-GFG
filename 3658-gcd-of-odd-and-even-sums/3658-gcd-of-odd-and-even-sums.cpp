class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        return __gcd(n*n,n*(n+1));
    }
};
/*
1 3 5 7
2 4 6 8
=
36

sumOdd=n*n
sumEven=n(1+n)
*/