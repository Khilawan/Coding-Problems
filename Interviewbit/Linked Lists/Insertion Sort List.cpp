/*
Sort a linked list using insertion sort.

Example :

Input : 1 -> 3 -> 2

Return 1 -> 2 -> 3
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
    
void sort(ListNode*& head,ListNode* p){
     ListNode* cur=head;
    if(head==NULL||head->val>=p->val){
        p->next=head;
        head=p;
    }else{
        cur=head;
        while(cur->next&&cur->next->val<p->val){
            cur=cur->next;
        }
        p->next=cur->next;
        cur->next=p;
    }
}
 
ListNode* Solution::insertionSortList(ListNode* A) {
    if(A==NULL||A->next==NULL){
        return A;
    }
    
    ListNode* ins=NULL;
    ListNode* p=A;
    ListNode* tmp=NULL;
    
    while(p){
        tmp=p->next;
        sort(ins,p);
        p=tmp;
    }
    
    return ins;
}
