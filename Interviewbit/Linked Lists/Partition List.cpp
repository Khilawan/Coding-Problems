/*
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode* Solution::partition(ListNode* A, int B) {
    ListNode* small=new ListNode(0);
    ListNode* big=new ListNode(0);
    ListNode* p=NULL;
    ListNode* q=NULL;
    p=small;
    q=big;
    
    ListNode* head=A;
    
    while(head!=NULL){
        if(head->val<B){
            p->next=head;
            p=p->next;
        }else{
            q->next=head;
            q=q->next;
        }   
        head=head->next;
    }
    q->next=NULL;
    p->next=big->next;
    
    return small->next;
}
