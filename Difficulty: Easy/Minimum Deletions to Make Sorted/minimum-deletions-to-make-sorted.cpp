class Solution {
  public:
    int minDeletions(vector<int>& arr) {
        vector<int> temp;
        int n=arr.size();
        temp.push_back(arr[0]);
        for(int i=1;i<n;i++){
            if(temp.back()<arr[i]){
                temp.push_back(arr[i]);
            }else{
                auto it=lower_bound(temp.begin(),temp.end(),arr[i]);
                *it=arr[i];
            }
        }
        return n-(int)temp.size();
    }
};
/*
1 4 7
1
*/