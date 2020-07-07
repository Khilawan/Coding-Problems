/*
Problem Description

Given a sorted array A and a target value B, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.



**Problem Constraints**
1 <= |A| <= 100000

1 <= B <= 109



**Input Format**
First argument is array A.

Second argument is integer B.



**Output Format**
Return an integer, the answer to the problem.



**Example Input**
Input 1:

 A = [1, 3, 5, 6]
B = 5
Input 2:

 A = [1, 3, 5, 6]
B = 2


**Example Output**
Output 1:

 2
Output 2:

 1
*/

int Solution::searchInsert(vector<int> &A, int B) {
    
    int s=0,e=A.size()-1;
    if(B<A[0]){
        return 0;
    }else if(B>A[e]){
        return e+1;
    }
    int mid;
    while(s<=e){
        mid=(s+e)/2;
        
        if(A[mid]==B){
            return mid;
        }else if(A[mid]<B&&A[mid+1]>B){
            return mid+1;
        }else if(A[mid]<B){
            s=mid+1;
        }else if(A[mid]>B){
            e=mid-1;
        }
    }
}
