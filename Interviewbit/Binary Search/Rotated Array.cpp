/*
Suppose a sorted array A is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

The array will not contain duplicates.

NOTE 1: Also think about the case when there are duplicates. Does your current solution work? How does the time complexity change?
*/

int Solution::findMin(const vector<int> &A) {
    if(A.size()==1){
        return A[0];
    }

    int s=0,e=A.size()-1;
    if(A[s]<=A[e]){
        return A[s];
    }
    while(s<=e){
        int mid=(s+e)/2;
        if(A[mid]>A[mid+1]||mid==e){
            return A[mid+1];
        }else if(A[mid]>=A[s]){
            s=mid+1;
        }else if(A[mid]<=A[s]){
            e=mid-1;
        }
    }
    return 0;
}
