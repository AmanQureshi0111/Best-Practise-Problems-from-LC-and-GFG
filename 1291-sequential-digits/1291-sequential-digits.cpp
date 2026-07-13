class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        int l=log10(low)+1;
        int h=log10(high)+1;
        string num="123456789";
        while(l<=h){
            for(int i=0;i+l<10;i++){
                int val=stoi(num.substr(i,l));
                if(val<low) continue;
                if(val>high) break;
                ans.push_back(val);
            }
            l++;
        }
        return ans;
    }
};