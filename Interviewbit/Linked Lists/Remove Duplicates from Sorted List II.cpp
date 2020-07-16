/*
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* A) {
    map<int,int>m;
    ListNode* head=A;
    
    while(head!=NULL){
        m[head->val]++;
        head=head->next;
    }
    
    map<int,int>::iterator it;
    it=m.begin();
    head=A;
    ListNode* prev=NULL;
    int flag=1;
    while(it!=m.end()){
        if(it->second==1){
            head->val=it->first;
            prev=head;
            head=head->next;
            flag=0;
        }
        it++;
    }
    
    if(flag){
        A=NULL;
        return A;
    }
    
    prev->next=NULL;
    
    return A;
}
