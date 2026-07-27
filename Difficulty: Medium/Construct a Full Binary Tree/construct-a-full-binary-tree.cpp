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
};*/

class Solution {
  public:
    int n;
    Node* help(vector<int> &pre, vector<int> &preMirror,int &preIndex,int l,int h){
        if(preIndex>=n || l>h){
            return nullptr;
        }
        Node* root=new Node(pre[preIndex++]);
        int i;
        for(i=l;i<=h;i++){
            if(preMirror[i]==pre[preIndex]){
                break;
            }
        }
        if(i<=h){
            root->left=help(pre,preMirror,preIndex,i,h);
            root->right=help(pre,preMirror,preIndex,l+1,i-1);
        }
        return root;
    }
    Node *constructBinaryTree(vector<int> &pre, vector<int> &preMirror) {
        n=pre.size();
        int preIndex=0;
        return help(pre,preMirror,preIndex,0,n-1);
    }
};