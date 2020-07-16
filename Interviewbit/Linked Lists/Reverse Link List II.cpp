/*
Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

 Note:
"Given m, n satisfy the following condition:
1 ≤ m ≤ n ≤ length of list. Note 2:
Usually the version often seen in the interviews is reversing the whole linked list which is obviously an easier version of this question." 
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* reverse(ListNode* A){
    ListNode* head=A;
    
    if(head==NULL||head->next==NULL){
        return head;
    }
    ListNode* p=NULL;
    ListNode* q=head;
    
    
    ListNode* tmp=NULL;
    while(q->next!=NULL){
        tmp=q->next;
        q->next=p;
        p=q;
        q=tmp;
    }
    q->next=p;
    head=q;
    
    return head;
}
 
 
ListNode* Solution::reverseBetween(ListNode* A, int B, int C) {
    
    if(B>=C){
        return A;
    }
    ListNode* node=new ListNode(0);
    node->next=A;
    ListNode* p=NULL;
    ListNode* q=NULL;
    ListNode* head=node;
    
    
    int i=0;
    
    while(i<C){
        if(i==B-1){
            p=head;
        }
        i++;
        head=head->next;
    }
    
    q=head->next;
    
    head->next=NULL;
    
    p->next=reverse(p->next);
    
    while(p->next!=NULL){
        p=p->next;
    }
    
    p->next=q;
    
    return node->next;
}
