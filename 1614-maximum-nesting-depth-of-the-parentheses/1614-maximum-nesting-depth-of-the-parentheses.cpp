class Solution {
public:
    int maxDepth(string s) {
        int depth=0;
        int maxDepth=0;
        for(auto ch:s){
            if(ch=='('){
                depth++;
            }else if(ch==')'){
                depth--;
            }
            maxDepth=max(maxDepth,depth);
        }
        return maxDepth;
    }
};