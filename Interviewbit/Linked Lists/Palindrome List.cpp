/*
Given a singly linked list, determine if its a palindrome. Return 1 or 0 denoting if its a palindrome or not, respectively.

Notes:

Expected solution is linear in time and constant in space.
For example,

List 1-->2-->1 is a palindrome.
List 1-->2-->3 is not a palindrome.

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int Solution::lPalin(ListNode* A) {
    vector<int>v;
    ListNode* head=A;
    
    while(head!=NULL){
        v.push_back(head->val);
        head=head->next;
    }
    
    reverse(v.begin(),v.end());
    
    int i=0;
    head=A;
    while(i<v.size()){
        if(v[i]!=head->val){
            return 0;
        }
        i++;
        head=head->next;
    }
    
    return 1;
}
