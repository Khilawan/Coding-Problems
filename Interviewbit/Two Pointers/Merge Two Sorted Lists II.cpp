/*
Given two sorted integer arrays A and B, merge B into A as one sorted array.

 Note: You have to modify the array A to contain the merge of A and B. Do not output anything in your code.
TIP: C users, please malloc the result into a new array and return the result. 
If the number of elements initialized in A and B are m and n respectively, the resulting size of array A after your code is executed should be m + n

Example :

Input : 
         A : [1 5 8]
         B : [6 9]

Modified A : [1 5 6 8 9]
*/

void Solution::merge(vector<int> &A, vector<int> &B) {
    vector<int>C;
    int l=0,r=0;
    while(l<A.size()&&r<B.size()){
        if(A[l]<B[r]){
            C.push_back(A[l++]);
        }else{
            C.push_back(B[r++]);
        }
    }
    while(l<A.size()){
        C.push_back(A[l++]);
    }
    while(r<B.size()){
        C.push_back(B[r++]);
    }
    for(int i=0;i<A.size();i++){
        A[i]=C[i];
    }
    for(int i=A.size();i<C.size();i++){
        A.push_back(C[i]);
    }
}
