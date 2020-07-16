/*
Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::swapPairs(ListNode* A) {
    ListNode* head=A;
    ListNode* p=NULL;
    ListNode* q=head;
    ListNode* tmp=NULL;
    int i=0;
    
    
    while(q!=NULL&&i<2){
        tmp=q->next;
        q->next=p;
        p=q;
        q=tmp;
        i++;
    }
    
    if(q){
        head->next=swapPairs(q);
    }
    
    return p;
}
