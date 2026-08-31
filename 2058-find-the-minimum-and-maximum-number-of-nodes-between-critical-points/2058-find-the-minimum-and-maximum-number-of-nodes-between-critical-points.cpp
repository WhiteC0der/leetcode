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
        ListNode* prev=head;
        ListNode* curr=prev->next;
        ListNode* next=curr->next;
        if(next==NULL) return {-1,-1};
        int dist=1;
        int mn=1e6;
        int mx=-1;
        // vector<int> temp;
        int prv=-1;
        int st=-1;
        while(next!=NULL){
            if((curr->val>prev->val && curr->val>next->val) || curr->val<prev->val&&curr->val<next->val){
                if(prv!=-1) mn=min(mn,dist-prv);
                else st=dist;

                prv=dist;
            }
            dist++;
            prev=curr;
            curr=next;
            next=next->next;
        }

        if(prv==-1 || prv == st) return {-1,-1};
        // for(int i=1;i<temp.size();i++){
        //     mn=min(temp[i]-temp[i-1],mn);
        // }
        // mx=temp.back()-temp.front();
        mx=prv-st;

        return {mn,mx};
    }
};