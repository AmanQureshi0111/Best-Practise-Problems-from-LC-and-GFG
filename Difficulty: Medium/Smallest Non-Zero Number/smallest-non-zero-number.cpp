class Solution {
  public:
    int find(vector<int>& arr) {
        int x=0;
        int n=arr.size()-1;
        while(n>=0){
            x=(x+arr[n]+1)/2;
            n--;
        }
        return x;
    }
};