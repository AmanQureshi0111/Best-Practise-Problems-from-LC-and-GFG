struct Node{
    Node* links[26];
    bool flag;
    Node(){
      flag=true;  
      for(int i=0;i<26;i++){
          links[i]=nullptr;
      }
    }
    bool containsKey(char ch){
        return links[ch-'a']!=nullptr;
    }
    
};
class Trie{
    Node* root;
public:
    Trie(){
        root=new Node();
    }
    void insert(string &s){
        Node* curr=root;
        for(auto &ch:s){
            if(curr->containsKey(ch)==false){
                curr->links[ch-'a']=new Node();
                curr=curr->links[ch-'a'];
            }else{
                curr=curr->links[ch-'a'];
                curr->flag=false;
                
            }
            
        }
    }
    string findPrefix(string s){
        string ans="";
        Node* curr=root;
        for(auto &ch:s){
            ans+=ch;
            curr=curr->links[ch-'a'];
            if(curr->flag==true){
                break;
            }
        }
        return ans;
    }
};
class Solution {
  public:
    vector<string> findPrefixes(vector<string>& arr) {
        Trie trie;
        for(auto &s:arr){
            trie.insert(s);
        }
        vector<string> ans;
        for(auto &s:arr){
            ans.push_back(trie.findPrefix(s));
        }
        return ans;
    }
};