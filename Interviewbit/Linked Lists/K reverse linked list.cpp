/*
Given a singly linked list and an integer K, reverses the nodes of the

list K at a time and returns modified linked list.

 NOTE : The length of the list is divisible by K 
Example :

Given linked list 1 -> 2 -> 3 -> 4 -> 5 -> 6 and K=2,

You should return 2 -> 1 -> 4 -> 3 -> 6 -> 5

Try to solve the problem using constant extra space.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 


ListNode* Solution::reverseList(ListNode* A, int B) {
    
    ListNode* head=A;
    ListNode* p=NULL;
    ListNode* q=head;
    ListNode* tmp=NULL;
    int i=0;
    
    
    while(q!=NULL&&i<B){
        tmp=q->next;
        q->next=p;
        p=q;
        q=tmp;
        i++;
    }
    
    if(q){
        head->next=reverseList(q,B);
    }
    
    return p;
}
