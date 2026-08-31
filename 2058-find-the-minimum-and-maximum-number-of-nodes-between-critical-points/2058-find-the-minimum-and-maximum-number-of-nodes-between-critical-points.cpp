/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int index=0;
        ListNode* prev=NULL;
        ListNode* curr=head;
        vector<int> indices;
        while(curr){
            ListNode* next=curr->next;
            if(prev && next && ((prev->val<curr->val && curr->val>next->val) || (prev->val>curr->val && curr->val<next->val))){
                indices.push_back(index);
            }
            index++;
            prev=curr;
            curr=next;
        }
        if(indices.size()<2){
            return {-1,-1};
        }
        int minDist=INT_MAX,maxDist=indices.back()-indices[0];
        for(int i=1;i<indices.size();i++){
            minDist=min(minDist,indices[i]-indices[i-1]);
        }
        return {minDist,maxDist};
    }
};