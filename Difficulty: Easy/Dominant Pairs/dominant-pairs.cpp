class Solution {
  public:
    int dominantPairs(vector<int> &arr) {
        // Code here
        int n=arr.size();
        int half=n/2;
        sort(arr.begin()+half,arr.end());
        sort(arr.begin(),arr.begin()+half);
        int i=half-1;
        int j=n-1;
        int cnt=0;
        while(i>=0 && j>=half){
            if(arr[i]>=5*arr[j]){
                cnt+=(j-half+1);
                i--;
            }else{
                j--;
            }
        }
        return cnt;
    }
};