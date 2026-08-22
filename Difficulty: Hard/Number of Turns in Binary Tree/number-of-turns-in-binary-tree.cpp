/* Structure of Binary Tree Node
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
  public:
    bool findPath(Node* root,int target,vector<Node*> &path){
        if(!root) return false;
        path.push_back(root);
        if(root->data==target){
            return true;
        }
        if(findPath(root->left,target,path)) return true;
        if(findPath(root->right,target,path)) return true;
        path.pop_back();
        return false;
    }
    int numberOfTurns(Node* root, int p, int q) {
        // code here
        vector<Node*> pathP,pathQ;
        findPath(root,p,pathP);
        findPath(root,q,pathQ);
        int i =0;
        while(i<pathP.size() && i<pathQ.size() && pathP[i]==pathQ[i]) i++;
        vector<Node*> path;
        for(int j=pathP.size()-1;j>=i;j--){
            path.push_back(pathP[j]);
        }
        for(int j=i-1;j<pathQ.size();j++){
            path.push_back(pathQ[j]);
        }
        int turns=0;
        int prevDir=0;
        for(int j=0;j<path.size()-1;j++){
            int currDir;
            if(path[j]->left==path[j+1] || path[j+1]->left==path[j]){
                currDir=1;
            }else {
                currDir=2;
            }
            if(prevDir!=0 && currDir!=prevDir) turns++;
            prevDir=currDir;
        }
        return turns == 0 ? -1 : turns;
    }
};