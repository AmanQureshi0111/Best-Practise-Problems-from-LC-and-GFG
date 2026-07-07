class Solution {
  public:
    int maxPathSum(vector<int> &a, vector<int> &b) {
        int result = 0;
        int sum1=0;
        int sum2=0;
        int i=0;
        int j=0;
        int n1=a.size();
        int n2=b.size();
        while(i<n1 && j<n2){
            if(a[i]<b[j]){
                sum1+=a[i];
                i++;
            }else if(a[i]>b[j]){
                sum2+=b[j];
                j++;
            }else{
                result+=max(sum1,sum2)+a[i];
                sum1=0;
                sum2=0;
                i++;
                j++;
            }
        }
        while(i<n1) sum1+=a[i++];
        while(j<n2) sum2+=b[j++];
        return result+max(sum1,sum2);
    }
};