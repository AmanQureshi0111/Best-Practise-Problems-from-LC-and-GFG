class Solution {
public:
    bool checkDivisibility(int n) {
        int digitSum=0;
        int digitProd=1;
        int temp=n;
        while(temp){
            int digit=temp%10;
            temp/=10;
            digitSum+=digit;
            digitProd*=digit;
        }
        return n%(digitSum+digitProd) == 0;
    }
};