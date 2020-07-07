/*
Given an array with n objects colored red, white or blue,
sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note: Using library sort function is not allowed.

Example :

Input : [0 1 2 0 1 2]
Modify array so that it becomes : [0 0 1 1 2 2]
*/

void Solution::sortColors(vector<int> &A) {
    
    int zero=0,one=0,two=0;
    for(int i=0;i<A.size();i++){
        if(A[i]==0){
            zero++;
        }else if(A[i]==1){
            one++;
        }else{
            two++;
        }
    }
    int l=0;
    for(int i=0;i<zero;i++){
        A[l++]=0;
    }
    for(int i=0;i<one;i++){
        A[l++]=1;
    }
    for(int i=0;i<two;i++){
        A[l++]=2;
    }
}
