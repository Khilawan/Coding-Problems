/*
Given an array of integers A of size N and an integer B.

array A is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2 ).

You are given a target value B to search. If found in the array, return its index, otherwise return -1.

You may assume no duplicate exists in the array.

NOTE:- Array A was sorted in non-decreasing order before rotation.

Input 1:
    A = [4, 5, 6, 7, 0, 1, 2, 3]
    B = 4
Output 1:
    0
Explanation 1:
 Target 4 is found at index 0 in A.


Input 2:
    A = [5, 17, 100, 3]
    B = 6
Output 2:
    -1
    
*/

int Binary(const vector<int> &A,int B,int s,int e){
    
    while(s<=e){
        int mid=(s+e)/2;
        if(A[mid]==B){
            return mid;
        }else if(A[mid]<B){
            s=mid+1;
        }else if(A[mid]>B){
            e=mid-1;
        }
    }
    return -1;
}

int partition(const vector<int> &A){
    int s=0,e=A.size()-1;
    
    while(s<=e){
        int mid=(s+e)/2;
        if(A[mid]>A[mid+1]){
            return mid;
        }else if(A[mid]<A[0]){
            e=mid-1;
        }else if(A[mid]>A[0]){
            s=mid+1;
        }
    }
}

int Solution::search(const vector<int> &A, int B) {
    int s=0,e=A.size()-1;
    
    if(A[s]<A[e]){
        return Binary(A,B,s,e);
    }
    if(A[0]<B){
        int p=partition(A);
        return Binary(A,B,s,p);
    }else if(A[0]>B){
        int p=partition(A);
        return Binary(A,B,p+1,e);
    }
    return -1;
}
